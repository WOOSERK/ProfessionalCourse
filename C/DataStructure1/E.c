
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// step 13. 이전 자료구조는 배열의 크기가 고정되어 있다는 단점이 있다.
// 이를 해결해 보자.
typedef struct
{
	int* contents;
	int size;
	int count;
} Array;

#define INITIAL_SIZE (4)
Array* arrayCreate()
{
	Array* array = calloc(1, sizeof(Array));
	if (array == NULL)
	{
		perror("arrayCreate");
		return NULL;
	}

	array->contents = malloc(sizeof(int) * INITIAL_SIZE);
	if (array->contents == NULL)
	{
		perror("arrayCreate");
		free(array);
		return NULL;
	}

	array->size = INITIAL_SIZE;

	return array;
}

#define MAX_SIZE (4096)
int arrayResize(Array* array)
{
	int newSize = array->size * 2;
	if (newSize > MAX_SIZE || newSize < array->size)
		newSize = MAX_SIZE;

	int* contents = realloc(array->contents, sizeof(int) * newSize);

	if (contents == NULL)
	{
		perror("arrayResize");
		return -1;
	}
	array->contents = contents;
	array->size = newSize;

	return 1;
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

	if (array->count >= array->size)
	{
		if (arrayResize(array) == -1)
		{
			fprintf(stderr, "정수 저장에 실패하였습니다.\n");
			return 0;
		}
	}

	array->contents[array->count++] = data;
	printf("정수 저장에 성공하였습니다.\n");

	return 1;
}

int arraySet(Array* array, const int index, const int newData, int* oldData)
{
	if (array == NULL || oldData == NULL)
	{
		fprintf(stderr, "arraySet : argument is null\n");
		return -1;
	}
	if (index < 0 || index >= array->count)
	{
		fprintf(stderr, "arraySet : out of index\n");
		return -1;
	}

	*oldData = array->contents[index];
	array->contents[index] = newData;

	return 1;
}

int arrayInsert(Array* array, int index, int data)
{
	if (array == NULL)
	{
		fprintf(stderr, "arrayInsert : array is null\n");
		return -1;
	}

	if (index < 0 || index >= array->count)
	{
		fprintf(stderr, "arrayInsert : out of index\n");
		return -1;
	}

	if (array->count >= array->size)
	{
		if (arrayResize(array) == -1)
		{
			fprintf(stderr, "정수 저장에 실패하였습니다.\n");
			return 0;
		}
	}

	memmove(array->contents + index + 1, array->contents + index, sizeof(int) * (array->count - index));

	array->contents[index] = data;
	array->count++;
	return 1;
}

int arrayCount(const Array* array)
{
	if (array == NULL)
	{
		fprintf(stderr, "arrayCount : argument is null\n");
		return -1;
	}

	return array->count;
}

int arrayGet(const Array* array, int index, int* outData)
{
	if (array == NULL || outData == NULL)
	{
		fprintf(stderr, "arrayGet : argument is null\n");
		return -1;
	}

	if (index < 0 || index >= array->count)
	{
		fprintf(stderr, "arrayGet : out of index\n");
		return -1;
	}

	*outData = array->contents[index];
}

int arrayRemove(Array* array, int index, int* outData)
{
	if (array == NULL || outData == NULL)
	{
		fprintf(stderr, "arrayRemove : argument is null\n");
		return -1;
	}

	if (array->count == 0)
	{
		fprintf(stderr, "arrayRemove : array is empty\n");
		return -1;
	}

	if (index < 0 || index >= array->count)
	{
		fprintf(stderr, "arrayRemove : out of index\n");
		return -1;
	}

	*outData = array->contents[index];

	int newCount = array->count - 1;
	if (index != newCount)
	{
		memmove(array->contents + index, array->contents + index + 1, sizeof(int) * (newCount - index));
	}

	array->count = newCount;
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
	Array* array = arrayCreate();

	for (int i = 0; i < 8; i++)
	{
		arrayAdd(array, i);
		arrayDisplay(array);
	}

	arrayInsert(array, 0, 110);
	arrayDisplay(array);

	arrayDestroy(array);
}