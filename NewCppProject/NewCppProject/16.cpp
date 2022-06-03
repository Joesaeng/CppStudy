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


// 열거형
enum class MY_TYPE
{
	TYPE_1, // 0
	TYPE_2, // 1
	TYPE_3, // 2
	TYPE_4 = 100,
	TYPE_5 // 101 *중간에 숫자를 지정하면 그 다음 타입에 숫자를지정하지않는다면 ++된다

};

enum class OTHER_TYPE
{
	TYPE_1,
};

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


int main()
{


	cBST<int, int> cBstInt;

	cBstInt.insert(makeBstpair(100, 0)); //		      100
	cBstInt.insert(makeBstpair(150, 0)); //		 50        150
	cBstInt.insert(makeBstpair(50, 0));  //	  25    75  125    175
	cBstInt.insert(makeBstpair(25, 0));  //		                   200
	cBstInt.insert(makeBstpair(75, 0));
	cBstInt.insert(makeBstpair(125, 0));
	cBstInt.insert(makeBstpair(175, 0));
	cBstInt.insert(makeBstpair(200, 0));

	cBST<int, int>::iterator Iter;
	Iter = cBstInt.find(150);
	Iter = cBstInt.erase(Iter);
	Iter = cBstInt.find(100);
	Iter = cBstInt.erase(Iter);





	return 0;
}