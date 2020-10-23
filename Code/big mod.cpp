#include <iostream>
#include <math.h>

using namespace std;

int big_mod(int B, int P, int M) {
	if (P == 0) { return 1; }
	else if (P % 2 == 0) { return big_mod(B, P / 2, M) * big_mod(B, P / 2, M) % M; }
	else { return ((B % M) * big_mod(B, P - 1, M)) % M; }
}

int main() {
	while (true) {
		int B, P, M;
		cin >> B;
		cin >> P;
		cin >> M;

		if (!cin) { break; }

		cout << big_mod(B, P, M) << endl;
	
	}
	
	return 0;
}