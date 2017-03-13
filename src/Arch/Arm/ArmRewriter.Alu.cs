﻿#region License
/* 
 * Copyright (C) 1999-2017 John Källén.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 */
#endregion

using Gee.External.Capstone.Arm;
using Reko.Core;
using Reko.Core.Expressions;
using Reko.Core.Machine;
using Reko.Core.Operators;
using Reko.Core.Rtl;
using Reko.Core.Types;
using System;
using System.Linq;
using System.Collections.Generic;
using Reko.Core.Lib;

namespace Reko.Arch.Arm
{
    public partial class ArmRewriter
    {
        private void RewriteBfi()
        {
            var opDst = this.Operand(Dst);
            var opSrc = this.Operand(Src1);
            var tmp = frame.CreateTemporary(opDst.DataType);
            var lsb = instr.ArchitectureDetail.Operands[2].ImmediateValue.Value;
            var bitsize = instr.ArchitectureDetail.Operands[3].ImmediateValue.Value;
            ConditionalSkip();
            m.Assign(tmp, m.Slice(opSrc, 0, bitsize));
            m.Assign(opDst, m.Dpb(opDst, tmp, lsb));
        }

        private void RewriteBinOp(Func<Expression,Expression,Expression> op, bool setflags)
        {
            var opDst = this.Operand(Dst);
            var opSrc1 = this.Operand(Src1);
            var opSrc2 = this.Operand(Src2);
            ConditionalAssign(opDst, op(opSrc1, opSrc2));
            if (setflags)
            {
                ConditionalAssign(frame.EnsureFlagGroup(A32Registers.cpsr, 0x1111, "SZCO", PrimitiveType.Byte), m.Cond(opDst));
            }
        }

        private void RewriteRevBinOp(Operator op, bool setflags)
        {
            var opDst = this.Operand(Dst);
            var opSrc1 = this.Operand(Src1);
            var opSrc2 = this.Operand(Src2);
            ConditionalAssign(opDst, new BinaryExpression(op, PrimitiveType.Word32, opSrc1, opSrc2));
            if (setflags)
            {
                ConditionalAssign(frame.EnsureFlagGroup(A32Registers.cpsr, 0x1111, "SZCO", PrimitiveType.Byte), m.Cond(opDst));
            }
        }

        private void RewriteUnaryOp(UnaryOperator op)
        {
            var opDst = this.Operand(Dst);
            var opSrc = this.Operand(Src1);
            ConditionalAssign(opDst, new UnaryExpression(op,  PrimitiveType.Word32, opSrc));
            if (instr.ArchitectureDetail.UpdateFlags)
            {
                ConditionalAssign(frame.EnsureFlagGroup(A32Registers.cpsr, 0x1111, "SZCO", PrimitiveType.Byte), m.Cond(opDst));
            }
        }

        private void RewriteBic()
        {
            var opDst = this.Operand(Dst);
            var opSrc1 = this.Operand(Src1);
            var opSrc2 = this.Operand(Src2);
            ConditionalAssign(opDst, m.And(opSrc1, m.Comp(opSrc2)));
        }

        private void RewriteClz()
        {
            var opDst = this.Operand(Dst);
            var opSrc = this.Operand(Src1);

            ConditionalAssign(
                opDst,
                host.PseudoProcedure("__clz", PrimitiveType.Int32, opSrc));
        }

        private void RewriteCmn()
        {
            var opDst = this.Operand(Dst);
            var opSrc = this.Operand(Src1);
            ConditionalAssign(
                frame.EnsureFlagGroup(A32Registers.cpsr, 0x1111, "NZCV", PrimitiveType.Byte),
                m.Cond(
                    m.IAdd(opDst, opSrc)));
        }

        private void RewriteCmp()
        {
            var opDst = this.Operand(Dst);
            var opSrc = this.Operand(Src1);
            ConditionalAssign(
                frame.EnsureFlagGroup(A32Registers.cpsr, 0x1111, "NZCV", PrimitiveType.Byte),
                m.Cond(
                    m.ISub(opDst, opSrc)));
        }

        private void RewriteTeq()
        {
            var opDst = this.Operand(Dst);
            var opSrc = this.Operand(Src1);
            m.Assign(
                frame.EnsureFlagGroup(A32Registers.cpsr, 0x1111, "NZCV", PrimitiveType.Byte),
                m.Cond(m.Xor(opDst, opSrc)));
        }

        private void RewriteTst()
        {
            var opDst = this.Operand(Dst);
            var opSrc = this.Operand(Src1);
            m.Assign(
                frame.EnsureFlagGroup(A32Registers.cpsr, 0x1111, "NZCV", PrimitiveType.Byte),
                m.Cond(m.And(opDst, opSrc)));
        }

        private void RewriteLdr(DataType size)
        {
            var opSrc = this.Operand(Src1);
            var opDst = this.Operand(Dst);
            Identifier dst = (Identifier)opDst;
            var rDst = dst.Storage as RegisterStorage;
            if (rDst == A32Registers.pc)
            {
                // Assignment to PC is the same as a jump
                ric.Class = RtlClass.Transfer;
                m.Goto(opSrc);
                return;
            }
            m.Assign(opDst, opSrc);
            MaybePostOperand(Src1);
        }

        private void RewriteLdrd()
        {
            var ops = instr.ArchitectureDetail.Operands;
            var regLo = A32Registers.RegisterByCapstoneID[ops[0].RegisterValue.Value];
            var regHi = A32Registers.RegisterByCapstoneID[ops[1].RegisterValue.Value];
            var opDst = frame.EnsureSequence(regHi, regLo, PrimitiveType.Word64);
            var opSrc = this.Operand(ops[2]);
            m.Assign(opDst, opSrc);
            MaybePostOperand(ops[2]);
        }

        private void RewriteStr(DataType size)
        {
            var opSrc = this.Operand(Dst);
            var opDst = this.Operand(Src1);
            m.Assign(opDst, opSrc);
            MaybePostOperand(Src1);
        }

        private void RewriteStrd()
        {
            var ops = instr.ArchitectureDetail.Operands;
            var regLo = A32Registers.RegisterByCapstoneID[ops[0].RegisterValue.Value];
            var regHi = A32Registers.RegisterByCapstoneID[ops[1].RegisterValue.Value];
            var opSrc = frame.EnsureSequence(regHi, regLo, PrimitiveType.Word64);
            var opDst = this.Operand(ops[2]);
            m.Assign(opDst, opSrc);
            MaybePostOperand(ops[2]);
        }

        private void RewriteMla()
        {
            var opDst = this.Operand(Dst);
            var opSrc1 = this.Operand(Src1);
            var opSrc2 = this.Operand(Src2);
            var opSrc3 = this.Operand(Src3);
            ConditionalAssign(opDst, m.IAdd(m.IMul(opSrc1, opSrc2), opSrc3));
            if (instr.ArchitectureDetail.UpdateFlags)
            {
                ConditionalAssign(frame.EnsureFlagGroup(A32Registers.cpsr, 0x1111, "SZCO", PrimitiveType.Byte), m.Cond(opDst));
            }
        }

        private void RewriteMov()
        {
            if (Dst.Type == ArmInstructionOperandType.Register && Dst.RegisterValue.Value == ArmRegister.PC)
            {
                ric.Class = RtlClass.Transfer;
                if (Src1.Type == ArmInstructionOperandType.Register && Src1.RegisterValue.Value == ArmRegister.LR)
                {
                    AddConditional(new RtlReturn(0, 0, RtlClass.Transfer));
                }
                else
                {
                    AddConditional(new RtlGoto(Operand(Src1), RtlClass.Transfer));
                }
                return;
            }
            var opDst = Operand(Dst);
            var opSrc = Operand(Src1);
            ConditionalAssign(opDst, opSrc);
        }

        private void RewriteMovt()
        {
            var opDst = Operand(Dst);
            var iSrc = ((Constant)Operand(Src1)).ToUInt32();
            var opSrc = m.Dpb(opDst, Constant.Word16((ushort)iSrc), 16);
            ConditionalAssign(opDst, opSrc);
        }

        private void RewriteLdm()
        {
            var dst = this.Operand(Dst);
            var range = instr.ArchitectureDetail.Operands.Skip(1);
            RewriteLdm(dst, range, instr.ArchitectureDetail.WriteBack);
        }

        private void RewriteLdm(Expression dst, IEnumerable<ArmInstructionOperand> range, bool writeback)
        {
            ConditionalSkip();
            int offset = 0;
            bool pcRestored = false;
            foreach (var r in range)
            {
                Expression ea = offset != 0
                    ? m.IAdd(dst, Constant.Int32(offset))
                    : dst;
                if (r.RegisterValue.Value == ArmRegister.PC)
                {
                    pcRestored = true;
                }
                else
                {
                    var dstReg = frame.EnsureRegister(A32Registers.RegisterByCapstoneID[r.RegisterValue.Value]);
                    m.Assign(dstReg, m.LoadDw(ea));
                }
                offset += 4;
            }
            if (writeback)
            {
                m.Assign(dst, m.IAdd(dst, Constant.Int32(offset)));
            }
            if (pcRestored)
            {
                m.Return(0, 0);
            }
        }

        private void RewriteMull(PrimitiveType dtResult, Func<Expression, Expression, Expression> op)
        {
            var ops = instr.ArchitectureDetail.Operands;
            var regLo = A32Registers.RegisterByCapstoneID[ops[0].RegisterValue.Value];
            var regHi = A32Registers.RegisterByCapstoneID[ops[1].RegisterValue.Value];

            var opDst = frame.EnsureSequence(regHi, regLo, dtResult);
            var opSrc1 = this.Operand(Src3);
            var opSrc2 = this.Operand(Src2);
            ConditionalAssign(opDst, op(opSrc1, opSrc2));
            if (instr.ArchitectureDetail.UpdateFlags)
            {
                ConditionalAssign(frame.EnsureFlagGroup(A32Registers.cpsr, 0x1111, "SZCO", PrimitiveType.Byte), m.Cond(opDst));
            }
        }

        private void RewritePop()
        {
            var sp = frame.EnsureRegister(A32Registers.sp);
            RewriteLdm(sp, instr.ArchitectureDetail.Operands, true);
        }

        private void RewritePush()
        {
            int offset = 0;
            var dst = frame.EnsureRegister(A32Registers.sp);
            foreach (var op in instr.ArchitectureDetail.Operands)
            {
                Expression ea = offset != 0
                    ? m.ISub(dst, offset)
                    : (Expression)dst;
                var reg = frame.EnsureRegister(A32Registers.RegisterByCapstoneID[op.RegisterValue.Value]);
                m.Assign(m.LoadDw(ea), reg);
                offset += reg.DataType.Size;
            }
            m.Assign(dst, m.ISub(dst, offset));
        }

        private void RewriteStm()
        {
            var dst = this.Operand(Dst);
            var range = instr.ArchitectureDetail.Operands.Skip(1);
            int offset = 0;
            foreach (var r in range)
            {
                Expression ea = offset != 0
                    ? m.ISub(dst, offset)
                    : (Expression) dst;
                var srcReg = frame.EnsureRegister(A32Registers.RegisterByCapstoneID[r.RegisterValue.Value]);
                m.Assign(m.LoadDw(ea), srcReg);
                offset += srcReg.DataType.Size;
            }
            if (offset != 0 && instr.ArchitectureDetail.WriteBack)
            {
                m.Assign(dst, m.ISub(dst, offset));
            }
        }

        private void RewriteStmib()
        {
            var dst = this.Operand(Dst);
            var range = instr.ArchitectureDetail.Operands.Skip(1);
            int offset = 4;
            foreach (var r in range)
            {
                Expression ea = m.IAdd(dst, Constant.Int32( offset));
                var srcReg = frame.EnsureRegister(A32Registers.RegisterByCapstoneID[r.RegisterValue.Value]);
                m.Assign(m.LoadDw(ea), srcReg);
                offset += 4;
            }
            if (offset != 4 && instr.ArchitectureDetail.WriteBack)
            {
                m.Assign(dst, m.IAdd(dst, Constant.Int32(offset)));
            }
#if NYI
            var dst = frame.EnsureRegister(((RegisterOperand)Dst).Register);
            var range = (RegisterRangeOperand)Src1;
            int offset = 0;
            foreach (var r in range.GetRegisters())
            {
                var srcReg = frame.EnsureRegister(arch.GetRegister(r));
                offset += srcReg.DataType.Size;
                Expression ea = offset != 0
                    ? emitter.ISub(dst, offset)
                    : (Expression)dst;
                emitter.Assign(emitter.LoadDw(ea), srcReg);
            }
            if (offset != 0 && instr.Update)
            {
                emitter.Assign(dst, emitter.ISub(dst, offset));
            }
#endif
        }

        private void RewriteUbfx()
        {
            var dst = this.Operand(Dst);
            var src = m.Cast(
                PrimitiveType.UInt32,
                m.Slice(
                    this.Operand(Src1),
                    Src2.ImmediateValue.Value,
                    Src3.ImmediateValue.Value));
            ConditionalAssign(dst, src);
        }

        private void RewriteXtb(DataType dt)
        {
            var dst = this.Operand(Dst);
            Expression src = frame.EnsureRegister(A32Registers.RegisterByCapstoneID[Src1.RegisterValue.Value]);
            if (Src1.Shifter.Type == ArmShifterType.ROR)
            {
                src = m.Shr(src, Src1.Shifter.Value);
            }
            src = m.Cast(dt, src);
            ConditionalAssign(dst, src);
        }
    }
}