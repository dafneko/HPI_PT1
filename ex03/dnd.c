#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROLL_COUNT 4

// These functions are probably helpful, but you can solve the task without them
// int min(/* parameters */); // Calculate the minimum
// int sum(/* parameters */); // Calculate the sum
 
int roll(void) 
{
    return (1 + rand() % 6);
}

int min(int *data, int len)
{
    int smoll;

    smoll = *data;
    for (int i = 1; i < len; i++)
        if (data[i] < smoll)
            smoll = data[i];
    return (smoll);    
}

int sum_of_rolls(void)
{
    int side[ROLL_COUNT];
    int sum = 0;

    for (int i = 0; i < ROLL_COUNT; i++)
    {
        side[i] = roll();
        sum += side[i];
    }
    sum -= min(side, ROLL_COUNT);
    return (sum);
}

int main(void) {
    // Simulate 1000 attribute rolls and print the resulting probabilities
    srand(time(NULL));
    int attributes[18] = { 0 }; //Which attribute values are possible? How long does the array need to be?
    // the largest possible sum of three largest rolls out of 4 is 6 + 6 + 6 = 18 
    for (int i = 0; i < 1000; i++)
        attributes[sum_of_rolls() - 1]++;
    for (int i = 0; i < 18; i++)
        printf("probability of attribute value %i is %i / 1000\n", i + 1, attributes[i]);
    return 0;
}