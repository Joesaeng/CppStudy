#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>

// 양측의 문자열의 우열을 확인해서 우측이 높으면 1, 좌측이 높으면 -1, 동일하면 0을 가지는 함수
// 1. 양측의 문자열을 받아온다.
// 2. 양측의 각 인덱스별로 비교하는 반복문을 만든다 (우열은 아스키코드로 확인할수 있다. 아스키코드가 작은 경우 우선)
// 3. 1번의 문자열을 비교 . 같은경우, 다른경우

int wcCompare(const wchar_t* _left, const wchar_t* _right)
{
	int i = 0;
	int j = 0;
	while (_left[i] != 0 || _right[i] != 0)
	{
		if (_left[i] != _right[i]) 
		{
			_left[i] < _right[i] ? j = -1 : j = 1;
			break; 
		}
		else
		{
			++i;
		}
	}
	return j;
}


int main()
{
	int i = wcCompare(L"abcde",L"abcdef");

	return 0;
}