
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define list_entry(ptr, type, member)    \
    (type*)((char*)ptr - (long)&((type*)0)->member)

#define list_foreach(node, head)    \
    for (node = (head)->next; node != (head); node = node->next)

#define list_foreach_reverse(node, head)    \
    for (node = (head)->prev; node != (head); node = node->prev)

#define LIST_HEAD(name) \
    Node name = { &(name), &(name)}


typedef struct Node {
    struct Node* next;
    struct Node* prev;
} Node;

static void insertNode(Node* new, Node* prev, Node* next) {
    new->next = next;
    new->prev = prev;
    prev->next = new;
    next->prev = new;
}

inline void listAdd(Node* head, Node* node) {
    insertNode(node, head->prev, head);
}

inline void listAddHead(Node* head, Node* node) {
    insertNode(node, head, head->next);
}

inline void listRemove(Node* node) {
    Node* prev = node->prev;
    Node* next = node->next;
    prev->next = next;
    next->prev = prev;
}

// 위의 코드는 라이브러리가 제공하는 코드입니다.
// ----------------------------------------------------------------------------------
// 아래의 코드는 사용자가 구현하는 코드입니다.
typedef struct Person {
    char name[32];
    int age;
    Node list;
} Person;

void display(const Node* head) {
    if (head == NULL) {
        fprintf(stderr, "display(): argument is null\n");
        return;
    }

    system("cls");
    printf("[head]");
    Node* node;
    list_foreach(node, head) {
        Person* p = list_entry(node, Person, list);
        printf("<->[%s(%d)]", p->name, p->age);
    }
    printf("<->[head]");
    getchar();
}

void displayBackwardly(const Node* head) {
    if (head == NULL) {
        fprintf(stderr, "displayBackwardly(): argument is null\n");
        return;
    }

    system("cls");
    printf("[head]");
    Node* node;
    list_foreach_reverse(node, head) {
        Person* p = list_entry(node, Person, list);
        printf("<->[%s(%d)]", p->name, p->age);
    }
    printf("<->[head]");
    getchar();
}

int main(void) {
    Person people[4] = {
        {"eddy", 20}, {"pororo", 30}, {"petty", 40}, {"poby", 50}
    };

    LIST_HEAD(head);
    display(&head);
    for (int i = 0; i < 4; i++) {
        listAdd(&head, &(people[i].list));
        display(&head);
    }

    Node* node;
    list_foreach(node, &head) {
        Person* p = list_entry(node, Person, list);
        if (strcmp(p->name, "pororo") == 0)
            // 아래의 삭제 함수를 구현해 보세요 :D
            listRemove(node);
    }
    display(&head);

    return 0;
}
