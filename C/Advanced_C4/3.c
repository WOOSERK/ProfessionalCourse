
// 연결성(linkage) 이야기
#include "Circle.h"
#include <stdio.h>

int main()
{
	int i = square(2);
	double d = getCircleArea(2);

	printf("%d %f", i, d);
	return 0;
}