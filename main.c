#include <stdio.h>
#include <stdlib.h>

void swapInt(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void sortInserts(int* arr, int len) {
    int temp, pos;
    for (int i = 1; i < len; ++i) {
        temp = arr[i];
        pos = i - 1;
        while (pos >= 0 && arr[pos] > temp) {
            arr[pos + 1] = arr[pos];
            pos--;
        }
        arr[pos + 1] = temp;
    }
}

void sortInserts2(int* arr, int i, int j) {
    int temp, pos;
    for (int n = i; n < j; ++n) {
        temp = arr[n];
        pos = n - 1;
        while (pos >= 0 && arr[pos] > temp) {
            arr[pos + 1] = arr[pos];
            pos--;
        }
        arr[pos + 1] = temp;
    }
}

void qs(int* arr, int first, int last) {
    int i = first;
    int j = last;

    int x = arr[(first + last) / 2];

    do {
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;

        if (i <= j) {
            swapInt(&arr[i], &arr[j]);
            i++;
            j--;
        }
    } while (i <= j);

    if (i < last) qs(arr, i, last);
    if (first < j) qs(arr, first, j);
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

void evenFunction (int* evenarray, int a, int e) {
    evenarray[e] = a;
}

void oddFunction (int* oddarray, int a, int i) {
    oddarray[i] = a;
}


void fillIntRandom(int* array, int size, int border) {
    int i = 0;
    int e = 0;
    for (int i = 0; i < size; ++i)
        *(array + i) = rand() % border;
}

int init_size_even(int* arr, int* evenarray, int* oddarray, int size) {
    int e = 0;
    for (int i = 0; i < size; ++i) {
      if (*(arr + i) % 2 == 0) {
        evenarray[e] = arr[i];
        e++;  
    } else {
        oddarray[i] = arr[i];
    }
}
    return e;
}

void mergeArrays (int* evenarray, int* oddarray, int size){
int j = 0;
for (int i = 0; i < size; ++i) {
    if (*(oddarray + i) == 0) {
        oddarray[i] = evenarray[j];
        j++;
    }
}


}

void bucketSort(int* arr, int len) {
   const int max = len;
   const int b = 10;

    int buckets[b][max+1];
    for (int i = 0; i < b; ++i) {
       buckets[i][max] = 0;
    }

    for (int digit = 1; digit < 1000000000; digit*=10) {
        for (int i = 0; i < max; ++i) {
            int d = (arr[i] / digit) % b;

           int counter = buckets[d][max];
            buckets[d][counter] = arr[i];
            counter++;
           buckets[d][max] = counter;

//            buckets[d][buckets[d][max]++] = arr[i];
        }
        int idx = 0;
        for (int i = 0; i < b; ++i) {
            for (int j = 0; j < buckets[i][max]; ++j) {
                arr[idx++] = buckets[i][j];
            }
            buckets[i][max] = 0;
        }
    }
}

int median(int a, int b, int c) {
int midarray[3];
midarray[0] = a;
midarray[1] = b;
midarray[2] = c;
sortInserts (midarray, 3);
return midarray[1];
}

void qs2(int* arr, int first, int last) {
    int i = first;
    int j = last;
    int const a = 10;
  if (i - j < a) {
       sortInserts2(arr, i, j);
  } else {
    int x = median(arr[i], arr[i+j/2], arr[j]);
    if (x == arr[i])
    swapInt(&arr[i],&arr[i+j/2]);
    if (x == arr[j])
    swapInt(&arr[j],&arr[i+j/2]);
    do {
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;

        if (i <= j) {
            swapInt(&arr[i], &arr[j]);
            i++;
            j--;
        }
    } while (i <= j);

    if (i < last) qs(arr, i, last);
    if (first < j) qs(arr, first, j);
}
}

int main() {
    printf("Excercise1:\n");
    const int SZ = 30;
    int arr[SZ];
    fillIntRandom(arr, SZ, 100);
    printIntArray(arr, SZ, 3);
    qs2(arr, 0, SZ - 1);
    printIntArray(arr, SZ, 3);
    printf("\n");

    printf("Excercise2:\n");
    fillIntRandom(arr, SZ, 100);
    printIntArray(arr, SZ, 3);
    int* evenarray;
    evenarray = (int*) calloc(SZ, sizeof(int));
    int* oddarray;
    oddarray = (int*) calloc(SZ, sizeof(int));
    int e = init_size_even(arr,evenarray,oddarray,SZ);
    bucketSort(evenarray, e);
    mergeArrays (evenarray, oddarray, SZ);
    printIntArray(oddarray, SZ, 3);
    return 0;
}