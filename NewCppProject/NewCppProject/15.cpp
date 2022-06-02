#include <iostream>

#include <vector>
#include <list>

#include "CArr.h"
#include "cLinkedList.h"


namespace MYSPACE // 네임스페이스
{
	int g_int;
}

namespace OTHERSPACE
{
	int g_int;	// 서로 다른 네임스페이스에서는 변수명을 중복으로 가져갈 수 있다.
}

// using namespace std; // 네임스페이스 없이 그 안의 기능을 사용 할 수 있다.
using std::cout; // 네임스페이스의 특정 기능만 네임스페이스 없이 사용한다  
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

	CTest(const CTest& _other) // 클래스 생성자가 하나라도 있다면 시스템 내부에서 기본 생성자를 만들어주지 않는다.
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
	
	MYSPACE::g_int = 0; // :: < 범위지정 연산자
	OTHERSPACE::g_int = 0;

	//// C printf
	//cout << "안녕" << 10 << endl;

	//wcout << L"안녕" << 10;
	//// C scanf
	//int iInput = 0;
	//cin >> iInput;

	setlocale(LC_ALL, "korean");
	_wsetlocale(LC_ALL, L"korean");

	//myCout << 10 << 20 << 30 << MyEndL;
	//myCout << L"한글" << 10<< 30;

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
	//// iterator (inner class *클래스 내부에 있는 클래스)  
	//list<int>::iterator iter = listInt.begin();
	//int iData = *iter;
	//listInt.erase(iter);

	//for (iter = listInt.begin(); iter != listInt.end(); ++iter) // iterator의 end는 마지막 데이터가 아닌 마지막데이터에서 다음을 가리키며 엔드이터레이터라 불린다
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


	// ++(전위, 후위), --, ==, !=
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

	// 1 ~ 10 을 벡터에 입력
	for (int i = 0; i < 10; ++i)
	{
		vecInt.push_back(i + 1);
	}

	// 짝수만 제거
	veciter = vecInt.begin();
	for (; veciter != vecInt.end();)
	{
		if (1 <= *veciter && *veciter <= 5)
			veciter = vecInt.erase(veciter); // 제거
		else // 제거가 되지 않았을 때
			++veciter; // 반복문 인수를 증가시킨다
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