
#include <stdio.h>
#include <stdlib.h> // exit
int foo()
{
	exit(0); // ���α׷� �Ǵ� ���μ����� ��� �����Ű���� exit �Լ��� ���
	printf("call foo()\n");
}

int main()
{
	// return 0; // ���� �Լ����� ��ȯ�Ǹ� ���α׷��� ����ȴ�. -> exit(main());

	foo();
	printf("hello, woorld\n");
}

// ���α׷� ���� ���
// 1. ���� �Լ����� ����
// 2. exit �Լ� ȣ�� -> ���� ����
// 3. abort �Լ� ȣ�� -> ������ ����