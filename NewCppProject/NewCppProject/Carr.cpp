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
	// 현재 최대 수용량 보다 더 적은 수치로 확장하려는 경우 
	if (m_iMaxCount >= _iResizeCount)
	{
		assert(nullptr);
	}

	// 1. 리사이즈 시킬 개수만큼 동적할당 한다
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
	if (m_iCount >= m_iMaxCount) // 배열의 길이가 모자라는것을 확인
	{
		resize(m_iMaxCount * 2);// 배열 길이 늘림
	}
	// 데이터 추가
	m_pInt[m_iCount++] = _Data;
}


