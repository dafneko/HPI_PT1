#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int length(char *string)
{
    int len = 0;
    if (string == NULL)
        exit(1);
    while (*string++)
    {
        printf("c = %c\n", *string);
        printf("%s\n", string);
        len++;
    }
    return len;
}


int main()
{
    printf("len = %i\n", length("hi there"));
}
