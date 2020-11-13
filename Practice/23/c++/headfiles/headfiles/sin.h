#ifndef _SIN_
#define _SIN_

double sin(double x, int k) {
	double sum = 0;
	double temp = x;
	int f = 1;
	for (int i = 0; i < k; i++, f += 2) {
		if (i == 0) sum += x;
		else {
			sum += -1 * temp * x * x /( f + 1) / (f + 2);
		}
			
	}
	return sum;
}
#endif


