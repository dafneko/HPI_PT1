#include <stdlib.h>
#include <stdio.h>

int main()
{
    int i;
    printf("List of ten random numbers:\n");
    for (i = 0; i < 10; i++)
        printf("%i = %i\n", i + 1 , rand());
}