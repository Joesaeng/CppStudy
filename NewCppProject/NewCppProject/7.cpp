#include <stdio.h>
#include <stdlib.h>

// �Լ��� ���ڸ� const �����ͷ� �޾ƿ����ν� �� ���� ��ü�� �޾ƿ��°ͺ��� ���� �����ս��� ��� �� �� �ִ�.
// const�� �����ϴ� ������ const�� �������� ������ �Լ��� ���ڿ��� �����͸� �޾ƿ��� �� �Լ� �ȿ��� �����Ϳ� ����ִ� ������ ������ �� �ֱ� �����̴�.
// const�� �����Ͽ��� const�� ������ ���� ������ ���� �����͸� ������ ���� ������ �׷��� ��ģ���̴�.
void Output(const int* pI)
{
	int i = *pI;
	
}

int main()
{
	// 1.const
	const int i = 100;

	// const �� ������
	int a = 0;
	int* pint = &a;

	// �����ʹ� �����Ͱ� ����Ű�� �ּ��� ���� �ٲ� �� �� �ְ�, �����Ͱ� ����ų �ּҸ� �ٲܼ��� �ִ�
	*pint = 1;
	pint = nullptr;

	int b = 0;
	// ============
	// const ������ : �ʱ�ȭ �� ����Ű�� ����� ������ ������ �� ����
	//				��� ��ü�� ���ȭ�� �Ǵ°��� �ƴ� �������� ����� ���ȭ�� �Ǵ� ��
	// ============
	const int* pConstInt = &a;
	// int const* p = &a; << �̷��� ���� ����� �ִ�.

	//*pConstInt = 100; : �Ұ�
	pConstInt = &b;

	// ============
	// ������ const : �ʱ�ȭ �� ����Ų ����� ������ �� ����
	// ============
	int* const pIntConst = &a;

	*pIntConst = 100;
	//pIntConst = &b; : �Ұ�

	// ============
	// const ������ const : �ʱ�ȭ �� ����Ų ���, ����Ű�� ������ ���� �� �� ����
	// ============
	const int* const pConstIntConst = nullptr;

	{
		int a = 0;
		const int* pInt = &a;

		// *pInt = 100; : �Ұ�
		a = 100;

		int* p = &a;
		*p = 100;

	}

	a = 100;
	Output(&a);
	

	// void ������
	// 1. ������ �ڷ����� ������ �ʴ´�
	// 2. �ڷ����� ���س��� �ʱ� ������ � �ڷ����� ������ �ּҵ� �� ������ �����ϴ�.
	// 3. ������ �����ϳ� �ڷ����� ������ ���� �ʱ� ������ �������� �Ұ����ϴ�.
	// 4. �ڷ����� ������ ���� �ʱ� ������ �ּ� ���굵 �Ұ����ϴ�.
	void* pVoid = nullptr;
	
	{
		int a = 0;
		float f = 0.f;
		double d = 0.;
		long long ll = 0;

		pVoid = &a;
		pVoid = &f;
		pVoid = &d;
		pVoid = &ll;

		// *pVoid;
		// pVoid + 1;
	}

	int ii = 1;
	float* pfi = (float*)&ii;
	int* pii = &ii;

	int iii = (int)*pfi;
	iii = *pii;




	return 0;
}

// ����Ű
// Ctrl + Shift + Space : �Լ� ���ڿ��� ����ϸ� �Լ��� ������ Ȯ���� �� �ִ�.