// VCExeSample.c
// Generated by decompiling C:\MyPrograms\git_repos\reko_ptomin\subjects\PE-x86\VCExeSample\VCExeSample.exe
// using Decompiler version 0.6.0.0.

#include "VCExeSample.h"

int32 main(int32 argc, char * * argv)
{
	test1(*argv, argc, "test123", 1.0F);
	return 0x00;
}

void test1(char * arg1, int32 arg2, char * arg3, real32 arg4)
{
	printf("%s %d %s %f");
	return;
}

void test2(word32 dwArg04)
{
	test1("1", 0x02, "3", (real32) globals->r4020E8);
	if (dwArg04 == 0x00)
	{
		real32 dwLoc08_30 = (real32) globals->r4020E4;
		*(fp - 0x0C) = 0x004020DC;
		*(fp - 0x10) = 0x06;
		*(fp - 0x14) = 0x004020E0;
		test1("1", 0x02, "3", dwLoc08_30);
	}
	return;
}

