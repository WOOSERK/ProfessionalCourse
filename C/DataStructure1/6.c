
#include <stdio.h>
#include <stdlib.h>
// step 5. 이전 자료구조는 자료구조의 컨텍스트를 저장하기 위해 스택 메모리를 사용하고 있다는
// 단점이 있다. 이를 해결하기 위해 정보 구조체를 힙에 생성하도록 한다.

typedef struct
{
	int contents[5];
	int size;
	int count;
} Array;

int arrayCreate(Array** array)
{
	if (array == NULL)
	{
		fprintf(stderr, "arrayInitiate : argument is null\n");
		return -1;
	}

	Array* temp = malloc(sizeof(Array));
	if(temp == NULL)
	{
		return -1;
	}
	
	temp->size = sizeof(temp->contents) / sizeof(temp->contents[0]);
	temp->count = 0;

	*array = temp;
	return 0;
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
	arrayCreate(&array);
	
	arrayDisplay(array);
	for (int i = 0; i < array->size; i++)
	{
		arrayAdd(array, i);
		arrayDisplay(array);
	}
	
	arrayDestroy(array);
}