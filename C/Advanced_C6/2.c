
#include <stdio.h>
#define ARR_MAX (4096)


// �迭���� ũ�⸦ ��Ÿ���� ���ڰ� ��ȿ�� ���� �ȿ� ������ �����ϴ� ���� ����.
int print_arr(const int arr[], size_t len) // void print_arr(int *arr)
{
	if (arr == NULL || len > ARR_MAX)
		return -1;

	for (size_t i = 0; i < len; i++)
		printf("%d ", arr[i]); // *(arr + i);
}

int main()
{
	int arr[] = { 1,2,3,4,5 };

	print_arr(arr, -39); // print_arr(0x12FF60);
}