#include <stdio.h>
#include <stdlib.h>
#include "isprime.h"

void printUsage() {
	printf("Usage: isprime number\n");
}

int main(int argc, char **argv) {
	long n;

	if (argc > 1) {
		n = atol(argv[1]);
	} else {
		printUsage();
		exit(EXIT_FAILURE);
	}

	if(isPrime(n))
		printf("%ld is prime.\n", n);
	else
		printf("%ld is not prime.\n", n);

	return EXIT_SUCCESS;
}
