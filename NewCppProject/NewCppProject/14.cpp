#include <iostream>
#include "Arr_.h"
#include "Carr.h"

class CTest
{
	int a;
	
public:
	CTest()
		: a(10)
	{}
};

int main()
{
	// ����ü --> Ŭ����

	// ��ü���� ��� Ư¡
	// 1. ĸ��ȭ
	// ����� �����ϱ� ���� �ʿ��� ��� ����, ����, ���м�
	// ��� �Լ���

	// 2. ���

	// 3. ������

	// 4. �߻�ȭ

	// ����ü ���� �����迭 --> Ŭ���� ���� �����迭


	// C++ �����Ҵ� new, delete
	CTest* pTest = new CTest;
	delete pTest;

	// Carr ����
	JoArr jArr = {};
	SetArr(&jArr);

	AddData(&jArr,10);
	AddData(&jArr,210);
	AddData(&jArr,130);

	EraseArr(&jArr);

	Carr carr;
	carr.push_back(10);
	carr.push_back(210);
	carr.push_back(130);

	int iData = carr[1];

	carr[1] = 200;

	printf("%d\n", carr[1]);
	printf("%d\n", carr[0]);
	printf("%d\n", carr[2]);

	return 0;
}