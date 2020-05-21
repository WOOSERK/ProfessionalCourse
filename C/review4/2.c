
#if 0
// 정보 은닉
// 스택 자료구조를 생각해 보자.
#include <stdlib.h>
struct Stack
{
	int* arr; // int arr[3];
	int top;
	int size;
};
typedef struct Stack Stack;

Stack* createStack(int size)
{
	Stack* p = calloc(1, sizeof(Stack));
	p->arr = malloc(sizeof(int) * size);
	p->size = size;
	//p->top = 0;
	return p;
}

int main()
{
	Stack* s = createStack(5);
}
#endif

//typedef struct Node
//{
//	struct Node* next; // OK, 포인터의 크기는 이미 결정되어 있기 때문
//	struct Node node; // ERROR, 타입 정보가 완벽하게 정의되어 있지 않기 때문
//};

#include "Stack.h"
#include <stdio.h>
int main()
{
	Stack* s = createStack(5);
}