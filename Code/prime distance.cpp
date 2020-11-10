#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

bool isPrime(unsigned long long x) {
	if (x < 2) { return false; }
	unsigned long long sqrt_x = sqrt(x);
	for (unsigned long long i = 2; i <= sqrt_x; i++) {
		if (x % i == 0) { return false; }
	}
	return true;
}

struct Pair {
	unsigned long long l, u;
	unsigned long long distance;
};

bool cmp1(const Pair &a, const Pair& b) {
	if (a.distance == b.distance) { return a.l < b.l; }
	return a.distance < b.distance;
}

bool cmp2(const Pair& a, const Pair& b) {
	if (a.distance == b.distance) { return a.u > b.u; }
	return a.distance < b.distance;
}

int main() {
	while (true) {
		unsigned long long L, U;
		cin >> L >> U;

		if (!cin) { break; }

		vector<unsigned long long > primes;
		for (unsigned long long i = L; i <= U; i++) {
			if (isPrime(i)) { primes.push_back(i); }
		}
		if (primes.size() < 2) { cout << "There are no adjacent primes." << endl; }
		else {
			Pair p;
			vector<Pair> d;
			for (unsigned long long i = 0; i < primes.size() - 1; i++) {
				unsigned long long j = i + 1;
				p.l = primes[i];
				p.u = primes[j];
				p.distance = primes[j] - primes[i];
				d.push_back(p);
			}
			if (d.size() < 1) { 
				cout << "There are no adjacent primes." << endl; 
			}
			else {
				vector<Pair> min_vector(d);
				sort(min_vector.begin(), min_vector.end(), cmp1);
				vector<Pair> max_vector(d);
				sort(max_vector.begin(), max_vector.end(), cmp2);
				cout << min_vector[0].l << "," << min_vector[0].u << " are closest, " << max_vector[max_vector.size() - 1].l << "," << max_vector[max_vector.size() - 1].u << " are most distant." << endl;
			}
		}
	}

	return 0;
}