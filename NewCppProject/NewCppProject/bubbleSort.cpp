#include "bubbleSort.h"
#include <iostream>

void BubbleSort(JoArr* pArr)
{
	// �������� �˰��� : �迭�� �ȿ� �ִ� ���ӵ� �����͸� ���Ͽ� �����Ͱ� ũ�ų� ������ �����͸� �������� �̵���Ű�� �˰���
	int i, j, temp;

	if (pArr->count <= 1)
		return;

	for (i = 0; i < pArr->count; ++i)
	{
		for (j = 0; j < pArr->count - i - 1; ++j)
		{
			if (pArr->pInt[j] > pArr->pInt[j + 1])
			{
				temp = pArr->pInt[j];
				pArr->pInt[j] = pArr->pInt[j + 1];
				pArr->pInt[j + 1] = temp;
			}
		}
	}
}
