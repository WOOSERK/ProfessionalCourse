
#include <stdio.h>
#include <stdlib.h>

// 이전 자료구조는 노드 탐색을 위한 코드가 중복되어 있고 리스트 전체에 걸쳐
// 탐색을 수행하므로 성능 상의 이슈도 존재한다.
// 이를 해결하기 위해 코드를 개선해 보자.
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

static Node* listSearch(int index)
{
	if (index < 0 || index >= count)
		return NULL;
	
	Node* node;
	if (index < (count >> 1))
	{
		node = head->next;
		for (int i = 0; i < index; i++)
			node = node->next;
	}
	else
	{
		node = tail->prev;
		for (int i = count - 1; i > index; i--)
			node = node->prev;
	}

	return node;
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

	Node* next = listSearch(index);
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
	if (outData == NULL)
	{
		fprintf(stderr, "listGet : argument is null\n");
		return -1;
	}

	if (index < 0 || index >= count)
	{
		fprintf(stderr, "listGet : out of index\n");
		return -1;
	}

	Node* node = listSearch(index);

	*outData = node->data;

	return 0;
}

int listRemoveTail(int* outData)
{
	if (count == 0)
	{
		fprintf(stderr, "listRemoveTail : list is empty\n");
		return -1;
	}

	if (outData == NULL)
	{
		fprintf(stderr, "listRemoveTail : argument is null\n");
		return -1;
	}

	Node* node = tail->prev;
	Node* prev = node->prev;

	tail->prev = prev;
	prev->next = tail;

	*outData = node->data;
	free(node);
	--count;
	return 0;
}

int listRemoveHead(int* outData)
{
	if (count == 0)
	{
		fprintf(stderr, "listRemoveHead : list is empty\n");
		return -1;
	}

	if (outData == NULL)
	{
		fprintf(stderr, "listRemoveHead : argument is null\n");
		return -1;
	}

	Node* node = head->next;
	Node* next = node->next;

	head->next = next;
	next->prev = head;

	*outData = node->data;
	free(node);
	--count;
	return 0;
}

int listRemove(int index, int* outData)
{
	if (count == 0)
	{
		fprintf(stderr, "listRemove : list is empty\n");
		return -1;
	}

	if (outData == NULL)
	{
		fprintf(stderr, "listRemove : argument is null\n");
		return -1;
	}

	if (index < 0 || index >= count)
	{
		fprintf(stderr, "listRemove : out of index\n");
		return -1;
	}

	Node* node = listSearch(index);

	Node* prev = node->prev;
	Node* next = node->next;

	prev->next = next;
	next->prev = prev;

	*outData = node->data;
	free(node);
	--count;
	return 0;
}

int main()
{
	listInitialize();

	for (int i = 0; i < 5; i++)
		listAdd(i + 1);

	for (int i = 0; i < 5; i++)
	{
		int data;
		listGet(i, &data);
		printf("%d\n", data);
	}
		return 0;
	}