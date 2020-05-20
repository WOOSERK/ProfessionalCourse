#if 0
#include <stdio.h>

void swap(void* a, void* b)
{
	int t = *(int*)a;
	*(int*)a = *(int*)b;
	*(int*)b = t;
}

int main()
{
	int a = 10, b = 1000;
	swap(&a, &b);
	printf("a = %d, b = %d\n", a, b);

	double d = 3.14, e = 4.14;
	swap(&d, &e);
	printf("d = %f, e = %f\n", d, e);

	return 0;
}
#endif


#if 0
#include <stdio.h>

// step 1. ���� �ڵ�� ���� Ÿ�Ը� ���� �����ϴٴ� ������ �ִ�.
// ��� Ÿ�Կ� ���Ͽ� ���� �����ϵ��� Ÿ�� ������ ����ڷκ��� �޴´�.

enum Type{ INT, DOUBLE }; // Ÿ�� �ڵ�
void swap(void* a, void* b, enum Type t)
{
	switch (t)
	{
	case INT:
	{
		int t = *(int*)a;
		*(int*)a = *(int*)b;
		*(int*)b = t;
	}
	break;
	case DOUBLE:
	{
		double t = *(double*)a;
		*(double*)a = *(double*)b;
		*(double*)b = t;
	}
	break;
	}
}

int main()
{
	int a = 10, b = 1000;
	swap(&a, &b, INT);
	printf("a = %d, b = %d\n", a, b);

	double d = 3.14, e = 4.14;
	swap(&d, &e, DOUBLE);
	printf("d = %f, e = %f\n", d, e);

	return 0;
}
#endif



#if 0
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// step 2. ���� �ڵ�� Ÿ�� �ڵ尡 ���Ǿ����Ƿ� ���ο� Ÿ���� �߰��Ǹ�
// �ڵ带 �����ؾ� �Ѵٴ� ������ �ִ�. Ÿ�� �ڵ�� �б⹮�� �����ϱ� �����̴�.

typedef struct { int x, y; } Point;

void swap(void* a, void* b, int size)
{
	void* t = malloc(size);
	memcpy(t, a, size); // t = a;
	memcpy(a, b, size); // a = b;
	memcpy(b, t, size); // b = t;
	free(t);
}

int main()
{
	int a = 10, b = 1000;
	swap(&a, &b, sizeof(int));
	printf("a = %d, b = %d\n", a, b);

	double d = 3.14, e = 4.14;
	swap(&d, &e, sizeof(double));
	printf("d = %f, e = %f\n", d, e);

	Point p1 = { 0, 0 };
	Point p2 = { 10, 10 };
	swap(&p1, &p2, sizeof(Point));
	printf("p1(%d,%d), p2(%d,%d)\n", p1.x, p1.y, p2.x, p2.y);

	return 0;
}
#endif


#if 0
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// step 3. ���� �ڵ�� ���������� ���� �Ҵ��� �ϱ� ������ ���� �̽��� �߻��Ѵ�.
// �̸� �ذ��ϱ� ���� ��ũ�θ� �����Ѵ�.

typedef struct { int x, y; } Point;

#define SWAP(x, y, t) \
	(t) = (x);\
	(x) = (y);\
	(y) = t;

int main()
{
	int a = 10, b = 1000;
	int t1;
	SWAP(a, b, t1); // t = (a);
					  // (a) = (b);
					  // (b) = t;
	printf("a = %d, b = %d\n", a, b);

	double d = 3.14, e = 4.14;
	double t2;
	SWAP(d, e, t2);
	printf("d = %f, e = %f\n", d, e);

	return 0;
}
#endif


#if 0
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// step 4. ���� �ڵ�� �ӽ� ������ ����Ѵٴ� ������ �ִ�.
// �̸� �ذ��ϱ� ���� �̸� ���� �߰�ȣ�� �����Ѵ�.

typedef struct { int x, y; } Point;

#define SWAP(x, y, T) \
{\
	T t = (x);\
	(x) = (y);\
	(y) = t;\
}

int main()
{
	int a = 10, b = 1000;
	SWAP(a, b, int); // t = (a);
					  // (a) = (b);
					  // (b) = t;
	printf("a = %d, b = %d\n", a, b);
	double d = 3.14, e = 4.14;
	SWAP(d, e, double);
	printf("d = %f, e = %f\n", d, e);

	return 0;
}
#endif



#if 0
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// step 4. ���� �ڵ�� �ӽ� ������ ����Ѵٴ� ������ �ִ�.
// �̸� �ذ��ϱ� ���� �̸� ���� �߰�ȣ�� �����Ѵ�.

// 4. ��ũ�θ� �߰��ϰ� ����� ��� : ���� ���� ��ũ�ο� ���ؼ� do-while(0)�� �����־�� �Ѵ�.
typedef struct { int x, y; } Point;

// �� �Լ��� �̸� ���� �߰�ȣ�� ����ϹǷ� if-else ��� �� �����ݷ��� ����ϸ� �ȵȴ�.
#define SWAP(x, y, T) \
do {\
	T t = (x);\
	(x) = (y);\
	(y) = t;\
} while(0)

int main()
{
	int a = 10, b = 1000;
	if(a > b)
		SWAP(a, b, int); // t = (a);
					  // (a) = (b);
					  // (b) = t;
	else
		printf("a = %d, b = %d\n", a, b);

	double d = 3.14, e = 4.14;
	SWAP(d, e, double);
	printf("d = %f, e = %f\n", d, e);

	return 0;
}
#endif

#include <stdio.h>
// ���� ���� : ��ũ�θ� ������� �ʰ� �Ϲ� �Լ��� ����Ͽ� �Ϻ��ϰ� �Ϲ�ȭ�� ���� �Լ��� ������ ����.
//void swap(void* p1, void* p2, size_t size)
//{
//	char* pA = (char*)p1;
//	char* pB = (char*)p2;
//
//	for (size_t i = 0; i < size; i++, pA++, pB++)
//	{
//		char temp = *pA;
//		*pA = *pB;
//		*pB = temp;
//	}
//}

static void generic_swap(void* a, void* b, int size)
{
	char t;

	do {
		t = *(char*)a;
		*((char*)a)++ = *(char*)b;
		*((char*)b)++ = t;
	} while (--size > 0);
}

int main()
{
	int a = 10, b = 1000;
	generic_swap(&a, &b, sizeof(int));
	printf("%d, %d", a, b);
}