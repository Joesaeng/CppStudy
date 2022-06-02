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
	int size() { return iCount; };

	class iterator;
	iterator begin();
	iterator Tail();
	iterator end();
	iterator erase(iterator& _iter);
	iterator insert(const iterator& _iter, const T& _data);

public:
	cLinkedList();
	~cLinkedList();

	class iterator
	{
		cLinkedList<T>*	pList;
		Node<T>*		pNode;	// null �� ���, end iterator �� ����
		bool			bValid;

	public:
		inline T& operator* ()
		{
			return pNode->data;
		}

		bool operator ==(const iterator& _other)
		{
			if (pList == _other.pList && pNode == _other.pNode)
				return true;

			return false;
		}
		bool operator !=(const iterator& _other)
		{
			return !(*this == _other);
		}

		iterator operator ++()
		{
			if (nullptr == pNode || !bValid)
				assert(nullptr);

			pNode = pNode->pNext;

			return *this;
		}

		iterator operator ++(int)
		{
			iterator copyIter(*this);

			++(*this);

			return copyIter;

		}

		iterator operator --()
		{
			if (nullptr == pNode || !bValid)
				assert(nullptr);

			pNode = pNode->pPrev;

			return *this;
		}
		
		iterator operator --(int)
		{
			iterator copyIter(*this);

			--(*this);

			return copyIter;
		}
	public:
		iterator()
			: pList(nullptr)
			, pNode(nullptr)
			, bValid(false)
		{}
		iterator(cLinkedList<T>* _pList, Node<T>* _pNode)
			: pList(_pList)
			, pNode(_pNode)
			, bValid(false)
		{
			if (nullptr != _pList && nullptr != _pNode)
				bValid = true;
		}
		~iterator()
		{}

		friend class cLinkedList;
	};
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

template<typename T>
inline typename cLinkedList<T>::iterator cLinkedList<T>::begin()
{
	return iterator(this, pHead);
}

template<typename T>
inline typename cLinkedList<T>::iterator cLinkedList<T>::Tail()
{
	return iterator(this, pTail);
}

template<typename T>
inline typename cLinkedList<T>::iterator cLinkedList<T>::end()
{
	return iterator(this, nullptr);
}

template<typename T>
 typename cLinkedList<T>::iterator cLinkedList<T>::erase(iterator& _iter)
{
	 // ����ó��
	 // iterator�� end iterator �� ��
	if (end() == _iter)
		 assert(nullptr);
	// ����� �� ��
	if (pHead == _iter.pNode)
	{
		pHead = pHead->pNext;
		delete(pHead->pPrev);
		pHead->pPrev = nullptr;
	}
	// ���ϳ�� �� ��
	else if (pTail == _iter.pNode)
	{
		pTail = pTail->pPrev;
		delete(pTail->pNext);
		pTail->pNext = nullptr;
	}
	else
	{
		Node<T>* iterNode = _iter.pNode;
		iterNode->pPrev->pNext = iterNode->pNext;
		iterNode->pNext->pPrev = iterNode->pPrev;
		delete(iterNode);
	}

	--iCount;
	_iter.bValid = false;
	return iterator(this,nullptr);
}

template<typename T>
typename cLinkedList<T>::iterator cLinkedList<T>::insert(const iterator& _iter, const T& _data)
{
	if (end() == _iter)
		assert(nullptr);

	// ����Ʈ�� �߰��Ǵ� �����͸� ������ Node ����
	Node<T>* pNode = new Node<T>(_data, nullptr, nullptr);

	// iterator �� ����Ű�� ��尡 ������� ���
	if (pHead == _iter.pNode)
	{
		_iter.pNode->pPrev = pNode;
		pNode->pNext = _iter.pNode;
		pHead = pNode;
	}
	else
	{
		// iterator �� ����Ű�� �ִ� ����� �������� ���� 
		// ���� ��� �ּ� ��Ʈ�� ���� ������ ���� ����
		_iter.pNode->pPrev->pNext = pNode;
		pNode->pPrev = _iter.pNode->pPrev;

		// iterator �� ����Ű�� �ִ� ����� ���� ���(pPrev)�� ���� ������ ���� ����
		// ���� ������ ����� ���� ���(pNext)�� iterator �� ����Ű�� �ִ� ���� ����
		_iter.pNode->pPrev = pNode;
		pNode->pNext = _iter.pNode;
	}

	++iCount;

	return iterator(this, pNode);
}
