#include <stdio.h>
#include <stdlib.h>

unsigned char checkIt(long long val);

int main()
{
    long long result;
//    unsigned char foundIt = 0;
    result = 20;

    while(!checkIt(result)) {
        result+=20;
    }
    printf("%I64d", result);
    return 0;
}

unsigned char checkIt(long long val)
{
    if(val % 20 == 0 &&
            val % 19 == 0 &&
            val % 18 == 0 &&
            val % 17 == 0 &&
            val % 16 == 0 &&
            val % 15 == 0 &&
            val % 14 == 0 &&
            val % 13 == 0 &&
            val % 12 == 0 &&
            val % 11 == 0)
        return(1);
    else
        return(0);
}
