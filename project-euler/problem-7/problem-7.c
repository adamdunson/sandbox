#include <stdio.h>
#include <stdlib.h>

#define NTH_PRIME 10001

struct PrimeList {
  long data;
  struct PrimeList *next;
};

typedef struct PrimeList PrimeList;

PrimeList *addPrime(long num, PrimeList *p);
void printPrimes(PrimeList *p);

int main(int argc, char **argv) {
  PrimeList *p = addPrime(2, NULL);
  long i = 3;
  int cnt = 1;

  printf("1: 2\n");
  while(cnt < NTH_PRIME) {
    if(isPrime(i, p)) {
      cnt++;
      p = addPrime(i, p);
      printf("%d: %ld\n", cnt, i);
    }
    i += 2;
  }

  return 0;
}

PrimeList *addPrime(long num, PrimeList *p) {
  PrimeList *temp = p;
  PrimeList *new = (PrimeList *)malloc(sizeof(PrimeList));
  new->data = num;
  new->next = NULL;

  if(!p) {
    return new;
  } else {
    while(temp->next) {
      temp = temp->next;
    }
    temp->next = new;

    return p;
  }
}

void printPrimes(PrimeList *p) {
  PrimeList *temp = p;

  while(temp) {
    printf("%ld\n", temp->data);
    temp = temp->next;
  }
}

int isPrime(long num, PrimeList *p) {
  PrimeList *temp = p;

  // traverse through temp checking for factors of num
  while(temp) {
    if(num % temp->data == 0) {
      return 0;
    } else {
      temp = temp->next;
    }
  }

  // if we get to here, num must be prime
  return 1;
}

