
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

// ���� �ڷᱸ���� ��� ���� ��å�� �̿�ȭ�Ǿ� �ִٴ� ������ �ִ�.
// �̸� �ذ��ϱ� ���� ���� ��å�� �Ͽ�ȭ �Ǵ� �Ϲ�ȭ�غ����� ����.
int insertNode(Node* new, Node* prev, Node* next)
{
    if (new == NULL || prev == NULL || next == NULL)
        return -1;

    prev->next = new;
    next->prev = new;
    new->next = next;
    new->prev = prev;

    return 1;
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
    Node nodes[5];  // ���ÿ� ����

    Node head;

    listInitialize(&head);
    listDisplay(&head);
    for (int i = 0; i < 5; i++) {
        nodes[i].data = i + 1;
        insertNode(nodes+i, &head, head.next);
        listDisplay(&head);
    }

    listDisplayBackwardly(&head);
    return 0;
}
