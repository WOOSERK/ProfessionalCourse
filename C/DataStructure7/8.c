
#include <stdio.h>
#include <stdlib.h>
// ���� �˻� Ʈ��(BST)
typedef struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
} Node;
Node* root;

static Node* createNode(int data)
{
	Node* node = calloc(1, sizeof(Node));
	if (node == NULL)
	{
		perror("createNode");
		return NULL;
	}

	node->data = data;
	return node;
}

int bstInsert(int data)
{
	// ���� ���� ���� ���� ���ʿ� ū ���� ���� ���� �����ʿ� �����ϸ� �ȴ�.
	// �� �ڷᱸ���� ���� �˻�Ʈ���̹Ƿ� Ű�� ���Ͽ� �ߺ��� ������� �ʴ´�.

	Node* node = createNode(data);
	if (node == NULL)
	{
		perror("bstInsert");
		return -1;
	}

	Node* parent = NULL;
	Node* cur = root;
	while (cur != NULL)
	{
		parent = cur;
		if (data < cur->data)
			cur = cur->left;
		else if (data > cur->data)
			cur = cur->right;
		else
		{
			free(node);
			return -1;
		}
	}

	if (data < parent->data)
		parent->left = node;
	else
		parent->right = node;

	//Node** ptr = &root;
	//while (ptr)
	//{
	//	Node* cur = *ptr;
	//	if (cur->data < data)
	//		cur = cur->right;
	//	else if (cur->data > data)
	//		cur = cur->left;
	//	else
	//		return 0;

	//	ptr = &cur;
	//}

	//*ptr = node;
	return 0;
}


int main()
{
	int arr[8] = { 4,2,1,3,6,5,7,8 };
	for (int i = 0; i < 8; i++)
	{
		bstInsert(arr[i]);
	}
}