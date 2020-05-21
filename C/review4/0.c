
#if 0
// ���� ó�� �̾߱�
#include <stdio.h>

int div(int a, int b)
{
	return a / b;
}

int main()
{
	int ret = div(4, 2);
	printf("%d\n", ret);
}
#endif



#if 
// step 1. �Ʒ��� �Լ��� ġ������ ������ �����Ѵ�.
// ������ 0�� ���, ������ �����̱� �����̴�.
#include <stdio.h>

// C������ ���������� �Լ��� ���Ͽ� ���� �ڵ带 ��ȯ�Ѵ�.
// 0 : �Լ� ȣ���� ������ ���(������ �߻����� ���� ���)
// 0 �̿��� ������ -> �Ϲ������� -1�� ��� : �Լ� ȣ���� ������ ���(������ �߻��� ���)
int div(int a, int b)
{
	if (b == 0)
		return -1;
	return a / b;
}

int main()
{
	// �Լ��� ȣ��� ���Ŀ��� �Լ��� ��ȯ���� Ȯ���ؾ� �Ѵ�.
	int ret = div(4, 0);
	if (ret == -1)
	{
		fprintf(stderr, "divide by zero\n");
	}
	printf("%d\n", ret);
}
#endif



#if 0
// step 2. ������ �ڵ忡���� �Լ��� ���Ͽ� ����� ���� �ڵ尡 ȥ��Ǿ� �ִٴ� ������ �ִ�.
// �̸� �ذ��ϱ� ���� ����� ���� �ڵ带 �и��Ѵ�.

// �ذ� ���
// 1. ���� �ڵ带 �Լ��� ��ȯ���� ó���Ѵ�.
// 2. ���� ����� ���ڷ� �����Ѵ�.
#include <stdio.h>
#define OUT
int div(int a, int b, OUT int* ret)
{
	// ������ ���
	if (b == 0 || ret == NULL)
		return -1;

	// ������ ���
	*ret = a / b;
	return a / b;
}

int main()
{
	// �Լ��� ȣ��� ���Ŀ��� �Լ��� ��ȯ���� Ȯ���ؾ� �Ѵ�.
	int ret;
	if (div(4, 0, &ret) == -1)
	{
		fprintf(stderr, "divide by zero\n");
		return -1;
	}
	printf("%d\n", ret);
}
#endif



#if 1
// step 3. ������ �ڵ�� �Լ��� ���� �ڵ� �Ǵ� ���� ������ ��ȯ�ϴ��� �� �� ���ٴ� ������ �ִ�.
// �̸� �ذ��ϱ� ���� typedef�� ����Ѵ�.

typedef int error_t;
#include <stdio.h>
error_t div(int a, int b, int* ret)
{
	// ������ ���
	if (b == 0 || ret == NULL)
		return -1;

	// ������ ���
	*ret = a / b;
	return a / b;
}

int main()
{
	// �Լ��� ȣ��� ���Ŀ��� �Լ��� ��ȯ���� Ȯ���ؾ� �Ѵ�.
	int ret;
	if (div(4, 0, &ret) == -1)
	{
		fprintf(stderr, "divide by zero\n");
		return -1;
	}
	printf("%d\n", ret);
}
#endif
 
// ��� : ���� �ڵ带 ��ȯ�ϴ� �Լ��� ��ȯ Ÿ���� ���ڵ��Ͽ� ����ڿ��� �˷��ִ� ���� ����.