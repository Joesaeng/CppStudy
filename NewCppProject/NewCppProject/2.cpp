#include <stdio.h>

// 함수가 사용하는 메모리는 스택 메모리 *스택: 선입 후출, 큐: 선입 선출
// 함수 기본개념 // 모듈화를 습관화하자!
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

// 재귀함수 : 함수 안에서 자기 자신을 호출하는 함수
// 가독성, 구현의 용이
// 단점, 속도가 느리다

// 재귀함수 팩토리얼
int Factorial_Re(int i) // * Re : Recusion : 재귀
{
	if (i == 1)
	{
		return 1;
	}
	return i* Factorial_Re(i - 1);
}

// 피보나치 수열
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

// 꼬리재귀(Tail Recusion) 라는것도 있다.
// 재귀 피보나치 수열
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

	// 배열
	// 메모리가 연속적
	int iArray[10] = {}; // iArray[0],iArray[1].....iArray[9] * index로 접근하는데 인덱스 값을 넘어서서 접근할 시 잡지 못하는 버그가 나올 수 있다.

	iArray[0] = 1;

	// 구조체



	

	return 0;
}