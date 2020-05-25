#if 0
#define _CRT_SECURE_NO_WARNINGS

// 타입 인코딩 방법 : typedef 기존 타입 새로운별칭
typedef unsigned int size_t;
typedef int(*arr_t)[3];

// 다차원 배열의 리턴

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

// 행과 열이 고정되지 않은 정수 타입의 2차원 배열을 생성하는 라이브러리를 구현해보자
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
	// 해제는 생성의 역순으로 처리해야 한다.
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