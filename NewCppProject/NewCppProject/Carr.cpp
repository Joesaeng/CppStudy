#include "Carr.h"
#include <iostream>
#include <assert.h>

Carr::Carr()
	: m_pInt(nullptr)
	, m_iCount(0)
	, m_iMaxCount(2)
{
	m_pInt = new int[2];
}

Carr::~Carr()
{
	delete[] m_pInt;
}

void Carr::resize(int _iResizeCount)
{
	// ���� �ִ� ���뷮 ���� �� ���� ��ġ�� Ȯ���Ϸ��� ��� 
	if (m_iMaxCount >= _iResizeCount)
	{
		assert(nullptr);
	}

	// 1. �������� ��ų ������ŭ �����Ҵ� �Ѵ�
	int* newP = new int[_iResizeCount];


	for (int i = 0; i < m_iCount; ++i)
	{
		newP[i] = m_pInt[i];
	}
	delete[] m_pInt;

	m_pInt = newP;
	
	m_iMaxCount = _iResizeCount;
}

int& Carr::operator[](int idx)
{
	return m_pInt[idx];
}



void Carr::push_back(int _Data)
{
	if (m_iCount >= m_iMaxCount) // �迭�� ���̰� ���ڶ�°��� Ȯ��
	{
		resize(m_iMaxCount * 2);// �迭 ���� �ø�
	}
	// ������ �߰�
	m_pInt[m_iCount++] = _Data;
}


