#include <iostream>
#include "Arr_.h"

class Cmy
{
	// 접근 제한 지정자
	// private, protected(상속을 배울때 배우겠음), public
private:
	int m_i;
	float m_f;
	
public:
	void SetInt(int i)
	{
		m_i = i;
	}

	// 대입 연산자
	Cmy& operator =(const Cmy& _Other)
	{
		m_i = _Other.m_i;
		m_f = _Other.m_f;

		return *this;
	}
	Cmy& operator +(const Cmy& _Other)
	{
		m_i += _Other.m_i;
		m_f += _Other.m_f;

		return *this;

	}

public:
	// 생성자 : 객체가 만들어 질때 호출되는 함수
	Cmy() : m_i(100),m_f(3.14f) // 이니셜라이져 : 초기화
	{}

	// 소멸자
	~Cmy()
	{

	}
};


int main()
{
	// C++ 클래스 특징
	// 접근제한 지정자
	// 클래스 내의 멤버변수 or 멤버함수의 접근 레벨을 지정함
	// 
	// 생성자, 소멸자
	// 객체 생성, 소멸 시 자동으로 호출
	// 직접 만들지 않으면 기본 생성자, 기본 소멸자가 만들어짐

	// 멤버함수
	// 해당 클래스가 사용하는 전용 함수
	// 해당 클래스의 객체가 필요함
	// 멤버함수를 객체를 통해서 호출하면, 해당 객체의 주소가 this 포인터로 전달 된다.

	{
		// 레퍼런스
		// 자료형* 변수명; : 포인터 변수 선언
		// *포인터변수; : 포인터로 주소 역참조
		// &변수; : 변수의 주소값
		// 자료형& 변수명; : 레퍼런스 변수 선언

		// C++ 에 추가된 기능
		// 포인터와 유사
		// 원본을 참조한다.
		// 참조변수를 통해서 직접적으로 원본을 수정 할 수 있다. **포인터는 주소의 역참조를 통해서 수정함


		int a = 10;

		int* const p = &a;
		*p = 100;
		// 위 아래의 식의 기능은 유사하다.
		int& iRef = a;
		iRef = 100;

		const int* const p2 = &a;
		//*p2 = 10;
		// 위 아래의 식의 기능은 유사하다.
		const int& iRefConst = a;
		//iRefConst = 100;
	}

	JoArr arr = {};
	SetArr(&arr);
	AddData(&arr, 10);
	EraseArr(&arr);

	Cmy c;
	c.SetInt(10);
	Cmy c2;
	c2.SetInt(100);
	Cmy c3;
	c3.SetInt(1000);
	
	c = c2 = c3;

	c3 = c2;
	c = c3 + c2;

	return 0;
}