#pragma once


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

	cBST()
		: pRoot(nullptr)
		, iCount(0)
	{}
	class iterator;
	iterator begin();
	iterator end();
	iterator find(const T1& _find);
	// iterator
	class iterator
	{
		cBST<T1, T2>*		pBST;
		tBSTNode<T1, T2>*	iterNode; // null 인 경우 end iterator

	public:
		iterator()
			: pBST(nullptr)
			, iterNode(nullptr)
		{}
		iterator(cBST<T1,T2>* _pBST, tBSTNode<T1,T2>* _pNode)
			: pBST(_pBST)
			, iterNode(_pNode)
		{}
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

