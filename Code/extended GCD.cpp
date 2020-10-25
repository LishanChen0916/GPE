#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void extended_Euclid(int A, int B) {
	int s = 0, old_s = 1;
	int t = 1, old_t = 0;
	int r = B, old_r = A;

	while (r != 0) {
		int q = old_r / r;
		int temp = old_r;

		old_r = r;
		r = temp - q * r;

		temp = old_s;
		old_s = s;
		s = temp - q * s;

		temp = old_t;
		old_t = t;
		t = temp - q * t;
	}
	cout << old_s << " " << old_t << " " << old_r << endl;
}

int main() {
	while (true) {
		int a, b;
		cin >> a;
		cin >> b;

		if (!cin) { break; }

		extended_Euclid(a, b);
	}
	
	return 0;
}