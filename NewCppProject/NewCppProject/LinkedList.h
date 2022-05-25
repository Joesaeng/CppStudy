#pragma once

typedef struct Node
{
	int		iData;
	Node*	pNextNode;
	Node*	pPrevNode;
};


typedef struct LinkedList
{
	Node*	pHeadNode;
	int		iCount;
};


// ������ ����Ʈ �ʱ�ȭ
void InitList(LinkedList* _List);

// ������ ����Ʈ ������ �߰�
void PushBack(LinkedList* _List, int _iData); // �ڿ� �߰�
void PushFront(LinkedList* _List, int _iData); // �տ� �߰�

// ������ ����Ʈ �޸� ����
void ReleaseList(LinkedList* _List);
