#include "Arr.h"
#include <iostream>

void InitArr(tArr* _pArr) // tArr�� �ʱ�ȭ�ϴ� �Լ�
{
	_pArr->pInt = (int*)malloc(sizeof(int) * 2);
	_pArr->iCount = 0;
	_pArr->iMaxCount = 2;
}

// ���� �߰� Ȯ�� �Լ�
void Reallocate(tArr* _pArr)
{
	// 1. 2�� �� ū ������ �����Ҵ��Ͽ� �Լ��� ���ú����� �ּҸ� �����صд�
	int* pNew = (int*)malloc(_pArr->iMaxCount * sizeof(int) * 2);

	// 2. ������ �ִ� �����͸� ���ο� ������ �����Ų��.
	for (int i = 0; i < _pArr->iCount; ++i)
	{
		if(pNew)pNew[i] = _pArr->pInt[i];
	}

	// 3. ������ �ִ� �����Ͱ� �ִ� ������ ������Ų��.
	free(_pArr->pInt);

	// 4. �迭�� ���� �Ҵ�� ������ ����Ű�� �Ѵ�.
	_pArr->pInt = pNew;

	// 5. iMaxCount ������ ����
	_pArr->iMaxCount *= 2;

}

void PushBack(tArr* _pArr, int _iData) //tArr�� �����͸� �߰��ϴ� �Լ�
{
	if (_pArr->iMaxCount <= _pArr->iCount) // �� ������ �Ҵ��� ������ �����Ͱ� �� ��
	{
		// ���� ���Ҵ�
		Reallocate(_pArr);
	}

	// ������ �߰�
	_pArr->pInt[_pArr->iCount++] = _iData;
}



void ReleaseArr(tArr* _pArr) // �迭�� �� �޸𸮸� �����ϴ� �Լ�
{
	free(_pArr->pInt);
	_pArr->iCount = 0;
	_pArr->iMaxCount = 0;
}
