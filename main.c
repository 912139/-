#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bynaryFunction (int a, char* number) {
 if (a <= 0)
 return;
 bynaryFunction (a / 2, number);
 if (a % 2 == 0)
 strcat (number , "0");
 else
 strcat (number , "1");
}

int powerFunction (int a, int exp) {
if (exp <= 0)
return 1;
return a * powerFunction (a, exp - 1);
}

int powerFunction2 (int a, int exp) {
if (exp <=0) return 1;
if (exp % 2 == 0)
return powerFunction2 (a * a, exp / 2);
else
return a* powerFunction2 (a, exp - 1);
}

int routes (int x, int y, int obs[5][5]) {
if (obs[x][y] == 1)
    return 0;
if (x==0 && y==0)
    return 0;
else if (x==0 ^ y==0)
    return 1;
else
    return routes (x,y-1,obs) + routes (x-1,y,obs);
}

int main()
{
 char num[] = "";
 bynaryFunction (75, num);
 printf("Exercise 1\n");
 printf("%s\n", num);
 printf("Exercise 2.1\n");
 printf("%d \n", powerFunction (5,8));
 printf("Exercise 2.2\n");
 printf("%d \n", powerFunction2 (5,8));
 printf("Exercise 3\n");
    const int sizeX = 5;
    const int sizeY = 5;
    int x,y;
    int obstacle[5][5] = {};
    obstacle[3][3] = 1;
    obstacle[0][1] = 1;
    for (y = 0; y < sizeY; ++y) {
        for (x = 0; x < sizeX; ++x) {
    printf("%5d", routes (x,y,obstacle));
        }
    printf("\n");
    }
    return 0;
}
