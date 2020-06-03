
#include <stdio.h>
#include <stdlib.h>

// 이전 자료구조는 잘 동작하지만 역방향 탐색에 대한 비용이 높다는 단점이 있다.
// 이를 해결하기 위해 이중 연결 리스트를 도입한다.

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

// 아래의 함수를 수정해보자.
int listAdd(Node* head, Node* node) {
    if (head == NULL || node == NULL) {
        fprintf(stderr, "listAdd(): argument is null\n");
        return -1;
    }

    Node* prev = head->prev;
    
    node->next = head;
    node->prev = prev;

    prev->next = node;
    head->prev = node;

    return 0;
}

int listAddHead(Node* head, Node* node)
{
    if (head == NULL || node == NULL)
    {
        fprintf(stderr, "listAddHead() : argument is null\n");
        return -1;
    }

    Node* next = head->next;

    node->next = next;
    node->prev = head;

    next->prev = node;
    head->next = node;

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
        listAddHead(&head, nodes + i);
        listDisplay(&head);
    }

    listReverse(&head), listDisplay(&head);
    return 0;
}
