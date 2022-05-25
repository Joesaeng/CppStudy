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


// 연결형 리스트 초기화
void InitList(LinkedList* _List);

// 연결형 리스트 데이터 추가
void PushBack(LinkedList* _List, int _iData); // 뒤에 추가
void PushFront(LinkedList* _List, int _iData); // 앞에 추가

// 연결형 리스트 메모리 해제
void ReleaseList(LinkedList* _List);
