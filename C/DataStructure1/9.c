
#include <stdio.h>
#include <stdlib.h>
// step 8. ������ �����ϴ� ��ġ�� �����͸� �����ϴ� �Լ��� �����غ���
// ��, ������ ���� �ݵ�� ���� �����ʹ� ���Ƿ� �����ϸ� �ȵȴ�.

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
		fprintf(stderr, "���� ���忡 �����Ͽ����ϴ�.\n");
		return 0;
	}

	array->contents[array->count++] = data;
	printf("���� ���忡 �����Ͽ����ϴ�.\n");

	return 1;
}

int arraySet(Array* array, const int index, const int newData, int *oldData)
{
	if(array == NULL || oldData == NULL)
	{
		fprintf(stderr, "arraySet : argument is null\n");
		return -1; 
	}
	if(index < 0 || index >= array->size)
	{
		fprintf(stderr, "arraySet : out of index\n");
		return -1;
	}

	*oldData = array->contents[index];
	array->contents[index] = newData;
	
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

	for (int i = 0; i < array->size; i++)
		arrayAdd(array, i);

	arrayDisplay(array);

	for (int i = 0; i < 5; i++)
	{
		int oldData;
		arraySet(array, i, 0, &oldData);	// arr[i] = 0;
		printf("old value : %d\n", oldData);
		arrayDisplay(array);
	}
	
	arrayDestroy(array);
}