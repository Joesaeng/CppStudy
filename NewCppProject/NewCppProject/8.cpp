#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>

#include <assert.h>


// ** 구현하고자 하는 기능을 고민해서 순서대로 정리해두는 습관을 가지자



// 함수 오버로딩  : 함수의 이름은 같지만 인자의 타입이나 인자의 개수의 차이 등으로 동일한 이름의 여러가지의 함수가 만들어질 수 있는것
void Test(int a)
{

}

void Test(int a, float b)
{

}



unsigned int GetLength(const wchar_t* _pStr)
{
	int i = 0; // 문자 개수 체크 변수
	while (true)
	{
		wchar_t c = *(_pStr + i); // *(_pStr + i) = _pStr[i]

		if ('\0' == c) // '\0' : Null 문자 // *비교문에서 상수를 왼쪽에 두면 혹시 실수하여 등호를 하나만 쓰더라도 컴파일에서 오류가 나기때문에 찾기가 쉽다
		{
			break;
		}
		++i;
	}
	return i;
}

void StrCat(wchar_t* _pDest, unsigned int _iBufferSize, const wchar_t* _pSrc)
{
	int iDestLen = GetLength(_pDest);
	int iSrcLen = GetLength(_pSrc);
	if (_iBufferSize < iDestLen + iSrcLen + 1)/*Null문자 공간까지 계산*/
	{
		assert(nullptr);
	}
	// 이어붙인 최종 문자열 길이가 목적지 저장 공간은 넘어서려는 경우 예외처리

	// 문자열 이어 붙이기
	// 1. Dest 문자열의 끝자리 찾기(문자열이 이어 붙을 자리) // Dest의 길이를 위에서 구해놓았기 때문에 Dest문자열의 끝자리는 그 길이를 인덱스로 가지는 자리가 된다.
	// 2. 반복적으로 Src 문자열을 Dest 끝 위치에 복사하기
	// 3. Src 문자열의 끝을 만나면 반복 종료
	for (int i = 0; i < iSrcLen + 1; ++i)
	{
		_pDest[iDestLen + i] = _pSrc[i];
	}

}

int main()
{
	wchar_t szName[10] = L"Seongmin";


	//int iLen = wcslen(szName);
	int iLen = GetLength(szName);


	Test(1, 1.4f);
	Test(1); // 함수 오버로딩

	// 문자열 이어 붙이기
	
	wchar_t szString[10] = L"abc";
	StrCat(szString, 10, L"def");
	
	int iRet = wcscmp(L"abc",L"abc");



	return 0;
}