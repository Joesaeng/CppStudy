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

// Tree : Ʈ��
// �ڽ� ����� ������ 2�� ������ Ʈ���� ����Ʈ����� �Ѵ�.
// �θ� ���� ���, �ֻ��� ��� : ��Ʈ ���(Root node)
// �ڽ��� ���� ���, �ܸ� ��� : ���� ���(Leaf node)
//
// ���� ���� Ʈ��
// ��Ʈ ��� ���� �����ؼ� �ڽĳ���� ������ �׻� 2���� �Ͽ� ä���������� ���
// ���� ���� Ʈ���� �迭�� �����Ѵ�
//
// ���� Ž�� Ʈ�� (���� ��ȸ�� ���) ������ �Է� �� O(logN), Ž�� �� O(logN)�� �ð����⵵�� ������.
// ���� Ʈ���̸鼭 Ž���� ������ Ʈ�� : �θ� ��庸�� ������ ���� �ڽĳ��, ũ�� ������ �ڽĳ�忡 �����͸�  ä��������.
// ������ : Ʈ���� ����� �뷱���� �������� ������ ����� �� Ž�� ȿ���� ������ �ʴ´�.
//			* �̸� �ذ��ϱ� ���� �ڰ����� ��� �ʿ��ϴ�(AVL, Red-Black Tree)
// 
// ���� ��ȸ : �θ� -> ���� �ڽĳ�� -> ������ �ڽĳ��
// ���� ��ȸ : �����ڽĳ�� -> �θ��� -> ������ �ڽĳ��
// ���� ��ȸ : ���� �ڽĳ�� -> ������ �ڽĳ��-> �θ���
//
// ���� Ž�� 
// 1. �����Ͱ� ���ĵ�������
// 2. ������ ���ݾ� �������� ������ ã�� Ž��

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

	tStdInfo info(L"�谳��", 20, MAN);
	tStdInfo info2(L"ȫ���", 30, WOMAN);

	mapData.insert(make_pair(L"�谳��", info));
	mapData.insert(make_pair(L"ȫ���", info2));

	map<const wchar_t*, tStdInfo>::iterator mapIter;
	mapIter = mapData.find(L"�Ӱ���");

	if (mapIter == mapData.end())
		wcout << L"�����͸� ã���� ����." << endl;
	else
	{
		wcout << L"�̸� : " << mapIter->second.szName << endl;
		wcout << L"���� : " << mapIter->second.age << endl;
		wcout << L"���� : ";
		mapIter->second.gender == MAN ? wcout << L"����" << endl : wcout << L"����" << endl;
	}

	map<wstring, tStdInfo> mapStdInfo;

	wstring str;
	str = L"abcdeFU ";
	str += L"as your mom";
	str[1] = L'v';

	str = L"�����������ܿ�";

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