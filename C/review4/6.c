
#if 0
// ��� : ������ �켱������ ��Ȯ�ϰ� �˴��� �׻� ��ȣ�� �������

// ¦���� �Ǻ��ϴ� �ڵ带 ������ ���ô�.
#include <stdio.h>

int isEven(int x)
{
	return !(x&1);
}

int main()
{
	int n = 3;
	if (isEven(n))
		printf("even\n");
	else
		printf("odd\n");
}
#endif


#include <stdio.h>

void increase(int* p)
{
	(*p)++;
}

int main()
{
	int age = 18;

	increase(&age);
	printf("%d\n", age);
}