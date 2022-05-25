#include "LinkedList.h"
#include <iostream>

void InitList(LinkedList* _List)
{
	_List->pHeadNode = nullptr;
	_List->iCount = 0;
}

void PushBack(LinkedList* _List, int _iData)
{
	// 데이터를 저장할 노드 생성
	Node* pNode = (Node*)malloc(sizeof(Node));
	// 데이터 노드에 데이터 복사
	pNode->iData = _iData;
	pNode->pNextNode = nullptr;

	
	if (_List->pHeadNode == nullptr) // 추가한 데이터가 처음인지 아닌지
	{
		_List->pHeadNode = pNode;
	}
	else
	{
		// 현재 가장 마지막 노드를 찾아서, 그 노드의 pNextNode 주소값에 지금 생성된 주소를 채운다
		Node* pCurFinalNode = _List->pHeadNode; // pHeadNode 값을 해치면 안되기 때문에 새로운 지역변수를 지정해준다
		while (pCurFinalNode->pNextNode)
		{
			pCurFinalNode = pCurFinalNode->pNextNode;
		}
		pCurFinalNode->pNextNode = pNode;
		pNode->pPrevNode = pCurFinalNode;
	}
	++_List->iCount;
}

void PushFront(LinkedList* _List, int _iData)
{
	// 데이터를 저장할 노드 생성
	Node* pNode = (Node*)malloc(sizeof(Node));
	// 데이터 노드에 데이터 복사
	pNode->iData = _iData;
	//pNode->pPrevNode = nullptr;
	if (_List->pHeadNode == nullptr) // 추가한 데이터가 처음인지 아닌지
	{
		_List->pHeadNode = pNode;
	}
	else
	{
		// 원래 있던 노드를 nextnode로 바꾼후 현재 노드를 헤드노드로 바꾼다.
		pNode->pNextNode = _List->pHeadNode;
		_List->pHeadNode->pPrevNode = pNode;
		_List->pHeadNode = pNode;
	}
	++_List->iCount;
}

void Release(Node* _pNode) // ReleaseList를 재귀함수로 만든다면 이렇게 만들수도 있다
{
	if (nullptr == _pNode)
		return;

	Release(_pNode->pNextNode);
	free(_pNode);
}

void ReleaseList(LinkedList* _List)
{
	//Release(_List->pHeadNode);
	Node* delNode = _List->pHeadNode;
	while (delNode)
	{
		Node* nextNode = delNode->pNextNode;
		free(delNode);
		delNode = nextNode;
	}
}
