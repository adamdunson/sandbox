#include <stdio.h>
#include <string.h>

int isPalindrome(int x) {
  char product[7];
  int i, j;

  sprintf(product, "%d", x);

  for(i = 0, j = strlen(product) - 1; i < (strlen(product) / 2); i++, j--) {
    if(product[i] != product[j]) {
      return 0;
    }
  }

  return 1;
}

int main() {
  int i, j;
  int temp, palindrome = 0;

  for(i = 101; i <= 999; i++) {
    if(i % 100 == 0) {
      continue;
    }
    for(j = 101; j <= 999; j++) {
      if(j % 100 == 0) {
        continue;
      }

      temp = i * j;
      if(isPalindrome(temp) && temp > palindrome) {
        palindrome = temp;
      }
    }
  }

  printf("%d\n", palindrome);
}
