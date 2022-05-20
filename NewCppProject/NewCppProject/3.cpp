


#include <stdio.h>

// 사용자 정의 자료형
typedef struct _tagMyST //*type define : 타입 재정의
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
	

	//구조체
	struct _tagMyST a; //C언어에서는 이렇게만 가능
	_tagMyST c; //C++에서 이렇게 선언 가능
	MYST t = {}; //구조체는 배열과 비슷하게 초기화가 가능하다.
	t.a = 14;
	t.f = 14.5f;
	BIG b;
	b.k.a = 17;

	int iSize = sizeof(MYST);

	return 0;
}
