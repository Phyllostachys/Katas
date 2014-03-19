#include <stdio.h>

int main(int argc, char **argv) {
  unsigned int byteCnt = 0;
  FILE * f = fopen(argv[1], "r");

  fseek(f, 0, SEEK_END);
  byteCnt = ftell(f);
  fclose(f);

  printf("%d",byteCnt);
  return(0);
}
