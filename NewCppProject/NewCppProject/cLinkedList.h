#pragma once
#include <iostream>

template<typename T>
struct Node
{
	T			data;
	Node<T>* pPrev;	// <T>는 생략 가능하다 : 본인의 것이기 때문에
	Node<T>* pNext;

	Node()
		: data()
		, pPrev(nullptr)
		, pNext(nullptr)
	{}
	Node(const T& _data, Node<T>* _pPrev, Node<T>* _pNext)
		: data(_data)
		, pPrev(_pPrev)
		, pNext(_pNext)
	{}
};

template<typename T>
class cLinkedList
{
private:
	Node<T>*	pHead;
	Node<T>*	pTail;
	int			iCount;

public:
	void pushBack(const T& _data);
	void pushFront(const T& _data);

public:
	cLinkedList();
	~cLinkedList();
};

template<typename T>
cLinkedList<T>::cLinkedList()
	: pHead(nullptr)
	, pTail(nullptr)
	, iCount(0)
{}
template<typename T>
cLinkedList<T>::~cLinkedList()
{
	Node<T>* delNode = pHead;
	while (delNode)
	{
		Node<T>* nextNode = delNode->pNext;
		delete(delNode);
		delNode = nextNode;
	}
}

template<typename T>
void cLinkedList<T>:: pushBack(const T& _data)
{
	// 입력된 데이터를 저장할 노드를 구조체 생성자를 활용해 동적할당
	Node<T>* pNewNode = new Node<T>(_data, nullptr, nullptr);

	if (pHead == nullptr)
	{
		// 처음 입력된 데이터라면
		pHead = pNewNode;
		pTail = pNewNode;
	}
	else
	{
		// 데이터가 1개 이상에서 입력된 경우
		// 현재 가장 마지막 데이터(tail)을 통해 저장하고 있는 노드와
		// 새로 생성된 노드와 서로 가리키게 한다.
		pTail->pNext = pNewNode;
		pNewNode->pPrev = pTail;

		// List가 마지막 노드의 주소값을 새로 입력된 노드로 갱신한다.
		pTail = pNewNode;
	}
	++iCount;
}

template<typename T>
void cLinkedList<T>::pushFront(const T& _data)
{
	Node<T>* pNewNode = new Node<T>(_data, nullptr, pHead);

	if (pHead == nullptr)
	{
		// 처음 입력된 데이터라면
		pHead = pNewNode;
		pTail = pNewNode;
	}
	else
	{
		// 새로 생성된 노드의 다음을 현재 헤드노드의 주소값으로 채움

		// 현재 헤드노드의 이전노드 주소값을 새로 생성된 주소로 채움
		pHead->pPrev = pNewNode;
		// 새로 생성된 노드를 새로운 헤드주소로 갱신한다.
		pHead = pNewNode;
	}
	++iCount;
}
