#include <stdio.h>
#include <stdlib.h>

int hashFunction (char* c){
    int i = 0;
    int hashVal = 0;
    while (c[i] != '\n'){
    hashVal += c[i];
    i++;
    }
    return hashVal;
}

int sum (int a){
    int array[5] = {50, 10, 5, 2, 1};
    int s = 0;
    for (int i = 0; i < 5; ++i) {
     if (s < a) {
        while (s <= a){
        s += array[i];
        }
        if (s > a)
        s -= array[i];
        }
     }
 return s;
}

int main()
{
    printf("Exercise 1:\n");
    int k;
    char str[100] = "";
    printf("Enter the string: ");
    fgets(str, 100, stdin);
    k = hashFunction(str);
    printf("Hash function value: %d\n", k);

    printf("Exercise 2:\n");
    int a = 98;
    printf("%d", sum(a));
    return 0;
}
