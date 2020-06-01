
// 이중 연결 리스트
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next;
	struct Node* prev;
} Node;

typedef struct List
{
	Node* head;
	Node* tail;
	int size;
} List;

int listInitialize(List* list)
{
	Node* head = malloc(sizeof(Node));
	if(head == NULL)
	{
		perror("listInitialize");
		return -1;
	}

	Node* tail = malloc(sizeof(Node));
	if (tail == NULL)
	{
		perror("listInitialize");
		free(head);
		return -1;
	}

	head->prev = head;
	head->next = tail;
	list->head = head;
	
	tail->prev = head;
	tail->next = tail;
	list->tail = tail;
	
	list->size = 0;
	
	return 0;
}

int listAddFirst(List* list, int data)
{
	if (list == NULL)
	{
		fprintf(stderr, "listAddFirst : list is empty\n");
		return -1;
	}
	
	Node* node = malloc(sizeof(Node));
	if(node == NULL)
	{
		perror("listAddFirst");
		return -1;
	}
	
	node->data = data;

	Node* head = list->head;
	Node* nextNode = head->next;
	
	node->next = nextNode;
	nextNode->prev = node;
	head->next = node;
	node->prev = head;
	list->size++;
	
	return 0;
}

int listAddIndex(List* list, int index, int data)
{
	if(list == NULL)
	{
		fprintf(stderr, "listAddIndex : list is empty\n");
		return -1;
	}

	if(index < 0 || index >= list->size)
	{
		fprintf(stderr, "listAddIndex : out of index\n");
		return -1;
	}
	
	Node* node = malloc(sizeof(Node));
	if(node == NULL)
	{
		perror("listAddIndex");
		return -1;
	}
	node->data = data;
	
	Node* prevNode = list->head;
	for(int i=0; i<index; i++)
		prevNode = prevNode->next;
	
	Node* nextNode = prevNode->next;

	node->prev = prevNode;
	prevNode->next = node;
	node->next = nextNode;
	nextNode->prev = prevNode;

	list->size++;
	
	return 0;
}

int listAddLast(List* list, int data)
{
	if (list == NULL)
	{
		fprintf(stderr, "listAddLast : list is empty\n");
		return -1;
	}

	Node* node = malloc(sizeof(Node));
	if(node == NULL)
	{
		perror("listAddLast");
		return -1;
	}
	
	node->data = data;
	
	Node* tail = list->tail;
	Node* prevNode = tail->prev;

	node->next = tail;
	tail->prev = node;
	node->prev = prevNode;
	prevNode->next = node;
	list->size++;
	
	return 0;
}

int listUpdate(List* list, int index, int data, int *oldData)
{
	if (list == NULL)
	{
		fprintf(stderr, "listUpdate : list is empty\n");
		return -1;
	}

	if (index < 0 || index >= list->size)
	{
		fprintf(stderr, "listUpdate : out of index\n");
		return -1;
	}

	Node* target = list->head->next;
	for(int i=0; i<index; i++)
	{
		target
	}
	
	return 0;
}

int listInsert(List* list, int index, int newData, int *oldData)
{
	if (list == NULL)
	{
		fprintf(stderr, "listInsert : list is empty\n");
		return -1;
	}

	if (index < 0 || index >= list->size)
	{
		fprintf(stderr, "listInsert : out of index\n");
		return -1;
	}

	
}

int listDelete(List* list, int data)
{
	if (list == NULL)
	{
		fprintf(stderr, "listDelete : list is empty\n");
		return -1;
	}

	Node* cur = list->head->next;
	
	while(cur != list->tail)
	{
		if(cur->data == data)
		{
			cur->prev->next = cur->next;
			cur->next->prev = cur->prev;
			free(cur);
			return data;
		}
		else
			cur = cur->next;
	}

	return -1;
}

int main()
{
	List list;
	listInitialize(&list);

	// 1. 앞, 뒤, 중간 추가
	// 2. 수정
	// 3. 삽입
	// 4. 제거
}