#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>


// ����ü�� ������
typedef struct _tagMyST
{
	int a; // ���
	float f;
}MYST;


int main()
{
	MYST a = {};
	
	MYST* pST = &a;

	(*pST).a = 100;
	(*pST).f = 3.14f;
	// �� �Ʒ� ���� ��������
	pST->a = 100;
	pST->f = 3.14f;



	

	return 0;
}