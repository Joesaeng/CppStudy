#include <iostream>
#include "Arr_.h"
#include "Carr.h"

class CTest
{
	int a;
	
public:
	CTest()
		: a(10)
	{}
};

int main()
{
	// 구조체 --> 클래스

	// 객체지향 언어 특징
	// 1. 캡슐화
	// 기능을 수행하기 위해 필요한 멤버 선언, 묶음, 은닉성
	// 멤버 함수들

	// 2. 상속

	// 3. 다형성

	// 4. 추상화

	// 구조체 버전 가변배열 --> 클래스 버전 가변배열


	// C++ 동적할당 new, delete
	CTest* pTest = new CTest;
	delete pTest;

	// Carr 예시
	JoArr jArr = {};
	SetArr(&jArr);

	AddData(&jArr,10);
	AddData(&jArr,210);
	AddData(&jArr,130);

	EraseArr(&jArr);

	Carr carr;
	carr.push_back(10);
	carr.push_back(210);
	carr.push_back(130);

	int iData = carr[1];

	carr[1] = 200;

	printf("%d\n", carr[1]);
	printf("%d\n", carr[0]);
	printf("%d\n", carr[2]);

	return 0;
}