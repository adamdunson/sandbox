#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct PrimeList {
  long data;
  struct PrimeList *next;
};

typedef struct PrimeList PrimeList;

void deletePrimes(PrimeList *p);
long lastFactor(PrimeList *factors);
long divideOutFactors(long num, PrimeList *factors);
PrimeList *addPrime(long num, PrimeList *p);
void printPrimes(PrimeList *p);
int isPrime(long num, PrimeList *p);

int main(int argc, char **argv) {
  PrimeList *p = NULL;
  PrimeList *factors = NULL;
  long i = 3;
  int cnt = 1;

  long temp, value = 600851475143L;

  if(value < 2) {
    exit(EXIT_FAILURE);
  }

  printf("sqrt(%ld) = %ld\nPress enter to start.", value, (long)sqrt(value));
  getchar();

  p = addPrime(2, p);
  printf("2\n");
  if(value % 2 == 0) {
    factors = addPrime(2, factors);
  }

  // check for all factors below sqrt(value)
  while(i <= sqrt(value)) {
    if(isPrime(i, p)) {
      cnt++;
      p = addPrime(i, p);
      printf("%ld\n", i);
      if(value % i == 0) {
        factors = addPrime(i, factors);
      }
    }
    i += 2;
  }

  if(factors) {
    temp = divideOutFactors(value, factors);
  }

  if(isPrime(temp, p) && temp != lastFactor(factors)) {
    p = addPrime(temp, p);
    printf("%ld\n", temp);
    if(value % temp == 0) {
      factors = addPrime(temp, factors);
    }
  }

  // if factors is still empty, number must be prime
  if(!factors) {
    p = addPrime(value, p);
    printf("%ld\n", value);
    factors = addPrime(value, factors);
  }

  printf("Results:\n");

  printPrimes(factors);

  deletePrimes(p);
  deletePrimes(factors);

  return EXIT_SUCCESS;
}

void deletePrimes(PrimeList *p) {
  PrimeList *temp = p;
  PrimeList *del;

  while(temp) {
    del = temp;
    temp = temp->next;
    free(del);
  }
}

long lastFactor(PrimeList *factors) {
  if(!factors) {
    return -1;
  }

  PrimeList *temp = factors;

  while(temp->next) {
    temp = temp->next;
  }

  return temp->data;
}

// it is up to the user to make sure they check for NULL factors
long divideOutFactors(long num, PrimeList *factors) {
  PrimeList *temp = factors;
  long val = num;

  while(temp->next) {
    temp = temp->next;
  }
  val = num / temp->data;

  return val;
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

