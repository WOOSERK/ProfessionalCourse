
#include <stdio.h>
#include <windows.h>
// step 1. 정수를 저장하는 배열을 생각해보자.
int arr[5];
int size = sizeof(arr) / sizeof(*arr);
int count; // 배열 안의 원소의 개수 & 저장할 다음 위치

// 다른 라이브러리의 심볼과 충돌을 막기 위해 관례적으로 라이브러리 이름을
// 접두어로 사용한다.

int arrayAdd(int data)
{
	if (size == count)
	{
		fprintf(stderr, "정수 저장에 실패하였습니다.\n");
		return 0;
	}

	arr[count++] = data;
	printf("정수 저장에 성공하였습니다.\n");

	return 1;
}

void arrayDisplay()
{
	system("cls"); // cls : 윈도우에서 화면을 지우는 명령어
	// clear : 리눅스에서 화면을 지우는 명령어

	for(int i=0; i<size; i++)
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
	arrayDisplay();
	for(int i=0; i<size; i++)
	{
		arrayAdd(i);
		arrayDisplay();
	}
}


