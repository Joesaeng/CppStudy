#include <iostream>
#include "Arr_.h"
#include "bubbleSort.h"


int main()
{
	JoArr arr;
	
	SetArr(&arr);

	AddData(&arr, 10);
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
	AddData(&arr, 1);

	for (int i = 0; i < arr.count; ++i)
		printf("%d\n", arr.pInt[i]);

	// 버블 정렬
	printf("\n 앞의 배열 값을 버블정렬 합니다 \n\n");

	BubbleSort(&arr);

	for (int i = 0; i < arr.count; ++i)
		printf("%d\n", arr.pInt[i]);



	EraseArr(&arr);
	return 0;
}