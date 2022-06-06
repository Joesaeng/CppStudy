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

	virtual void OutPut() // vitrual : 가상함수
	{
		cout << "ParentOP" << endl;
	}
public:
	CParent()
		: m_i(0)
	{
		//std::cout << "Parent" << std::endl;
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
		//std::cout << "Child" << std::endl;
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
	//parent.OutPut();
	//child.OutPut();
	
	// 상속
	// 자식 or 부모 클래스는 상속관계에서 다른 클래스의 멤버를 초기화 할 수 없다
	// 생성자 호출 순서는 자식클래스 -> 부모클래스
	// 생성자 실행 순서(초기화 순서)는 부모클래스 -> 자식클래스

	// 소멸자 호출 및 실행 순서는 자식클래스 -> 부모클래스
	
	// 오버라이딩
	// 부모 클래스의 멤버함수를 자식쪽에서 재정의 함으로써, 자식 클래스에 구현된 기능이 호출되도록 한다.
	

	// 상속 and 포인터

	CParent* pParent = nullptr; // O
	// CChild* pChild = &parent; X
	
	// 자식 포인터로 부모 클래스의 주소를 받을수 없다.
	// 부모 포인터로 자식 클래스의 주소를 받는건 가능하다.

	parent.OutPut();
	pParent = &parent;
	pParent->OutPut();

	child.OutPut();
	pParent = &child;
	pParent->OutPut();

	// 다형성, 가상함수(virtual)
	// 부모 포인터 타입으로, 부모 클래스로부터 파생되는 자식클래스 객체들의 주소를 가리킬 수 있다.
	// 모든 객체를 부모 클래스 타입으로 인식하게 되기 때문에, 실제 객체가 무엇인지 알 수 없다.
	// virtual 키워드를 통해서, 각 클래스는 자신만의 고유한 가상함수 테이블을 가지게 된다.
	// 각 클래스의 객체들은 가상함수 테이블 포인터에서 해당 클래스에 맞는 테이블을 가리키게 된다.
	// 그 테이블에는 해당 클래스의 가상함수들이 등록

	// 다운 캐스팅
	// 부모 클래스에서 선언되지 않은, 오직 자식쪽에서만 추가된 함수를 호출 하고 싶을 때
	// 자식 포인터타입으로 일시적으로 캐스팅 해서 호출한다.
	// 문제가 발생할 수 있기 때문에 dynamic_cast 로 안전하게 확인해 볼 수 있다.
	// RTTI(Run Time Type Identification or Information)
	// 
	// 추상화
	// 실제 객체를 생성할 목적의 클래스가 아닌, 상속을 통해서 구현해야할 내용을 전달하는 상속 목적으로 만들어진 클래스
	// virtual, = 0 (1개 이상의 순수가상함수를 포함하면 추상클래스가 된다.)
	//


	return 0;
}