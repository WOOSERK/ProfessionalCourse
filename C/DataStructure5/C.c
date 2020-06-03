
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

/*
int hashmapPut(Hashmap* map, const char* name, const char* age, char** oldValue)
{
	if (map == NULL || name == NULL || age == NULL || oldValue == NULL)
	{
		fprintf(stderr, "hashmapPut : argument is null\n");
		return -1;
	}

	Node* node = calloc(1, sizeof(Node));
	if(node == NULL)
	{
		perror("hashmapPut");
		return -1;
	}
	node->key = name;
	node->value = age;

	int index = hashCode(name, map->bucketSize);

	if(map->buckets[index] != NULL)
		*oldValue = map->buckets[index]->value;

	map->buckets[index] = node;
	map->count++;
	return 0;
}
*/

int hashmapPut(Hashmap* map, const char* name, const char* age, char** oldValue)
{
	if (map == NULL || name == NULL || age == NULL || oldValue == NULL)
	{
		fprintf(stderr, "hashmapPut : argument is null\n");
		return -1;
	}

	Node* node = calloc(1, sizeof(Node));
	if (node == NULL)
	{
		perror("hashmapPut");
		return -1;
	}
	node->key = name;
	node->value = age;

	int index = hashCode(name, map->bucketSize);
	Node* cur = map->buckets[index];

	if(cur == NULL)
	{
		map->buckets[index] = node;
		map->count++;
		return 0;
	}
	
	while (cur)
	{
		if (strcmp(cur->key, name) == 0) // 기존 키가 존재하는 경우
		{
			*oldValue = cur->value;
			cur->value = age;
			return 0;
		}
		cur = cur->next;
	}

	// 키가 존재하지 않는 경우
	node->next = map->buckets[index];
	map->buckets[index] = node;
	map->count++;
	return 0;
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