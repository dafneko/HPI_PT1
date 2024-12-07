#include <stdio.h>

#define FALSE 0
#define TRUE 1 

int isEven(int num){ // 0.5P
    return !(num & 1);
}

int halve(int num){ // 0.5P
    return num >> 1;
}

int makeMultipleOfEight(int num){ // 0.5P

    return num & ~7;
}

int main() {
 
    int num = 6;
    printf("Is %d even? %s\n", num, isEven(num) == TRUE? "TRUE":"FALSE");
 
    num = 8;
    printf("Half of %d is: %d\n", num, halve(num));
 
    num = 78;
    printf("When making %d a multiple of 8, we get: %d\n", num, makeMultipleOfEight(num));
 
    return 0;
}