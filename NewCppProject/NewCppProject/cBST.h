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
	// �θ���
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
	tBSTNode<T1,T2>*	pRoot; // ��Ʈ ��� �ּ�
	int					iCount; // ������ ����

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
		tBSTNode<T1, T2>*	iterNode; // null �� ��� end iterator

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
			// iternode nullptr üũ(end iterator���� �ƴ���)
			assert(iterNode);

			return iterNode->pair;
		}
		const tPair<T1, T2>* operator ->()
		{
			// iternode nullptr üũ(end iterator���� �ƴ���)
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

	// ù��° ������ ���
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
	// ������ �ڽ� ��尡 ����, �θ��� ���� �ڽĳ���� �θ��尡 ���� �ļ���
	// ������ �ڽ� ��尡 �ִٸ�, ���� �ڽĳ�尡 �ִ��� üũ�ϰ� ������ �� ��尡 ���� �ļ���
	tBSTNode<T1, T2>* pSuccessor = nullptr;
	if (nullptr != _pNode->arrNode[(int)NODE_TYPE::RCHILD]) // ������ �ڽĳ�� ���� üũ
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
	// ���� �ڽ� ��尡 ����, �θ��� ������ �ڽĳ���� �θ��尡 ���� ������
	// ���� �ڽ� ��尡 �ִٸ�, ������ �ڽĳ�尡 �ִ��� üũ�ϰ� ������ �� ��尡 ���� ������
	tBSTNode<T1, T2>* pDecessor = nullptr;
	if (nullptr != _pNode->arrNode[(int)NODE_TYPE::LCHILD]) // ���� �ڽĳ�� ���� üũ
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
			// ã�Ҵ� : pNode�� find ����̴�
			break;
		}
		if (nullptr == pNode->arrNode[(int)node_type])
		{
			// ã�� ���ߴ� : pNode == nullptr ==> enditerator
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

	// 1. �ڽ��� �ϳ��� ���� ���
	if (_pTargetNode->isLeaf())
	{
		// ������ų ����� �ļ��� ��带 ã�Ƶд�.
		// ������ų ��尡 ��Ʈ����� ���( �ڽ��� ���� ��Ʈ == BST �ȿ� �����Ͱ� 1���ۿ� ������ )
		if (_pTargetNode == pRoot)
		{
			pRoot = nullptr;
			delete _pTargetNode;
		}
		else
		{
			// �θ���� ����, ������ ����� �ڽ��� ����Ű�� �����͸� nullptr
			if (_pTargetNode->isLeftChild())
				_pTargetNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD] = nullptr;
			else
				_pTargetNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::RCHILD] = nullptr;

			delete _pTargetNode;
		}
		// ������ ���� ������
		--iCount;
	}
	// 2. �ڽ��� 2���� ���
	else if (_pTargetNode->isFull())
	{
		// ���� �� �ڸ��� ���� �ļ����� ���� �����Ų��.
		_pTargetNode->pair = pSuccessor->pair;

		// ���� �ļ��� ��带 �����Ѵ�.
		DeleteNode(pSuccessor);

		// ������ ��尡 �� ���� �ļ��ڰ� �Ǿ���.
		pSuccessor = _pTargetNode;
	}
	// 3. �ڽ��� 1���� ���
	else
	{
		NODE_TYPE targetChild = NODE_TYPE::LCHILD;
		if (_pTargetNode->arrNode[(int)NODE_TYPE::RCHILD])
			targetChild = NODE_TYPE::RCHILD;

		if (_pTargetNode->isRoot())// Ÿ�ٳ�尡 ��Ʈ����϶�
		{
			pRoot = _pTargetNode->arrNode[(int)targetChild];
			pRoot->arrNode[(int)NODE_TYPE::PARENT] = nullptr;
		}
		else
		{
			if (_pTargetNode->isLeftChild()) // Ÿ�� ��尡 ���� �ڽ� ����϶�
			{
				_pTargetNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD] = _pTargetNode->arrNode[(int)targetChild];
			}
			else if (_pTargetNode->isRightChild())// Ÿ�ٳ�尡 ������ �ڽĳ���϶�
			{
				_pTargetNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::RCHILD] = _pTargetNode->arrNode[(int)targetChild];
			}
			_pTargetNode->arrNode[(int)targetChild]->arrNode[(int)NODE_TYPE::PARENT] = _pTargetNode->arrNode[(int)NODE_TYPE::PARENT];
		}
		delete _pTargetNode;
		// ������ ���� ������
		--iCount;
	}

	
	return pSuccessor;
}

