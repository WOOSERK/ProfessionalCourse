
#include <stdio.h>
#include <stdlib.h>

// 이전 자료구조는 내부적으로 사용되는 더미 헤드와 더미 테일을 삭제하지 않으므로
// 메모리 누수가 발생한다는 문제가 있다. 이를 해결하기 위해 마무리 함수를 도입한다.
typedef struct Node
{
	int data;
	struct Node* next;
} Node;

Node* head;
Node* tail;

// 이전 자료구조는 마지막 노드를 식별하기 위해 널을 사용하고 있다.
// 이는 잠재적으로 널 참조가 발생할 위험이 있다. 이를 해결하기 위해 더미 테일을 도입한다.
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
		free(head); // 중요
		perror("listInitialize");
		return -1;
	}

	head->next = tail;
	tail->next = tail;

	return 0;
}

int listFinalize()
{
	if(head == NULL || tail == NULL)
	{
		fprintf(stderr, "listFinalize : list is wrong\n");
		return -1;
	}

	while(head->next != tail)
	{
		Node* target = head->next;
		head->next = target->next;
		free(target);
	}

	free(head);
	free(tail);
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
	node->next = tail;

	Node* cur = head;

	while (cur->next != tail)
		cur = cur->next;

	cur->next = node;
	return 0;
}

void listDisplay()
{
	system("cls");
	printf("[head]");

	for (Node* node = head->next; node != tail; node = node->next)
	{
		printf("->[%2d]", node->data);
	}
	printf("->[tail]");
	getchar();
}

int main()
{
	listInitialize();

	listDisplay();
	for (int i = 0; i < 5; i++)
	{
		listAdd(i + 1);
		listDisplay();
	}

	listFinalize();
	return 0;
}