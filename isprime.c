#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int n) {
	if(n == 2 || n == 3)
		return 1;
	if(n < 2 || n % 2 == 0 || n % 3 == 0)
		return 0;

	int k = 1;
	while((6*k - 1) <= sqrt(n))
		if(n % (6*k - 1) == 0 || n % (6*k + 1) == 0)
			return 0;
		else
			k++;

	return 1;
}

void printUsage() {
	printf("Usage: isprime n\n");
}

int main(int argc, char **argv) {
	int n;

	if (argc > 1) {
		n = atoi(argv[1]);
	} else {
		printUsage();
		exit(EXIT_FAILURE);
	}

	if(isPrime(n))
		printf("%d is prime.\n", n);
	else
		printf("%d is not prime.\n", n);

	return EXIT_SUCCESS;
}
