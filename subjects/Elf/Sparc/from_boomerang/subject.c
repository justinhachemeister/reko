// subject.c
// Generated by decompiling subject.exe
// using Reko decompiler version 0.8.0.0.

#include "subject.h"

// 00010958: void _start(Register (ptr32 Eq_2) g1, Register (ptr32 Eq_3) o7, Register ui32 fsr, Stack int32 dwArg40)
void _start( * g1, Eq_3 * o7, ui32 fsr, int32 dwArg40)
{
	globals->ptr20E60 = fp + 0x44;
	globals->ptr20E3C = fp + 0x44 + ((dwArg40 << 0x02) + 0x04);
	if (0x00 != 0x00)
	{
		globals->dw20E58 = fsr;
		globals->dw20E58 &= 0x303FFFFF;
		if (false)
			globals->dw20E5C = 0x01;
	}
	if (g1 == null)
	{
		atexit(&globals->t10CB8);
		_init(o7);
		exit(main(dwArg40));
	}
	else
		atexit(g1);
}

// 00010A5C: void func1()
void func1()
{
}

// 00010A74: void func2()
void func2()
{
}

// 00010A8C: void func3()
void func3()
{
}

// 00010AA4: void func4()
void func4()
{
}

// 00010ABC: void func5()
void func5()
{
}

// 00010AD4: void func6()
void func6()
{
}

// 00010AEC: void func7()
void func7()
{
}

// 00010B04: void func8()
void func8()
{
}

// 00010B0C: Register int32 main(Register int32 o0)
int32 main(int32 o0)
{
	word32 o0_159 = 0x01;
	if (o0 <= 0x01)
		o0_159 = 0x00;
	word32 o0_155;
	if (o0_159 != 0x00)
		o0_155 = 68188;
	else
		o0_155 = 68212;
	word32 o3_150;
	if (o0_159 != 0x00)
		o3_150 = 68236;
	else
		o3_150 = 0x00010AA4;
	word32 o2_145;
	if (o0_159 != 0x00)
		o2_145 = 68284;
	else
		o2_145 = 68308;
	word32 o1_140;
	if (o0_159 != 0x00)
		o1_140 = 68332;
	else
		o1_140 = 0x00010B04;
	word32 i1_105;
	Eq_81 Z_38;
	if (o0_159 != 0x00)
	{
		if (o0_155 != 68188 || (o3_150 != 68236 || (o2_145 != 68284 || o1_140 != 68332)))
		{
			i1_105 = 0x00;
			Z_38 = cond(0x00);
			goto l00010C44;
		}
		i1_105 = 0x01;
	}
	else if (o0_155 == 68212 && (o3_150 == 0x00010AA4 && (o2_145 == 68308 && o1_140 == 0x00010B04)))
		i1_105 = 0x01;
	else
		i1_105 = 0x00;
	Z_38 = cond(i1_105);
l00010C44:
	if (!Z_38)
		printf("Pass\n");
	else
		printf("Failed!\n");
	int32 i0_42 = 0x00;
	if (i1_105 == 0x00)
		i0_42 = 0x01;
	return i0_42;
}

// 00010C80: void _init(Register (ptr32 Eq_3) o7)
void _init(Eq_3 * o7)
{
	fn00010C90(o7);
}

// 00010C90: void fn00010C90(Register (ptr32 Eq_3) o7)
void fn00010C90(Eq_3 * o7)
{
	struct Eq_125 * o0_5 = o7 + o7->dw0008 / 0x0C;
	word32 l0_6 = o0_5->dwFFFFFFF8;
	if (l0_6 == 0x00)
		return;
	word32 sp_11;
	word32 o0_12;
	word32 o7_13;
	word32 l0_14;
	word32 g0_15;
	byte NZVC_16;
	byte Z_17;
	word32 i7_18;
	word32 i0_19;
	word32 o1_20;
	word32 i1_21;
	word32 o2_22;
	word32 i2_23;
	word32 o3_24;
	word32 i3_25;
	word32 o4_26;
	word32 i4_27;
	word32 o5_28;
	word32 i5_29;
	word32 i6_30;
	fn81C7E008();
}

// 00010CB8: void _fini(Register (ptr32 Eq_158) o7)
void _fini(Eq_158 * o7)
{
	fn00010CC8(o7);
}

// 00010CC8: void fn00010CC8(Register (ptr32 Eq_158) o7)
void fn00010CC8(Eq_158 * o7)
{
	struct Eq_163 * o0_5 = o7 + o7->dw0008 / 0x0C;
	<anonymous> * l0_6 = o0_5->ptrFFFFFFFC;
	if (l0_6 == null)
		return;
	word32 sp_11;
	word32 o0_12;
	word32 o7_13;
	word32 l0_14;
	word32 g0_15;
	byte NZVC_16;
	byte Z_17;
	word32 i7_18;
	word32 i0_19;
	word32 o1_20;
	word32 i1_21;
	word32 o2_22;
	word32 i2_23;
	word32 o3_24;
	word32 i3_25;
	word32 o4_26;
	word32 i4_27;
	word32 o5_28;
	word32 i5_29;
	word32 i6_30;
	l0_6();
}

// 00020D40: void atexit()
void atexit()
{
}

// 00020D4C: void exit()
void exit()
{
}

// 00020D58: void _exit()
void _exit()
{
}

// 00020D64: void printf()
void printf()
{
}

