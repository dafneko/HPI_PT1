#include <stdio.h>

void printArray(int *array, int n);

#define FALSE 0
#define TRUE 1

void swap(int *a, int *b){
    int tmp;

    tmp = *b;
    *b = *a;
    *a = tmp;
}

/* Alternative :)
void swap(int *a, int *b){

    *a ^= *b;
    *b ^= *a;
    *a ^= *b; 
}
*/

/*
void selectionSort(int *array, int n){
    int *itr;
    int *cur;
    int *cur_min;
    int i;
    int k;

    itr = array;
    for (i = 0; i < n; i++)
    {
        cur = array + i;
        cur_min = cur;
        for (k = i + 1; k < n; k++)
        {
            if (*(itr + k) < *cur_min)
                cur_min = itr + k; 
        }
        if (cur != cur_min)
            swap(cur, cur_min);
    }
}
*/


/* I love while loops <3 */
void selectionSort(int *array, int n){
    int *itr;
    int *cur;
    int *cur_min;
    int i;

    cur = array;
    while (n)
    {
        i = n;
        itr = cur + 1; 
        cur_min = cur;
        while (--i)
        {
            if (*itr < *cur_min)
                cur_min = itr; 
            itr++;
        }
        if (cur != cur_min)
            swap(cur, cur_min);
        cur++;
        n--;
    }
}
 

int is_sorted(int *arr, int n)
{
    while (--n)
    {
        if (*(arr + 1) < *arr)
            return FALSE;
        arr++;        
    }
    return TRUE;    
}

void bubbleSort(int *array, int n){
    int *itr;
    int swapped;

    do
    {
        itr = array;
        swapped = FALSE;
        for (int i = 0; i < n - 1; i++)
        {
            if (*(itr + i) > *(itr + i + 1))
            {
                swap(itr + i, itr + i + 1);
                swapped = TRUE;
            }
        }
    } while (swapped);
}
 
void insertionSort(int *array, int n){
    int *itr;
    int i;
    int k;

    itr = array;
    for (i = 1; i < n; i++)
    {
        k = i - 1;
        while (k >= 0 && *(itr + k + 1) < *(itr + k))
        {
            swap(itr + k, itr + k + 1);
            k--;
        }
    }
}
 
void printArray(int *array, int n){
    for(size_t i = 0; i <n; i++)
        printf("%d ", array[i]);
    printf("\n");
}
 
int main(void){
    int arrayA [5] = {5, 2, 3, 4, 1};
    int arrayB [5] = {3, 5, 2, 1, 4};
    int arrayC [5] = {2, 1, 3, 4, 5};
    int arrayD [7] = {0, 2, 1, 3, 5, 4, 6};
 
    selectionSort(arrayA, 5);
    printArray(arrayA, 5); // 1 2 3 4 5
 
    bubbleSort(arrayB, 5);
    printArray(arrayB, 5); // 1 2 3 4 5
 
    insertionSort(arrayC, 5);
    printArray(arrayC, 5); // 1 2 3 4 5
 
    bubbleSort(arrayD, 7);
    printArray(arrayD, 7);
    return 0;
}