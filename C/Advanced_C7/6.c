
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
#define STACK_SIZE (5)
	int top;
	int arr[STACK_SIZE];
} Stack;

int isFull(const Stack* p) { return p->top == STACK_SIZE; }

// ������ �߻��� ���, ���� ó�� ��å�� ����ڿ��� �����ϰ� �ִ�.
// �̷��� �ڵ�� ���� ���ϸ� ������ �߻��Ǹ� ����ڿ��� �˷��־� �����ϰ� ó���ϵ��� �ϴ� ���� ����.
int push(Stack* p, int data)
{
	assert(p != NULL); // ��쿡 ���󼭴� �����Ű�� �͵� ���� ����̴�.

	if (isFull(p))
	{
		// exit(-1);	// abort();
		return -1;
	}
	return 0;
}

int main()
{
	Stack s = { 0, };
	
	if (push(&s, 10) == -1)
	{
		// ���� ó��
	}
}