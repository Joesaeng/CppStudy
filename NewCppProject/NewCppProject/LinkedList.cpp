#include "LinkedList.h"
#include <iostream>

void InitList(LinkedList* _List)
{
	_List->pHeadNode = nullptr;
	_List->iCount = 0;
}

void PushBack(LinkedList* _List, int _iData)
{
	// �����͸� ������ ��� ����
	Node* pNode = (Node*)malloc(sizeof(Node));
	// ������ ��忡 ������ ����
	pNode->iData = _iData;
	pNode->pNextNode = nullptr;

	
	if (_List->pHeadNode == nullptr) // �߰��� �����Ͱ� ó������ �ƴ���
	{
		_List->pHeadNode = pNode;
	}
	else
	{
		// ���� ���� ������ ��带 ã�Ƽ�, �� ����� pNextNode �ּҰ��� ���� ������ �ּҸ� ä���
		Node* pCurFinalNode = _List->pHeadNode; // pHeadNode ���� ��ġ�� �ȵǱ� ������ ���ο� ���������� �������ش�
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
	// �����͸� ������ ��� ����
	Node* pNode = (Node*)malloc(sizeof(Node));
	// ������ ��忡 ������ ����
	pNode->iData = _iData;
	//pNode->pPrevNode = nullptr;
	if (_List->pHeadNode == nullptr) // �߰��� �����Ͱ� ó������ �ƴ���
	{
		_List->pHeadNode = pNode;
	}
	else
	{
		// ���� �ִ� ��带 nextnode�� �ٲ��� ���� ��带 ������ �ٲ۴�.
		pNode->pNextNode = _List->pHeadNode;
		_List->pHeadNode->pPrevNode = pNode;
		_List->pHeadNode = pNode;
	}
	++_List->iCount;
}

void Release(Node* _pNode) // ReleaseList�� ����Լ��� ����ٸ� �̷��� ������� �ִ�
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
