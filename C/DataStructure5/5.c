#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// ������ �ڷᱸ���� ���� Ÿ���� �����͸� ������ �� �ִٴ� ������ �ִ�.
// ���� ��� Ÿ���� ó���ϱ� ���� void*�� ����� �ڵ�� �����غ���.
typedef struct Node {
    void* data;
    struct Node* prev;
    struct Node* next;
} Node;

int listInitialize(Node* head) {
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

    prev->next = new;
    next->prev = new;
    new->next = next;
    new->prev = prev;

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
    char name[32];
    int age;
} Person;

const char* printPerson(void* data)
{
    static char buf[36];
    Person* p = data;
    sprintf(buf, "%s(%d)", p->name, p->age);
    return buf;
}

void display(const Node* head, const char* print(void*)) {
    if (head == NULL) {
        fprintf(stderr, "display(): argument is null\n");
        return;
    }

    system("cls");
    printf("[head]");
    for (Node* node = head->next; node != head; node = node->next)
        printf("->[%s]", print(node->data));
    printf("->[head]");
    getchar();
}

void displayBackwardly(const Node* head, const char* print(void*)) {
    if (head == NULL) {
        fprintf(stderr, "displayBackwardly(): argument is null\n");
        return;
    }

    system("cls");
    printf("[head]");
    for (Node* node = head->prev; node != head; node = node->prev)
        printf("->[%s]", print(node->data));
    printf("->[head]");
    getchar();
}

int main(void) {
    Node nodes[5];  // ���ÿ� ����

    Node head;

    Person p[5] = { {"takho", 10}, {"gwiomi", 15}, {"jackson", 20}, {"apolo", 25}, {"puagra", 30} };
    listInitialize(&head);
    display(&head, printPerson);
    for (int i = 0; i < 5; i++) {
        nodes[i].data = p + i;
        listAdd(&head, nodes + i);
        display(&head, printPerson);
    }

    displayBackwardly(&head, printPerson);
    return 0;
}