#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T char
#define true 1 == 1
#define false 1 != 1
typedef int boolean;

typedef struct OneLinkNode {
    int dat;
    struct OneLinkNode *next;
} OneLinkNode;

typedef struct {
    OneLinkNode *head;
    int size;
} OneLinkList;

typedef struct TwoLinkNode {
    int dat;
    struct TwoLinkNode *next;
    struct TwoLinkNode *prev;
} TwoLinkNode;

typedef struct {
    struct TwoLinkNode *head;
    struct TwoLinkNode *tail;
    int size;
} TwoLinkList;

void initTwoLinkList(TwoLinkList *lst) {
    lst->head = NULL;
    lst->tail = NULL;
    lst->size = 0;
}

void printTwoLinkIntNode(TwoLinkNode *n) {
    if (n == NULL) {
        printf("[]");
        return;
    }
    printf("[%d]", n->dat);
}

void printTwoLinkIntList(TwoLinkList *lst) {
    TwoLinkNode *current = lst->head;
    if (current == NULL) {
        printTwoLinkIntNode(current);
    } else {
        do {
            printTwoLinkIntNode(current);
            current = current->next;
        } while (current != NULL);
    }
    printf(" Size: %d \n", lst->size);
}

boolean TwoLinkEnqueue(TwoLinkList *queue, T value) {
    TwoLinkNode *tmp = (TwoLinkNode*) malloc(sizeof(TwoLinkNode));
    if (tmp == NULL) {
        printf("Out of memory! \n");
        return false;
    }
    tmp->dat = value;
    tmp->next = NULL;
    tmp->prev = queue->tail;

    if (queue->tail != NULL) {
        queue->tail->next = tmp;
    }
    if (queue->head == NULL) {
        queue->head = tmp;
    }

    queue->tail = tmp;
    queue->size++;
    return true;
}

void checkSorted (OneLinkList *lst){
OneLinkNode *parent = lst->head;
OneLinkNode *current = lst->head->next;
        while(current != NULL)  {
           if (parent->dat > current->dat){
               printf("Result: No\n");
               return;
           }
        parent = parent->next;
        current = current->next;
        }
     printf("Result: Yes\n");
}

int main () {
TwoLinkList *lst = (TwoLinkList*) malloc(sizeof(TwoLinkList));
initTwoLinkList(lst);
TwoLinkEnqueue(lst, 0);
TwoLinkEnqueue(lst, 0);
TwoLinkEnqueue(lst, 1);
TwoLinkEnqueue(lst, 1);
TwoLinkEnqueue(lst, 3);
printf("lst: ");
printTwoLinkIntList(lst);
checkSorted(lst);
return 0;
}
