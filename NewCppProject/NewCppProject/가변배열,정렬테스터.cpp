#include <iostream>
#include "Arr_.h"
#include <time.h>

void BubbleSort(int* _pData, int _iCount)
{
	// 버블정렬 알고리즘 : 배열에 안에 있는 연속된 데이터를 비교하여 데이터가 크거나 작을때 데이터를 우측으로 이동시키는 알고리즘
	int i, j, temp;

	if (_iCount <= 1)
		return;

	for (i = 0; i < _iCount; ++i)
	{
		for (j = 0; j < _iCount - i - 1; ++j)
		{
			if (_pData[j] > _pData[j + 1])
			{
				temp = _pData[j];
				_pData[j] = _pData[j + 1];
				_pData[j + 1] = temp;
			}
		}
	}
}

void Test(void)
{

}

int main()
{
	/*void(*pFunc)(void) = nullptr;
	pFunc = Test;
	pFunc();*/ // Test함수 호출

	JoArr arr;
	
	SetArr(&arr);

	/*AddData(&arr, 10);
	AddData(&arr, 15);
	AddData(&arr, 77);
	AddData(&arr, 897);
	AddData(&arr, 44);
	AddData(&arr, 345);
	AddData(&arr, 646);
	AddData(&arr, 9643);
	AddData(&arr, 409);
	AddData(&arr, 3);
	AddData(&arr, 66);
	AddData(&arr, 6236);
	AddData(&arr, 6566);
	AddData(&arr, 62896);
	AddData(&arr, 6446);
	AddData(&arr, 1);*/

	// 난수(랜덤)
	srand(time(nullptr));

	for (int i = 0; i < 20; ++i)
	{
		int iRand = rand() % 1000 + 1;
		AddData(&arr, iRand);
	}

	for (int i = 0; i < arr.count; ++i)
		printf("%d\n", arr.pInt[i]);

	// 버블 정렬
	printf("\n 앞의 배열 값을 버블정렬 합니다 \n\n");


	Sort(&arr, BubbleSort);


	for (int i = 0; i < arr.count; ++i)
		printf("%d\n", arr.pInt[i]);
	// 삽입, 선택, 합병, 쾌속, 힙 정렬도 한번씩 구현해보자.



	EraseArr(&arr);
	return 0;
}