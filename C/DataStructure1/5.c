
#include <stdio.h>
#include <windows.h>
// step 4. 이전 자료구조는 자료구조 생성 시, 내부 데이터가 초기화되지 않는다는 단점이 있다.
// 이를 해결하기 위해 자료구조를 초기화하는 함수를 추가한다.

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
	Array array;
	arrayInitiate(&array);
	arrayDisplay(&array);
	for (int i = 0; i < array.size; i++)
	{
		arrayAdd(&array, i);
		arrayDisplay(&array);
	}
}