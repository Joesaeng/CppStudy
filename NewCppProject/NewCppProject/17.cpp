#include <iostream>
#include <map>
#include <set>
#include <string>

#include "cBST.h"

using std::cout;
using std::endl;

class CParent
{
protected: // �ڽ� ��ü�� �θ� ��ü�� ����� ������ �� �ְ� ���ش�
	int		m_i;

public:
	void SetInt(int _a)
	{
		m_i = _a;
	}

	void OutPut()
	{
		cout << "ParentOP" << endl;
	}
public:
	CParent()
		: m_i(0)
	{
		std::cout << "Parent" << std::endl;
	}
	CParent(int _a)
		:m_i(_a)
	{}
	~CParent()
	{
		std::cout << "PerentDie" << std::endl;

	}
};

class CChild : public CParent
{
private:
	float m_f;
public:
	void SetFloat(float _f)
	{
		m_f = _f;
		m_i = 100; //��ӹ��� �θ��� private ����� ����� ������ �� ������, protected ������ ���ִٸ� ������ �����ϴ�
	}
	// ��ӹ��� �θ�Ŭ������ �Լ��� ������(�������̵�)
	void OutPut()
	{
		cout << "ChildOP" << endl;
	}
public:
	CChild()
		: CParent(1000)
		,m_f(0.f)
	{
		std::cout << "Child" << std::endl;
	}
	~CChild()
	{
		std::cout << "ChildDie" << std::endl;
	}
};

int main()
{
	// ��ü���� ��� Ư¡
	// 1. ĸ��ȭ (���м�)
	// 2. ���
	// 3. ������
	// 4. �߻�ȭ

	CParent parent;
	CChild child; 

	parent.SetInt(10);
	child.SetInt(10);
	parent.OutPut();
	child.OutPut();
	
	// ���
	// �ڽ� or �θ� Ŭ������ ��Ӱ��迡�� �ٸ� Ŭ������ ����� �ʱ�ȭ �� �� ����
	// ������ ȣ�� ������ �ڽ�Ŭ���� -> �θ�Ŭ����
	// ������ ���� ����(�ʱ�ȭ ����)�� �θ�Ŭ���� -> �ڽ�Ŭ����
	
	// �������̵�
	// �θ� Ŭ������ ����Լ��� �ڽ��ʿ��� ������ �����ν�, �ڽ� Ŭ������ ������ ����� ȣ��ǵ��� �Ѵ�.
	




	return 0;
}