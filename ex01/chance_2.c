#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <time.h>

/* This solution guarentees non-repetitivenes/non-deterministic variability,
    unlike using rand() alone by itself.
    That is due to a different seed value, created by srand
    using the current time, each time the program is executed.
    Although it is still biased towards lower numbers (when the range is bigger)
    due to the use of modulo operator. Mod operator  */
int main()
{
    int i;
    srand(time(NULL));
    printf("List of ten random numbers:\n");
    for (i = 0; i < 10; i++)
        printf("%i = %i\n", i + 1 , rand() % 100 + 1);
}


// int main()
// {
//     int i;
//     printf("List of ten random numbers:\n");
//     for (i = 0; i < 10; i++)
//         printf("%i = %i\n", i + 1 , rand() % 100);
// }


/* 
    the RAND_MAX value, defined in the stdlib library only
    guarantees the lowest maximum number, but the actual value of
    RAND_MAX actually depends on different compilers or systems 
*/

// int main()
// {
//     int i;
//     printf("List of ten random numbers:\n");
//     for (i = 0; i < 10; i++)
//         printf("%i = %i\n", i + 1 , rand() / (RAND_MAX / 100 + 1));
// }

/* lol biased much? */
// int main()
// {
//     int i;
//     int num = INT_MAX;
//     printf("List of ten random numbers:\n");
//     for (i = 0; i < 10; i++)
//     {
//         while (num > 100)
//             num = rand();
//         printf("%i = %i\n", i + 1 , num);
//     }
// }


/* good resources:
http://www.azillionmonkeys.com/qed/random.html 
https://stackoverflow.com/questions/10984974/why-do-people-say-there-is-modulo-bias-when-using-a-random-number-generator/10984975#10984975
*/