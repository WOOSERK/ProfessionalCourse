
#if 0
// ���� ����
// ���� �ڷᱸ���� ������ ����.
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
//	struct Node* next; // OK, �������� ũ��� �̹� �����Ǿ� �ֱ� ����
//	struct Node node; // ERROR, Ÿ�� ������ �Ϻ��ϰ� ���ǵǾ� ���� �ʱ� ����
//};

#include "Stack.h"
#include <stdio.h>
int main()
{
	Stack* s = createStack(5);
}