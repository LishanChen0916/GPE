#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int LCS(vector<int> ints, vector<int> sorted_ints) {
	int m = ints.size();
	int n = sorted_ints.size();
	vector< vector<int> > LCS_matrix(m + 1, vector<int>(n + 1));

	if (ints.empty() || sorted_ints.empty()) { return 0; }
	else {
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (ints.at(i - 1) == sorted_ints.at(j - 1)) {
					LCS_matrix[i][j] = LCS_matrix[i - 1][j - 1] + 1;
				}
				else {
					LCS_matrix[i][j] = max(LCS_matrix[i - 1][j], LCS_matrix[i][j - 1]);
				}
			}
		}
		return LCS_matrix[m][n];
	}
}

int main() {
	while (true) {
		int num_of_ints;
		cin >> num_of_ints;

		if (!cin) { break; }

		vector<int> ints;
		for (int i = 0; i < num_of_ints; i++) {
			int tmp;
			cin >> tmp;
			ints.push_back(tmp);
		}
		vector<int> sorted_ints(ints);
		sort(sorted_ints.begin(), sorted_ints.end());

		cout << LCS(ints, sorted_ints) << endl;
	}

	return 0;
}