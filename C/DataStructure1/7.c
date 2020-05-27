
#include <stdio.h>
#include <stdlib.h>
// step 6. ���� �ڷᱸ���� �Լ��� ���޵Ǵ� �迭�� ���Ͽ� �� ����� �Ϲ�ȭ���� �ʾҽ��ϴ�.
// �̴� �ڷᱸ���� ����� ��ư� �Ѵٴ� ������ �ȴ�. �̸� �ذ��� ����.

typedef struct
{
	int contents[5];
	int size;
	int count;
} Array;

//int arrayCreate(Array** array)
Array* arrayCreate()
{
	Array* array = malloc(sizeof(Array));
	if (array == NULL)
	{
		perror("arrayCreate");
		return NULL;
	}

	array->size = sizeof(array->contents) / sizeof(array->contents[0]);
	array->count = 0;

	return array;
}

void arrayDestroy(Array* array)
{
	if (array == NULL)
		return;
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
	array = arrayCreate();

	arrayDisplay(array);
	for (int i = 0; i < array->size; i++)
	{
		arrayAdd(array, i);
		arrayDisplay(array);
	}

	arrayDestroy(array);
}