#include <stdio.h>

#define HUNGRY	0x01	//16진수 0x를 앞에 붙인다
#define THIRSTY		0x02
#define TIRED			0x04
#define FIRE			0x08
#define COLD			0x10
#define POISON		0x20
#define HURT			0x40


// 전처리기 #define : 내가 지정한 구문을 특정 숫자로 치환해준다
// 1. 가독성
// 2. 유지보수

// 주석은 무엇이냐~
// 설명 역할, 코드로 인식되지 않는다.

// 전역변수
int global = 0;

int Add(int left, int right)
{
	return left + right;
}
// 함수
int main()
{
	// 자료형 (크기단위, byte)
	// 정수형 : char(1), short(2), int(4), long(4), long long(8)....
	// 실수형 : float(4), double(8) ....

	//int i = 0;

	// 1바이트로 양수만 표현
	// 256가지 -> 0 ~ 255

	unsigned char c = 0;		//unsigned : 양의 정수만 취급

	c = 0;
	c = 255;

	// 1바이트로 양수, 음수 둘다 표현
	// -128 ~ 0 ~ 127
	char c1 = 0;

	c1 = -1;

	// 음의 정수 찾기 (2의 보수법)
	// 대응되는 양수의 부호를 반전 후, 1을 더한다 //2진수 에서

	// 1byte로 표현할때. 
	// 양의정수 255와 음의정수 -128의 비트 값은 11111111로 동일하다. ****중요****

	// 정수표현 방식과 실수 표현 방식은 다르다
	// 실수 표현방식은 정밀도에 의존한다.
	// 따라서 double(8) 자료형이 float(4) 보다 더 아래의 소수점까지 정확하게 표현이 가능하다

	// 정수는 정수끼리, 실수는 실수끼리 연산하되, 두 표현방식의 피 연산자가 연산될 경우 명시적으로 변환하자

	float f = 10.2415f + (float)20; // 형변환을 하지 않아도 컴파일러는 변환하여 계산하지만, 변환자를 사용하여 의도가 있다는것을 명시적으로 표현하자.

	// 실수를 상수로 적을 경우 소수점 뒤에 f를 붙이면 float형식으로, 그렇지 않으면 double 형식으로 간주한다.

	// 연산자
	// 대입 연산자 , =

	// 산술 연산자
	// +. -, *, /, %(모듈러스 : 나머지 , 피 연산자가 모두 정수여야 한다.)
	// ++, -- // 증감 연산자 : 한단계 증가 혹은 감소

	int data = 10 + 10;
	// data = data + 20;
	data += 20; // data에 20을 더한 값을 대입한다 (data = data + 20)

	data = 10 / 3;

	data = 0;
	++data; // 전위연산
	data++; // 후위연산 ( 대입 연산자보다도 후순위 // 모든 연산중 가장 후순위)
	//증감 연산자를 쓸 때 특별한 사유가 없다면 전위 연산자를 쓰는 습관을 들이자

	data++;
	data++;

	data = 0;
	--data; // 전위
	data--; // 후위

	// 논리 연산자
	// !(역,반전), &&(논리곱,AND), ||(논리합,OR)
	// 참(true), 거짓(false)
	// 참		:	0이 아닌 값, 대표적으로 1
	// 거짓	:	0
	bool isTrue = true; //

	isTrue = false;
	isTrue = !isTrue;

	int iTrue = 100;
	iTrue = !iTrue; // iTrue값은 0(false)가 됨

	iTrue = 100 && 200; // 참
	iTrue = 100 && 0; // 거짓
	iTrue = 100 || 0; // 참
	iTrue = 0 || 0; // 거짓

	// 비교 연산자
	// ==, !=, >, <, >=, <=
	// 참과 거짓으로만 나온다.

	// 구문
	// if, else
	data = 0;
	if (data >= 10)
	{
		data = 100; // 참인 경우
	}
	else
	{
		data = 0; // 거짓인 경우
	}

	if (data)
	{
		//if가 참인 경우
	}
	else if (!data)
	{
		//else if가 참인 경우
	}
	else
	{
		//거짓인 경우
	}

	// switch case
	int iTest = 10;
	switch (iTest)
	{
	case 10:

		break;
	case 20:

		break;
	default:

		break;
	}
	if (iTest == 10)
	{

	}
	else if (iTest == 20)
	{

	}
	else
	{

	}

	// 삼항 연산자
	// : ?
	iTest == 10 ? iTest = 100 : iTest = 200;
	// 같은 의미
	if (iTest == 10)
	{
		iTest = 100;
	}
	else
	{
		iTest = 200;
	}

	// 비트 연산자
	// 쉬프트 <<, >> 비트를 방향으로 한칸씩 미는 연산
	int n=1;
	unsigned char byte = 1;
	byte <<= n; // byte 의 2^n 배수
	byte >>= n; // byte 의 2^n 으로 나눈 몫

	// 비트 곱( & ), 합( | ), xor( ^ ), 반전 ( ~ )
	// 비트 단위로 연산을 진행
	// & 둘다 1인 경우 1
	// |	둘중 하나라도 1인 경우 1
	//	^	같으면 0, 다르면 1
	// ~	1은 0으로, 0은 1로

	unsigned int iStatus = 0;

	iStatus |= HUNGRY;
	iStatus |= THIRSTY;
	iStatus |= TIRED;

	if (iStatus & HUNGRY)
	{

	}

	//특정 자리 비트 제거
	iStatus &= ~HUNGRY; //반전시켜서 곱을 하기 때문에 제거가 된다 *암기*


	// 변수
	// 1. 지역변수
	// 2. 전역변수
	// 3. 정적변수
	// 4. 외부변수



	// 지역변수
	// 괄호 안에 선언된 변수 (함수, 지역)
	
	//변수명 규칙
	

	// 함수
	int addData = Add(10, 20);

	//printf("Hello World\n");
	//반복문
	//for (/*반복자 초기화*/;/*반복자 조건 체크*/;/*반복자 변경*/)
	
	for (int i = 0; i < 4; ++i)
	{
		if (i % 2 == 1)
		{
			continue; // 반복문의 시작 지점으로 이동
		}
		printf("Hello World\n");

		//break; //반복문 탈출
	}

	int i = 0;
	while (i < 2)
	{
		printf("hello world\n");
		++i;

		continue;

		break;
	}
	//콘솔
	// printf
	printf("abcdef  %d \n", 10);
	printf("abcdef  %f \n", 3.14f);
	for (int i=0; i < 10; ++i)
	{
		printf("Output i : %d \n", i);
	}
	
	// scanf
	int iInput = 0;
	scanf_s("%d", &iInput);
	printf("\n%d", iInput);

	






	return 0;
}

// 단축키
// 지정한 구문 주석			: Ctrl + k, c
// 지정한 구문 주석 해제		: Ctrl + k, u
// Alt Drag					: 원하는 부분만 드래그

// 디버깅
// 디버깅 시작	: F5
// 다음 중단점까지 코드 실행
// 중단점 생성 및 해제 : F9
// 디버깅 중, 구문 수행 : F10 : 프로시저 단위 실행
// 디버깅 중, 구문 수행(함수 진입) : F11 : 한 단계씩 코드 실행
// 디버깅 중, 디버깅 종료하기 : Shift + F5


