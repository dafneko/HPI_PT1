#include <stdio.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0

typedef enum functions
{
    END,
    TRI,
    FAC,
    FIB,
    PRIME
}   functions;

int is_prime(int nb)
{
    if (nb <= 1)
        return (0);
    for (int i = 2; i < nb; i++)
        if (nb % i == 0)
            return (FALSE);
    return (TRUE);
}
    
int prime(int n)
{
    int num = 0;
    int itr = 1;
    int count = 0;

    if (n < 1)
        return (FALSE);
    while (count < n && itr <= __INT_MAX__)
    {
        if (is_prime(itr))
        {
            count++;
            num = itr;
        }
        itr++;
    }
    return (num);
}

int fib(int n)
{
    int fib_num = 0;
    int prev = 1;
    int pre_prev = 0;

    if (n == 1)
        return (1);
    for (int i = 2; i <= n; i++)
    {
        fib_num = prev + pre_prev;
        pre_prev = prev;
        prev = fib_num;
    }
    return (fib_num);
}

int fac(int n)
{
    int fac_num = 1;

    while (n > 0)
        fac_num *= n--; 
    return (fac_num);
}

int tri(int n)
{
    return (n * (n + 1) / 2);
}

void call_function(int (*func)(int n), int choice)
{
    int n;

    printf("n? ");
    scanf("%i", &n);
    if (n < 1)
    {
        printf("Invalid.\n");
        return;
    }
    switch (choice)
    {
    case TRI:
        printf("tri(%i) = %i\n", n, func(n)); 
        break;
    case FAC:
        printf("fac(%i) = %i\n", n, func(n));
        break;
    case FIB:
        printf("fib(%i) = %i\n", n, func(n));
        break;
    case PRIME:
        printf("prime(%i) = %i\n", n, func(n));
        break;
    default:
        break;
    }
}

int main()
{
    int func;
    do
    {
        printf("Aktion? ");
        scanf("%i", &func);
        switch (func)
        {
        case END:
            printf("Bye.\n");
            break;
        case TRI:
            call_function(tri, func);
            break;
        case FAC:
            call_function(fac, func);
            break;
        case FIB:
            call_function(fib, func);
            break;
        case PRIME:
            call_function(prime, func);
            break;
        default:
            printf("invalid input.\n");
            break;
        }
    }
    while (func != 0);
}