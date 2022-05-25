#include <iostream>
#include "Arr_.h"
#include <time.h>

void BubbleSort(int* _pData, int _iCount)
{
	// �������� �˰��� : �迭�� �ȿ� �ִ� ���ӵ� �����͸� ���Ͽ� �����Ͱ� ũ�ų� ������ �����͸� �������� �̵���Ű�� �˰���
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
	pFunc();*/ // Test�Լ� ȣ��

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

	// ����(����)
	srand(time(nullptr));

	for (int i = 0; i < 20; ++i)
	{
		int iRand = rand() % 1000 + 1;
		AddData(&arr, iRand);
	}

	for (int i = 0; i < arr.count; ++i)
		printf("%d\n", arr.pInt[i]);

	// ���� ����
	printf("\n ���� �迭 ���� �������� �մϴ� \n\n");


	Sort(&arr, BubbleSort);


	for (int i = 0; i < arr.count; ++i)
		printf("%d\n", arr.pInt[i]);
	// ����, ����, �պ�, ���, �� ���ĵ� �ѹ��� �����غ���.



	EraseArr(&arr);
	return 0;
}