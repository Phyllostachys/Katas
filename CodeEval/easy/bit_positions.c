#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    FILE* f;
    int n, p1, p2;
    
    f = fopen(argv[1], "r");
    
    do {
        int rCnt;
        rCnt = fscanf(f, "%d,%d,%d", &n, &p1, &p2);
        
        // Skip empty lines
        if (rCnt == 0) {
            continue;
        }

        if (p1 == p2) {
            printf("true\n");
        } else if (((n >> (p1 - 1)) & 1) ^ ((n >> (p2 - 1)) & 1)) {
            printf("false\n");
        } else {
            printf("true\n");
        }
    } while (!feof(f));
    
    fclose(f);
    return 0;
}