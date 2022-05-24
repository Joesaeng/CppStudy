#include <iostream>

#include "Arr.h"



int main()
{
	tArr s = {};
	InitArr(&s);



	for (int i = 0; i < 20; ++i)
	{
		PushBack(&s, i);
	}

	for (int i = 0; i < s.iCount; ++i)
	{
		printf("%d\n", s.pInt[i]);
	}



	ReleaseArr(&s);

	return 0;
}