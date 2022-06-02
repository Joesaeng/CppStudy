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


// ������
enum class MY_TYPE
{
	TYPE_1, // 0
	TYPE_2, // 1
	TYPE_3, // 2
	TYPE_4 = 100,
	TYPE_5 // 101 *�߰��� ���ڸ� �����ϸ� �� ���� Ÿ�Կ� ���ڸ����������ʴ´ٸ� ++�ȴ�

};

enum class OTHER_TYPE
{
	TYPE_1,
};

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


int main()
{


	cBST<int, int> cBstInt;

	cBstInt.insert(makeBstpair(100, 0));
	cBstInt.insert(makeBstpair(150, 0));
	cBstInt.insert(makeBstpair(50, 0));

	cBST<int, int>::iterator Iter = cBstInt.begin();
	Iter = cBstInt.find(150);

	return 0;
}