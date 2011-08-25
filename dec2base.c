#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

char *dec2base(int dec, int base) {
	char symbols[] = {
			'0', '1', '2', '3', '4', '5',
			'6', '7', '8', '9', 'A', 'B',
			'C', 'D', 'E', 'F', 'G', 'H',
			'I', 'J', 'K', 'L', 'M', 'N',
			'O', 'P', 'Q', 'R', 'S', 'T',
			'U', 'V', 'W', 'X', 'Y', 'Z'
		};
	char *buf, *tmp = (char *)calloc(1, sizeof(char));
	int r = 0, q = dec;
	int i = 0, j = 0;

	while (q != 0) {
		tmp = realloc(tmp, (sizeof(tmp) + 1) * sizeof(char));
		r = q % base;
		q /= base;

		tmp[i] = symbols[r];
		tmp[++i] = 0;
	}

	buf = (char *)malloc(sizeof(tmp));
	while(i >= 0) {
		buf[j++] = tmp[--i];
	}
	free(tmp);

	return buf;
}

void printUsage() {
	printf("Usage: dec2base [-b|--base base] input\n");
}

int main(int argc, char **argv) {
	int dec, base = 2;
	char *buf;
	int i = 1;

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

	buf = dec2base(dec, base);
	printf("%s\n", buf);
	free(buf);

	return EXIT_SUCCESS;
}
