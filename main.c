#include <stdio.h>
#include <stdlib.h>

#define T int
#define SIZE 1000
#define true 1 == 1
#define false 1 != 1
#define SZ 10

typedef struct {
    int pr;
    int dat;
} Node;

Node* arr[SZ];
int head;
int tail;
int items;

typedef int boolean;
int cursor = -1;
T Stack[SIZE];


void initQueue() {
    for (int i = 0; i < SZ; ++i) {
        arr[i] = NULL;
    }
    head = 0;
    tail = 0;
    items = 0;
}

Node* rem() {
    int flag;
    if (items == 0) {
        printf("%s \n", "Queue is empty");
        return NULL;
    }
    else {
        int i = 0;
        int idx = 0;
        Node *tmp;
        tmp = arr[head];
        flag = head;
        for (i = head+1; i < tail; ++i) {
            idx = i % SZ;
            if (arr[idx]->pr <= tmp->pr){
                tmp = arr[idx];
                flag = idx % SZ;
            }
        }
        i = flag;
        while (i < tail) {
            idx = i % SZ;
            arr[idx] = arr[idx+1];
            i++;
        }
        arr[i] = NULL;
        items--;
        tail--;
        return tmp;
    }
}

void ins(int pr, int dat) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->dat = dat;
    node->pr = pr;
    if (items == 0) {
        arr[tail++] = node;
        items++;
    } else if (items == SZ) {
        printf("%s \n", "Queue is full");
        return;

    } else {
        int idx = tail++ % SZ;
        arr[idx] = node;
        items++;
    }
}

void printQueue() {
    printf("[ ");
    for (int i = 0; i < SZ; ++i) {
        if (arr[i] == NULL)
            printf("[*, *] ");
        else
            printf("[%d, %d] ", arr[i]->pr, arr[i]->dat);
    }
    printf(" ]\n");
}

boolean pushStack(T data) {
    if (cursor < SIZE) {
        Stack[++cursor] = data;
        return true;
    } else {
        printf("%s \n", "Stack overflow");
        return false;
    }
}

T popStack() {
    if (cursor != -1) {
        return Stack[cursor--];
    } else {
        printf("%s \n", "Stack is empty");
        return -1;
    }
}




int main() {
    printf("%s", "Exercise 1: ");
    initQueue();
    ins(1, 11);
    ins(3, 22);
    ins(4, 33);
    ins(2, 44);
    ins(3, 55);
    ins(4, 66);
    ins(5, 77);
    ins(1, 88);
    ins(2, 99);
    ins(6, 100);
    printQueue();
    for (int i = 0; i < 7; ++i) {
        Node* n = rem();
        printf("pr=%d, dat=%d \n", n->pr, n->dat);
    }
    printQueue();
    ins(1, 110);
    ins(3, 120);
    ins(6, 130);
    printQueue();

    for (int i = 0; i < 5; ++i) {
        Node* n = rem();
        printf("pr=%d, dat=%d \n", n->pr, n->dat);
    }
    printQueue();

    printf("%s", "Exercise 2: ");
    T a;
    T c;
    printf("%s", "Enter the number: ");
    scanf("%d", &a);
    while (a>=1){
    c = a % 2;
    a = a / 2;
    pushStack (c);
    }
    while (cursor != -1) {
        printf("%d ", popStack());
    }
    return 0;
}
