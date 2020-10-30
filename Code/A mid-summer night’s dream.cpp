#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	while (true) {
		int num;
		cin >> num;
		if (!cin) { break; }
		
		vector<int> ints;
		for (int i = 0; i < num; i++) {
			int x;
			cin >> x;
			ints.push_back(x);
			sort(ints.begin(), ints.end());		
		}
		int ans1;
		if (num % 2 != 0) { ans1 = ints.at(num / 2); }
		else { ans1 = ints.at(num / 2 - 1); }

		int ans2 = 0;
		if (num % 2 != 0) { 
			int m = ints.at(num / 2);
			for (int i = 0; i < num; i++) {
				if (ints.at(i) == m) { ans2++; }
			}
		}
		else {
			int m1 = ints.at(num / 2 - 1), m2 = ints.at(num / 2);
			for (int i = 0; i < num; i++) {
				if (ints.at(i) == m1 || ints.at(i) == m2) { ans2++; }
			}
		}
		
		int ans3;
		if (num % 2 != 0) { ans3 = 1; }
		else { ans3 = ints.at(num / 2) - ints.at(num / 2 - 1) + 1; }

		cout << ans1 << " " << ans2 << " " << ans3 << endl;
	}

	return 0;
}