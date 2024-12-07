#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    int i;
    int nb;

    i = 0;
    srand(time(NULL));
    printf("List of ten random numbers:\n");
    while (i < 200)
    {
        nb = 1000 + rand() / (RAND_MAX / 1000);
        if (nb % 2 == 0)
        {
            printf("%i: %i\n", i + 1 , nb);
            i++;
        }
    }
}

// int main()
// {
//     int i;
//     int nb;

//     i = 0;
//     srand(time(NULL));
//     printf("List of ten random numbers:\n");
//     while (i < 200)
//     {
//         do
//             nb = 1000 + rand() / (RAND_MAX / 1000);
//         while (nb % 2 != 0);
//         printf("%i: %i\n", i + 1 , nb);
//         i++;
//     }
// }

// int main()
// {
//     int i;
//     int nb;

//     i = 0;
//     nb = 1;
//     srand(time(NULL));
//     printf("List of ten random numbers:\n");
//     while (i < 200)
//     {
//         nb = 1;
//         while (nb % 2 != 0)
//         {
//             nb = 1000 + rand() / (RAND_MAX / 1000);
//         }
//         printf("%i: %i\n", i + 1 , nb);
//         i++;
//     }
// }