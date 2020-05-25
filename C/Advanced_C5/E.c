
#include <stdio.h>

void printBinary(float f)
{
	unsigned int* p = (unsigned int*)&f;
	for (int i = 31; i >= 0; i--)
	{
		if ((*p >> i) & 0x1)
			printf("1");
		else
			printf("0");
	}
	printf("\n");
}

int main()
{
	float f = 10.25f; // 0 10000010 01001

	// 연습 문제
	// 위의 변수에 대하여 2진수로 출력해보자

	printBinary(f);
}