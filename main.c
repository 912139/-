#include <stdio.h>
#include <stdlib.h>

int checkFunction (int A)
{
    int P = 2;
    int T;
    int isPrime = 0;
    while (P < A)
    {
    T = A % P;
      if (T == 0)
         {
         isPrime = 1;
         break;
         }
    P++;
    }
    if (isPrime)
        printf("%s" , "The number is not prime:");
    else
        printf("%s" , "The number is prime:");
    return 0;
}


int main()
{
    int a;
    printf("%s" , "Enter the number: ");
    scanf("%d" , &a);
    checkFunction(a);
    return 0;
}
