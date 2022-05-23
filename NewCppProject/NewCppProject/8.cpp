#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>

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

int main()
{
	wchar_t szName[10] = L"Seongmin";


	//int iLen = wcslen(szName);
	int iLen = GetLength(szName);

	// 문자열 이어 붙이기

	return 0;
}