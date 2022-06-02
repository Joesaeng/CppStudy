#pragma once

template<typename T1, typename T2>
struct tPair
{
	T1 first;
	T2 second;
};


template<typename T1, typename T2>
struct tBSTNode
{
	// data
	tPair<T1,T2> pair;
	// 부모노드
	tBSTNode* pParent;
	tBSTNode* pLeftChild;
	tBSTNode* pRightChild;

};

template <typename T1, typename T2>
class cBST
{
private:
	tBSTNode<T1,T2>*	pRoot; // 루트 노드 주소
	int			iCount; // 데이터 개수

public:
	bool insert(const tPair<T1, T2>& _pair);

	cBST()
		: pRoot(nullptr)
		, iCount(0)
	{}

};

template<typename T1, typename T2>
inline bool cBST<T1, T2>::insert(const tPair<T1, T2>& _pair)
{
	tBSTNode<T1,T2>* pNewNode = new tBSTNode<T1, T2>();
	pNewNode->pair = _pair;
	pNewNode->pParent = nullptr;
	pNewNode->pLeftChild = nullptr;
	pNewNode->pRightChild = nullptr;

	// 첫번째 데이터 라면
	if (nullptr == pRoot)
	{
		pRoot = pNewNode;
	}
	else
	{
		tBSTNode<T1, T2>* pNode = pRoot;
		while (true)
		{
			if (pNode->pair.first < pNewNode->pair.first)
			{
				if (nullptr == pNode->pRightChild)
				{
					pNode->pRightChild = pNewNode;
					pNewNode->pParent = pNode;
					break;
				}
				else
					pNode = pNode->pRightChild;


			}
			else if (pNode->pair.first > pNewNode->pair.first)
			{
				if (nullptr == pNode->pLeftChild)
				{
					pNode->pLeftChild = pNewNode;
					pNewNode->pParent = pNode;
					break;
				}
				else
					pNode = pNode->pLeftChild;
			}
			else
			{
				return false;
			}
		}
		
	}


	++iCount;

	return true;
}

