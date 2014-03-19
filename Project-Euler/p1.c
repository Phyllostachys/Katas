#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0;
    int sum = 0;
    for(; i < 1000; i++) {
        if(i % 3 == 0 || i % 5 == 0) {
            printf("%i\t",i);
            sum += i;
            printf("%i\n",sum);
        }
    }
    printf("Result is %i", sum);
    return 0;
}
