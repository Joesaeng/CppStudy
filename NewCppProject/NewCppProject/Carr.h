#pragma once
#include <assert.h>
#include <iostream>

template<typename T>
class CArr
{
private:
	T*		m_pData;	//배열 주소
	int		m_iCount;	//배열이 채워진 회수
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
	iterator erase(iterator& _iter);

	void clear(){m_iCount = 0;}

public:
	CArr();		// 생성자
	~CArr();	// 소멸자

	// inner 클래스는 이너클래스를 포함하는 클래스의 private 멤버에 접근 가능
	class iterator
	{
	private:
		CArr*	pArr;		// iterator 가 가리킬 데이터를 관리하는 가변배열 주소
		T*		pData;		// 데이터들의 시작 주소
		int		index;		// 가리키는 데이터의 인덱스
		bool	bValid;	// 유효성

	public:
		T& operator * ()
		{
			// iterator 가 알고있는 주소와, 가변배열이 알고있는 주소가 달라진 경우(공간 확장으로 주소가 달라진 경우)
			// iterator 가 end iterator 일 경우
			// 예외처리 한다.
			if (pArr->m_pData != pData || -1 == index || !bValid)
				assert(nullptr);
			
			return pData[index];
		}

		// 전위
		iterator& operator ++()
		{
			// end iterator인 경우
			// 데이터 재할당이 발생하여 Vector의 주소와 iterator의 주소가 다른경우
			if (pArr->m_pData != pData || -1 == index || !bValid)
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
			if (pArr->m_pData != pData || 0 == index || !bValid)
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
T& CArr<T>::operator[](int idx)
{
	return m_pData[idx];
}

template<typename T>
typename CArr<T>::iterator CArr<T>::begin()
{
	if (0 == m_iCount)
		return iterator(this, m_pData, -1); // 데이터가 없는 경우, begin() == end()

	// 시작을 가리키는 iterator를 만들어서 반환해줌
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
	// 예외처리
	// iterator 가 가리키는 배열이 현재 관리하고있는 배열이 아닌 다른 배열인 경우
	// iterator 가 end iterator 인 경우
	if (this != _iter.pArr || end() == _iter || m_iCount <= _iter.index )
		assert(nullptr);

	// iterator 가 가리키는 데이터를 배열 내에서 제거한다.
	int iLoopCount = m_iCount - (_iter.index + 1);

	for (int i = 0; i < iLoopCount; ++i)
	{
		m_pData[i + _iter.index] = m_pData[i + _iter.index + 1];
	}

	_iter.bValid = false;
	// 카운트 감소
	--m_iCount;


	return iterator(this, m_pData, _iter.index);
}


template<typename T>
void CArr<T>::push_back(const T& _Data)
{
	if (m_iCount >= m_iMaxCount) // 배열의 길이가 모자라는것을 확인
	{
		resize(m_iMaxCount * 2);// 배열 길이 늘림
	}
	// 데이터 추가
	m_pData[m_iCount++] = _Data;
}