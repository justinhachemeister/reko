// IncorrectUserSignature.c
// Generated by decompiling VCExeSample.exe
// using Reko decompiler version 0.8.0.0.

#include "IncorrectUserSignature.h"

// 00401120: void test6(Stack (ptr Eq_2) c, Stack int32 a, Stack int32 b)
void test6(cdecl_class * c, int32 a, int32 b)
{
	// Incorrect user-defined signature
	// "void sum(int, int)" is set instead of "int sum(int, int)"
	// Reko should emit code which gives chance for user to find this mistake
	c->vtbl->sum(c, a, b);
	word32 eax_37 = <invalid>;
	c->vtbl->method04(c, eax_37);
}

