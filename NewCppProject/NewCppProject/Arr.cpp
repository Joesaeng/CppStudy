#include "Arr.h"
#include <iostream>

void InitArr(tArr* _pArr) // tArr을 초기화하는 함수
{
	_pArr->pInt = (int*)malloc(sizeof(int) * 2);
	_pArr->iCount = 0;
	_pArr->iMaxCount = 2;
}

// 공간 추가 확장 함수
void Reallocate(tArr* _pArr)
{
	// 1. 2배 더 큰 공간을 동적할당하여 함수의 로컬변수에 주소를 저장해둔다
	int* pNew = (int*)malloc(_pArr->iMaxCount * sizeof(int) * 2);

	// 2. 기존에 있던 데이터를 새로운 공간에 복사시킨다.
	for (int i = 0; i < _pArr->iCount; ++i)
	{
		if(pNew)pNew[i] = _pArr->pInt[i];
	}

	// 3. 기존에 있던 데이터가 있던 공간을 해제시킨다.
	free(_pArr->pInt);

	// 4. 배열이 새로 할당된 공간을 가리키게 한다.
	_pArr->pInt = pNew;

	// 5. iMaxCount 변경점 적용
	_pArr->iMaxCount *= 2;

}

void PushBack(tArr* _pArr, int _iData) //tArr에 데이터를 추가하는 함수
{
	if (_pArr->iMaxCount <= _pArr->iCount) // 힙 영역에 할당한 공간에 데이터가 꽉 참
	{
		// 공간 재할당
		Reallocate(_pArr);
	}

	// 데이터 추가
	_pArr->pInt[_pArr->iCount++] = _iData;
}



void ReleaseArr(tArr* _pArr) // 배열의 힙 메모리를 해제하는 함수
{
	free(_pArr->pInt);
	_pArr->iCount = 0;
	_pArr->iMaxCount = 0;
}
