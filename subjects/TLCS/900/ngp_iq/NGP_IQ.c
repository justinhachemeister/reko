// NGP_IQ.c
// Generated by decompiling NGP_IQ.NGP
// using Reko decompiler version 0.6.2.0.

#include "NGP_IQ.h"

// 00200089: void fn00200089(Register word16 de, Register word32 xsp)
void fn00200089(word16 de, word32 xsp)
{
	fn0020060C();
	*(ui32 *) 0x6F86 = *(ui32 *) 0x6F86 | 0x40;
	word32 xsp_3 = DPB(xsp, fp, 0);
	word32 * xiy_14 = (word32 *) 28600;
	byte b_15 = 0x12;
	do
	{
		*xiy_14 = globals->dw200040;
		xiy_14 = xiy_14 + 0x01;
		b_15 = b_15 - 0x01;
	} while (b_15 != 0x00);
	*(byte *) 0x8002 = 0x00;
	*(byte *) 0x8003 = 0x00;
	*(byte *) 0x8004 = 0xA0;
	*(byte *) 0x8005 = 0x98;
	word16 * xhl_38 = (word16 *) 0xA000;
	word16 bc_40 = 0x0200;
	do
	{
		*xhl_38 = 0x00;
		xhl_38 = xhl_38 + 0x01;
		bc_40 = bc_40 - 0x01;
	} while (bc_40 != 0x00);
	word16 bc_55 = 0x0250;
	word16 * xde_59 = (word16 *) 0xA400;
	word16 * xhl_62 = globals->a20061D;
	do
	{
		*xde_59 = *xhl_62;
		xhl_62 = xhl_62 + 0x01;
		xde_59 = xde_59 + 0x01;
		bc_55 = bc_55 - 0x01;
	} while (bc_55 != 0x00);
	fn002005B8();
	__ei(0x00);
	word16 bc_102 = 0x10;
	word16 * xde_86 = (word16 *) 0x8300;
	word16 * xhl_89 = globals->a200ABD;
	do
	{
		*xde_86 = *xhl_89;
		xhl_89 = xhl_89 + 0x01;
		xde_86 = xde_86 + 0x01;
		bc_102 = bc_102 - 0x01;
	} while (bc_102 != 0x00);
	*(byte *) 0x83E0 = 0x33;
	*(byte *) 33761 = 0x07;
	*(byte *) 0x8118 = 0x80;
	word32 xbc_123;
	word32 xde_124;
	word32 xsp_125;
	word16 wa_127 = (word16) fn00200557(0x00, DPB(bc_102, 0x00, 8), DPB(xde_86, 0x04, 8), &globals->b2000FD, xsp_3, out xbc_123, out xde_124, out xsp_125);
	word32 xbc_138;
	word32 xde_139;
	word32 xsp_140;
	word16 wa_142 = (word16) fn00200557(wa_127, DPB(bc_102, 0x01, 8), DPB(xde_124, 0x04, 8), &globals->b200122, xsp_125, out xbc_138, out xde_139, out xsp_140);
	word32 xbc_153;
	word32 xde_154;
	word32 xsp_155;
	word16 wa_157 = (word16) fn00200557(wa_142, DPB(bc_102, 0x04, 8), DPB(xde_139, 0x04, 8), &globals->b200147, xsp_140, out xbc_153, out xde_154, out xsp_155);
	word32 xbc_168;
	word32 xde_169;
	word32 xsp_170;
	word16 wa_172 = (word16) fn00200557(wa_157, DPB(bc_102, 0x05, 8), DPB(xde_154, 0x02, 8), &globals->b200165, xsp_155, out xbc_168, out xde_169, out xsp_170);
	word32 xbc_182;
	word32 xde_183;
	ptr32 xsp_184;
	word32 xwa_185 = fn00200557(wa_172, DPB(bc_102, 0x06, 8), DPB(xde_169, 0x02, 8), &globals->b20017F, xsp_170, out xbc_182, out xde_183, out xsp_184);
	byte * xde_189 = (byte *) 0x7000;
	byte * xhl_192 = &globals->b200363;
	word16 bc_194 = 303;
	word32 xbc_197 = DPB(xbc_182, 303, 0);
	do
	{
		*xde_189 = *xhl_192;
		bc_194 = bc_194 - 0x01;
		xhl_192 = xhl_192 + 0x01;
		xde_189 = xde_189 + 0x01;
		xbc_197 = DPB(xbc_197, bc_194, 0);
	} while (bc_194 != 0x00);
	word32 xsp_218 = fn002004F2(DPB(xwa_185, 0x01, 8), xsp_184);
	word32 xwa_220 = 0x7000;
	if (true)
	{
		word16 sp_677;
		word32 xix_678;
		word32 xiy_679;
		byte b_680;
		word16 wa_682;
		bool H_686;
		bool V_687;
		bool N_688;
		byte d_689;
		byte c_690;
		byte w_691;
		word16 hl_692;
		byte a_693;
		byte SZHVC_694;
		bool Z_695;
		word16 de_696;
		((<anonymous> **) 0x7000)();
	}
	word32 xsp_278;
	word32 xde_277;
	word16 bc_275;
	word16 wa_268;
	word32 xbc_245;
	byte * xde_246;
	word32 xhl_247;
	word32 xsp_248;
	word32 xwa_254 = DPB(fn00200532(DPB(xwa_220, 0x04, 8), xbc_197, xde_189, DPB(xhl_192, 3334, 0), xsp_218, out xbc_245, out xde_246, out xhl_247, out xsp_248), 0x04, 8);
	word32 xbc_255;
	word32 xde_256;
	word32 xhl_257;
	word32 xsp_258;
	word16 wa_260 = (word16) fn00200532(xwa_254, xbc_245, xde_246, DPB(xhl_247, 3333, 0), xsp_248, out xbc_255, out xde_256, out xhl_257, out xsp_258);
	if (*(byte *) 0x4003 == 0x04)
	{
		bc_275 = DPB(bc_194, 0x04, 8);
		word32 xbc_652;
		wa_268 = (word16) fn00200557(wa_260, bc_275, DPB(xde_256, 0x01, 8), &globals->b2001D2, xsp_258, out xbc_652, out xde_277, out xsp_278);
	}
	else
	{
		bc_275 = DPB(bc_194, 0x04, 8);
		word32 xbc_667;
		wa_268 = (word16) fn00200557(wa_260, bc_275, DPB(xde_256, 0x03, 8), &globals->b2001E8, xsp_258, out xbc_667, out xde_277, out xsp_278);
	}
	word32 xbc_288;
	word32 xde_289;
	word32 xsp_290;
	word16 wa_292 = (word16) fn00200557(wa_268, DPB(bc_275, 0x08, 8), DPB(xde_277, 0x04, 8), &globals->b2001FD, xsp_278, out xbc_288, out xde_289, out xsp_290);
	word32 xbc_303;
	word32 xde_304;
	word32 xsp_305;
	word16 wa_307 = (word16) fn00200557(wa_292, DPB(bc_275, 0x09, 8), DPB(xde_289, 0x02, 8), &globals->b200217, xsp_290, out xbc_303, out xde_304, out xsp_305);
	word32 xbc_317;
	word32 xde_318;
	ptr32 xsp_319;
	word32 xwa_320 = fn00200557(wa_307, DPB(bc_275, 0x0A, 8), DPB(xde_304, 0x02, 8), &globals->b200231, xsp_305, out xbc_317, out xde_318, out xsp_319);
	byte * xde_324 = (byte *) 0x7000;
	byte * xhl_327 = &globals->b200492;
	word16 bc_329 = 0x23;
	word32 xbc_332 = DPB(xbc_317, 0x23, 0);
	do
	{
		*xde_324 = *xhl_327;
		bc_329 = bc_329 - 0x01;
		xhl_327 = xhl_327 + 0x01;
		xde_324 = xde_324 + 0x01;
		xbc_332 = DPB(xbc_332, bc_329, 0);
	} while (bc_329 != 0x00);
	word32 xsp_353 = fn002004F2(DPB(xwa_320, 0x01, 8), xsp_319);
	word32 xwa_355 = 0x7000;
	if (true)
	{
		word16 sp_622;
		word32 xix_623;
		word32 xiy_624;
		byte b_625;
		word16 wa_627;
		bool H_631;
		bool V_632;
		bool N_633;
		byte d_634;
		byte c_635;
		byte w_636;
		word16 hl_637;
		byte a_638;
		byte SZHVC_639;
		bool Z_640;
		word16 de_641;
		((<anonymous> **) 0x7000)();
	}
	word32 xsp_413;
	word32 xde_412;
	word16 bc_410;
	word16 wa_403;
	word32 xbc_380;
	byte * xde_381;
	word32 xhl_382;
	word32 xsp_383;
	word32 xwa_389 = DPB(fn00200532(DPB(xwa_355, 0x04, 8), xbc_332, xde_324, DPB(xhl_327, 3338, 0), xsp_353, out xbc_380, out xde_381, out xhl_382, out xsp_383), 0x04, 8);
	word32 xbc_390;
	word32 xde_391;
	word32 xhl_392;
	word32 xsp_393;
	word16 wa_395 = (word16) fn00200532(xwa_389, xbc_380, xde_381, DPB(xhl_382, 3337, 0), xsp_383, out xbc_390, out xde_391, out xhl_392, out xsp_393);
	if (*(byte *) 0x4003 == 0x01)
	{
		bc_410 = DPB(bc_329, 0x08, 8);
		word32 xbc_599;
		wa_403 = (word16) fn00200557(wa_395, bc_410, DPB(xde_391, 0x01, 8), &globals->b200284, xsp_393, out xbc_599, out xde_412, out xsp_413);
	}
	else
	{
		bc_410 = DPB(bc_329, 0x08, 8);
		word32 xbc_614;
		wa_403 = (word16) fn00200557(wa_395, bc_410, DPB(xde_391, 0x03, 8), &globals->b20029A, xsp_393, out xbc_614, out xde_412, out xsp_413);
	}
	word32 xbc_423;
	word32 xde_424;
	word32 xsp_425;
	word16 wa_427 = (word16) fn00200557(wa_403, DPB(bc_410, 0x0C, 8), DPB(xde_412, 0x04, 8), &globals->b2002AF, xsp_413, out xbc_423, out xde_424, out xsp_425);
	word32 xbc_438;
	word32 xde_439;
	word32 xsp_440;
	word16 wa_442 = (word16) fn00200557(wa_427, DPB(bc_410, 0x0D, 8), DPB(xde_424, 0x02, 8), &globals->b2002CB, xsp_425, out xbc_438, out xde_439, out xsp_440);
	word32 xbc_452;
	word32 xde_453;
	ptr32 xsp_454;
	word32 xwa_455 = fn00200557(wa_442, DPB(bc_410, 0x0E, 8), DPB(xde_439, 0x02, 8), &globals->b2002E5, xsp_440, out xbc_452, out xde_453, out xsp_454);
	byte * xde_459 = (byte *) 0x7000;
	byte * xhl_462 = &globals->b2004B5;
	word16 bc_464 = 0x2B;
	word32 xbc_467 = DPB(xbc_452, 0x2B, 0);
	do
	{
		*xde_459 = *xhl_462;
		bc_464 = bc_464 - 0x01;
		xhl_462 = xhl_462 + 0x01;
		xde_459 = xde_459 + 0x01;
		xbc_467 = DPB(xbc_467, bc_464, 0);
	} while (bc_464 != 0x00);
	word32 xsp_488 = fn002004F2(DPB(xwa_455, 0x01, 8), xsp_454);
	word32 xwa_490 = 0x7000;
	if (true)
	{
		word16 sp_569;
		word32 xix_570;
		word32 xiy_571;
		byte b_572;
		word16 wa_574;
		bool H_578;
		bool V_579;
		bool N_580;
		byte d_581;
		byte c_582;
		byte w_583;
		word16 hl_584;
		byte a_585;
		byte SZHVC_586;
		bool Z_587;
		word16 de_588;
		((<anonymous> **) 0x7000)();
	}
	word32 xbc_515;
	byte * xde_516;
	word32 xhl_517;
	word32 xsp_518;
	word32 xwa_524 = DPB(fn00200532(DPB(xwa_490, 0x04, 8), xbc_467, xde_459, DPB(xhl_462, 0x0D0E, 0), xsp_488, out xbc_515, out xde_516, out xhl_517, out xsp_518), 0x04, 8);
	word32 xbc_525;
	word32 xde_526;
	word32 xhl_527;
	word32 xsp_528;
	word16 wa_530 = (word16) fn00200532(xwa_524, xbc_515, xde_516, DPB(xhl_517, 0x0D0D, 0), xsp_518, out xbc_525, out xde_526, out xhl_527, out xsp_528);
	if (*(byte *) 0x4003 == 0x00)
	{
		word32 xbc_553;
		word32 xde_554;
		word32 xsp_555;
		fn00200557(wa_530, DPB(bc_464, 0x0C, 8), DPB(xde_526, 0x01, 8), &globals->b200338, xsp_528, out xbc_553, out xde_554, out xsp_555);
	}
	else
	{
		word32 xbc_564;
		word32 xde_565;
		word32 xsp_566;
		fn00200557(wa_530, DPB(bc_464, 0x0C, 8), DPB(xde_526, 0x03, 8), &globals->b20034E, xsp_528, out xbc_564, out xde_565, out xsp_566);
	}
	while (true)
		;
}

// 002004F2: Register ptr32 fn002004F2(Register word32 xwa, Register ptr32 xsp)
ptr32 fn002004F2(word32 xwa, ptr32 xsp)
{
	ptr32 xsp_3 = DPB(xsp, fp, 0);
	*(xsp_3 - 0x04) = xwa;
	*(byte *) 0x4004 = 0x00;
	do
		;
	while (*(byte *) 0x4004 != w);
	return xsp_3;
}

// 0020050A: Register word32 fn0020050A(Register byte w, Register byte a, Register word32 xbc, Register (ptr byte) xde, Register (ptr byte) xhl, Register ptr32 xsp, Register out ptr32 xdeOut, Register out ptr32 xhlOut, Register out ptr32 xspOut)
word32 fn0020050A(byte w, byte a, word32 xbc, byte * xde, byte * xhl, ptr32 xsp, ptr32 & xdeOut, ptr32 & xhlOut, ptr32 & xspOut)
{
	ptr32 xsp_3 = DPB(xsp, fp, 0);
	*(xsp_3 - 0x04) = (byte **) xhl;
	*(xsp_3 - 0x08) = (byte **) xde;
	*(xsp_3 - 0x0C) = xbc;
	struct Eq_705 * xde_29 = DPB(0x9800, (word16) (DPB(bc, 0x00, 8) * 0x02) + 0x9800 + (word16) (DPB(hl, 0x00, 8) * 0x40), 0);
	xde_29->b0000 = a;
	xde_29->b0001 = w;
	word32 xde_44;
	*xdeOut = *(xsp_3 - 0x08);
	word32 xhl_47;
	*xhlOut = *(xsp_3 - 0x04);
	word32 xsp_50;
	*xspOut = xsp_3;
	return *(xsp_3 - 0x0C);
}

// 00200532: Register word32 fn00200532(Register word32 xwa, Register word32 xbc, Register (ptr byte) xde, Register (ptr byte) xhl, Register word32 xsp, Register out ptr32 xbcOut, Register out ptr32 xdeOut, Register out ptr32 xhlOut, Register out ptr32 xspOut)
word32 fn00200532(word32 xwa, word32 xbc, byte * xde, byte * xhl, word32 xsp, ptr32 & xbcOut, ptr32 & xdeOut, ptr32 & xhlOut, ptr32 & xspOut)
{
	ptr32 xsp_3 = DPB(xsp, fp, 0);
	*(xsp_3 - 0x04) = (byte **) xhl;
	*(xsp_3 - 0x08) = xbc;
	*(xsp_3 - 0x0C) = xwa;
	byte * xde_23;
	word32 xhl_24;
	ptr32 xsp_25;
	word32 xbc_26 = fn0020050A(w, ((a & 0xF0) >> 0x04) + 0x40, DPB(xbc, a, 0), xde, xhl, xsp_3 - 0x0C, out xde_23, out xhl_24, out xsp_25);
	word32 xde_36;
	word32 xhl_37;
	struct Eq_789 * xsp_38;
	fn0020050A(w, ((byte) xbc_26 & 0x0F) + 0x40, xbc_26, xde_23, DPB(xhl_24, h + 0x01, 8), xsp_25, out xde_36, out xhl_37, out xsp_38);
	word32 xbc_44;
	*xbcOut = xsp_38->dw0004;
	word32 xhl_47;
	*xhlOut = xsp_38->dw0008;
	word32 xsp_49;
	*xspOut = &xsp_38->dw0008 + 0x01;
	return xsp_38->dw0000;
}

// 00200557: Register word32 fn00200557(Register word16 wa, Register word16 bc, Register (ptr word16) xde, Register (ptr byte) xhl, Register word32 xsp, Register out ptr32 xbcOut, Register out ptr32 xdeOut, Register out ptr32 xspOut)
word32 fn00200557(word16 wa, word16 bc, word16 * xde, byte * xhl, word32 xsp, ptr32 & xbcOut, ptr32 & xdeOut, ptr32 & xspOut)
{
	word32 * xsp_3 = DPB(xsp, fp, 0);
	*(xsp_3 - 0x04) = (byte **) xhl;
	*(xsp_3 - 0x08) = (word16 **) xde;
	*(ui8 *) 0x4002 = d << 0x01;
	word32 xwa_110 = (word32) (c * 0x02);
	uint16 bc_29 = DPB(bc, 0x00, 8);
	word16 wa_23 = DPB(wa, c * 0x02, 0);
	byte * xde_102 = (word16) (bc_29 * 0x40) + (xwa_110 + 0x9800);
	byte b_106 = 0x13;
	word32 xbc_107;
	*xbcOut = DPB(bc_29 * 0x40, 0x13, 8);
l00200579:
	cu8 v18_50 = *xhl;
	xwa_110 = DPB(xwa_110, v18_50, 0);
	word16 wa_111 = DPB(wa_23, v18_50, 0);
	if (v18_50 != 0x00)
	{
		xhl = xhl + 0x01;
		if (v18_50 >= 0x5B)
		{
			xwa_110 = DPB(xwa_110, v18_50 + 0xE0, 0);
			wa_111 = DPB(wa_23, v18_50 + 0xE0, 0);
		}
		word16 wa_88 = DPB(wa_111, 0x00, 8);
		byte w_93 = SLICE(wa_88 + 0x09, byte, 8) + *((byte *) 0x4002);
		*xde_102 = (byte) (wa_88 + 0x09);
		byte * xde_99 = xde_102 + 0x01;
		*xde_99 = w_93;
		b_106 = b_106 - 0x01;
		xwa_110 = DPB(xwa_110, w_93, 8);
		wa_23 = DPB(wa_88 + 0x09, w_93, 8);
		xde_102 = xde_99 + 0x01;
		*xbcOut = DPB(xbc_107, b_106, 8);
		if (b_106 != 0x00)
			goto l00200579;
	}
	return xwa_110;
	word32 xde_72;
	*xdeOut = *xsp_3;
	word32 xsp_76;
	*xspOut = xsp_3 + 0x02;
	return xwa_110;
}

// 002005B8: void fn002005B8()
void fn002005B8()
{
	byte * xbc_2 = (byte *) 0x9000;
	word16 hl_3 = 0x04C0;
	do
	{
		*xbc_2 = 0x00;
		xbc_2 = xbc_2 + 0x01;
		hl_3 = hl_3 - 0x01;
	} while (hl_3 != 0x00);
	byte * xbc_13 = (byte *) 0x9800;
	word16 hl_14 = 0x04C0;
	do
	{
		*xbc_13 = 0x00;
		xbc_13 = xbc_13 + 0x01;
		hl_14 = hl_14 - 0x01;
	} while (hl_14 != 0x00);
	return;
}

// 0020060C: void fn0020060C()
void fn0020060C()
{
	if (*(byte *) 0x6F91 == 0x00)
	{
		*(ui32 *) 0x6F83 = *(ui32 *) 0x6F83 & ~0x08;
		*(byte *) 0x6DA0 = 0x00;
	}
	return;
}
