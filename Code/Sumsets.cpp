#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(const vector<int>& ints) {
	int size = ints.size();

	for (int i = ints.size() - 1; i >= 3; i--) {
		int goal = ints.at(i);
		int tmp = 0;
		for (int j = 0; j < size - 3; j++) {
			for (int k = j + 1; k < size - 2; k++) {
				for (int l = k + 1; l < size - 1; l++) {
					tmp += ints.at(j);
					tmp += ints.at(k);
					tmp += ints.at(l);
					if (tmp == goal) { return goal; }
					else { tmp = 0; }
				}
			}
		}
	}
	// Maybe the answer is negative
	return float('inf');
}

int main() {
	while (true) {
		int num;
		cin >> num;
		if (num == 0) { break; }

		vector<int> ints;
		for (int i = 0; i < num; i++) {
			int tmp;
			cin >> tmp;
			ints.push_back(tmp);
		}
		sort(ints.begin(), ints.end());
		int ans = solve(ints);
		if (ans == float('inf')) { cout << "no solution" << endl; }
		else { cout << ans << endl; }
	}

	return 0;
}