#include <stdlib.h>
#include <stdio.h>

void Test(int* a)
{
	*a = 500;
}

int main()
{
	// 포인터 변수
	// 자료형 변수명 // 변수를 선언할 때
	int* pInt = nullptr;

	// 주소를 저장
	// 포인터 변수는 8byte 이다 * 우리의 운영체제가 64bit(8byte)이기 때문 (운영체제가 32bit라면 주소를 저장하는 변수도 4byte가 된다)

	char* pChar = nullptr;
	short* pShort = nullptr;

	int iSize = sizeof(pInt);

	int i = 0;
	pInt = &i; //i의 시작 주소에서부터 i만큼(4byte)의 주소값

	pInt += 1;	// 주소값을 하나 증가시킨다. 예를 들어 시작 위치가 100이라면 101이 되는 것이 아니고 
				// pInt는 int형 포인터 변수이기 때문에 100에서 int값(4byte)만큼 증가한 104가 된다.
				// 그러므로 당연히 char 포인터의 증감은 char값(1byte)씩, short 포인터는 short값(2byte) 씩 증감하게 된다.
				// * 주소의 단계를 증감한다고 생각하면 될 것 같다.
	
	
	// 포인터와 배열
	// 배열의 특징
	// 1. 메모리가 연속적인 구조이다.
	// 2. 배열의 이름은 배열의 시작 주소이다.

	int iArr[10] = {};
	
	//int 단위로 접근
	*(iArr) = 10;		// iArr[0] = 10
	*(iArr + 1) = 10;	// iArr[1] = 10


	// 포인터 이해 확인 문제
	// 문제 1. 
	short sArr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	
	int* pI = (int*)sArr;

	int iData = *((short*)(pI + 2));

	printf("1번 문제 정답 : %d\n", iData);


	// 문제 2.
	char cArr[2] = { 1, 1 };
	
	short* pS = (short*)cArr;

	iData = *pS;

	printf("2번 문제 정답 : %d\n", iData);


	int a = 100;
	
	Test(&a);

	printf("출력 : %d\n", a);

	//scanf_s("%d", &a);


	// const : 문법적으로 상수화로 접근을 막지만, 포인터 등을 사용하여 주소로 강제 접근하여 값을 바꿀수는 있다.
	// *레지스터 최적화(컴파일러에서 자주 쓰이는 변수를 자동으로 레지스터에 배당함으로써 수행 속도를 높이는 최적화 기법)
	// 로 인해 상수로 기억된 값이 넘어오지 않도록 volatile(휘발성, 레지스터 활용 x) 키워드를 사용한다.
	const int cInt = 100;

	// 상수화 : 바뀔수가 없다
	// r-value : 상수
	// l-value : 변수

	pInt = (int*)&cInt;
	*pInt = 300;

	printf("cInt 출력 : %d\n", cInt);


	return 0;
}