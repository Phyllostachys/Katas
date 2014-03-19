#include <math.h>

int primes[1000] = {0}; // zero init

void seivePrimes() {
    int index, nonPrime;
    for(index = 2; index < 500; index++) {
        if(primes[index] == -1) continue;
        for(nonPrime = 2; nonPrime < 1000; nonPrime++) {
            if(nonPrime * index > 999) break;
            else {
                primes[nonPrime * index] = -1;
            }
        }
    }
}

int isPalindrome(int n) {
    int i;
    int size = (int)(log10(n) + 1);
    //printf("possible palindrome: %d\tsize:%d\n", n, size);
    char str[size];
    sprintf(str, "%d", n);
    for(i = 0; i < size/2; i++) {
        if(str[i] != str[size-i-1]) return 0;
    }
    return 1;
}

int main() {
    int i = 1000;
    seivePrimes();
    while(i > 0) {
        i--;
        if(primes[i] == -1) continue;
        if(isPalindrome(i)) break;
    }
    printf("%d", i);
    return 0;
}