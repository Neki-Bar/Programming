#pragma once

int fact (int x) {
	int f = 1;
	while (x) {
		f *= x;
		x--;
	}
	return f;
}
