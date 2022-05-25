#include <iostream>
#include "LinkedList.h"


int main()
{
	// 연결형 리스트
	LinkedList list;

	InitList(&list);

	PushBack(&list, 100);
	PushBack(&list, 200);
	PushBack(&list, 300);

	PushFront(&list, 100);
	PushFront(&list, 200);
	PushFront(&list, 300);

	Node* pNode = list.pHeadNode;
	for (int i = 0; i < list.iCount; ++i)
	{
		printf("%d\n", pNode->iData);
		pNode = pNode->pNextNode;
	}
	ReleaseList(&list);


	return 0;
}
