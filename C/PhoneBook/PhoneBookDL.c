#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DoublyLinkedlist.h"

typedef struct Person
{
	char name[32];
	char phone[20];
} Person;

void freePerson(void* data)
{
	Person* person = data;
	free(person);
}

void myflush()
{
	while (getchar() != '\n')
	{
		;
	}
}

char menu()
{
	char choice;

	printf("# ��ȭ��ȣ�� ���� ���α׷� #\n"
			"1. ���\n"
			"2. ����\n"
			"3. �˻�\n"
			"4. ����\n"
			"5. ���\n"
			"---------------------------\n"
			"�޴�(0. ����) : ");
	scanf("%c", &choice);
	myflush();

	return choice;
}

// �����ؾ� �� ���� ����
int comparePersonName(void* data1, void* data2)
{
	Person* p1 = data1;
	Person* p2 = data2;

	return strcmp(p1->name, p2->name);
}

int phoneAdd(const List* list)
{
	Person* p = malloc(sizeof(Person));
	if (p == NULL)
	{
		perror("phoneAdd");
		return -1;
	}

	char name[32];
	char phone[20];

	printf("# ��ȭ��ȣ�� ��� #\n");
	printf("�̸� : ");
	fgets(name, sizeof(name), stdin);
	name[strlen(name) - 1] = '\0';
	if (listFind(list, name, comparePersonName) != NULL)
	{
		printf("�̹� ��ϵ� �̸��Դϴ�.\n");
		return -1;
	}

	printf("��ȭ��ȣ : ");
	fgets(phone, sizeof(phone), stdin);
	phone[strlen(phone) - 1] = '\0';

	strcpy(p->name, name);
	strcpy(p->phone, phone);

	int result = listAdd(list, p);
	if (result == 0)
		printf("�Է��� �Ϸ�Ǿ����ϴ�.\n");
	else
		printf("�Է¿� �����Ͽ����ϴ�.\n");
	return result;
}

void phoneUpdate(List* list)
{
	char name[32];
	char phone[20];

	printf("# ��ȭ��ȣ�� ���� #\n");
	printf("�̸� : ");
	fgets(name, sizeof(name), stdin);
	name[strlen(name) - 1] = '\0';

	Node* node = listFind(list, name, comparePersonName);
	if (node == NULL)
	{
		printf("�׷� �̸��� �����ϴ�.\n");
		return -1;
	}

	printf("������ ��ȭ��ȣ : ");
	fgets(phone, sizeof(phone), stdin);
	phone[strlen(phone) - 1] = '\0';

	Person* p = getData(node);
	strcpy(p->phone, phone);
	printf("������ �Ϸ�Ǿ����ϴ�.\n");
}

int phoneSearch(const List* list)
{
	if (list == NULL)
	{
		fprintf(stderr, "phoneSearch : list is empty\n");
		return -1;
	}

	char name[32];
	char phone[20];

	printf("# ��ȭ��ȣ�� �˻� #\n");
	printf("�̸� : ");
	fgets(name, sizeof(name), stdin);
	name[strlen(name) - 1] = '\0';
	if (listFind(list, name, comparePersonName) == NULL)
	{
		printf("�׷��� �̸��� �����ϴ�.\n");
		return 0;
	}

	printf("%s�� ã�ҽ��ϴ�.\n", name);
	return 1;
}

int phoneDelete(List* list)
{
	if (list == NULL)
	{
		fprintf(stderr, "phoneSearch : list is empty\n");
		return -1;
	}

	char name[32];
	char phone[20];

	printf("# ��ȭ��ȣ�� ���� #\n");

	printf("�̸� : ");
	fgets(name, sizeof(name), stdin);
	name[strlen(name) - 1] = '\0';
	if (listFind(list, name, comparePersonName) == NULL)
	{
		printf("�׷��� �̸��� �����ϴ�.\n");
		return 0;
	}

	return listDelete(list, name, comparePersonName);
}

const char* printPerson(void* data)
{
	static char buf[60];

	Person* p = data;
	sprintf(buf, "%s, %s", p->name, p->phone);

	return buf;
}

int phoneDisplay(const List* list)
{
	if (list == NULL)
	{
		fprintf(stderr, "phoneDisplay : list is NULL\n");
		return -1;
	}

	listDisplay(list, printPerson);

	return 0;
}

void loop(List* list)
{
	while (1)
	{
		char choice = menu();
		system("cls");
		switch (choice)
		{
		case '0':
			return;
		case '1':
			phoneAdd(list);
			// ���
			break;
		case '2':
			phoneUpdate(list);
			// ����
			break;
		case '3':
			// �˻�
			phoneSearch(list);
			break;
		case '4':
			// ����
			phoneDelete(list);
			break;
		case '5':
			phoneDisplay(list);
			break;
		default:
			printf("�ٽ� �Է����ּ���.\n");
			break;
		}
	}
}

int main()
{
	List* list = listInitialize(NULL);
	loop(list);
	listFinalize(list);
}