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
	// �� �������� ���� �ִ� �迭�� �ٷ� �� �ּҿ� �����͸� �߰��� �Ҵ������ ���� ������ ������ �����͸� �Ҵ����ش�.
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
	if (pArr->count >= pArr->maxCount) // �迭�� ���̰� ���ڶ�°��� Ȯ��
		Relocate(pArr); // �迭 ���� �ø�

	pArr->pInt[pArr->count] = data;
	++(pArr->count);
}



void EraseArr(JoArr* pArr)
{
	free(pArr->pInt);
	pArr->count = 0;
	pArr->maxCount = 0;
}


void Sort(JoArr* pArr, void(*SortFunc)(int*, int)) // �Լ� �����͸� Ȱ���� ���� �Լ�
{
	SortFunc(pArr->pInt, pArr->count);
}