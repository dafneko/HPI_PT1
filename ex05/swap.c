#include <stdio.h>




int main()
{
    int a = 42;
    int b = 25;
    int tmp;

    tmp = b;
    b = a;
    a = tmp;
}


/* alternative :)))
int main()
{
    int a = 42;
    int b = 25;

    a ^= b;
    b ^= a;
    a ^= b; 

    printf("a = %i\n", a);
    printf("b = %i\n", b);
}
*/