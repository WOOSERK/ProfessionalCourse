
// �ʱ�ȭ���� ���� ������ �������� ����
#include <stdio.h>

int sum(const int* arr, int len)
{
	int sum;
	for (int i = 0; i < len; i++)
		sum += arr[i];
	return sum;
}

int main()
{
	int arr[5] = { 1,2,3,4,5 };
	printf("%d\n", sum(arr, 5));
}