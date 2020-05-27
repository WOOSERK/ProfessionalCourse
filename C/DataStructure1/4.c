
#include <stdio.h>
#include <windows.h>
// step 3. ���� �ڷᱸ���� �����͵��� �и��Ǿ� �־� ����ϱ� ��ƴٴ� ������ �ִ�.
// �̸� �ذ��ϱ� ���� �����͸� ���� ���ο� Ÿ������ ����(�߻�ȭ)�Ѵ�.

typedef struct 
{
	int contents[5];// arr[5];
	int size;
	int count;
} Array;

int arrayAdd(Array *array, int data)
{
	if(array == NULL)
	{
		fprintf(stderr, "arrayAdd : argument is null\n");
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
	array.size = 5;
	array.count = 0;
	
	arrayDisplay(&array);
	for (int i = 0; i < array.size; i++)
	{
		arrayAdd(&array, i);
		arrayDisplay(&array);
	}
}