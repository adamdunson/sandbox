#include <stdio.h>

int abs(int x) {
  return x >= 0 ? x : -x;
}

int count_numbers(int low, int high) {
  return abs((high - low) + 1);
}

int main(int argc, char **argv) {
  int count = 0;
  int low = 1, high = 20;
  int num;
  int i;

  if(high < low) {
    printf("Low must be less than or equal to high.\n");
    return 1;
  }

  // TODO process command-line arguments
  if(argc > 1) {
  }

  num = low;
  while(count < count_numbers(low, high)) {
    for(i = low; i <= high; i++) {
      if(num % i == 0) {
        count++;
      } else {
        count = 0;
        num++;
        break;
      }
    }
  }

  printf("%d\n", num);

  return 0;
}
