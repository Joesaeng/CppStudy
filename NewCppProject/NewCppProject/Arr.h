#pragma once



typedef struct _tabArr // �����迭 ����ü
{
	int*	pInt;
	int		iCount;
	int		iMaxCount;

}tArr; //�ڷ���

// ����Ű Ctrl + '+','.' �Լ� ���� ����Ű

// �迭 �ʱ�ȭ �Լ�
void InitArr(tArr* _pArr);

// ������ �߰� �Լ�
void PushBack(tArr* _pArr,int _iData);

// �迭 �޸� ���� �Լ�
void ReleaseArr(tArr* _pArr);
