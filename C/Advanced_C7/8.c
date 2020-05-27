
// 가변 인자 함수의 원리
#include <stdio.h>

int total(int cnt, ...)
{
	int* ptr = &cnt + 1;
	for (int i = 0; i < cnt; i++)
		printf("%d ", ptr[i]);
	printf("\n");
	return 0;
}

int main()
{
	int result = total(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
}