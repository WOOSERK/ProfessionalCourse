// Stack.c
#include <stdlib.h>
#include "Stack.h"

// ���� ����ü ����
struct Stack
{
	int* arr; // int arr[3];
	int top;
	int size;
};

Stack createStack(int size)
{
	Stack p = calloc(1, sizeof(Stack));
	p->arr = malloc(sizeof(int) * size);
	p->size = size;
	
	return p;
}
