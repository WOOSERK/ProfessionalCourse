
#include <stdio.h>

// ��� �ҽ� ���Ͽ��� �迭�� ���� �ɺ��� �ϰ��� ǥ�� ����� ����ϴ� ���� �����Ѵ�.
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