#ifndef LIST_H
#define LIST_H

typedef void(*DISPLAY)(void*);
typedef int(*COMPARE)(void*, void*);

typedef struct Node {
    void  *data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    unsigned int size;
} LinkedList;

void llistInit(LinkedList *list);
void llistPush(LinkedList *list, void *data);
void llistDelete(LinkedList *list, Node *node);
void llistDestroy(LinkedList *list);
Node* llistPop(LinkedList *list);
Node* llistGetNode(LinkedList *list, COMPARE compare, void *data);
void llistPrint(LinkedList *list, DISPLAY display);


#endif