#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <sstream>

using namespace std;

bool isPrime(int x) {
	int sqrt_x = sqrt(x);
	for (int p = 2; p <= sqrt_x; p++) { 
		if (x % p == 0) { return false; }
	}
	return true;
}

int main() {
	int num_of_cases;
	cin >> num_of_cases;

	for (int i = 0; i < num_of_cases; i++) {
		int t1, t2;
		cin >> t1 >> t2;

		int num_of_digit_primes = 0;
		for (int j = t1; j <= t2; j++) {
			if (!isPrime(j)) { continue; }
			stringstream ss;
			ss << j;
			string tmp;
			ss >> tmp;
			int digit_sum = 0;
			for (int k = 0; k < tmp.size(); k++) { digit_sum += (tmp[k] - '0'); }
			if (isPrime(digit_sum)) { num_of_digit_primes += 1; }
		}
		cout << num_of_digit_primes << endl;
	}

	return 0;
}