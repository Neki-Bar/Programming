#ifndef _COMB_
#define _COMB_
#include "fact.h"

int comb(int n, int k) {
	return fact(n) / fact(k) / fact(n - k);
}
#endif
