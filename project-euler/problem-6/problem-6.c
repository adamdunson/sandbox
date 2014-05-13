#include <stdio.h>

long abs(long x) {
  return x >= 0 ? x : -x;
}

int main() {
  long sum_of_squares = 0;
  long square_of_sum = 0;
  int i, n = 100;

  for(i = 1; i <= n; i++) {
    sum_of_squares += i*i;
    square_of_sum += i;
  }
  square_of_sum *= square_of_sum;

  printf("%ld\n", abs(square_of_sum - sum_of_squares));

  return 0;
}
