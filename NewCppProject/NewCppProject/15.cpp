#include <iostream>

#include <vector>
#include <list>

#include "CArr.h"
#include "cLinkedList.h"


namespace MYSPACE // ���ӽ����̽�
{
	int g_int;
}

namespace OTHERSPACE
{
	int g_int;	// ���� �ٸ� ���ӽ����̽������� �������� �ߺ����� ������ �� �ִ�.
}

// using namespace std; // ���ӽ����̽� ���� �� ���� ����� ��� �� �� �ִ�.
using std::cout; // ���ӽ����̽��� Ư�� ��ɸ� ���ӽ����̽� ���� ����Ѵ�  
using std::wcout;
using std::endl;
using std::cin;
using std::vector;
using std::list;

class CTest
{
public:
	int i;

public:
	CTest& operator =(const CTest& _other)
	{
		i = _other.i;
		return *this;
	}

	CTest(const CTest& _other) // Ŭ���� �����ڰ� �ϳ��� �ִٸ� �ý��� ���ο��� �⺻ �����ڸ� ��������� �ʴ´�.
		: i(_other.i)
	{}
	CTest()
		:i(0)
	{}
	~CTest()
	{}

};

void MyEndL()
{
	wprintf(L"\n");
}

class MyOStream
{

public:
	MyOStream& operator << (int _Data)
	{
		printf("%d", _Data);
		return *this;
	}
	MyOStream& operator << (const wchar_t* _pString)
	{
		wprintf(L"%s", _pString);
		return *this;
	}
	MyOStream& operator >> (int& _Data)
	{
		scanf_s("%d", &_Data);
		return *this;
	}
	MyOStream& operator << (void(*_pFunc)(void))
	{
		_pFunc();
		return *this;
	}
};

MyOStream myCout;
int main()
{
	
	MYSPACE::g_int = 0; // :: < �������� ������
	OTHERSPACE::g_int = 0;

	//// C printf
	//cout << "�ȳ�" << 10 << endl;

	//wcout << L"�ȳ�" << 10;
	//// C scanf
	//int iInput = 0;
	//cin >> iInput;

	setlocale(LC_ALL, "korean");
	_wsetlocale(LC_ALL, L"korean");

	//myCout << 10 << 20 << 30 << MyEndL;
	//myCout << L"�ѱ�" << 10<< 30;

	//int a = 0;
	//myCout >> a;

	//vector<int> vecInt;
	//vecInt.push_back(10);
	//vecInt.push_back(20);
	//
	//vector<int>::iterator veciter = vecInt.begin();
	//
	//for (int i = 0; i < 10; ++i)
	//{
	//	vecInt.push_back(i);
	//}







	//list<int> listInt;
	//listInt.push_back(10);
	//listInt.push_back(200);
	//
	//// iterator (inner class *Ŭ���� ���ο� �ִ� Ŭ����)  
	//list<int>::iterator iter = listInt.begin();
	//int iData = *iter;
	//listInt.erase(iter);

	//for (iter = listInt.begin(); iter != listInt.end(); ++iter) // iterator�� end�� ������ �����Ͱ� �ƴ� �����������Ϳ��� ������ ����Ű�� �������ͷ����Ͷ� �Ҹ���
	//{
	//	cout << *iter << endl;
	//}

	CArr<int> myVector;
	myVector.push_back(1);
	myVector.push_back(2);
	myVector.push_back(3);
	myVector.push_back(4);
	myVector.push_back(5);

	CArr<int>::iterator myIter = myVector.begin();
	myIter = myVector.erase(myIter);
	myIter = myVector.erase(myIter);
	myIter = myVector.erase(myIter);
	myIter = myVector.erase(myIter);
	myIter = myVector.erase(myIter);


	// ++(����, ����), --, ==, !=
	//for (myIter = myVector.begin(); myIter != myVector.end(); ++myIter)
	//{
	//	cout << *myIter << endl;
	//}


	//for (; myIter != myVector.end(); ++myIter)
	//{
	//	cout << *myIter << endl;
	//}
	
	//--myIter;
	//cout << *myIter << endl;
	//--myIter;
	//cout << *myIter << endl;
	//myIter--;
	//cout << *myIter << endl;


	vector<int> vecInt;

	vecInt.push_back(100);
	vecInt.push_back(200);
	vecInt.push_back(300);
	vecInt.push_back(400);

	vector<int>::iterator veciter = vecInt.begin();
	veciter = vecInt.erase(veciter);
	int i = *veciter;


	vecInt.clear();

	// 1 ~ 10 �� ���Ϳ� �Է�
	for (int i = 0; i < 10; ++i)
	{
		vecInt.push_back(i + 1);
	}

	// ¦���� ����
	veciter = vecInt.begin();
	for (; veciter != vecInt.end();)
	{
		if (1 <= *veciter && *veciter <= 5)
			veciter = vecInt.erase(veciter); // ����
		else // ���Ű� ���� �ʾ��� ��
			++veciter; // �ݺ��� �μ��� ������Ų��
	}

	for (int i = 0; i < vecInt.size(); ++i)
	{
		cout << vecInt[i] << endl;
	}

	// =============
	// list iterator
	// =============

	cLinkedList<int> myList;

	myList.pushBack(100);
	myList.pushBack(300);
	myList.pushBack(400);

	cLinkedList<int>::iterator listIter = myList.begin();
	++listIter;
	listIter = myList.insert(listIter, 200);

	cout << endl <<"=============" << endl;
	cout << "list iterator" << endl;
	cout << "=============" << endl << endl;


	for (listIter = myList.begin(); listIter != myList.end(); ++listIter)
	{
		cout << *listIter << endl;
	}

	listIter = myList.begin();
	myList.erase(listIter);



	return 0;
}