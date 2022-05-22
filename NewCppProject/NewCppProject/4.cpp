#include <stdio.h>
#include "funtion.h"
#include "common.h"


// 변수의 종류
// 1. 지역변수
// 2. 전역변수
// 3. 정적변수(static)
// 4. 외부변수(extern)

// 메모리 영역
// 1. 스택 영역 // 지역변수
// 2. 데이터 영역 // 전역, 정적, 외부 변수는 데이터 영역
// 3. 읽기 전용(코드, ROM)
// 4. 힙 영역



 // 전역변수
int g_i = 0; // Data 영역 

// Data 영역 특징
// 프로그램 시작과 동시에 생성
// 프로그램 종료와 함께 해제


// 정적변수 : 선언된 지역에서만 활동한다 
// 최초 선언할 때만 초기화한다.
// 데이터 영역에 존재하지만 선언된 지역 이외의 다른 지역에선 접근할 수 없다
static int g_iStatic = 0;

int Test()
{
	static int i = 0;
	++i;

	return i;
}

// 외부변수 : 헤더 파일에 존재하기만 하는 변수를 어느 파일이던 선언을 해주면 프로젝트 내 어느 파일에서건 사용이 가능하다.
int g_iExtern = 0;





int main()
{
	// 지역변수
	g_iExtern = 100;
	int data = Add(10, 10);
	data = Sub(10, 5);
	data = Mul(10, 10);

	Test();
	Test();
	Test();
	Test();
	Test();
	int iCall = Test();
	printf("Test 함수 호출 횟수 : %d\n", iCall);


	

	// 포인터 변수
	// 주소를 저장하는 변수
	// 자료형 + * 변수명
	// 해당 포인터가 가리키는 주소를 해석하는 자료형

	int i = 100;
	float f = 3.f;
	int* pInt = &i; // i의 주소를 pInt에 저장
	pInt = (int*)&f;


	// 주소로 접근
	i = *pInt;


	// 주소의 단위는 바이트 단위이며 정수단위이다
	// BYTE 



	return 0;
}