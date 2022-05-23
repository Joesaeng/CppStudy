#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>


// 메모리 영역
// 1. 스택 영역
// 2. 데이터 영역
// 3. ROM(Read Only Memory)(코드) 영역
// 4. 힙 영역



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

	{
		// 문자
		// char(1), wchar(2)
		// 표현 방식은 정수형이지만, 그 정수에 대응하는 문자를 보여준다.

		char c = 'a';
		wchar_t wc = L'a';

		char szChar[10] = "abcdef";
		wchar_t szWchar[10] = L"abcdef"; //문자열의 초기화 방식, 앞의 L은 모든 문자를 2바이트 방식으로 표현하는 것

		const wchar_t* pChar = L"abcdef"; // 문자열의 포인터 주소는 ROM에 있기 때문에 읽을순 있으니 코드영역에 있는 것이기 때문에 수정할 수 없다
											// 그렇기 때문에 비주얼스튜디오 자체에서 문자열의 포인터는 const 포인터로만 읽어올 수 있다.
		short arrShort[10] = { 97, 98, 99, 100, 101, 102, };

		szWchar[1] = 'z';
		// pChar[0] = 'z';
		
		unsigned char szTestC[10] = "abc한글"; // *앞에 L이 없으면 멀티바이트 방식으로, 1바이트 문자면 1바이트, 2바이트 문자면 2바이트로 표현한다.
									// 멀티바이트 시스템은 표준으로 쓰이는 시스템은 아니며 요새는 모든 문자열을 2바이트(와이드바이트)식으로 쓴다*(유니코드 시스템)

		wchar_t szTestWc[10] = L"abc한글"; // 와이드바이트 (앞의 L)


	}

	{
		wchar_t szName[10] = L"Raimond";

		int iLen = wcslen(szName);

		int a = 0;
	}


	return 0;
}

// 단축키
// Ctrl + Shift + Space : 함수 인자에서 사용하면 함수의 선언문을 확인할 수 있다.