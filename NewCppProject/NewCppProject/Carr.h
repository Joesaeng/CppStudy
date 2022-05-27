#pragma once
#include <assert.h>
#include <iostream>

template<typename T>
class Carr
{
private:
	T*	m_pData;		//배열 주소
	int		m_iCount;	//배열의 채워진 회수
	int		m_iMaxCount;//배열의 현재 최대 길이

public:
	void push_back(const T& _Data);
	void resize(int _iResizeCount);

	T& operator[] (int idx);

public:
	Carr();		// 생성자
	~Carr();	// 소멸자
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
	// 현재 최대 수용량 보다 더 적은 수치로 확장하려는 경우 
	if (m_iMaxCount >= _iResizeCount)
	{
		assert(nullptr);
	}

	// 1. 리사이즈 시킬 개수만큼 동적할당 한다
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
	if (m_iCount >= m_iMaxCount) // 배열의 길이가 모자라는것을 확인
	{
		resize(m_iMaxCount * 2);// 배열 길이 늘림
	}
	// 데이터 추가
	m_pData[m_iCount++] = _Data;
}