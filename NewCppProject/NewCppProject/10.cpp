#include <iostream>

#include "Arr.h"
// 변수
// 지역 : 스택
// 전역, 정적, 외부 : 데이터

// 메모리 영역
// 스택
// 데이터
// ROM
// 힙 영역(동적할당)

// 동적할당 : 프로그램 실행 도중에 힙 영역에 메모리 공간을 할당 ** C++언어의 특징이다.
// 1. 런타임 중에 대응 가능
// 2. 사용자가 직접 메모리를 관리해야함(해제)

int main()
{
	int* pInt = (int*)malloc(100); // malloc : 힙 영역에 메모리를 할당해주는 함수
	float* pF = (float*)malloc(4); // 사용자가 원하는 형식으로 변환하여 포인터로 받아온다.

	free(pInt); // pInt 안에 있는 힙 메모리를 해제하는 함수
	free(pF);


	// 가변배열
	int a = 100;

	scanf_s("%d", &a);

	// 배열 개수를 선언할 때에는 변수를 사용 할 수 없다.
	// int arr[a] = {};


	// 객체(Instance)
	// int
	// int a 일때 a가 객체이다.

	tArr arr;

	tArr arr2;

	tArr arr3;
	

	return 0;
}