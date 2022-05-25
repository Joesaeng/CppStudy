#include "bubbleSort.h"
#include <iostream>

void BubbleSort(JoArr* pArr)
{
	// 버블정렬 알고리즘 : 배열에 안에 있는 연속된 데이터를 비교하여 데이터가 크거나 작을때 데이터를 우측으로 이동시키는 알고리즘
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
