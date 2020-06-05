#include <stdio.h>
#include <string.h>

typedef int(*HashFn)(void* key);
typedef int(*EqualsFn)(void* key1, void* key2);
typedef struct Node
{
	void* key;
	void* value;
	int hash; // Ű�� ���� �ؽð�, key�� Ÿ���� �� �� �����Ƿ�
			  // ����ڷκ��� ������ ��� �ؽð��� ����Ͽ� �����Ѵ�.
	struct Node* next;
} Node;

typedef struct Hashmap
{
	Node** buckets;
	size_t bucketSize;
	size_t count;
	HashFn hash; // Ű�� ����, �� �ؽ÷� ��ȯ�ϴ� �Լ�
	EqualsFn equals; // ������ �񱳸� ���� �Լ�
} Hashmap;

#define DEFAULT_BUCKET_SIZE (16)
Hashmap* hashmapCreate(HashFn hash, EqualsFn equals)
{
	if (hash == NULL || equals == NULL)
	{
		fprintf(stderr, "hashmapCreate : argument is null\n");
		return NULL;
	}

	Hashmap* map = calloc(1, sizeof(Hashmap));
	if (map == NULL)
	{
		perror("hashmapCreate");
		return NULL;
	}

	Node** buckets = calloc(DEFAULT_BUCKET_SIZE, sizeof(Node*));
	if (buckets == NULL)
	{
		perror("hashmapCreate");
		free(map);
		return NULL;
	}

	map->buckets = buckets;
	map->bucketSize = DEFAULT_BUCKET_SIZE;
	map->hash = hash;
	map->equals = equals;

	return map;
}

Hashmap* hashmapDestroy(Hashmap* map)
{
	if (map == NULL)
		return;

	//---------------------------------

	//---------------------------------

	free(map->buckets);
	free(map);
}

// �� �ڵ�� ���̺귯�� �����ڰ� �����ϴ� �ڵ��̴�.
// -----------------------------------------------------------------------
// �Ʒ� �ڵ�� ����ڰ� �����ϴ� �ڵ��̴�.

// ���������� ���ٰ� �����Ѵ�.
// key : �̸�, value : Person
typedef struct
{
	char name[32];
	int age;
} Person;

// ���ڷ� ���޵� Ű�� �ؽ� ������ ��ȯ�ϴ� �Լ�
int myHash(void* key)
{
	return strlen((const char*)key);
}

// �浹�� Ű�� ���Ͽ� �񱳸� �����ϴ� �Լ�
int myEquals(void* key1, void* key2)
{
	if (key1 == NULL || key2 == NULL)
		return 0;
	return strcmp((const char*)key1, (const char*)key2) == 0;
}

int main()
{
	Hashmap* map = hashmapCreate(myHash, myEquals);
	hashmapDestroy(map);
	return 0;
}