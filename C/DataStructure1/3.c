
#include <stdio.h>
#include <windows.h>
// step 2. 이전 자료구조는 추가가 잘 동작하나 2개 이상의 자료구조를 만들 수 없다는 문제가 있다.
// 이는 함수가 전역 심볼을 직접적으로 사용하고 있기 때문이다.
// 이제 이 문제를 해결하기 위해 전역 심볼을 지역 심볼로 변경하여 처리한다.

int arrayAdd(int* arr, int size, int* count, int data)
{
	if (size == *count)
	{
		fprintf(stderr, "정수 저장에 실패하였습니다.\n");
		return 0;
	}

	arr[(*count)++] = data;
	printf("정수 저장에 성공하였습니다.\n");

	return 1;
}

void arrayDisplay(const int *arr, int size, int count)
{
	system("cls"); 

	for (int i = 0; i < size; i++)
	{
		if (i < count)
			printf("[%2d]", arr[i]);
		else
			printf("[%2c]", ' ');
	}
	getchar();
}


int main()
{
	// 이제 2개 이상의 자료구조를 생성할 수 있다.
	int arr[5] = { 0, };
	int size = sizeof(arr) / sizeof(*arr);
	int count = 0;
	
	arrayDisplay(arr, size, count);
	for (int i = 0; i < size; i++)
	{
		arrayAdd(arr, size, &count, i);
		arrayDisplay(arr, size, count);
	}
}