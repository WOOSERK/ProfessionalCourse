#if 0
#define _CRT_SECURE_NO_WARNINGS

// Ÿ�� ���ڵ� ��� : typedef ���� Ÿ�� ���οĪ
typedef unsigned int size_t;
typedef int(*arr_t)[3];

// ������ �迭�� ����

arr_t foo(int row, int col)
{
	int arr[2][3];
	return arr;
}

int main()
{
	int (*p)[3] = foo();
}
#endif


#include <stdio.h>
#include <stdlib.h>

// ��� ���� �������� ���� ���� Ÿ���� 2���� �迭�� �����ϴ� ���̺귯���� �����غ���
int** createArray(int row, int col)
{
	int** array = malloc(sizeof(int*) * row);

	for (int i = 0; i < row; i++)
	{
		array[i] = malloc(sizeof(int) * col);
	}

	return array;
}

void freeArray(int** arr, int row)
{
	// ������ ������ �������� ó���ؾ� �Ѵ�.
	for (int i = 0; i < row; i++)
	{
		free(arr[i]);
	}

	free(arr);
}

int main()
{
	int** arr = createArray(2, 3);

	int cnt = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			arr[i][j] = ++cnt;
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	free(arr);
}