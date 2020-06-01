
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
int count;

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
	count = 0;
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

	++count;
	return 0;
}

int listAddHead(int data)
{
	Node* node = malloc(sizeof(Node));
	if (node == NULL)
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

	++count;
	return 0;
}

int listInsert(int index, int data)
{
	if (index < 0 || index >= count)
	{
		fprintf(stderr, "listInsert : out of index\n");
		return -1;
	}

	Node* node = malloc(sizeof(Node));
	if (node == NULL)
	{
		perror("listInsert");
		return -1;
	}

	node->data = data;

	Node* next = head->next;
	for (int i = 0; i < index; i++)
		next = next->next;
	Node* prev = next->prev;

	node->prev = prev;
	node->next = next;
	prev->next = node;
	next->prev = node;

	++count;
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

int listCount()
{
	return count;
}

int listGet(int index, int* outData)
{
	if(outData == NULL)
	{
		fprintf(stderr, "listGet : argument is null\n");
		return -1;
	}
	
	if(index < 0 || index >= count)
	{
		fprintf(stderr, "listGet : out of index\n");
		return -1;
	}

	Node* node;
	if(index < (count>>1))
	{
		node = head->next;

		for (int i = 0; i < index; i++)
			node = node->next;
	}
	else
	{
		int loopCount = count - index - 1;
		node = tail->prev;

		for (int i = 0; i < loopCount; i++)
			node = node->prev;
	}

	*outData = node->data;
	
	return 0;
}

int main()
{
	listInitialize();

	for (int i = 0; i < 5; i++)
		listAdd(i + 1);

	for(int i=0; i<listCount(); i++)
	{
		int data;
		listGet(i, &data);
		printf("%d\n", data);
	}
	
	return 0;
}