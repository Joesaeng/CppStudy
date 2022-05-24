#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>

#include <assert.h>


// ** �����ϰ��� �ϴ� ����� ����ؼ� ������� �����صδ� ������ ������



// �Լ� �����ε�  : �Լ��� �̸��� ������ ������ Ÿ���̳� ������ ������ ���� ������ ������ �̸��� ���������� �Լ��� ������� �� �ִ°�
void Test(int a)
{

}

void Test(int a, float b)
{

}



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

void StrCat(wchar_t* _pDest, unsigned int _iBufferSize, const wchar_t* _pSrc)
{
	int iDestLen = GetLength(_pDest);
	int iSrcLen = GetLength(_pSrc);
	if (_iBufferSize < iDestLen + iSrcLen + 1)/*Null���� �������� ���*/
	{
		assert(nullptr);
	}
	// �̾���� ���� ���ڿ� ���̰� ������ ���� ������ �Ѿ���� ��� ����ó��

	// ���ڿ� �̾� ���̱�
	// 1. Dest ���ڿ��� ���ڸ� ã��(���ڿ��� �̾� ���� �ڸ�) // Dest�� ���̸� ������ ���س��ұ� ������ Dest���ڿ��� ���ڸ��� �� ���̸� �ε����� ������ �ڸ��� �ȴ�.
	// 2. �ݺ������� Src ���ڿ��� Dest �� ��ġ�� �����ϱ�
	// 3. Src ���ڿ��� ���� ������ �ݺ� ����
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
	Test(1); // �Լ� �����ε�

	// ���ڿ� �̾� ���̱�
	
	wchar_t szString[10] = L"abc";
	StrCat(szString, 10, L"def");
	
	int iRet = wcscmp(L"abc",L"abc");



	return 0;
}