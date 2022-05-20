#include <stdio.h>

// �Լ��� ����ϴ� �޸𸮴� ���� �޸� *����: ���� ����, ť: ���� ����
// �Լ� �⺻���� // ���ȭ�� ����ȭ����!
// Factorial
int Factorial(int i)
{
	int value = 1;

	for (int j = 0; j < i - 1; ++j)
	{
		value *= (j + 2);
	}
	return value;
}

// ����Լ� : �Լ� �ȿ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ�
// ������, ������ ����
// ����, �ӵ��� ������

// ����Լ� ���丮��
int Factorial_Re(int i) // * Re : Recusion : ���
{
	if (i == 1)
	{
		return 1;
	}
	return i* Factorial_Re(i - 1);
}

// �Ǻ���ġ ����
// 1 1 2 3 5 8 13 21 34 55 .....
int Fibonacci(int i)
{
	if (i == 1 || i == 2)
		return 1;
	int iPrev1 = 1;
	int iPrev2 = 1;
	int iValue = 0;
	for (int j = 0; j < i - 2; ++j)
	{
		iValue = iPrev1 + iPrev2;
		iPrev1 = iPrev2;
		iPrev2 = iValue;
	}
	return iValue;
}

// �������(Tail Recusion) ��°͵� �ִ�.
// ��� �Ǻ���ġ ����
int Fibonacci_Re(int i)
{
	if (i == 1 || i == 2)
		return 1;

	return Fibonacci_Re(i - 1) + Fibonacci_Re(i - 2);
}




int main()
{
	int iValue = Factorial(10);
	iValue = Factorial_Re(10);

	iValue = Fibonacci(7);
	iValue = Fibonacci_Re(7);

	// �迭
	// �޸𸮰� ������
	int iArray[10] = {}; // iArray[0],iArray[1].....iArray[9] * index�� �����ϴµ� �ε��� ���� �Ѿ�� ������ �� ���� ���ϴ� ���װ� ���� �� �ִ�.

	iArray[0] = 1;

	// ����ü



	

	return 0;
}