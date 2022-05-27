#pragma once
#include <assert.h>
#include <iostream>

template<typename T>
class Carr
{
private:
	T*	m_pData;		//�迭 �ּ�
	int		m_iCount;	//�迭�� ä���� ȸ��
	int		m_iMaxCount;//�迭�� ���� �ִ� ����

public:
	void push_back(const T& _Data);
	void resize(int _iResizeCount);

	T& operator[] (int idx);

public:
	Carr();		// ������
	~Carr();	// �Ҹ���
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
void Carr<T>::push_back(const T& _Data)
{
	if (m_iCount >= m_iMaxCount) // �迭�� ���̰� ���ڶ�°��� Ȯ��
	{
		resize(m_iMaxCount * 2);// �迭 ���� �ø�
	}
	// ������ �߰�
	m_pData[m_iCount++] = _Data;
}