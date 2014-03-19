#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    FILE* f;
    //char* line;
    int a,b,n,i;
    
    f = fopen(argv[1], "r");
    
    while (!feof(f)) {
        int rCnt;
        rCnt = fscanf(f, "%d %d %d", &a, &b, &n);
        
        //printf("Read Count: %d\n", rCnt);
        //printf("A: %d B: %d N: %d\n", a, b, n);
        
        // Skip empty lines
        if (rCnt == 0) {
            continue;
        }
        
        ;
        for(i = 1; i < n; i++) {
            if(i % a == 0 && i % b == 0) printf("FB");
            else if(i % a == 0) printf("F");
            else if(i % b == 0) printf("B");
            else printf("%d", i);
            printf(" ");
        }
        if(n % a == 0 && n % b == 0) printf("FB");
        else if(n % a == 0) printf("F");
        else if(n % b == 0) printf("B");
        else printf("%d", i);
        
        if(!feof(f)) printf("\n");
    }
    
    fclose(f);
    return 0;
}