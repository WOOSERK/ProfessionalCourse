#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node* prev;
    struct Node* next;
} Node;

int listInitialize(Node* head)
{
    if (head == NULL) {
        fprintf(stderr, "listInitialize(): argument is null\n");
        return -1;
    }

    head->next = head;
    head->prev = head;
    return 0;
}

static int insertNode(Node* new, Node* prev, Node* next)
{
    if (new == NULL || prev == NULL || next == NULL)
        return -1;

    new->next = next;
    new->prev = prev;
    prev->next = new;
    next->prev = new;

    return 1;
}

inline int listAdd(Node* head, Node* node)
{
    if (head == NULL || node == NULL)
    {
        fprintf(stderr, "listAdd : argument is null\n");
        return -1;
    }

    insertNode(node, head->prev, head);
    return 0;
}

inline int listAddHead(Node* head, Node* node)
{
    if (head == NULL || node == NULL)
    {
        fprintf(stderr, "listAdd : argument is null\n");
        return -1;
    }

    insertNode(node, head, head->next);
    return 0;
}

#define list_entry(ptr, type, member) \
    (type*)((char*)ptr - (long)&((type*)0)->member)

#define list_foreach(node, head) \
    for (Node* node = head->next; node != head; node = node->next)

#define list_foreach_reverse(node, head)    \
    for (Node* node = head->prev; node != head; node = node->prev)

#define LIST_HEAD(name) \
    Node name = {&(name), &(name)}

// 위의 코드는 라이브러리가 제공하는 코드
// -------------------------------------------
// 아래의 코드는 사용자가 구현하는 코드

// 이전의 코드는 자료구조의 탐색이 어렵다는 단점이 있다. 이를 해결하기 위해
// 반복을 위한 함수를 제공한다.

typedef struct Person
{
    Node list;
    char name[32];
    int age;
} Person;

void display(const Node* head)
{
    if (head == NULL)
    {
        fprintf(stderr, "display(): argument is null\n");
        return;
    }

    system("cls");
    printf("[head]");
    list_foreach(node, head)
    {
        Person* person = list_entry(node, Person, list);
        printf("->[%s(%d)]", person->name, person->age);
    }
    printf("->[head]");
    getchar();
}

void displayBackwardly(const Node* head)
{
    if (head == NULL)
    {
        fprintf(stderr, "displayBackwardly(): argument is null\n");
        return;
    }

    system("cls");
    printf("[head]");
    list_foreach_reverse(node, head)
    {
        Person* person = list_entry(node, Person, list);
        printf("->[%s(%d)]", person->name, person->age);
    }
    printf("->[head]");
    getchar();
}

int main(void) {

    Node head;

    Person p[5] = { {{0}, "takho", 10}, {{0}, "gwiomi", 15}, {{0}, "jackson", 20}, {{0}, "apolo", 25}, {{0}, "puagra", 30} };
    listInitialize(&head);
    display(&head);
    for (int i = 0; i < 5; i++) {
        listAdd(&head, &(p[i].list));
        display(&head);
    }

    displayBackwardly(&head);
    return 0;
}