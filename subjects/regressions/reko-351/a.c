// a.c
// Generated by decompiling a.out
// using Reko decompiler version 0.8.0.0.

#include "a.h"

// 80000080: void deregister_tm_clones()
void deregister_tm_clones()
{
	if (false && 0x00 != 0x00)
	{
		word32 a7_39;
		word32 a6_40;
		word32 d0_41;
		byte CVZN_42;
		byte CVZNX_43;
		word32 d1_44;
		bool C_45;
		word32 a0_46;
		byte ZN_47;
		bool V_48;
		bool Z_49;
		null();
	}
}

// 800000AE: void register_tm_clones()
void register_tm_clones()
{
	int32 d0_11 = 0x00;
	if (true)
		d0_11 = 0x01;
	int32 d0_15 = d0_11 >> 0x01;
	if (d0_15 != 0x00 && 0x00 != 0x00)
	{
		word32 a7_49;
		word32 a6_50;
		word32 d0_51;
		byte CVZN_52;
		byte CVZNX_53;
		bool N_54;
		bool Z_55;
		word32 a0_56;
		byte ZN_57;
		bool C_58;
		bool V_59;
		null();
	}
}

// 800000E4: void __do_global_dtors_aux()
void __do_global_dtors_aux()
{
	if (globals->b80002724 == 0x00)
	{
		up32 d0_100 = globals->dw80002726;
		<anonymous> * a2_101[] = globals->a80002714;
		if (0x00 - d0_100 > 0x00)
		{
			do
			{
				uint32 d0_102 = d0_100 + 0x01;
				globals->dw80002726 = d0_102;
				<anonymous> * a0_107 = a2_101[d0_102];
				word32 a7_108;
				word32 a6_109;
				byte CVZN_111;
				word32 d2_112;
				byte ZN_113;
				bool C_114;
				bool V_115;
				bool Z_116;
				word32 d0_117;
				byte CVZNX_118;
				byte VZ_119;
				word32 a0_120;
				byte CZ_121;
				a0_107();
				d0_100 = globals->dw80002726;
			} while (0x00 - d0_100 > 0x00);
		}
		deregister_tm_clones();
		if (0x00 != 0x00)
		{
			word32 a7_85;
			word32 a6_86;
			word32 a2_87;
			byte CVZN_88;
			word32 d2_89;
			byte ZN_90;
			bool C_91;
			bool V_92;
			bool Z_93;
			word32 d0_94;
			byte CVZNX_95;
			byte VZ_96;
			word32 a0_97;
			byte CZ_98;
			null();
		}
		globals->b80002724 = 0x01;
	}
}

// 80000158: void call___do_global_dtors_aux()
void call___do_global_dtors_aux()
{
}

// 80000160: void frame_dummy()
void frame_dummy()
{
	if (0x00 != 0x00)
	{
		word32 a7_83;
		word32 a6_84;
		word32 a0_85;
		byte ZN_86;
		bool C_87;
		bool V_88;
		bool Z_89;
		word32 a1_90;
		byte CVZN_91;
		word32 d0_92;
		byte CVZNX_93;
		bool N_94;
		null();
	}
	if (globals->dw8000271C != 0x00 && 0x00 != 0x00)
	{
		word32 a7_64;
		word32 a6_65;
		word32 a0_66;
		byte ZN_67;
		bool C_68;
		bool V_69;
		bool Z_70;
		word32 a1_71;
		byte CVZN_72;
		word32 d0_73;
		byte CVZNX_74;
		bool N_75;
		null();
		register_tm_clones();
	}
	else
		register_tm_clones();
}

// 800001A4: void call_frame_dummy()
void call_frame_dummy()
{
}

// 800001AC: void sine_taylor(Stack real64 rArg04)
void sine_taylor(real64 rArg04)
{
}

// 8000033C: void factorial(Stack int32 dwArg04)
void factorial(int32 dwArg04)
{
	int32 dwLoc08_15 = 0x02;
	while (dwLoc08_15 - dwArg04 <= 0x00)
	{
		++dwLoc08_15;
	}
}

// 80000372: void pow_int(Stack real64 rArg04, Stack int32 dwArg0C)
void pow_int(real64 rArg04, int32 dwArg0C)
{
	int32 dwLoc08_16 = 0x00;
	while (dwLoc08_16 - dwArg0C < 0x00)
	{
		++dwLoc08_16;
	}
}

// 800003BC: void sine_taylor(Stack real64 rArg04, Stack int32 dwArg0C)
void sine_taylor(real64 rArg04, int32 dwArg0C)
{
	word32 dwArg04_5 = (word32) rArg04;
	int32 dwLoc08_24 = 0x03;
	while (dwLoc08_24 - dwArg0C <= 0x00)
	{
		rLoc28 = DPB(rLoc28, dwArg04_5, 0);
		pow_int(rLoc28, dwLoc08_24);
		factorial(dwLoc08_24);
		dwLoc08_24 += 0x04;
	}
	int32 dwLoc08_133 = 0x05;
	while (dwLoc08_133 - dwArg0C <= 0x00)
	{
		rLoc28 = DPB(rLoc28, dwArg04_5, 0);
		pow_int(rLoc28, dwLoc08_133);
		factorial(dwLoc08_133);
		dwLoc08_133 += 0x04;
	}
}

// 8000049A: void main()
void main()
{
	sine_taylor(DPB(rLoc10, 0x40091EB8, 0));
	_sin(DPB(rLoc1C, 0x40091EB8, 0), DPB(rLoc14, 1063818100, 0), fp - 0x08);
}

// 800004DE: void _sin(Stack real64 rArg04, Stack real64 rArg0C, Stack Eq_219 tArg14)
void _sin(real64 rArg04, real64 rArg0C, Eq_219 tArg14)
{
	Eq_230 rLoc0C_23 = DPB(rLoc0C, SLICE(rArg04, word32, 32), 32);
	Eq_234 v9_26 = (real64) ((real80) rLoc0C_23 * rLoc0C_23);
	int32 dwLoc20_100 = 0x01;
	while ((real64) ((real80) rLoc0C_23 / rLoc14) >= rArg0C)
	{
		*tArg14 = (word32) *tArg14 + 0x01;
		int32 v23_65 = dwLoc20_100 + 0x01;
		rLoc0C_23 = (real64) ((real80) (real64) ((real80) rLoc0C_23 * v9_26) * v9_26);
		dwLoc20_100 = v23_65 + 0x03;
		rLoc14 = (real64) ((real80) (real64) ((real80) (real64) ((real80) (real64) ((real80) rLoc14 * (real80) v23_65) * (real80) (v23_65 + 0x01)) * (real80) (v23_65 + 0x02)) * (real80) (v23_65 + 0x03));
	}
}

// 80000624: void __do_global_ctors_aux()
void __do_global_ctors_aux()
{
	<anonymous> * a0_12 = globals->ptr8000270C;
	if (-0x01 - a0_12 != 0x00)
	{
		do
		{
			word32 a7_26;
			word32 a6_27;
			ptr32 a2_28;
			byte CVZN_29;
			word32 a0_30;
			word32 d0_31;
			bool Z_32;
			a0_12();
		} while (-0x01 - *(a2_28 - 0x04) != 0x00);
	}
}

// 8000064E: void call___do_global_ctors_aux()
void call___do_global_ctors_aux()
{
}

