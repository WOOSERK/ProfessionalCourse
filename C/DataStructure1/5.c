
#include <stdio.h>
#include <windows.h>
// step 4. ���� �ڷᱸ���� �ڷᱸ�� ���� ��, ���� �����Ͱ� �ʱ�ȭ���� �ʴ´ٴ� ������ �ִ�.
// �̸� �ذ��ϱ� ���� �ڷᱸ���� �ʱ�ȭ�ϴ� �Լ��� �߰��Ѵ�.

typedef struct
{
	int contents[5];
	int size;
	int count;
} Array;

int arrayInitiate(Array* array)
{
	if(array == NULL)
	{
		fprintf(stderr, "arrayInitiate : argument is null\n");
		return -1;
	}
	array->size = sizeof(array->contents) / sizeof(array->contents[0]);
	array->count = 0;
	return 0;
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
	Array array;
	arrayInitiate(&array);
	arrayDisplay(&array);
	for (int i = 0; i < array.size; i++)
	{
		arrayAdd(&array, i);
		arrayDisplay(&array);
	}
}