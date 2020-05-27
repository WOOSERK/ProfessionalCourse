
#include <stdio.h>
#include <stdlib.h>
// step 7. 이전 자료구조는 배열의 크기가 고정되어 있다는 단점이 있다. 이를 해결하기 위해 포인터를 도입한다.

typedef struct
{
	int* contents;
	int size;
	int count;
} Array;

Array* arrayCreate(size_t size)
{
	if(size <= 0)
	{
		fprintf(stderr, "arrayCreate : size is zero\n");
		return NULL;
	}
	
	Array* array = calloc(1, sizeof(Array));
	if (array == NULL)
	{
		perror("arrayCreate");
		return NULL;
	}

	array->contents = malloc(sizeof(int) * size);
	if(array->contents == NULL)
	{
		perror("arrayCreate");
		free(array);
		return NULL;
	}
	
	array->size = size;

	return array;
}

void arrayDestroy(Array* array)
{
	if (array == NULL)
		return;
	
	free(array->contents);
	free(array);
}

int arrayAdd(Array* array, int data)
{
	if (array == NULL)
	{
		fprintf(stderr, "arrayAdd : argument is null\n");
		return -1;
	}

	if (array->size == array->count)
	{
		fprintf(stderr, "정수 저장에 실패하였습니다.\n");
		return 0;
	}

	array->contents[array->count++] = data;
	printf("정수 저장에 성공하였습니다.\n");

	return 1;
}

void arrayDisplay(Array* array)
{
	system("cls");

	for (int i = 0; i < array->size; i++)
	{
		if (i < array->count)
			printf("[%2d]", array->contents[i]);
		else
			printf("[%2c]", ' ');
	}
	getchar();
}

int main()
{
	Array* array;
	array = arrayCreate(5);

	arrayDisplay(array);
	for (int i = 0; i < array->size; i++)
	{
		arrayAdd(array, i);
		arrayDisplay(array);
	}

	arrayDestroy(array);
}