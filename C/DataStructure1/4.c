
#include <stdio.h>
#include <windows.h>
// step 3. 이전 자료구조는 데이터들이 분리되어 있어 사용하기 어렵다는 단점이 있다.
// 이를 해결하기 위해 데이터를 묶어 새로운 타입으로 정의(추상화)한다.

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
	array.size = 5;
	array.count = 0;
	
	arrayDisplay(&array);
	for (int i = 0; i < array.size; i++)
	{
		arrayAdd(&array, i);
		arrayDisplay(&array);
	}
}