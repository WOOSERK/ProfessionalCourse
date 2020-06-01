
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next;
	struct Node* prev;
} Node;

Node* head;
Node* tail;

int listInitialize()
{
	head = malloc(sizeof(Node));
	if (head == NULL)
	{
		perror("listInitialize");
		return -1;
	}

	tail = malloc(sizeof(Node));
	if (tail == NULL)
	{
		perror("listInitialize");
		free(head);
		return -1;
	}

	head->next = tail;
	head->prev = head;

	tail->next = tail;
	tail->prev = head;
	return 0;
}

int listAdd(int data)
{
	Node* node = malloc(sizeof(Node));
	if (node == NULL)
	{
		perror("listAdd");
		return -1;
	}

	node->data = data;

	Node* prev = tail->prev;
	node->prev = prev;
	node->next = tail;
	tail->prev = node;
	prev->next = node;

	return 0;
}

int listAddHead(int data)
{
	Node* node = malloc(sizeof(Node));
	if(node == NULL)
	{
		perror("listAddHead");
		return -1;
	}
	
	node->data = data;

	Node* next = head->next;
	
	node->prev = head;
	node->next = next;
	head->next = node;
	next->prev = node;
	
	return 0;
}

void listDisplay()
{
	system("cls");

	printf("[head]");
	Node* cur = head->next;
	while (cur != tail)
	{
		printf("<->[%2d]", cur->data);
		cur = cur->next;
	}
	printf("<->[tail]\n");
	getchar();
}

void listDisplayBackwardly()
{
	system("cls");

	printf("[tail]");
	Node* cur = tail->prev;
	while (cur != head)
	{
		printf("<->[%2d]", cur->data);
		cur = cur->prev;
	}
	printf("<->[head]\n");
	getchar();
}

int main()
{
	listInitialize();

	listDisplay();
	for (int i = 0; i < 5; i++)
	{
		listAddHead(i + 1);// listAdd(i + 1);
		listDisplay();
	}
	listDisplayBackwardly();

	return 0;
}