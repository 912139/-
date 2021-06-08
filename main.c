#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int boolean;

typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} BinTreeIntNode;

void fillIntRandom(int* array, int size, int border) {
    for (int i = 0; i < size; ++i)
        *(array + i) = rand() % border;
}

void printIntArray(int* array, int size, int offset) {
    char format[7];
    sprintf(format, "%%%dd", offset);
    for (int i = 0; i < size; ++i) {
        printf(format, array[i]);
        if (i != size - 1)
            printf(",");
    }
    printf("\n");
}

void printBinTree(BinTreeIntNode *root) {
    if (root) {
        printf("%d", root->key);
        if (root->left || root->right) {
            printf("(");
            if (root->left)
                printBinTree(root->left);
            else
                printf("NULL");
            printf(",");
            if (root->right)
                printBinTree(root->right);
            else
                printf("NULL");
            printf(")");
        }
    }
}

BinTreeIntNode* treeInsert(BinTreeIntNode *t, int data) {
    BinTreeIntNode *newNode;
    newNode = (BinTreeIntNode*) malloc(sizeof(BinTreeIntNode));
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    BinTreeIntNode *current = t;
    BinTreeIntNode *parent = t;
    if (t == NULL) {
        t = newNode;
    } else {
        while (current->key != data) {
            parent = current;
            if (current->key > data) {
                current = current->left;
                if (current == NULL) {
                    parent->left = newNode;
                    return t;
                }
            } else {
                current = current->right;
                if (current == NULL) {
                    parent->right = newNode;
                    return t;
                }
            }
        }
    }
    return t;
}

BinTreeIntNode* initTree (int* array, int SIZE){
BinTreeIntNode* tree = (BinTreeIntNode*) malloc(sizeof(BinTreeIntNode));
tree = NULL;
fillIntRandom(array, SIZE, 100);
//printIntArray(array, SIZE, 3);
for (int i = 0; i < SIZE; ++i) {
tree = treeInsert(tree, array[i]);
}
return tree;
}

int max (int a, int b) {
if (a >= b)
return a;
return b;
}

int mod (int a, int b) {
    if (a>=b)
    return (a-b);
    else
    return (b-a);
}

boolean checkBalance(BinTreeIntNode* t){
  if (heightSearch(t) == -1){
      return false;
  }
  return true;
}

int heightSearch (BinTreeIntNode* current){
int left_height = 0;
int right_height = 0;
int k;

if(current->left){
k = heightSearch(current->left);
if (k == -1){
return -1;
}
left_height = k;
left_height++;
}

if(current->right){
k = heightSearch(current->right);
if (k == -1){
return -1;
}
right_height = k;
right_height++;
}
int c = mod(left_height,right_height);
if (c > 1){
return -1;
}
 return max(left_height, right_height);
}

float percentOfTrees (BinTreeIntNode** array, int const TREES) {
    int balanced = 0;
    float percent;
    float p = TREES; // потому, что TREES int const и может преобразовать percent в int
for (int i = 0; i < TREES; ++i){
    if (checkBalance(array[i]))
    balanced++;
}
return percent = (balanced/p)*100;
}

boolean searchKey (BinTreeIntNode* current, int dat) {
if (current && current->key == dat){
    return true;
}
if(current->left){
    if (searchKey(current->left, dat))
    return true;
}
if(current->right){
   if (searchKey(current->right, dat))
   return true;
}
return false;
}

int main()
{
    int const SIZE = 10000;
    int const TREES = 50;
    BinTreeIntNode* array_of_trees[TREES];
    int array[SIZE];

    printf("Exercise 2: \n");
    for (int i = 0; i < TREES; ++i){
    array_of_trees[i] = initTree(array, SIZE);
    //printBinTree(array_of_trees[i]);
    }

    printf("Exercise 1: \n");
    printf("Tree[0]: ");
    printBinTree(array_of_trees[0]);
    printf("\n");
    printf("The tree is balanced: ");
    if (checkBalance(array_of_trees[0]))
       printf("True\n");
    else printf("False\n");

    printf("Exercise 3: \n");
    printf("Percentage of balanced trees: ");
    printf("%.2f\n", percentOfTrees(array_of_trees, TREES));

    printf("Exercise 4: \n");
    printf("Tree[0]: ");
    printBinTree(array_of_trees[0]);
    printf("\n");
    int num = 67;
    printf("Value %d in the tree: ", num);
    if (searchKey(array_of_trees[0], num))
    printf("Yes");
    else printf("No");
    return 0;
}
