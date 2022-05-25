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

void SelectionSort(void) //���� ����
{

}
void InsertionSort(void) //���� ����
{

}
void MergeSort(void) //�պ� ����
{

}
void QuickSort(void) //��� ����
{

}
void HeapSort(void) //�� ����
{

}

int main()
{
	JoArr arr;
	
	SetArr(&arr);

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