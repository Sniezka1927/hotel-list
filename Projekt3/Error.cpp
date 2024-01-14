#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Error.h"
const int maxErr = 4;

static const char* p[] = { "",
" Provided incorrect date ",
" Failed while opening file ",
" Failed while allocating memory ",
" Unknown error ",
};

void throwError(int nr) {
	int k;
	k = nr >= maxErr ? maxErr : nr;
	fprintf(stderr, "Blad(%d) - %s \n", nr, p[k]);
	exit(nr);

}
