#include <stdio.h>
#include <stdlib.h>

// 함수의 인자를 const 포인터로 받아옴으로써 그 변수 자체를 받아오는것보다 좋은 퍼포먼스를 기대 할 수 있다.
// const를 선언하는 이유는 const를 선언하지 않으면 함수의 인자에서 포인터를 받아오면 그 함수 안에서 포인터에 들어있는 내용을 수정할 수 있기 때문이다.
// const를 선언하여도 const를 억지로 깨서 포인터 내의 데이터를 변경할 수는 있지만 그러면 미친놈이다.
void Output(const int* pI)
{
	int i = *pI;
	
}

int main()
{
	// 1.const
	const int i = 100;

	// const 와 포인터
	int a = 0;
	int* pint = &a;

	// 포인터는 포인터가 가리키는 주소의 값을 바꿀 수 도 있고, 포인터가 가리킬 주소를 바꿀수도 있다
	*pint = 1;
	pint = nullptr;

	int b = 0;
	// ============
	// const 포인터 : 초기화 시 가리키는 대상의 원본을 수정할 수 없음
	//				대상 자체가 상수화가 되는것이 아닌 포인터의 기능이 상수화가 되는 것
	// ============
	const int* pConstInt = &a;
	// int const* p = &a; << 이렇게 쓰는 사람도 있다.

	//*pConstInt = 100; : 불가
	pConstInt = &b;

	// ============
	// 포인터 const : 초기화 시 가리킨 대상을 변경할 수 없음
	// ============
	int* const pIntConst = &a;

	*pIntConst = 100;
	//pIntConst = &b; : 불가

	// ============
	// const 포인터 const : 초기화 시 가리킨 대상, 가리키는 원본을 수정 할 수 없음
	// ============
	const int* const pConstIntConst = nullptr;

	{
		int a = 0;
		const int* pInt = &a;

		// *pInt = 100; : 불가
		a = 100;

		int* p = &a;
		*p = 100;

	}

	a = 100;
	Output(&a);
	

	// void 포인터
	// 1. 원본의 자료형을 정하지 않는다
	// 2. 자료형을 정해놓지 않기 때문의 어떤 자료형의 변수의 주소든 다 저장이 가능하다.
	// 3. 저장은 가능하나 자료형이 정해져 있지 않기 때문에 역참조는 불가능하다.
	// 4. 자료형이 정해져 있지 않기 때문에 주소 연산도 불가능하다.
	void* pVoid = nullptr;
	
	{
		int a = 0;
		float f = 0.f;
		double d = 0.;
		long long ll = 0;

		pVoid = &a;
		pVoid = &f;
		pVoid = &d;
		pVoid = &ll;

		// *pVoid;
		// pVoid + 1;
	}

	int ii = 1;
	float* pfi = (float*)&ii;
	int* pii = &ii;

	int iii = (int)*pfi;
	iii = *pii;




	return 0;
}

// 단축키
// Ctrl + Shift + Space : 함수 인자에서 사용하면 함수의 선언문을 확인할 수 있다.