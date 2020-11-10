#include <iostream>
#include <iomanip>

using namespace std;

void Bangla(unsigned long long n) {
	if (n == 0) { return; }

	if (n / 10000000) {
		Bangla(n / 10000000);
		cout << " kuti";
		n = n % 10000000;
		if (n > 0) cout << " ";
	}
	if (n / 100000) {
		Bangla(n / 100000);
		cout << " lakh";
		n = n % 100000;
		if (n > 0) cout << " ";
	}
	if (n / 1000) {
		Bangla(n / 1000);
		cout << " hajar";
		n = n % 1000;
		if (n > 0) cout << " ";
	}
	if (n / 100) {
		Bangla(n / 100);
		cout << " shata";
		n = n % 100;
		if (n > 0) cout << " ";
	}
	if (n) { cout << " " << n; }
}

int main() {
	int cases = 0;
	while (true) {
		cases += 1;
		unsigned long long num;
		cin >> num;
		if (!cin) { break; }

		cout << setw(4) << cases << '.';
		if (num == 0) { cout << " 0"; }
		else { 
			Bangla(num); 
		}
		cout << endl;
	}
	
	return 0;
}