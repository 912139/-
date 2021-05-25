#include <stdio.h>
#include <stdlib.h>
#include <math.h>

 void sortArray (int* array, const int row, const int col){
  int sum = row*col;
  for (int j = 0; j < sum; ++j){
  for (int i = 0; i < sum-1; ++i){
    if (*(array + i) > *(array + i + 1))
     swap((array + i), (array + i + 1));
    }
  }
 }

 void swap (int* a, int* b) {
 int t = *a;
 *a = *b;
 *b = t;
 }

 void printArray (int array[3][3], const int row, const int col){
  for (int i = 0; i < row; ++i){
    for (int j = 0; j < col; ++j){
    printf("%4d", array[i][j]);
    }
    printf("\n");
  }
 }

int initArray2 (double* array2, int const n) {
for (int i = 0; i < n; ++i){
    printf("Enter the number %d: ", i+1);
    scanf("%lf", &array2[i]);
    }
}

void formula2 (double* array2, int const n) {
for (int i = 0; i < n; ++i){
array2[i] = sqrt(fabs(array2[i])) + 5 * pow(array2[i], 3);
if (array2[i] > 400)
    printf("A%d > 400: ", i);
}
}

void invertFunction2 (double* array2, int const n){
double temp;
int j = n-1;
int i = 0;
while (i != j){
     temp = array2[i];
     array2[i] = array2[j];
     array2[j] = temp;
     i++;
     j--;
}
}

void printArray2 (double* array2, int const n){
for (int i = 0; i < n; ++i)
    printf("[%.2f]", array2[i]);
}

int main()
{
int const row = 3;
int const column = 3;
int arr[3][3] = {
1,9,2,
5,7,6,
4,3,8
};
printf("Exercise 1: \n");
printArray(arr,row,column);
sortArray(arr,row,column);
printf("\n");
printArray(arr,row,column);
printf("\n");

printf("Exercise 3: \n");
int const n = 11;
double arr2[n];
initArray2(arr2,n);
invertFunction2(arr2,n);
formula2(arr2,n);
printf("\n");
printf("Final sequence: ");
printArray2(arr2,n);
    return 0;
}
