#include <stdio.h>

// �Լ� �⺻���� // ���ȭ�� ����ȭ����!
// Factorial
int Factorial(int _iNum)
{
	int value = 1;

	for (int j = 0; j < _iNum - 1; ++j)
	{
		value *= (j + 2);
	}
	return value;
}

int main()
{
	int i = 4;

	int iValue = 1;
	
	for (int j = 0; j < i - 1; ++j)
	{
		iValue *= (j + 2);
	}

	iValue = Factorial(4);
	printf("%d", iValue);

	return 0;
}