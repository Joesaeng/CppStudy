#include <iostream>
#include <map>
#include <set>

#include <string>

#include "cBST.h"

using std::map;
using std::make_pair;
using std::set;
using std::cout;
using std::endl;
using std::wcout;
using std::wstring;

#define MAN		1
#define WOMAN	2

// Tree : 트리
// 자식 노드의 개수가 2개 이하인 트리를 이진트리라고 한다.
// 부모가 없는 노드, 최상위 노드 : 루트 노드(Root node)
// 자식이 없는 노드, 단말 노드 : 리프 노드(Leaf node)
//
// 완전 이진 트리
// 루트 노드 부터 시작해서 자식노드의 개수를 항상 2개로 하여 채워져나가는 노드
// 완전 이진 트리는 배열로 구현한다
//
// 이진 탐색 트리 (중위 순회를 사용) 데이터 입력 시 O(logN), 탐색 시 O(logN)의 시간복잡도를 가진다.
// 이진 트리이면서 탐색이 가능한 트리 : 부모 노드보다 작으면 왼쪽 자식노드, 크면 오른쪽 자식노드에 데이터를  채워나간다.
// 문제점 : 트리의 모양이 밸런스가 유지되지 않으면 제대로 된 탐색 효율이 나오지 않는다.
//			* 이를 해결하기 위해 자가균형 기능 필요하다(AVL, Red-Black Tree)
// 
// 전위 순회 : 부모 -> 왼쪽 자식노드 -> 오른쪽 자식노드
// 중위 순회 : 왼쪽자식노드 -> 부모노드 -> 오른쪽 자식노드
// 후위 순회 : 왼쪽 자식노드 -> 오른쪽 자식노드-> 부모노드
//
// 이진 탐색 
// 1. 데이터가 정렬되있을때
// 2. 범위를 절반씩 나눠가며 문제를 찾는 탐색

struct tStdInfo
{
	wchar_t szName[20];
	unsigned char age;
	unsigned char gender;

	tStdInfo()
		: szName{}
		, age(0)
		, gender(0)
	{}
	tStdInfo(const wchar_t* _pName, unsigned char _age, unsigned char _gender)
		: szName{}
		, age(_age)
		, gender(_gender)
	{
		wcscpy_s(szName, _pName);
	}
};


int main()
{
	setlocale(LC_ALL, "korean");
	_wsetlocale(LC_ALL, L"korean");

	set<int> setInt;

	setInt.insert(100);
	setInt.insert(100);
	setInt.insert(100);

	map<const wchar_t*, tStdInfo> mapData;

	tStdInfo info(L"김개똥", 20, MAN);
	tStdInfo info2(L"홍길똥", 30, WOMAN);

	mapData.insert(make_pair(L"김개똥", info));
	mapData.insert(make_pair(L"홍길똥", info2));

	map<const wchar_t*, tStdInfo>::iterator mapIter;
	mapIter = mapData.find(L"임개똥");

	if (mapIter == mapData.end())
		wcout << L"데이터를 찾을수 없다." << endl;
	else
	{
		wcout << L"이름 : " << mapIter->second.szName << endl;
		wcout << L"나이 : " << mapIter->second.age << endl;
		wcout << L"성별 : ";
		mapIter->second.gender == MAN ? wcout << L"남자" << endl : wcout << L"여자" << endl;
	}

	map<wstring, tStdInfo> mapStdInfo;

	wstring str;
	str = L"abcdeFU ";
	str += L"as your mom";
	str[1] = L'v';

	str = L"봄여름가을겨울";

	wstring str2;
	if (str < str2)
	{

	}

	cBST<int, int> cBstInt;
	tPair<int, int> pair;

	pair.first = 100;
	cBstInt.insert(pair);
	pair.first = 150;
	cBstInt.insert(pair);
	pair.first = 50;
	cBstInt.insert(pair);


	return 0;
}