#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n0 = 1;
    int n1 = 2;
    int fibSum, totalSum;
    fibSum = n0 + n1;
    totalSum = 0;

    while(fibSum < 4000000) {
        if(fibSum % 2 == 0) {
            totalSum += fibSum;
        }
        n0 = n1;
        n1 = fibSum;
        fibSum = n0 + n1;
    }
    printf("Result: %i",totalSum + 2);
    return 0;
}
