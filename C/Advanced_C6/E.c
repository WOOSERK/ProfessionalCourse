
#if 0
#include <stdio.h>

typedef struct Test
{
	int y;
	int arr[0];
};

int main()
{
	int arr; // ERROR
	struct Test t;
}
#endif


#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
	int age;
	char name[32];
} Person;

int main()
{
	// ����ڷκ��� �̸��� ���̸� �Է¹޾Ҵٰ� �����մϴ�.
	char name[32] = "daniel";
	int age = 20;

	Person* p = (Person*)malloc(sizeof(Person));
	strcpy(p->name, name);
	p->age = age;
	printf("%s, %d\n", p->name, p->age);

	free(p);
}
#endif


#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// ���� �ڵ�� �̸��� �����ϱ� ���� ���� �迭�� ����ϰ� �ִٴ� ������ �ֽ��ϴ�.
// �̸� �ذ��ϱ� ���� �����͸� ����մϴ�.
typedef struct
{
	int age;
	char* name; // char name[32];
} Person;

int main()
{
	char name[32] = "daniel";
	int age = 20;

	Person* p = (Person*)malloc(sizeof(Person));
	p->name = malloc(strlen(name) + 1);
	strcpy(p->name, name);
	p->age = age;
	printf("%s, %d\n", p->name, p->age);

	// �ڿ��� ������ ������ ��������!
	free(p->name);
	free(p);
}
#endif



#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// ���� �ڵ�� ���� �Ҵ����� ���� ���� ���� �̽��� �޸� ���� ���ɼ��� �ִ�.
// �̸� �ذ��غ���.
typedef struct
{
	int age;
	char name[0]; // ASCII NULL�� ���� ��
} Person;

int main()
{
	char name[32] = "daniel";
	int age = 20;

	Person* p = (Person*)malloc(sizeof(Person) + strlen(name) + 1);
	// p->name = malloc(strlen(name) + 1);
	strcpy(p->name, name);
	p->age = age;
	printf("%s, %d\n", p->name, p->age);

	// �ڿ��� ������ ������ ��������!
	// free(p->name);
	free(p);
}
#endif



#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// ���� �ڵ�� ���� �Ҵ����� ���� ���� ���� �̽��� �޸� ���� ���ɼ��� �ִ�.
// �̸� �ذ��غ���.
typedef struct
{
	int age;
	char name[]; // flexible array member(C99) : �迭�� ���� ������ ���� ��� �ʵ�
				 // ���� ���� : �ݵ�� ����ü�� ������ ����� ��ġ�ؾ� �Ѵ�.
				 // �ݵ�� 1���� �����ؾ� �Ѵ�.
} Person;

int main()
{
	char name[32] = "daniel";
	int age = 20;

	Person* p = (Person*)malloc(sizeof(Person) + strlen(name) + 1);
	// p->name = malloc(strlen(name) + 1);
	strcpy(p->name, name);
	p->age = age;
	printf("%s, %d\n", p->name, p->age);

	// �ڿ��� ������ ������ ��������!
	// free(p->name);
	free(p);
}
#endif