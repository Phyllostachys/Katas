#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    FILE* f;
    int index;
    char string[1024] = {0,};
    f = fopen(argv[1], "r");
    
    while (fgets(string, 1024, f)) {
        //printf("%s", string);

        // Skip empty lines
        if (string[0] == '\n') {
            continue;
        }

        for(index = 0; index < 1024; index++) {
            // end of string
            if(string[index] == 0) break;

            if (string[index] >= 65 && string[index] <= 90) { // capital letter
                printf("%c", (char)(string[index] + 32));
            } else if(string[index] >= 97 && string[index] <= 122){ // lower case letter
                printf("%c", (char)(string[index] - 32));
            } else { // otherwise letter
                printf("%c", string[index]);
            }
            string[index] = 0;
        }

        //printf("%c", '\n');
    }
    
    fclose(f);
    return 0;
}