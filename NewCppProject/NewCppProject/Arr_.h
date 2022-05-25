#pragma once


// 가변배열 : 배열 데이터 주소를 힙 영역에 할당함으로써 런타임 중에도 배열의 길이를 변화할수 있게 만든 배열

typedef struct JoArr // 배열의 자료형 지정
{
	int*	pInt;
	int		count;
	int		maxCount;
}JoArr;

// 가변배열 자료형을 서포트할 함수

// 1. 배열에 힙 영역 데이터 할당
void SetArr(JoArr* pArr);


// 2. 배열에 데이터 삽입
void AddData(JoArr* pArr, int data);




// 4. 힙 영역에 할당된 데이터 해제
void EraseArr(JoArr* pArr);