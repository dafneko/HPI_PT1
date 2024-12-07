#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *s;
    s = calloc((strlen("I love PT1") + 1), sizeof(char));
    if (!s)
        return (EXIT_FAILURE);
    memcpy(s,"I love PT1", strlen("I love PT1") + 1);

    printf("s = %s\n", s);
    const char *temp = s;
    while (*temp)
    {
        printf("%p: %c\n", temp, *temp);
        temp++;
    }
    free(s);
    return (0);
}