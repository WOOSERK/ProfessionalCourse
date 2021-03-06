
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
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

// 이전 자료구조는 삽입 정책이 일반화되어 있지만 사용하기가 어렵다는 단점이 있다.
// 사용자가 사용하기 쉽도록 코드를 변경해 보자.
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

void listDisplay(const Node* head) {
    if (head == NULL) {
        fprintf(stderr, "listDisplay(): argument is null\n");
        return;
    }

    system("cls");
    printf("[head]");
    for (Node* node = head->next; node != head; node = node->next)
        printf("->[%2d]", node->data);
    printf("->[head]");
    getchar();
}

void listDisplayBackwardly(const Node* head) {
    if (head == NULL) {
        fprintf(stderr, "listDisplay(): argument is null\n");
        return;
    }

    system("cls");
    printf("[head]");
    for (Node* node = head->prev; node != head; node = node->prev)
        printf("->[%2d]", node->data);
    printf("->[head]");
    getchar();
}

int main(void) {
    Node nodes[5];  // 스택에 생성

    Node head;

    listInitialize(&head);
    listDisplay(&head);
    for (int i = 0; i < 5; i++) {
        nodes[i].data = i + 1;
        listAdd(&head, nodes + i);
        listDisplay(&head);
    }

    listDisplayBackwardly(&head);
    return 0;
}