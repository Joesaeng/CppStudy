#include "Arr_.h"
#include <iostream>

void SetArr(JoArr* pArr)
{
	pArr->pInt = (int*)malloc(sizeof(int) * 2);
	pArr->count = 0;
	pArr->maxCount = 2;
}

void Relocate(JoArr* pArr)
{
	// 힙 영역에서 원래 있던 배열의 바로 뒷 주소에 데이터를 추가로 할당받을수 없기 때문에 새로이 데이터를 할당해준다.
	int* newP = (int*)malloc(pArr->maxCount * sizeof(int) * 2);
	for (int i = 0; i < pArr->count; ++i)
	{
		newP[i] = pArr->pInt[i];
	}
	free(pArr->pInt);

	pArr->pInt = newP;
	pArr->maxCount *= 2;
}

void AddData(JoArr* pArr, int data)
{
	if (pArr->count >= pArr->maxCount) // 배열의 길이가 모자라는것을 확인
		Relocate(pArr); // 배열 길이 늘림

	pArr->pInt[pArr->count] = data;
	++(pArr->count);
}



void EraseArr(JoArr* pArr)
{
	free(pArr->pInt);
	pArr->count = 0;
	pArr->maxCount = 0;
}


void Sort(JoArr* pArr, void(*SortFunc)(int*, int)) // 함수 포인터를 활용한 정렬 함수
{
	SortFunc(pArr->pInt, pArr->count);
}