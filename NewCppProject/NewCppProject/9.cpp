#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>


// 구조체와 포인터
typedef struct _tagMyST
{
	int a; // 멤버
	float f;
}MYST;


int main()
{
	MYST a = {};
	
	MYST* pST = &a;

	(*pST).a = 100;
	(*pST).f = 3.14f;
	// 위 아래 식은 같은거임
	pST->a = 100;
	pST->f = 3.14f;



	

	return 0;
}