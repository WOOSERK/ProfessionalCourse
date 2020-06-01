#ifndef _DOUBLY_LINKEDLIST_H_
#define _DOUBLY_LINKEDLIST_H_

typedef void(FreeFunction)(void* ptr);
typedef struct Node Node;
typedef struct List List;
List* listInitialize();
int listAdd(List* list, void* data);
int listDisplay(const List* list, const char* print(void*));
Node* listFind(const List* list, void* data, int compare(void*, void*));
int listDelete(List* list, void* data, int compare(void*, void*));
void* getData(Node* node);
#endif