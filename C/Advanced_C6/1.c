
#include <stdio.h>

// 모든 소스 파일에서 배열에 대한 심볼은 일관된 표기 방법을 사용하는 것을 권장한다.
// int arr[];
int* arr;
extern void create();
extern void destroy();

int main()
{
	create();

	for (int i = 0; i < 10; i++)
		arr[i] = i + 1; 

	for (int i = 0; i < 10; i++)
		printf("arr[%d] = %d\n", i, arr[i]);

	destroy();
}