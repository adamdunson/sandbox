#include <stdlib.h>

char *dec2base(int dec, int base);

char *dec2base(int dec, int base) {
  char symbols[] = {
      '0', '1', '2', '3', '4', '5',
      '6', '7', '8', '9', 'A', 'B',
      'C', 'D', 'E', 'F', 'G', 'H',
      'I', 'J', 'K', 'L', 'M', 'N',
      'O', 'P', 'Q', 'R', 'S', 'T',
      'U', 'V', 'W', 'X', 'Y', 'Z'
    };
  /**
   * fub is the reversed final result
   */
	char *fub = NULL;
  /**
   * tmp is used for memory reallocation when building fub
   */
	char *tmp = NULL;
  /**
   * buf is the final result
   */
	char *buf = NULL;

	int r = 0, q = dec;
	int i = 0, j = 0;
  int neg = 0;

  // 0 < base <= # of elements in the symbols array
  if(base <= 0 || base > (sizeof(symbols) / sizeof(char))) {
    return NULL;
  }

  if(dec < 0) {
    neg = 1;
  }

  // primary algorithm, store reversed result in fub
	while(q != 0) {
		tmp = realloc(fub, sizeof(fub) + sizeof(char));

    if(!tmp) {
      free(fub);
      return NULL;
    } else {
      fub = tmp;
    }

		r = q % base;
		q /= base;

		fub[i] = symbols[r];
		fub[++i] = 0;
	}

  // tack on the negative sign if required
  if(neg) {
		fub[i] = '-';
		fub[++i] = 0;
  }

  // allocate memory for buf
	buf = (char *)malloc(sizeof(fub));
  if(!buf) {
    free(fub);
    return NULL;
  }

  // reverse fub; store the result in buf
	while(i >= 0) {
		buf[j++] = fub[--i];
	}
	free(fub);

	return buf;
}
