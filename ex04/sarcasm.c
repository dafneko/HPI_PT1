#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
 
#define LOWER 0
#define UPPER 1

int to_upper(int c)
{ 
    if (c >= 'a' && c <= 'z')
            return (c - 32);
    return (c);
}

int to_lower(int c)
{ 
    if (c >= 'A' && c <= 'Z')
            return (c + 32);
    return (c);
}

void select_case(char *s)
{
    int to_up;

    while (*s)
    {
        to_up = rand() % 2;
        if (to_up)
            *s = to_upper((int)*s);
        else
            *s = to_lower((int)*s);
        s++;
    }
}
 
int main(void) {
 
    char s[100];
    srand(time(NULL));

    while(1){
        printf("Enter text: ");
        fgets(s, 100, stdin);
        if (strcmp(s, "exit\n") == 0)
            break;
        select_case(s);
        printf("%s", s);
    }
    return 0;
}