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
		Node<T>*		pNode;	// null 인 경우, end iterator 로 간주
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
	 // 예외처리
	 // iterator가 end iterator 일 때
	if (end() == _iter)
		 assert(nullptr);
	// 헤드노드 일 때
	if (pHead == _iter.pNode)
	{
		pHead = pHead->pNext;
		delete(pHead->pPrev);
		pHead->pPrev = nullptr;
	}
	// 테일노드 일 떄
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

	// 리스트에 추가되는 데이터를 저장할 Node 생성
	Node<T>* pNode = new Node<T>(_data, nullptr, nullptr);

	// iterator 가 가리키는 노드가 헤드노드인 경우
	if (pHead == _iter.pNode)
	{
		_iter.pNode->pPrev = pNode;
		pNode->pNext = _iter.pNode;
		pHead = pNode;
	}
	else
	{
		// iterator 가 가리키고 있는 노드의 이전으로 가서 
		// 다음 노드 주소 파트로 새로 생성한 노드로 지정
		_iter.pNode->pPrev->pNext = pNode;
		pNode->pPrev = _iter.pNode->pPrev;

		// iterator 가 가리키고 있는 노드의 이전 노드(pPrev)를 새로 생성된 노드로 지정
		// 새로 생성된 노드의 다음 노드(pNext)를 iterator 가 가리키고 있는 노드로 지정
		_iter.pNode->pPrev = pNode;
		pNode->pNext = _iter.pNode;
	}

	++iCount;

	return iterator(this, pNode);
}
