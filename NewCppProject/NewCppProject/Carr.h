#pragma once

class Carr
{
private:
	int*	m_pInt;		//배열 주소
	int		m_iCount;	//배열의 채워진 회수
	int		m_iMaxCount;//배열의 현재 최대 길이

public:
	void push_back(int _Data);
	void resize(int _iResizeCount);

	int& operator[] (int idx);

public:
	Carr();		// 생성자
	~Carr();	// 소멸자
};

