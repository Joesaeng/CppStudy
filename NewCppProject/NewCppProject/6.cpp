#include <stdlib.h>
#include <stdio.h>

void Test(int* a)
{
	*a = 500;
}

int main()
{
	// ������ ����
	// �ڷ��� ������ // ������ ������ ��
	int* pInt = nullptr;

	// �ּҸ� ����
	// ������ ������ 8byte �̴� * �츮�� �ü���� 64bit(8byte)�̱� ���� (�ü���� 32bit��� �ּҸ� �����ϴ� ������ 4byte�� �ȴ�)

	char* pChar = nullptr;
	short* pShort = nullptr;

	int iSize = sizeof(pInt);

	int i = 0;
	pInt = &i; //i�� ���� �ּҿ������� i��ŭ(4byte)�� �ּҰ�

	pInt += 1;	// �ּҰ��� �ϳ� ������Ų��. ���� ��� ���� ��ġ�� 100�̶�� 101�� �Ǵ� ���� �ƴϰ� 
				// pInt�� int�� ������ �����̱� ������ 100���� int��(4byte)��ŭ ������ 104�� �ȴ�.
				// �׷��Ƿ� �翬�� char �������� ������ char��(1byte)��, short �����ʹ� short��(2byte) �� �����ϰ� �ȴ�.
				// * �ּ��� �ܰ踦 �����Ѵٰ� �����ϸ� �� �� ����.
	
	
	// �����Ϳ� �迭
	// �迭�� Ư¡
	// 1. �޸𸮰� �������� �����̴�.
	// 2. �迭�� �̸��� �迭�� ���� �ּ��̴�.

	int iArr[10] = {};
	
	//int ������ ����
	*(iArr) = 10;		// iArr[0] = 10
	*(iArr + 1) = 10;	// iArr[1] = 10


	// ������ ���� Ȯ�� ����
	// ���� 1. 
	short sArr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	
	int* pI = (int*)sArr;

	int iData = *((short*)(pI + 2));

	printf("1�� ���� ���� : %d\n", iData);


	// ���� 2.
	char cArr[2] = { 1, 1 };
	
	short* pS = (short*)cArr;

	iData = *pS;

	printf("2�� ���� ���� : %d\n", iData);


	int a = 100;
	
	Test(&a);

	printf("��� : %d\n", a);



	return 0;
}