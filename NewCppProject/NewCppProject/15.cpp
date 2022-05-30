#include <iostream>


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

	myCout << 10 << 20 << 30 << MyEndL;
	myCout << L"한글" << 10<< 30;

	int a = 0;
	myCout >> a;

	return 0;
}