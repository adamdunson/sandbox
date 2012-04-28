#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "dec2base.h"

void printUsage() {
	printf("Usage: dec2base [-b|--base base] input\n");
}

int main(int argc, char **argv) {
	int dec = 0, base = 2;
	char *buf;
	int i = 1;

  /* begin parse input */
	if (argc > 1) {
		if (argc == 2 || (argc == 4 && (strcmp(argv[1], "-b")==0 || strcmp(argv[1], "--base")==0))) {
			if (argc == 4) {
				i = 3;
				base = atoi(argv[2]);
				buf = (char *)malloc(strlen(argv[2]) * sizeof(char));
				sprintf(buf, "%d", dec);

				if (base < 2 || base > 36) {
					fprintf(stderr, "Invalid base (must be between 2 and 36 inclusive).\n");
					exit(EXIT_FAILURE);
				}

				free(buf);
			}

			dec = atoi(argv[i]);
			buf = (char *)malloc(strlen(argv[i]) * sizeof(char));
			sprintf(buf, "%d", dec);

			if (strcmp(buf, argv[i]) != 0) {
				if (dec == 0) {
					fprintf(stderr, "Input is not a number.\n");
				} else if (dec == INT_MIN) {
					fprintf(stderr, "Input is too small (must be between %d and %d inclusive).\n", INT_MIN, INT_MAX);
				} else if (dec == INT_MAX) {
					fprintf(stderr, "Input is too large (must be between %d and %d inclusive).\n", INT_MIN, INT_MAX);
				}
				exit(EXIT_FAILURE);
			}

			free(buf);
		} else {
			fprintf(stderr, "Invalid syntax.\n");
			printUsage();
			exit(EXIT_FAILURE);
		}
	} else {
		fprintf(stderr, "Input is null.\n");
		printUsage();
		exit(EXIT_FAILURE);
	}
  /* end parse input */

	buf = dec2base(dec, base);
	printf("%s\n", buf);
	free(buf);

	return EXIT_SUCCESS;
}
