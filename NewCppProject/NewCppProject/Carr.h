#pragma once

class Carr
{
private:
	int*	m_pInt;		//�迭 �ּ�
	int		m_iCount;	//�迭�� ä���� ȸ��
	int		m_iMaxCount;//�迭�� ���� �ִ� ����

public:
	void push_back(int _Data);
	void resize(int _iResizeCount);

	int& operator[] (int idx);

public:
	Carr();		// ������
	~Carr();	// �Ҹ���
};

