#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>

unsigned int GetLength(const wchar_t* _pStr)
{
	int i = 0; // ���� ���� üũ ����
	while (true)
	{
		wchar_t c = *(_pStr + i); // *(_pStr + i) = _pStr[i]

		if ('\0' == c) // '\0' : Null ���� // *�񱳹����� ����� ���ʿ� �θ� Ȥ�� �Ǽ��Ͽ� ��ȣ�� �ϳ��� ������ �����Ͽ��� ������ ���⶧���� ã�Ⱑ ����
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

	// ���ڿ� �̾� ���̱�

	return 0;
}