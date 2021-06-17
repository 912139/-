#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* caesarCoding (char* c){
    int i = 0;
    while (c[i] != '\0'){
        if (c[i] >= 65 && c[i] <= 90) {
            c[i] += 3;
            if (c[i] > 90)
            c[i] -= 26;
         }
        if (c[i] >= 97 && c[i] <= 122) {
            c[i] += 3;
            if (c[i] > 122)
            c[i] -= 26;
            }
    i++;
    }
   return c;
}

char* caesarDecoding (char* c){
    int i = 0;
    while (c[i] != '\0'){
        if (c[i] >= 65 && c[i] <= 90) {
            c[i] -= 3;
            if (c[i] <= 65)
            c[i] += 26;
         }
        if (c[i] >= 97 && c[i] <= 122) {
            c[i] -= 3;
            if (c[i] <= 97)
            c[i] += 26;
            }
    i++;
    }
    return c;
}

char* transposCoding (char* c, int key) {
int i = 0;
int j = 0;
int sum = 0;
int z = 0;
char* cryptogram;
cryptogram = malloc (sizeof(*c) * 100);
char copy[100];
while (c[i] != '\0'){
if (c[i] == ' ')
i++;
copy[j] = c[i];
i++;
j++;
sum++;
}
i = 0;
j = 0;
strcpy(cryptogram, copy);
while (i < sum) {
 for (int k = 0; k <= key-1; ++k){
  cryptogram[i] = copy[j];
  j += key+1;
  i++;
 }
 z++;
 j = z;
}
return cryptogram;
}

char* transposDeCoding (char* c, int key) {
int i = 0;
int j = 0;
int sum = 0;
int z = 0;
char* massage;
massage = malloc (sizeof(*c) * 100);
strcpy(massage, c);
while (c[i] != '\0'){
sum++;
i++;
}
i = 0;
j = 0;
while (i < sum) {
 for (int k = 0; k <= key; ++k){
  massage[i] = c[j];
  j += key;
  i++;
 }
 z++;
 j = z;
}
return massage;
}

int main()
{
    printf("Exercise 1:\n");
    char str[100] = "This is X";
    char *sc;
    sc = malloc (sizeof(*sc) * 100);
    printf("Original message : %s\n", str);
    sc = caesarCoding(str);
    printf("Cryptogram: %s\n", sc);
    sc = caesarDecoding(sc);
    printf("Decoding: %s\n", sc);

    printf("Exercise 2:\n");
    int k = 4;
    char str1[100] = "This is a secret massage";
    printf("Original message : %s\n", str1);
    char *s;
    s = malloc (sizeof(*s) * 100);
    s = transposCoding(str1, k);
    printf("Cryptogram: %s\n", s);
    s = transposDeCoding(s, k);
    printf("Decoding: %s\n", s);
    return 0;
}