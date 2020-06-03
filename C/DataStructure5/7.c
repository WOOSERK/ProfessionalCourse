
//#define DATASIZE (sizeof(Person)-sizeof(Node))
#define DISTANCE (&((Person *)0)->list)
#include <stdio.h>

typedef struct Node
{
	struct Node* next;
	struct Node* prev;
} Node;

typedef struct
{
	char name[32];
	int age;
	Node list;
} Person;

int main()
{
	Person p = { "daniel", 20 };
	Node* pList = &p.list;

	//Person* ptr = (char*)pList - DATASIZE;
	Person* ptr = (Person*)((char*)pList - DISTANCE);
	printf("%s, %d\n", ptr->name, ptr->age);
}