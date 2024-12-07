#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
 
#define FALSE 0
#define TRUE 1

void tri(int n, int* t){
    *t = n * (n + 1) / 2;
}
 
void fac(int n, int* t){
    *t = 1;
    while (n > 0)
    {
        *t *= n;
        n--;
    }
}

int is_prime(int n)
{
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return FALSE;        
    return TRUE;
}

void prime(int n, int* t){
    int count = 0;
    int i;
    for (i = 2; i < INT32_MAX && count < n; i++)
    {
        if (is_prime(i))
            count++;
    }
    *t = i - 1;
}
 
 
int main(void){
    int x;
 
    tri(5, &x);
    printf("tri(5) = %d\n", x);   // 15
 
    fac(6, &x);
    printf("fac(6) = %d\n", x);   // 720
 
    prime(7, &x);
    printf("prime(7) = %d\n", x); // 17
 
    return 0;
}