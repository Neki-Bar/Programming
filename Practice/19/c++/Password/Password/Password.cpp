#include <iostream>
#include <vector>

using namespace std;

void out(vector <int> &a) {
	for (int i = 0; i < a.size(); i++) {
		cout << a[i];
	}
	cout << "\n";
}

void dig(int index, int n, int m , vector<int> & a, vector<bool> & used) {
	if (index == n) {
		out(a);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (used[i]) continue;
		a[index] = i;
		used[i] = true;
		dig(index + 1, n, m, a, used);
		used[i] = false;
	}
}

int main() {
	int n = 3;
	int m = 2;
	vector <int> a = {0,0,0};
	vector <bool> used = { 0,0,0 };
	dig(0, n , m, a, used);
}





