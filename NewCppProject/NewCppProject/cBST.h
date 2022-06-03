#pragma once
#include <assert.h>


enum class NODE_TYPE
{
	PARENT,
	LCHILD,
	RCHILD,
	END,
};

template<typename T1, typename T2>
struct tPair
{
	T1 first;
	T2 second;
};

template<typename T1, typename T2>
tPair<T1, T2> makeBstpair(const T1& _first, const T2& _second)
{
	return tPair<T1, T2>{_first, _second};
}


template<typename T1, typename T2>
struct tBSTNode
{
	// data
	tPair<T1,T2> pair;
	// 부모노드
	tBSTNode*	arrNode[(int)NODE_TYPE::END];

	bool isRoot()
	{
		if (nullptr == arrNode[(int)NODE_TYPE::PARENT])
			return true;
		return false;
	}
	bool isLeftChild()
	{
		if (arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD] == this)
			return true;
		return false;
	}
	bool isRightChild()
	{
		if (arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::RCHILD] == this)
			return true;
		return false;
	}

	bool isLeaf()
	{
		if (nullptr == arrNode[(int)NODE_TYPE::LCHILD] && nullptr == arrNode[(int)NODE_TYPE::RCHILD])
			return true;
		return false;
	}
	bool isFull()
	{
		if (arrNode[(int)NODE_TYPE::LCHILD] && arrNode[(int)NODE_TYPE::RCHILD])
			return true;
		return false;
	}

	tBSTNode()
		:pair()
		,arrNode()
	{}
	tBSTNode(const tPair<T1,T2>& _pair, tBSTNode* _pParent, tBSTNode* _pLchild, tBSTNode* _pRchild)
		: pair(_pair)
		, arrNode{ _pParent, _pLchild, _pRchild }
	{}
};

template <typename T1, typename T2>
class cBST
{
private:
	tBSTNode<T1,T2>*	pRoot; // 루트 노드 주소
	int					iCount; // 데이터 개수

public:
	bool insert(const tPair<T1, T2>& _pair);
	tBSTNode<T1, T2>* GetInOrderSuccessor(tBSTNode<T1, T2> *_pNode);
	tBSTNode<T1, T2>* GetInOrdePredecessor(tBSTNode<T1, T2> *_pNode);

	cBST()
		: pRoot(nullptr)
		, iCount(0)
	{}
	class iterator;
	iterator begin();
	iterator end();
	iterator find(const T1& _find);
	iterator erase(const iterator& _iter);
private:
	tBSTNode<T1, T2>* DeleteNode(tBSTNode<T1, T2>* _pTargetNode);

public:
	// iterator
	class iterator
	{
		cBST<T1, T2>*		pBST;
		tBSTNode<T1, T2>*	iterNode; // null 인 경우 end iterator

	public:
		bool operator ==(const iterator& _other)
		{
			if (pBST == _other.pBST && iterNode == _other.iterNode)
				return true;

			return false;
		}
		bool operator !=(const iterator& _other)
		{
			return !(*this == _other);
		}

		const tPair<T1, T2>& operator *()
		{
			// iternode nullptr 체크(end iterator인지 아닌지)
			assert(iterNode);

			return iterNode->pair;
		}
		const tPair<T1, T2>* operator ->()
		{
			// iternode nullptr 체크(end iterator인지 아닌지)
			assert(iterNode);

			return &iterNode->pair;
		}

		iterator& operator ++()
		{
			iterNode = pBST->GetInOrderSuccessor(iterNode);
			return *this;
		}

		iterator& operator--()
		{
			iterNode = pBST->GetInOrdePredecessor(iterNode);
			return *this;
		}
	public:
		iterator()
			: pBST(nullptr)
			, iterNode(nullptr)
		{}
		iterator(cBST<T1,T2>* _pBST, tBSTNode<T1,T2>* _pNode)
			: pBST(_pBST)
			, iterNode(_pNode)
		{}
		friend class cBST;
	 };
};

template<typename T1, typename T2>
inline bool cBST<T1, T2>::insert(const tPair<T1, T2>& _pair)
{
	tBSTNode<T1, T2>* pNewNode = new tBSTNode<T1, T2>(_pair, nullptr, nullptr, nullptr);

	// 첫번째 데이터 라면
	if (nullptr == pRoot)
	{
		pRoot = pNewNode;
	}
	else
	{
		tBSTNode<T1, T2>* pNode = pRoot;
		NODE_TYPE node_type = NODE_TYPE::END;
		while (true)
		{
			if (pNode->pair.first < pNewNode->pair.first)
				node_type = NODE_TYPE::RCHILD;
			else if (pNode->pair.first > pNewNode->pair.first)
				node_type = NODE_TYPE::LCHILD;
			else
				return false;

			if (nullptr == pNode->arrNode[(int)node_type])
			{
				pNode->arrNode[(int)node_type] = pNewNode;
				pNewNode->arrNode[(int)NODE_TYPE::PARENT] = pNode;
				break;
			}
			else
				pNode = pNode->arrNode[(int)node_type];
		}
		
	}


	++iCount;

	return true;
}

template<typename T1, typename T2>
inline tBSTNode<T1, T2>* cBST<T1, T2>::GetInOrderSuccessor(tBSTNode<T1, T2> *_pNode)
{
	// 오른쪽 자식 노드가 없고, 부모의 왼쪽 자식노드라면 부모노드가 중위 후속자
	// 오른쪽 자식 노드가 있다면, 왼쪽 자식노드가 있는지 체크하고 없으면 그 노드가 중위 후속자
	tBSTNode<T1, T2>* pSuccessor = nullptr;
	if (nullptr != _pNode->arrNode[(int)NODE_TYPE::RCHILD]) // 오른쪽 자식노드 보유 체크
	{
		pSuccessor = _pNode->arrNode[(int)NODE_TYPE::RCHILD];
		while (pSuccessor->arrNode[(int)NODE_TYPE::LCHILD])
		{
			pSuccessor = pSuccessor->arrNode[(int)NODE_TYPE::LCHILD];
		}
	}
	else
	{
		pSuccessor = _pNode;
		while (true)
		{
			if (pSuccessor->isRoot())
			{
				pSuccessor = nullptr;
				break;
			}
			if (pSuccessor->isLeftChild())
			{
				pSuccessor = pSuccessor->arrNode[(int)NODE_TYPE::PARENT];
				break;
			}
			else
				pSuccessor = pSuccessor->arrNode[(int)NODE_TYPE::PARENT];
		}
	}


	return pSuccessor;
}

template<typename T1, typename T2>
inline tBSTNode<T1, T2>* cBST<T1, T2>::GetInOrdePredecessor(tBSTNode<T1, T2> *_pNode)
{
	// 왼쪽 자식 노드가 없고, 부모의 오른쪽 자식노드라면 부모노드가 중위 선행자
	// 왼쪽 자식 노드가 있다면, 오른쪽 자식노드가 있는지 체크하고 없으면 그 노드가 중위 선행자
	tBSTNode<T1, T2>* pDecessor = nullptr;
	if (nullptr != _pNode->arrNode[(int)NODE_TYPE::LCHILD]) // 왼쪽 자식노드 보유 체크
	{
		pDecessor = _pNode->arrNode[(int)NODE_TYPE::LCHILD];
		while (pDecessor->arrNode[(int)NODE_TYPE::RCHILD])
		{
			pDecessor = pDecessor->arrNode[(int)NODE_TYPE::RCHILD];
		}
	}
	else
	{
		pDecessor = _pNode;
		while (true)
		{
			if (pDecessor->isRoot())
			{
				pDecessor = nullptr;
				break;
			}
			if (pDecessor->isRightChild())
			{
				pDecessor = pDecessor->arrNode[(int)NODE_TYPE::PARENT];
				break;
			}
			else
				pDecessor = pDecessor->arrNode[(int)NODE_TYPE::PARENT];
		}
	}
	return pDecessor;
}

template<typename T1, typename T2>
inline typename cBST<T1,T2>::iterator cBST<T1, T2>::begin()
{
	tBSTNode<T1, T2>* pNode = pRoot;
	while (pNode->arrNode[(int)NODE_TYPE::LCHILD])
	{
		pNode = pNode->arrNode[(int)NODE_TYPE::LCHILD];
	}
	
	return iterator(this, pNode);
}
template<typename T1, typename T2>
inline typename cBST<T1, T2>::iterator cBST<T1, T2>::end()
{
	return iterator(this, nullptr);
}

template<typename T1, typename T2>
inline typename cBST<T1,T2>::iterator cBST<T1, T2>::find(const T1& _find)
{
	tBSTNode<T1, T2>* pNode = pRoot;
	NODE_TYPE node_type = NODE_TYPE::END;

	while (true)
	{
		if (pNode->pair.first < _find)
			node_type = NODE_TYPE::RCHILD;
		else if (pNode->pair.first > _find)
			node_type = NODE_TYPE::LCHILD;
		else
		{
			// 찾았다 : pNode가 find 노드이다
			break;
		}
		if (nullptr == pNode->arrNode[(int)node_type])
		{
			// 찾지 못했다 : pNode == nullptr ==> enditerator
			pNode = nullptr;
			break;
		}
		else
			pNode = pNode->arrNode[(int)node_type];
	}
	return iterator(this, pNode);
}

template<typename T1, typename T2>
inline typename cBST<T1,T2>::iterator cBST<T1, T2>::erase(const iterator& _iter)
{
	assert(this == _iter.pBST);

	tBSTNode<T1,T2>* pSuccessor = DeleteNode(_iter.iterNode);

	return iterator(this, pSuccessor);
}

template<typename T1, typename T2>
inline tBSTNode<T1, T2>* cBST<T1, T2>::DeleteNode(tBSTNode<T1, T2>* _pTargetNode)
{
	tBSTNode<T1, T2>* pSuccessor = GetInOrderSuccessor(_pTargetNode);

	// 1. 자식이 하나도 없는 경우
	if (_pTargetNode->isLeaf())
	{
		// 삭제시킬 노드의 후속자 노드를 찾아둔다.
		// 삭제시킬 노드가 루트노드일 경우( 자식이 없고 루트 == BST 안에 데이터가 1개밖에 없었다 )
		if (_pTargetNode == pRoot)
		{
			pRoot = nullptr;
			delete _pTargetNode;
		}
		else
		{
			// 부모노드로 접근, 삭제될 노드인 자식을 가리키는 포인터를 nullptr
			if (_pTargetNode->isLeftChild())
				_pTargetNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD] = nullptr;
			else
				_pTargetNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::RCHILD] = nullptr;

			delete _pTargetNode;
		}
		// 데이터 개수 맞춰줌
		--iCount;
	}
	// 2. 자식이 2개인 경우
	else if (_pTargetNode->isFull())
	{
		// 삭제 될 자리에 중위 후속자의 값을 복사시킨다.
		_pTargetNode->pair = pSuccessor->pair;

		// 중위 후속자 노드를 삭제한다.
		DeleteNode(pSuccessor);

		// 삭제할 노드가 곧 중위 후속자가 되었다.
		pSuccessor = _pTargetNode;
	}
	// 3. 자식이 1개인 경우
	else
	{
		NODE_TYPE targetChild = NODE_TYPE::LCHILD;
		if (_pTargetNode->arrNode[(int)NODE_TYPE::RCHILD])
			targetChild = NODE_TYPE::RCHILD;

		if (_pTargetNode->isRoot())// 타겟노드가 루트노드일때
		{
			pRoot = _pTargetNode->arrNode[(int)targetChild];
			pRoot->arrNode[(int)NODE_TYPE::PARENT] = nullptr;
		}
		else
		{
			if (_pTargetNode->isLeftChild()) // 타겟 노드가 왼쪽 자식 노드일때
			{
				_pTargetNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD] = _pTargetNode->arrNode[(int)targetChild];
			}
			else if (_pTargetNode->isRightChild())// 타겟노드가 오른쪽 자식노드일때
			{
				_pTargetNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::RCHILD] = _pTargetNode->arrNode[(int)targetChild];
			}
			_pTargetNode->arrNode[(int)targetChild]->arrNode[(int)NODE_TYPE::PARENT] = _pTargetNode->arrNode[(int)NODE_TYPE::PARENT];
		}
		delete _pTargetNode;
		// 데이터 개수 맞춰줌
		--iCount;
	}

	
	return pSuccessor;
}

