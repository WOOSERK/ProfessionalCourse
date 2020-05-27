
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// step 9. 특정 위치에 삽입을 하는 arrayInsert 함수를 구현해 보자

typedef struct
{
	int* contents;
	int size;
	int count;
} Array;

Array* arrayCreate(size_t size)
{
	if (size <= 0)
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
	if (array->contents == NULL)
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
	if(array == NULL)
	{
		fprintf(stderr, "arrayInsert : array is null\n");
		return -1;
	}

	if (index < 0 || index > array->count)
	{
		fprintf(stderr, "arrayInsert : out of index\n");
		return -1;
	}
	
	if(array->size == array->count)
	{
		fprintf(stderr, "arrayInsert : array is full\n");
		return -1;
	}

	// 아래의 코드는 성능 상의 이슈가 있으므로 memmove를 사용하자.
	// 
	//for(int i=array->count; i>index; i--)
	//{
	//	array->contents[i] = array->contents[i-1];
	//}

	memmove(array->contents + index + 1, array->contents + index, sizeof(int) * (array->count - index));
	
	array->contents[index] = data;
	array->count++;
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
	Array* array = arrayCreate(5);

	for (int i = 0; i < 3; i++)
		arrayAdd(array, i);
	arrayDisplay(array);

	arrayInsert(array, 1, 10);
	arrayDisplay(array);

	arrayInsert(array, 0, 15);
	arrayDisplay(array);
	
	arrayDestroy(array);
} 