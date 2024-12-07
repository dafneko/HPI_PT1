#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define ERROR -1
int div_int(int a, int b)
{
    /* How can I signal if a is not divisible by b or that the division is invalid? */
    if (a % b != 0)
        return (ERROR);
    return (a / b);
}
 
int main(void)
{
    int a;
    int b;
    printf("Enter two integers: ");
    /* What do I do if the input is invalid? 
    Maybe scanf can give me more information?*/
    // Hint: Terminate the program on wrong input here.
    // Using while with scanf is very tricky...
    
    scanf("%d %d", &a, &b);
    /* How do I make sure the numbers are not negative? */
    if (a < 0 || b <= 0)
    {
        printf("Enter two non-negative integers. The second integer must be positive.\n");
        return (EXIT_FAILURE);
    }

    int result = div_int(a, b);
    if(result == ERROR)
    {
        printf("Enter two divisible numbers.\n");
        return (EXIT_FAILURE);
    }
 
    printf("%d / %d = %d\n", a, b, div_int(a, b));
    return 0;
}