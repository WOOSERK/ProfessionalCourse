#if 0
#define _CRT_SECURE_NO_WARNINGS

// ������� �̸��� �����ϴ� �ڵ�
#include <stdio.h>

int main()
{
	char name[3][32];

	for (int i = 0; i < 3; i++)
	{
		printf("input name : ");
		scanf("%s", name[i]);
	}

	for (int i = 0; i < 3; i++)
		printf("your name : %s\n", name[i]);
}
#endif


#if 0
#define _CRT_SECURE_NO_WARNINGS

// ���� �ڵ�� ��뷮�� �ڷᱸ���� ���ÿ� �����Ѵٴ� ������ �ִ�.
// ���� �� �����͸� ���� �����Ѵ�.
// ���� �ڵ�� �� �޸𸮿� ���Ͽ� ���� �߻��Ѵ�.
// �̸� �ذ��ϱ� ���� ���ڿ� �����͸� ���
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char* names[3];
	char name[32];

	for (int i = 0; i < 3; i++)
	{
		printf("input name : ");
		scanf("%s", name);
		names[i] = malloc(sizeof(char) * strlen(name) + 1);
		strcpy(names[i], name);
	}

	for (int i = 0; i < 3; i++)
	{
		printf("your name : %s\n", names[i]);
		free(names[i]);
	}
}
#endif


#if 1
#define _CRT_SECURE_NO_WARNINGS

// ���� �ڵ�� �迭�� ��ü�� ���ÿ� ����ȴٴ� ������ �ִ�.
// �̸� �ذ��ϱ� ���� ������ �迭�� ���� �����Ѵ�.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char** names;
	char name[32];

	names = malloc(sizeof(char*) * 3);
	
	for (int i = 0; i < 3; i++)
	{
		printf("input name : ");
		scanf("%s", name);
		names[i] = malloc(sizeof(char) * strlen(name) + 1);
		strcpy(names[i], name);
	}

	// �޸��� ������ �ݵ�� ������ �������� ����� �Ѵ�.
	for (int i = 0; i < 3; i++)
	{
		printf("your name : %s\n", names[i]);
		free(names[i]);
	}

	free(names);
}
#endif