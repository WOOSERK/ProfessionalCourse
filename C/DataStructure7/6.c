#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef int(*HashFn)(void* key);
typedef int(*EqualsFn)(void* key1, void* key2);
typedef struct Node
{
	void* key;
	void* value;
	int hash; // 키에 대한 해시값, key의 타입을 알 수 없으므로
			  // 사용자로부터 정보를 얻어 해시값을 계산하여 저장한다.
	struct Node* next;
} Node;

typedef struct Hashmap
{
	Node** buckets;
	size_t bucketSize;
	size_t count;
	HashFn hash; // 키를 정수, 즉 해시로 변환하는 함수
	EqualsFn equals; // 데이터 비교를 위한 함수
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

void hashmapDestroy(Hashmap* map)
{
	if (map == NULL)
		return;

	//---------------------------------

	//---------------------------------

	free(map->buckets);
	free(map);
}

static size_t calculateIndex(size_t bucketSize, int hash)
{
	return (size_t)hash & (bucketSize - 1);
}

static Node* createNode(void* key, int hash, void* value)
{
	Node* node = calloc(1, sizeof(Node));
	if (node == NULL)
	{
		perror("createNode");
		return NULL;
	}

	node->key = key;
	node->hash = hash;
	node->value = value;

	return node;
}

static int equalsKey(void* key1, int hash1, void* key2, int hash2, EqualsFn equals)
{
	if (key1 == NULL || key2 == NULL || equals == NULL)
		return 0;

	if (key1 == key2) // 주소 값이 같다면 같은 키
		return 1;
	if (hash1 != hash2) // 주소가 같지 않으면 해시 값으로 비교
		return 0;

	return equals(key1, key2);
}

void* hashmapPut(Hashmap* map, void* key, void* value)
{
	if (map == NULL || key == NULL || value == NULL)
	{
		fprintf(stderr, "hashmapPut : argument is null\n");
		return NULL;
	}

	int hash = hashKey(map, key);
	size_t index = calculateIndex(DEFAULT_BUCKET_SIZE, hash);

	Node** ptr = &(map->buckets[index]);

	while (1)
	{
		Node* cur = *ptr;
		if (cur == NULL)
		{
			Node* node = createNode(key, hash, value);
			if (node == NULL)
			{
				fprintf(stderr, "hashmapPut : createNode error\n");
				return NULL;
			}

			*ptr = node;
			map->count++;
			return NULL;
		}

		if (equalsKey(cur->key, cur->hash, key, hash, map->equals) == 1)
		{
			void* oldValue = cur->value;
			cur->value = value;
			return oldValue;
		}

		ptr = &(cur->next);
	}
}

static int hashKey(Hashmap* map, void* key)
{
	int h = map->hash(key);

	h += ~(h << 9);
	h ^= (((unsigned int)h) >> 14);
	h += (h << 4);
	h ^= (((unsigned int)h) >> 10);
	return h;
}

void hashmapDisplay(const Hashmap* map, const char* (*toString)(void*))
{
	if (map == NULL || toString == NULL)
		return;
	system("cls");

	size_t bucketSize = map->bucketSize;
	for (size_t i = 0; i < bucketSize; i++)
	{
		printf("bucket[%2d]", i);

		for (Node* p = map->buckets[i]; p != NULL; p = p->next)
			printf("->[%s]", toString(p->value));
		printf("\n");
	}
	getchar();
}

void* hashmapGet(const Hashmap* map, void* key)
{
	if (map == NULL || key == NULL)
	{
		fprintf(stderr, "hashmapGet : argument is null\n");
		return NULL;
	}

	int hash = hashKey(map, key);
	int index = calculateIndex(map->bucketSize, hash);

	for (Node* node = map->buckets[index]; node != NULL; node = node->next)
	{
		if (equalsKey(node->key, node->hash, key, hash, map->equals) == 1)
			return node->value;
	}

	return NULL;
}

void* hashmapRemove(Hashmap* map, void* key)
{
	if (map == NULL || key == NULL)
	{
		fprintf(stderr, "hashmapRemove : argument is null\n");
		return NULL;
	}

	int hash = hashKey(map, key);
	int index = calculateIndex(map->bucketSize, hash);

	Node** ptr = &map->buckets[index];

	while (1)
	{
		Node* cur = *ptr;
		if (cur == NULL)
			return NULL;

		if (equalsKey(cur->key, cur->hash, key, hash, map->equals) == 1)
		{
			void* value = cur->value;
			*ptr = cur->next;
			free(cur);
			--map->count;
			return value;
		}

		ptr = &(cur->next);
	}
}

int hashmapForEach(Hashmap* map, int (*callback)(void*, void*))
{
	if (map == NULL || callback == NULL)
	{
		fprintf(stderr, "hashmapForEach : argument is null\n");
		return - 1;
	}

	int size = map->bucketSize;
	for (int i = 0; i < size; i++)
	{
		Node* node = map->buckets[i];

		while (node)
		{
			if (callback(node->key, node->value) == 0)
				return 0;
			node = node->next;
		}
	}
	return 0;
}

// 위 코드는 라이브러리 설계자가 제공하는 코드이다.
// -----------------------------------------------------------------------
// 아래 코드는 사용자가 구현하는 코드이다.

typedef struct
{
	char name[32];
	int age;
} Person;

int myHash(void* key)
{
	return strlen((const char*)key);
}

int myEquals(void* key1, void* key2)
{
	if (key1 == NULL || key2 == NULL)
		return 0;
	return strcmp((const char*)key1, (const char*)key2) == 0;
}

const char* myToString(void* p)
{
	static char buf[1024];
	Person* person = p;
	sprintf(buf, "%s(%d)", person->name, person->age);
	return buf;
}

int increaseAge(void* key, void* value)
{
	if (key == NULL || value == NULL)
		return 0;

	Person* p = value;
	++p->age;
	return 1;
}

int main()
{
	Person people[4] =
	{
		{"daniel", 20}, {"susan", 30}, {"petty", 40}, {"eddy", 50}
	};

	Hashmap* map = hashmapCreate(myHash, myEquals);

	for (int i = 0; i < 4; i++)
		hashmapPut(map, people[i].name, &people[i]);
	hashmapDisplay(map, myToString);

	// 해시맵에 저장된 사람 데이터에 대하여 나이를 1씩 증가!
	hashmapForEach(map, increaseAge);
	hashmapDisplay(map, myToString);

	hashmapDestroy(map);
	return 0;
}