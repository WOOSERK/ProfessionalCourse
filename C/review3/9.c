
#include <stdio.h>

// �Լ� ���� ��, Ÿ�� ������ �����ϰ� �����ض�
int foo(int a, int b, int c);

int main()
{
	// int ret = foo(1, 2);
	int(*fp)(int, int) = foo;
	fp(1, 2);
}

int foo(int a, int b, int c)
{
	printf("foo(%d, %d, %d)\n", a, b, c);

	void* v1;

	printf("%d", sizeof(v1));
	return 0; 
}