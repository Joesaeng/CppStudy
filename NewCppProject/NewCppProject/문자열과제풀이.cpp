#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>

// ������ ���ڿ��� �쿭�� Ȯ���ؼ� ������ ������ 1, ������ ������ -1, �����ϸ� 0�� ������ �Լ�
// 1. ������ ���ڿ��� �޾ƿ´�.
// 2. ������ �� �ε������� ���ϴ� �ݺ����� ����� (�쿭�� �ƽ�Ű�ڵ�� Ȯ���Ҽ� �ִ�. �ƽ�Ű�ڵ尡 ���� ��� �켱)
// 3. 1���� ���ڿ��� �� . �������, �ٸ����

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