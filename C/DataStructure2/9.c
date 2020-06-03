
#include <stdio.h>
#include <stdlib.h>

// ���� �ڷᱸ���� ���������� ���Ǵ� ���� ���� ���� ������ �������� �����Ƿ�
// �޸� ������ �߻��Ѵٴ� ������ �ִ�. �̸� �ذ��ϱ� ���� ������ �Լ��� �����Ѵ�.
typedef struct Node
{
	int data;
	struct Node* next;
} Node;

Node* head;
Node* tail;

// ���� �ڷᱸ���� ������ ��带 �ĺ��ϱ� ���� ���� ����ϰ� �ִ�.
// �̴� ���������� �� ������ �߻��� ������ �ִ�. �̸� �ذ��ϱ� ���� ���� ������ �����Ѵ�.
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
		free(head); // �߿�
		perror("listInitialize");
		return -1;
	}

	head->next = tail;
	tail->next = tail;

	return 0;
}

int listFinalize()
{
	if (head == NULL || tail == NULL)
	{
		fprintf(stderr, "listFinalize : list is wrong\n");
		return -1;
	}

	while (head->next != tail)
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

int listSet(int index, int newData, int* oldData)
{
	Node* cur = head;
	
	for(int i=0; i<index; i++)
	{
		cur = cur->next;
		if(cur == tail)
		{
			fprintf(stderr, "listSet : index is over\n");
			return -1;
		}
	}

	*oldData = cur->data;
	cur->data = newData;
	return 0;
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

	int data = 0;
	listSet(2, 10, &data);
	listDisplay();
	listFinalize();

	return 0;
}