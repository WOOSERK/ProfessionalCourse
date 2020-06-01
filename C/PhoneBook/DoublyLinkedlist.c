#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedlist.h"

typedef struct Node
{
	void* data;
	struct Node* prev;
	struct Node* next;
} Node;

typedef struct List
{
	struct Node* head;
	struct Node* tail;
	FreeFunction* fn;
	int count;
} List;

List* listInitialize(FreeFunction* fn)
{
	List* list = malloc(sizeof(List));
	if (list == NULL)
	{
		perror("listInitialize");
		return NULL;
	}

	Node* head = malloc(sizeof(Node));
	if (head == NULL)
	{
		perror("listInitialize");
		free(list);
		return NULL;
	}

	Node* tail = malloc(sizeof(Node));
	if (tail == NULL)
	{
		perror("listInitialize");
		free(list);
		free(head);
		return NULL;
	}

	head->prev = head;
	head->next = tail;
	tail->prev = head;
	tail->next = tail;

	list->head = head;
	list->tail = tail;
	list->fn = fn;
	list->count = 0;

	return list;
}

int listFinalize(List* list)
{
	if (list == NULL)
	{
		fprintf(stderr, "listFinalize : list is empty\n");
		return -1;
	}
	Node* head = list->head;
	Node* tail = list->tail;

	if (head == NULL || tail == NULL)
	{
		fprintf(stderr, "listFinalize : list is wrong\n");
		return -1;
	}

	while (head->next != tail)
	{
		Node* target = head->next;
		head->next = target->next;
		if (list->fn != NULL)
			list->fn(target->data);
		free(target);
	}

	free(list->head);
	free(list->tail);
	return 0;
}

int listAdd(List* list, void* data)
{
	if (list == NULL)
	{
		fprintf(stderr, "listAdd : list is empty\n");
		return -1;
	}

	Node* node = malloc(sizeof(Node));
	if (node == NULL)
	{
		perror("listAdd");
		return -1;
	}

	node->data = data;

	Node* tail = list->tail;
	Node* prev = tail->prev;

	node->prev = prev;
	node->next = tail;
	tail->prev = node;
	prev->next = node;
	
	list->count++;
	return 0;
}

Node* listFind(const List* list, void* data, int compare(void*, void*))
{
	if (list == NULL || data == NULL)
	{
		fprintf(stderr, "argument is NULL\n");
		return NULL;
	}

	Node* node = list->head;

	while (node->next != list->tail)
	{
		node = node->next;
		if (compare(node->data, data) == 0)
			return node;
	}

	return NULL;
}

int listDelete(List* list, void* data, int compare(void*, void*))
{
	if (list == NULL || data == NULL)
	{
		fprintf(stderr, "argument is NULL\n");
		return -1;
	}

	Node* node = list->head;

	while (node->next != list->tail)
	{
		node = node->next;
		if (compare(node->data, data) == 0)
		{
			Node* prev = node->prev;
			Node* next = node->next;

			prev->next = next;
			next->prev = prev;

			if(list->fn != NULL)
				list->fn(node->data);
			free(node);
			list->count--;
			printf("삭제가 완료되었습니다.\n");
			return 1;
		}
	}

	return 0;
}

int listDisplay(const List* list, const char* print(void*))
{
	if (list == NULL)
	{
		fprintf(stderr, "listDisplay : list is null\n");
		return -1;
	}

	Node* node = list->head;
	int count = 1;
	while (node->next != list->tail)
	{
		node = node->next;
		printf("%d. %s\n", count++, print(node->data));
	}

	return 0;
}

void* getData(Node* node)
{
	return node->data;
}