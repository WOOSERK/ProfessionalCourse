#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	const char* key;
	const char* value;
	struct Node* next;
} Node;

typedef struct HashMap
{
	Node** buckets;
	size_t bucketSize;
	size_t count;
} Hashmap;

Hashmap* hashmapCreate(size_t bucketSize)
{
	if (bucketSize == 0)
	{
		fprintf(stderr, "hashmapCreate : bucket size is zero\n");
		return NULL;
	}

	Node** buckets = calloc(bucketSize, sizeof(Node*));
	if (buckets == NULL)
	{
		perror("hashmapCreate");
		return NULL;
	}

	Hashmap* map = calloc(1, sizeof(Hashmap));
	if (map == NULL)
	{
		perror("hashmapCreate");
		free(buckets);
		return NULL;
	}

	map->buckets = buckets;
	map->bucketSize = bucketSize;

	return map;
}

// 이전의 자료구조는 정보구조체와 버킷리스트만 삭제했다.
// 이제 생성된 노드와 깊은 복사된 문자열도 삭제해보자.
void hashmapDestroy(Hashmap* map)
{
	if (map == NULL)
		return;

	size_t bucketSize = map->bucketSize;
	for (unsigned int i = 0; i < bucketSize; i++)
	{
		Node* cur = map->buckets[i];

		while (cur)
		{
			free(cur->key);
			free(cur->value);
			Node* next = cur->next;
			free(cur);
			cur = next;
		}
	}

	free(map->buckets);
	free(map);
}

int hashCode(char* name, size_t bucketSize)
{
	if (name == NULL || bucketSize <= 0)
	{
		fprintf(stderr, "hashCode : argument is null\n");
		return -1;
	}

	int result = 0;
	int length = strlen(name);
	for (int i = 0; i < length; i++)
		result += name[i];

	return result % bucketSize;
}

static Node* createNode(const char* key, const char* value)
{
	if (key == NULL || value == NULL)
	{
		fprintf(stderr, "createNode : argument is null\n");
		return NULL;
	}

	Node* node = calloc(1, sizeof(Node));
	if (node == NULL)
	{
		perror("createNode");
		return NULL;
	}

	// 아래 코드는 얕은 복사이다.
	// node->key = key;
	// node->value = value;

	// 깊은 복사 코드로 변경한다.
	char* k = malloc(strlen(key) + 1);
	if (k == NULL)
	{
		perror("createNode");
		free(node);
		return NULL;
	}

	char* v = malloc(strlen(key) + 1);
	if (v == NULL)
	{
		perror("createNode");
		free(node);
		free(k);
		return NULL;
	}

	strcpy(k, key);
	strcpy(v, value);
	node->key = k;
	node->value = v;
	return node;
}

int hashmapPut(Hashmap* map, const char* key, const char* value, char** oldValue)
{
	if (map == NULL || key == NULL || value == NULL || oldValue == NULL)
	{
		fprintf(stderr, "hashmapPut : argument is null\n");
		return -1;
	}

	int index = hashCode(key, map->bucketSize);
	Node** ptr = &(map->buckets[index]);

	while (1)
	{
		Node* cur = *ptr;

		if (cur == NULL)
		{
			Node* node = createNode(key, value);
			if (node == NULL)
			{
				fprintf(stderr, "hashmapCreate : createNode error\n");
				return -1;
			}

			*oldValue = NULL;
			*ptr = node;
			map->count++;
			return 0;
		}

		if (strcmp(cur->key, key) == 0)
		{
			*oldValue = cur->value;

			char* v = malloc(strlen(value) + 1);
			if (v == NULL)
			{
				perror("hashmapPut");
				return -1;
			}
			strcpy(v, value);
			cur->value = v;
			return 0;
		}
		ptr = &(cur->next);
	}
}

void hashmapDisplay(Hashmap* map)
{
	if (map == NULL)
		return;
	system("cls");

	size_t bucketSize = map->bucketSize;

	for (unsigned int i = 0; i < bucketSize; i++)
	{
		printf("bucket[%2u]", i);
		Node* bucket = map->buckets[i];

		for (Node* node = bucket; node != NULL; node = node->next)
		{
			printf("->[%s(%s)]", node->key, node->value);
		}

		printf("\n");
	}
	getchar();
}

// 만약 코드를 아래와 같이 작성할 경우, 얕은 복사가 일어나므로
// 함수 호출이 끝나면 해당 포인터는 댕글링 포인터가 된다.
// 이를 해결하기 위해 깊은 복사를 수행한다.
void foo()
{
	char buf[32];
	printf("input key : ");
	scanf("%s", buf);
}

int main()
{
	char* names[8] = { "takho", "gwiomi", "jackson", "yeoul", "neogul", "neogul", "meongmuli", "yeoul" };
	char* ages[8] = { "10", "20", "30", "40", "50", "50", "60", "70" };

	Hashmap* map = hashmapCreate(10);
	hashmapDisplay(map);
	for (int i = 0; i < 8; i++)
	{
		char* oldValue = NULL;
		hashmapPut(map, names[i], ages[i], &oldValue);

		if (oldValue != NULL)
			free(oldValue);

		hashmapDisplay(map);
	}

	hashmapDestroy(map);
}