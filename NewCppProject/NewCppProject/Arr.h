#pragma once



typedef struct _tabArr // 가변배열 구조체
{
	int*	pInt;
	int		iCount;
	int		iMaxCount;

}tArr; //자료형

// 단축키 Ctrl + '+','.' 함수 선언 단축키

// 배열 초기화 함수
void InitArr(tArr* _pArr);

// 데이터 추가 함수
void PushBack(tArr* _pArr,int _iData);

// 배열 메모리 해제 함수
void ReleaseArr(tArr* _pArr);
