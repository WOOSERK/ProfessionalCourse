
#include <stdio.h>
#include <windows.h>
// step 2. ���� �ڷᱸ���� �߰��� �� �����ϳ� 2�� �̻��� �ڷᱸ���� ���� �� ���ٴ� ������ �ִ�.
// �̴� �Լ��� ���� �ɺ��� ���������� ����ϰ� �ֱ� �����̴�.
// ���� �� ������ �ذ��ϱ� ���� ���� �ɺ��� ���� �ɺ��� �����Ͽ� ó���Ѵ�.

int arrayAdd(int* arr, int size, int* count, int data)
{
	if (size == *count)
	{
		fprintf(stderr, "���� ���忡 �����Ͽ����ϴ�.\n");
		return 0;
	}

	arr[(*count)++] = data;
	printf("���� ���忡 �����Ͽ����ϴ�.\n");

	return 1;
}

void arrayDisplay(const int *arr, int size, int count)
{
	system("cls"); 

	for (int i = 0; i < size; i++)
	{
		if (i < count)
			printf("[%2d]", arr[i]);
		else
			printf("[%2c]", ' ');
	}
	getchar();
}


int main()
{
	// ���� 2�� �̻��� �ڷᱸ���� ������ �� �ִ�.
	int arr[5] = { 0, };
	int size = sizeof(arr) / sizeof(*arr);
	int count = 0;
	
	arrayDisplay(arr, size, count);
	for (int i = 0; i < size; i++)
	{
		arrayAdd(arr, size, &count, i);
		arrayDisplay(arr, size, count);
	}
}