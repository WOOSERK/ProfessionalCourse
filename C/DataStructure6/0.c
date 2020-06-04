
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

void hashmapDestroy(Hashmap* map)
{
	if (map == NULL)
		return;

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

// 이전 자료구조는 데이터 삽입에 대한 코드가 이원화되어 있다는 단점이 있다.
// 이를 해결해 보자
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

	node->key = key;
	node->value = value;
	return node;
}

int hashmapPut(Hashmap* map, const char* name, const char* age, char** oldValue)
{
	if (map == NULL || name == NULL || age == NULL || oldValue == NULL)
	{
		fprintf(stderr, "hashmapPut : argument is null\n");
		return -1;
	}

	int index = hashCode(name, map->bucketSize);
	Node** ptr = &(map->buckets[index]);

	while (1)
	{
		Node* cur = *ptr;
		// 버킷이 비는 경우
		if (cur == NULL)
		{
			Node* node = createNode(name, age);
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
		// 버킷이 비어 있지 않은 경우
		if (strcmp(cur->key, name) == 0) // 기존 키가 존재하는 경우
		{
			*oldValue = cur->value;
			cur->value = age;
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

	for (int i = 0; i < bucketSize; i++)
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

int main()
{
	char* names[6] = { "takho", "gwiomi", "jackson", "yeoul", "neogul", "neogul" };
	char* ages[6] = { "10", "20", "30", "40", "50", "50" };

	Hashmap* map = hashmapCreate(10);
	hashmapDisplay(map);
	for (int i = 0; i < 6; i++)
	{
		char* oldValue = NULL;
		hashmapPut(map, names[i], ages[i], &oldValue);
		hashmapDisplay(map);
	}

	hashmapDestroy(map);
}