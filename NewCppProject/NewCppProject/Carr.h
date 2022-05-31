#pragma once
#include <assert.h>
#include <iostream>

template<typename T>
class Carr
{
private:
	T*		m_pData;	//배열 주소
	int		m_iCount;	//배열의 채워진 회수
	int		m_iMaxCount;//배열의 현재 최대 길이

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
	Carr();		// 생성자
	~Carr();	// 소멸자

	// inner 클래스는 이너클래스를 포함하는 클래스의 private 멤버에 접근 가능
	class iterator
	{
	private:
		Carr*	pArr;		// iterator 가 가리킬 데이터를 관리하는 가변배열 주소
		T*		pData;		// 데이터들의 시작 주소
		int		index;		// 가리키는 데이터의 인덱스

	public:
		T& operator * ()
		{
			// iterator 가 알고있는 주소와, 가변배열이 알고있는 주소가 달라진 경우(공간 확장으로 주소가 달라진 경우)
			// iterator 가 end iterator 일 경우
			// 예외처리 한다.
			if (pArr->m_pData != pData || -1 == index)
				assert(nullptr);
			
			return pData[index];
		}

		// 전위
		iterator& operator ++()
		{
			// end iterator인 경우
			// 데이터 재할당이 발생하여 Vector의 주소와 iterator의 주소가 다른경우
			if (pArr->m_pData != pData || -1 == index)
				assert(nullptr);

			// iterator 가 마지막 데이터를 가리키고 있는 경우
			// end iterator 가 되야 한다.
			if (pArr->m_iCount - 1 == index)
				index = -1;
			else
				++index;

			return *this;
		}

		// ++ 후위 연산
		iterator operator ++(int)
		{
			iterator copyIter = *this;

			++(*this);

			return copyIter;
		}

		// -- 전위 연산
		iterator& operator --()
		{
			// 예외처리
			// 데이터 재할당이 발생하여 Vector의 주소가 iterator의 주소와 다른경우
			// iterator의 인덱스가 0 (시작점을 가리키고 있는 경우)
			if (pArr->m_pData != pData || 0 == index)
				assert(nullptr);

			// iterator가 end iterator인 경우
			if (-1 == index)
				index = pArr->m_iCount - 1;

			else
				--index;

			return *this;
		}
		// -- 후위 연산
		iterator operator --(int)
		{
			iterator copyIter = *this;

			--(*this);

			return copyIter;
		}

		// 비교연산자 ==, !=
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

			// return !(*this == _otherIter); // 간단히 이렇게도 표현할 수 있다. : 위에 구현한 ==을 활용한다.
			// * 반대되는 함수가 있으면 이런식으로 표현하는게 추후 변경점이 생겼을 때 용이하게 수정할 수 있다.

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
typename Carr<T>::iterator Carr<T>::begin()
{
	if (0 == m_iCount)
		return iterator(this, m_pData, -1); // 데이터가 없는 경우, begin() == end()
	// 시작을 가리키는 iterator를 만들어서 반환해줌
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
	if (m_iCount >= m_iMaxCount) // 배열의 길이가 모자라는것을 확인
	{
		resize(m_iMaxCount * 2);// 배열 길이 늘림
	}
	// 데이터 추가
	m_pData[m_iCount++] = _Data;
}