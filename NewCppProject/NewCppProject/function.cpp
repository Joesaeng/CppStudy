#include "funtion.h"
#include "common.h"
#include <stdio.h>


static int g_iStatic = 0;

int Add(int a, int b)
{
	printf("%d", g_iExtern);
	return a + b;
}
int Sub(int a, int b)
{
	return a - b;
}
int Mul(int a, int b)
{
	return a * b;
}