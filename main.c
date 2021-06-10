#include <stdio.h>
#include <stdlib.h>
#define n 6
#define T char
#define true 1 == 1
#define false 1 != 1
typedef int boolean;

static int matrix[n][n] = {
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 1},
        {0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0},
};
int visitedDepth[n] = {0};
int links[n] = {0};

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

void initOneLinkList(OneLinkList *lst) {
    lst->head = NULL;
    lst->size = 0;
}

void initTwoLinkList(TwoLinkList *lst) {
    lst->head = NULL;
    lst->tail = NULL;
    lst->size = 0;
}

T TwoLinkDequeue(TwoLinkList *queue) {
    if (queue->size == 0) {
        printf("Queue is empty \n");
        return -1;
    }
    TwoLinkNode *tmp = queue->head;
    T data = queue->head->dat;

    queue->head = queue->head->next;

    if (queue->head != NULL) {
        queue->head->prev = NULL;
    }
    if (tmp == queue->tail) {
        queue->tail = NULL;
    }

    free(tmp);
    queue->size--;
    return data;
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

void printOneLinkIntNode(OneLinkNode *m) {
    if (m == NULL) {
        printf("[]");
        return;
    }
    printf("[%d]", m->dat);
}

void printOneLinkIntList(OneLinkList *lst) {
    OneLinkNode *current = lst->head;
    if (current == NULL) {
        printOneLinkIntNode(current);
    } else {
        do {
            printOneLinkIntNode(current);
            current = current->next;
        } while (current != NULL);
    }
    printf(" Size: %d \n", lst->size);
}

boolean pushOneLinkStack(OneLinkList *stack, T value) {
    OneLinkNode *tmp = (OneLinkNode*) malloc(sizeof(OneLinkNode));
    if (tmp == NULL) {
        printf("Stack overflow \n");
        return false;
    }
    tmp->dat = value;
    tmp->next = stack->head;

    stack->head = tmp;
    stack->size++;
    return true;
}

T popOneLinkStack(OneLinkList *stack) {
    if (stack->size == 0) {
        printf("Stack is empty \n");
        return -1;
    }
    OneLinkNode *tmp = stack->head;
    T data = stack->head->dat;
    stack->head = stack->head->next;
    free(tmp);
    stack->size--;
    return data;
}

T getDataStack(OneLinkList *stack) {
    if (stack->size == 0) {
        printf("Stack is empty \n");
        return -1;
    }
    T data = stack->head->dat;
    return data;
}

void depthTravers(int st, OneLinkList* stack) {
    int r;
    //printf("%d ", st);

    visitedDepth[st] = 1;
    pushOneLinkStack(stack, st);
    while (stack->size > 0){
    for (r = 0; r < n; ++r) {
        if (matrix[st][r] == 1 && !visitedDepth[r]) {
            visitedDepth[r] = 1;
            pushOneLinkStack(stack, r);
            st = r;
            r = -1;
        }  
    }
    popOneLinkStack(stack);
    st = getDataStack(stack);
    }

}

void depthTravers2(int st) {
    int r;
    //printf("%d ", st);

    visitedDepth[st] = 1;
    for (r = 0; r < n; ++r) {
        if (matrix[st][r] == 1) {
            links[r]++;
        if (!visitedDepth[r]) {
            depthTravers2(r);
        }
        }
    }
}

void resetArr(int* array) {
    for (int i = 0; i < n; ++i) {
        array[i] = 0;
    }
}

void clearVisited(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = 0;
    }
}

int get2dInt(const int row, const int col) {
    return *((*(matrix + row)) + col);
}

void widthTravers(int start, const int size) {
    TwoLinkList* queue = (TwoLinkList*) malloc(sizeof(TwoLinkList));
    initTwoLinkList(queue);
    int visited[size];
    clearVisited(visited, size);
    TwoLinkEnqueue(queue, start);
    while (queue->size > 0) {
        int indx = TwoLinkDequeue(queue);
        if (visited[indx] == 1) continue;
        visited[indx] = 1;
        //printf("%d ", indx);
        for (int i = 0; i < size; ++i) {
            if (get2dInt(indx, i) == 1) {
             if (visited[i] == 0){
                TwoLinkEnqueue(queue, i);
             }
             links[i]++;
            }
        }
    }
}

int main () {
    OneLinkList* stack = (OneLinkList*) malloc(sizeof(OneLinkList));
    initOneLinkList(stack);
    printf("Exercise 1:\n");
    depthTravers(0, stack);
    for (int i = 0; i < n; ++i)
    printf("%d", visitedDepth[i]);
    resetArr(visitedDepth);
    printf("\n");

    printf("Exercise 2:\n");
    printf("depth: ");
    depthTravers2(3);
    for (int i = 0; i < n; ++i)
    printf("%d", links[i]);
    resetArr(links);
    printf("\n");
    printf("width: ");
    widthTravers(3, n);
    for (int i = 0; i < n; ++i)
    printf("%d", links[i]);
    return 0;
}