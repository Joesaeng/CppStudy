#pragma once
#include <iostream>

template<typename T>
struct Node
{
	T			data;
	Node<T>* pPrev;	// <T>�� ���� �����ϴ� : ������ ���̱� ������
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
	// �Էµ� �����͸� ������ ��带 ����ü �����ڸ� Ȱ���� �����Ҵ�
	Node<T>* pNewNode = new Node<T>(_data, nullptr, nullptr);

	if (pHead == nullptr)
	{
		// ó�� �Էµ� �����Ͷ��
		pHead = pNewNode;
		pTail = pNewNode;
	}
	else
	{
		// �����Ͱ� 1�� �̻󿡼� �Էµ� ���
		// ���� ���� ������ ������(tail)�� ���� �����ϰ� �ִ� ����
		// ���� ������ ���� ���� ����Ű�� �Ѵ�.
		pTail->pNext = pNewNode;
		pNewNode->pPrev = pTail;

		// List�� ������ ����� �ּҰ��� ���� �Էµ� ���� �����Ѵ�.
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
		// ó�� �Էµ� �����Ͷ��
		pHead = pNewNode;
		pTail = pNewNode;
	}
	else
	{
		// ���� ������ ����� ������ ���� ������� �ּҰ����� ä��

		// ���� ������� ������� �ּҰ��� ���� ������ �ּҷ� ä��
		pHead->pPrev = pNewNode;
		// ���� ������ ��带 ���ο� ����ּҷ� �����Ѵ�.
		pHead = pNewNode;
	}
	++iCount;
}
