#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// ������ �ڷᱸ���� ���� Ÿ���� �����͸� ������ �� �ִٴ� ������ �ִ�.
// ���� ��� Ÿ���� ó���ϱ� ���� void*�� ����� �ڵ�� �����غ���.
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

// ���� �ڵ�� ���̺귯���� �����ϴ� �ڵ�
// -------------------------------------------
// �Ʒ��� �ڵ�� ����ڰ� �����ϴ� �ڵ�

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
    for (Node* node = head->next; node != head; node = node->next)
    {
        Person* person = (Person*)node;
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
    for (Person* person = head->prev; person != head; person = person->list.prev)
        printf("->[%s(%d)]", person->name, person->age);
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