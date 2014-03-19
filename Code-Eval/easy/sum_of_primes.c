#include <stdio.h>
#include <math.h>

#define MAX_NUM 1000

int isPrime(int n)
{
    int i;
    for(i = 2; i < (n >> 1); i++){
        if(n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int primeCount = 2;
    unsigned int sum = 5;
    unsigned int curNum = 5;
    
    while(primeCount < MAX_NUM){
        if(isPrime(curNum)) {
            //printf("%d ", curNum);
            sum += curNum;
            primeCount++;
            curNum++;
        }
        else
            curNum++;
    }

    printf("%d", sum);
}