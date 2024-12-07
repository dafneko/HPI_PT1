#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* I would assume that it would take <10 guesses on average (log2(100) is rounded up to 7 + human error :) ).
    I used a binary-search-like technique, 
    doubling down the range the number could be in, to find the correct number */
int main()
{
    int input;
    srand(time(NULL));
    int num = rand() % 100;

    printf("I picked a random number between 0 and 100, can you guess it?\n");
    do
    {
        printf("Guess? ");
        scanf("%i", &input);
        // fflush(stdout); scanf ingores whitespace anyways
        if (input > num)
            printf("Your guess %i is too high :(\n", input);
        else if (input < num)
            printf("Your guess %i is too low :(\n", input);
        else
            printf("Your guess %i is CORRECT :)\n", input);
    }
    while (input != num);
}