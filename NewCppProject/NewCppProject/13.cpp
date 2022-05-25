#include <iostream>
#include "Arr_.h"

class Cmy
{
	// ���� ���� ������
	// private, protected(����� ��ﶧ ������), public
private:
	int m_i;
	float m_f;
	
public:
	void SetInt(int i)
	{
		m_i = i;
	}

	// ���� ������
	Cmy& operator =(const Cmy& _Other)
	{
		m_i = _Other.m_i;
		m_f = _Other.m_f;

		return *this;
	}
	Cmy& operator +(const Cmy& _Other)
	{
		m_i += _Other.m_i;
		m_f += _Other.m_f;

		return *this;

	}

public:
	// ������ : ��ü�� ����� ���� ȣ��Ǵ� �Լ�
	Cmy() : m_i(100),m_f(3.14f) // �̴ϼȶ����� : �ʱ�ȭ
	{}

	// �Ҹ���
	~Cmy()
	{

	}
};


int main()
{
	// C++ Ŭ���� Ư¡
	// �������� ������
	// Ŭ���� ���� ������� or ����Լ��� ���� ������ ������
	// 
	// ������, �Ҹ���
	// ��ü ����, �Ҹ� �� �ڵ����� ȣ��
	// ���� ������ ������ �⺻ ������, �⺻ �Ҹ��ڰ� �������

	// ����Լ�
	// �ش� Ŭ������ ����ϴ� ���� �Լ�
	// �ش� Ŭ������ ��ü�� �ʿ���
	// ����Լ��� ��ü�� ���ؼ� ȣ���ϸ�, �ش� ��ü�� �ּҰ� this �����ͷ� ���� �ȴ�.

	{
		// ���۷���
		// �ڷ���* ������; : ������ ���� ����
		// *�����ͺ���; : �����ͷ� �ּ� ������
		// &����; : ������ �ּҰ�
		// �ڷ���& ������; : ���۷��� ���� ����

		// C++ �� �߰��� ���
		// �����Ϳ� ����
		// ������ �����Ѵ�.
		// ���������� ���ؼ� ���������� ������ ���� �� �� �ִ�. **�����ʹ� �ּ��� �������� ���ؼ� ������


		int a = 10;

		int* const p = &a;
		*p = 100;
		// �� �Ʒ��� ���� ����� �����ϴ�.
		int& iRef = a;
		iRef = 100;

		const int* const p2 = &a;
		//*p2 = 10;
		// �� �Ʒ��� ���� ����� �����ϴ�.
		const int& iRefConst = a;
		//iRefConst = 100;
	}

	JoArr arr = {};
	SetArr(&arr);
	AddData(&arr, 10);
	EraseArr(&arr);

	Cmy c;
	c.SetInt(10);
	Cmy c2;
	c2.SetInt(100);
	Cmy c3;
	c3.SetInt(1000);
	
	c = c2 = c3;

	c3 = c2;
	c = c3 + c2;

	return 0;
}