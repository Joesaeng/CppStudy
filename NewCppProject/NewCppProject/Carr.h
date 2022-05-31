#pragma once
#include <assert.h>
#include <iostream>

template<typename T>
class Carr
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

public:
	Carr();		// ������
	~Carr();	// �Ҹ���

	// inner Ŭ������ �̳�Ŭ������ �����ϴ� Ŭ������ private ����� ���� ����
	class iterator
	{
	private:
		Carr*	pArr;		// iterator �� ����ų �����͸� �����ϴ� �����迭 �ּ�
		T*		pData;		// �����͵��� ���� �ּ�
		int		index;		// ����Ű�� �������� �ε���

	public:
		T& operator * ()
		{
			// iterator �� �˰��ִ� �ּҿ�, �����迭�� �˰��ִ� �ּҰ� �޶��� ���(���� Ȯ������ �ּҰ� �޶��� ���)
			// iterator �� end iterator �� ���
			// ����ó�� �Ѵ�.
			if (pArr->m_pData != pData || -1 == index)
				assert(nullptr);
			
			return pData[index];
		}

		// ����
		iterator& operator ++()
		{
			// end iterator�� ���
			// ������ ���Ҵ��� �߻��Ͽ� Vector�� �ּҿ� iterator�� �ּҰ� �ٸ����
			if (pArr->m_pData != pData || -1 == index)
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
			if (pArr->m_pData != pData || 0 == index)
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
		{}
		iterator(Carr* _pArr,T* _pData, int _index)
			: pArr(_pArr)
			, pData(_pData)
			, index(_index)
		{}
		~iterator()
		{

		}
	};
};

template<typename T>
Carr<T>::Carr()
	: m_pData(nullptr)
	, m_iCount(0)
	, m_iMaxCount(2)
{
	m_pData = new T[2];
}

template<typename T>
Carr<T>::~Carr()
{
	delete[] m_pData;
}

template<typename T>
void Carr<T>::resize(int _iResizeCount)
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
T& Carr<T>::operator[](int idx)
{
	return m_pData[idx];
}

template<typename T>
typename Carr<T>::iterator Carr<T>::begin()
{
	if (0 == m_iCount)
		return iterator(this, m_pData, -1); // �����Ͱ� ���� ���, begin() == end()
	// ������ ����Ű�� iterator�� ���� ��ȯ����
	return iterator(this, m_pData, 0);
}
template<typename T>
typename Carr<T>::iterator Carr<T>::end()
{
	return iterator(this, m_pData, -1);
}


template<typename T>
void Carr<T>::push_back(const T& _Data)
{
	if (m_iCount >= m_iMaxCount) // �迭�� ���̰� ���ڶ�°��� Ȯ��
	{
		resize(m_iMaxCount * 2);// �迭 ���� �ø�
	}
	// ������ �߰�
	m_pData[m_iCount++] = _Data;
}