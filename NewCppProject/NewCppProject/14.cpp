#include <iostream>
#include "Arr_.h"
#include "Carr.h"
#include "cLinkedList.h"

class CTest
{
	int a;
	
public:
	CTest()
		: a(10)
	{}
};

template<typename T>
T Add(T a, T b)
{
	return a + b;
}
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

	Carr<int> carr;
	carr.push_back(10);
	carr.push_back(210);
	carr.push_back(130);

	int iData = carr[1];
	carr[1] = 200;

	printf("%d\n", carr[1]);
	printf("%d\n", carr[0]);
	printf("%d\n", carr[2]);

	// �Լ� ���ø�
	int i = Add<int>(10, 20);

	Carr<float> cArrF;

	cArrF.push_back(3.14f);
	cArrF.push_back(4.534f);
	cArrF.push_back(3515.f);
	cArrF.push_back(1212.5f);
	printf("%f\n", cArrF[0]);
	printf("%f\n", cArrF[1]);
	printf("%f\n", cArrF[2]);
	printf("%f\n", cArrF[3]);

	// ���ø� ����Ʈ
	cLinkedList<int> cList;

	for (int i = 0; i < 4; ++i)
	{
		cList.pushBack(i);
	}

	// C printf ��ü
	std::cout << "�ȳ�" << 10 << std::endl;

	// C scanf ��ü
	int iInput= 0 ;
	std::cin >> iInput;

	return 0;
}