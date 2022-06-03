#include <iostream>
#include <map>
#include <set>
#include <string>

#include "cBST.h"

using std::cout;
using std::endl;

class CParent
{
protected: // 자식 객체가 부모 객체의 멤버에 접근할 수 있게 해준다
	int		m_i;

public:
	void SetInt(int _a)
	{
		m_i = _a;
	}

	void OutPut()
	{
		cout << "ParentOP" << endl;
	}
public:
	CParent()
		: m_i(0)
	{
		std::cout << "Parent" << std::endl;
	}
	CParent(int _a)
		:m_i(_a)
	{}
	~CParent()
	{
		std::cout << "PerentDie" << std::endl;

	}
};

class CChild : public CParent
{
private:
	float m_f;
public:
	void SetFloat(float _f)
	{
		m_f = _f;
		m_i = 100; //상속받은 부모의 private 선언된 멤버는 접근할 수 없지만, protected 선언이 되있다면 접근이 가능하다
	}
	// 상속받은 부모클래스의 함수를 재정의(오버라이딩)
	void OutPut()
	{
		cout << "ChildOP" << endl;
	}
public:
	CChild()
		: CParent(1000)
		,m_f(0.f)
	{
		std::cout << "Child" << std::endl;
	}
	~CChild()
	{
		std::cout << "ChildDie" << std::endl;
	}
};

int main()
{
	// 객체지향 언어 특징
	// 1. 캡슐화 (은닉성)
	// 2. 상속
	// 3. 다형성
	// 4. 추상화

	CParent parent;
	CChild child; 

	parent.SetInt(10);
	child.SetInt(10);
	parent.OutPut();
	child.OutPut();
	
	// 상속
	// 자식 or 부모 클래스는 상속관계에서 다른 클래스의 멤버를 초기화 할 수 없다
	// 생성자 호출 순서는 자식클래스 -> 부모클래스
	// 생성자 실행 순서(초기화 순서)는 부모클래스 -> 자식클래스
	
	// 오버라이딩
	// 부모 클래스의 멤버함수를 자식쪽에서 재정의 함으로써, 자식 클래스에 구현된 기능이 호출되도록 한다.
	




	return 0;
}