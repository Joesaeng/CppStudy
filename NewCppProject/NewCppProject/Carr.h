#pragma once
#include <assert.h>
#include <iostream>

template<typename T>
class CArr
{
private:
	T*		m_pData;	//�迭 �ּ�
	int		m_iCount;	//�迭�� ä���� ȸ��
	int		m_iMaxCount;//�迭�� ���� �ִ� ����

public:
	void push_back(const T& _Data);
	void resize(int _iResizeCount);
	void data() { return *m_pData; };
	void size() { return m_iCount; };
	void capacity() { return m_iMaxCount; };
	T& operator[] (int idx);

	class iterator;
	iterator begin();
	iterator end();
	iterator erase(iterator& _iter);

	void clear(){m_iCount = 0;}

public:
	CArr();		// ������
	~CArr();	// �Ҹ���

	// inner Ŭ������ �̳�Ŭ������ �����ϴ� Ŭ������ private ����� ���� ����
	class iterator
	{
	private:
		CArr*	pArr;		// iterator �� ����ų �����͸� �����ϴ� �����迭 �ּ�
		T*		pData;		// �����͵��� ���� �ּ�
		int		index;		// ����Ű�� �������� �ε���
		bool	bValid;	// ��ȿ��

	public:
		T& operator * ()
		{
			// iterator �� �˰��ִ� �ּҿ�, �����迭�� �˰��ִ� �ּҰ� �޶��� ���(���� Ȯ������ �ּҰ� �޶��� ���)
			// iterator �� end iterator �� ���
			// ����ó�� �Ѵ�.
			if (pArr->m_pData != pData || -1 == index || !bValid)
				assert(nullptr);
			
			return pData[index];
		}

		// ����
		iterator& operator ++()
		{
			// end iterator�� ���
			// ������ ���Ҵ��� �߻��Ͽ� Vector�� �ּҿ� iterator�� �ּҰ� �ٸ����
			if (pArr->m_pData != pData || -1 == index || !bValid)
				assert(nullptr);

			// iterator �� ������ �����͸� ����Ű�� �ִ� ���
			// end iterator �� �Ǿ� �Ѵ�.
			if (pArr->m_iCount - 1 == index)
				index = -1;
			else
				++index;

			return *this;
		}

		// ++ ���� ����
		iterator operator ++(int)
		{
			iterator copyIter = *this;

			++(*this);

			return copyIter;
		}

		// -- ���� ����
		iterator& operator --()
		{
			// ����ó��
			// ������ ���Ҵ��� �߻��Ͽ� Vector�� �ּҰ� iterator�� �ּҿ� �ٸ����
			// iterator�� �ε����� 0 (�������� ����Ű�� �ִ� ���)
			if (pArr->m_pData != pData || 0 == index || !bValid)
				assert(nullptr);

			// iterator�� end iterator�� ���
			if (-1 == index)
				index = pArr->m_iCount - 1;

			else
				--index;

			return *this;
		}
		// -- ���� ����
		iterator operator --(int)
		{
			iterator copyIter = *this;

			--(*this);

			return copyIter;
		}

		// �񱳿����� ==, !=
		bool operator == (const iterator& _otherIter)
		{
			if (pData == _otherIter.pData && index == _otherIter.index)
			{
				return true;
			}
			return false;
		}
		bool operator != (const iterator& _otherIter)
		{
			if (pData == _otherIter.pData && index == _otherIter.index)
			{
				return false;
			}
			return true;

			// return !(*this == _otherIter); // ������ �̷��Ե� ǥ���� �� �ִ�. : ���� ������ ==�� Ȱ���Ѵ�.
			// * �ݴ�Ǵ� �Լ��� ������ �̷������� ǥ���ϴ°� ���� �������� ������ �� �����ϰ� ������ �� �ִ�.

		}



	public:
		iterator()
			: pArr(nullptr)
			, pData(nullptr)
			, index(-1)
			, bValid(false)
		{}
		iterator(CArr* _pArr,T* _pData, int _index)
			: pArr(_pArr)
			, pData(_pData)
			, index(_index)
			, bValid(false)
		{
			if (nullptr != _pArr && 0 <= _index)
				bValid = true;
		}
		~iterator()
		{

		}
		friend class CArr;

	};
};

template<typename T>
CArr<T>::CArr()
	: m_pData(nullptr)
	, m_iCount(0)
	, m_iMaxCount(2)
{
	m_pData = new T[2];
}

template<typename T>
CArr<T>::~CArr()
{
	delete[] m_pData;
}

template<typename T>
void CArr<T>::resize(int _iResizeCount)
{
	// ���� �ִ� ���뷮 ���� �� ���� ��ġ�� Ȯ���Ϸ��� ��� 
	if (m_iMaxCount >= _iResizeCount)
	{
		assert(nullptr);
	}

	// 1. �������� ��ų ������ŭ �����Ҵ� �Ѵ�
	T* newP = new T[_iResizeCount];


	for (int i = 0; i < m_iCount; ++i)
	{
		newP[i] = m_pData[i];
	}
	delete[] m_pData;

	m_pData = newP;

	m_iMaxCount = _iResizeCount;
}

template<typename T>
T& CArr<T>::operator[](int idx)
{
	return m_pData[idx];
}

template<typename T>
typename CArr<T>::iterator CArr<T>::begin()
{
	if (0 == m_iCount)
		return iterator(this, m_pData, -1); // �����Ͱ� ���� ���, begin() == end()

	// ������ ����Ű�� iterator�� ���� ��ȯ����
	return iterator(this, m_pData, 0);
}
template<typename T>
typename CArr<T>::iterator CArr<T>::end()
{
	return iterator(this, m_pData, -1);
}

template<typename T>
typename CArr<T>::iterator CArr<T>::erase(iterator& _iter)
{
	// ����ó��
	// iterator �� ����Ű�� �迭�� ���� �����ϰ��ִ� �迭�� �ƴ� �ٸ� �迭�� ���
	// iterator �� end iterator �� ���
	if (this != _iter.pArr || end() == _iter || m_iCount <= _iter.index )
		assert(nullptr);

	// iterator �� ����Ű�� �����͸� �迭 ������ �����Ѵ�.
	int iLoopCount = m_iCount - (_iter.index + 1);

	for (int i = 0; i < iLoopCount; ++i)
	{
		m_pData[i + _iter.index] = m_pData[i + _iter.index + 1];
	}

	_iter.bValid = false;
	// ī��Ʈ ����
	--m_iCount;


	return iterator(this, m_pData, _iter.index);
}


template<typename T>
void CArr<T>::push_back(const T& _Data)
{
	if (m_iCount >= m_iMaxCount) // �迭�� ���̰� ���ڶ�°��� Ȯ��
	{
		resize(m_iMaxCount * 2);// �迭 ���� �ø�
	}
	// ������ �߰�
	m_pData[m_iCount++] = _Data;
}