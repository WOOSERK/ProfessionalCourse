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

	printf("# 전화번호부 관리 프로그램 #\n"
			"1. 등록\n"
			"2. 수정\n"
			"3. 검색\n"
			"4. 삭제\n"
			"5. 목록\n"
			"---------------------------\n"
			"메뉴(0. 종료) : ");
	scanf("%c", &choice);
	myflush();

	return choice;
}

// 수정해야 할 수도 있음
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

	printf("# 전화번호부 등록 #\n");
	printf("이름 : ");
	fgets(name, sizeof(name), stdin);
	name[strlen(name) - 1] = '\0';
	if (listFind(list, name, comparePersonName) != NULL)
	{
		printf("이미 등록된 이름입니다.\n");
		return -1;
	}

	printf("전화번호 : ");
	fgets(phone, sizeof(phone), stdin);
	phone[strlen(phone) - 1] = '\0';

	strcpy(p->name, name);
	strcpy(p->phone, phone);

	int result = listAdd(list, p);
	if (result == 0)
		printf("입력이 완료되었습니다.\n");
	else
		printf("입력에 실패하였습니다.\n");
	return result;
}

void phoneUpdate(List* list)
{
	char name[32];
	char phone[20];

	printf("# 전화번호부 수정 #\n");
	printf("이름 : ");
	fgets(name, sizeof(name), stdin);
	name[strlen(name) - 1] = '\0';

	Node* node = listFind(list, name, comparePersonName);
	if (node == NULL)
	{
		printf("그런 이름은 없습니다.\n");
		return -1;
	}

	printf("수정할 전화번호 : ");
	fgets(phone, sizeof(phone), stdin);
	phone[strlen(phone) - 1] = '\0';

	Person* p = getData(node);
	strcpy(p->phone, phone);
	printf("수정이 완료되었습니다.\n");
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

	printf("# 전화번호부 검색 #\n");
	printf("이름 : ");
	fgets(name, sizeof(name), stdin);
	name[strlen(name) - 1] = '\0';
	if (listFind(list, name, comparePersonName) == NULL)
	{
		printf("그러한 이름은 없습니다.\n");
		return 0;
	}

	printf("%s를 찾았습니다.\n", name);
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

	printf("# 전화번호부 삭제 #\n");

	printf("이름 : ");
	fgets(name, sizeof(name), stdin);
	name[strlen(name) - 1] = '\0';
	if (listFind(list, name, comparePersonName) == NULL)
	{
		printf("그러한 이름은 없습니다.\n");
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
			// 등록
			break;
		case '2':
			phoneUpdate(list);
			// 수정
			break;
		case '3':
			// 검색
			phoneSearch(list);
			break;
		case '4':
			// 삭제
			phoneDelete(list);
			break;
		case '5':
			phoneDisplay(list);
			break;
		default:
			printf("다시 입력해주세요.\n");
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