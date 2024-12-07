int sumN(int n) {
    int accumulator = 0;
    int i;
    
    for (i = 0; i <= n; i++) {
        accumulator += i;
    }
    return (accumulator);
}
 
int sum100(void)
{
    return sumN(100);
}
 
// -------------------------------------------------------------------------- //
//     Den Code unter dieser Linie müsst ihr für die Aufgabe nicht ändern
// -------------------------------------------------------------------------- //
 
#include <stdio.h>
 
int main() {
    printf("sum100: %d\n", sum100());
    printf("sumN(500): %d\n", sumN(500));
    return 0;
}