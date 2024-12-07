#include <stdio.h>
 
#define TRUE 1
#define FALSE 0

float min(float *data, int len);    // Calculates the minimum
float max(float *data, int len);    // Calculates the maximum
float med(float *data, int len);    // Calculates the median
                             // Hint: Consider possible edge cases and document how you treat them.
float avg(float *data, int len);    // Calculates the average
 

float avg(float *data, int len)
{
    int sum = 0;

    for (int i = 0; i < len; i++)
        sum += data[i];
    return (sum / len);   
}

int is_sorted(float *data, int len)
{
    for (int i = 1; i < len; i++)
        if (data[i - 1] > data[i])
            return FALSE;
    return (TRUE);    
}

void bubble_sort(float *data, int len)
{
    float temp;
    int i;

    i = 1;
    while (!is_sorted(data, len))
    {
        for (int i = 1; i < len; i++)
        {
            if (data[i - 1] > data[i])
            {
                temp = data[i];
                data[i] = data[i - 1];
                data[i - 1] = temp; 
            }
        }
    }
}


float med(float *data, int len)
{
    bubble_sort(data, len);
    if (len % 2 == 0)
        return ((data[len / 2] + data[len / 2 - 1]) / 2);
    return(data[len / 2]);
}

float max(float *data, int len)
{
    float large;

    large = *data;
    for (int i = 1; i < len; i++)
        if (data[i] > large)
            large = data[i];
    return (large);
}


float min(float *data, int len)
{
    float smoll;

    smoll = *data;
    for (int i = 1; i < len; i++)
        if (data[i] < smoll)
            smoll = data[i];
    return (smoll);    
}


int main(void)
{
    int len = 10;
    float data[] = {10.0, 11.5, -1.0, 13.5, 9.4, 10.1, 4.2, -10.0, -5.0, 4.0};
    
    float mini  = min(data, len);
    printf("Minimum temperature: %.2f\n", min(data, len));
    printf("Maximum temperature: %.2f\n", max(data, len));
    printf("Median temperature: %.2f\n", med(data, len));
    printf("Average temperature: %.2f\n", avg(data, len));
 
    return 0;
}