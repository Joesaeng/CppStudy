#pragma once


// �����迭 : �迭 ������ �ּҸ� �� ������ �Ҵ������ν� ��Ÿ�� �߿��� �迭�� ���̸� ��ȭ�Ҽ� �ְ� ���� �迭

typedef struct JoArr // �迭�� �ڷ��� ����
{
	int*	pInt;
	int		count;
	int		maxCount;
}JoArr;

// �����迭 �ڷ����� ����Ʈ�� �Լ�

// 1. �迭�� �� ���� ������ �Ҵ�
void SetArr(JoArr* pArr);


// 2. �迭�� ������ ����
void AddData(JoArr* pArr, int data);




// 4. �� ������ �Ҵ�� ������ ����
void EraseArr(JoArr* pArr);