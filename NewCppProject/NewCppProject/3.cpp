


#include <stdio.h>

// ����� ���� �ڷ���
typedef struct _tagMyST //*type define : Ÿ�� ������
{
	int a;
	float f;
}MYST;

typedef struct _tagBig
{
	MYST k;
	int i;
	char c;
}BIG;

typedef int INT;

int main()
{
	

	//����ü
	struct _tagMyST a; //C������ �̷��Ը� ����
	_tagMyST c; //C++���� �̷��� ���� ����
	MYST t = {}; //����ü�� �迭�� ����ϰ� �ʱ�ȭ�� �����ϴ�.
	t.a = 14;
	t.f = 14.5f;
	BIG b;
	b.k.a = 17;

	int iSize = sizeof(MYST);

	return 0;
}
