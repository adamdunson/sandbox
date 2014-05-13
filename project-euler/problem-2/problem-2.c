#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  int a = 1, b = 2;
  int sum = 2; // add the first even number
  int swap = 0; // start with a, swap to b
  int limit = 0; // must be >= 2

  if(argc > 1) {
    limit = atoi(argv[1]);
  }

  if(limit < 2) {
    limit = 4000000;
  }

  while(a <= limit && b <= limit) {
    if(!swap) {
      a = a + b;
      if(a % 2 == 0) {
        sum+=a;
      }
      swap = 1;
    } else {
      b = a + b;
      if(b % 2 == 0) {
        sum+=b;
      }
      swap = 0;
    }
  }

  printf("%d\n", sum);

  return 0;
}
