#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int LCS(string s1, string s2) {
	int m = s1.size();
	int n = s2.size();
	vector< vector<int> > LCS_matrix(m+1, vector<int>(n+1));

	if (s1.empty() || s2.empty()) { return 0; }
	else {
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				//cout << s1.at(i-1) << "," << s2.at(j-1) << endl;

				if (s1.at(i-1) == s2.at(j-1)) {
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
		string s1, s2;
		cin >> s1;
		cin >> s2;

		if (!cin) { break; }

		cout << LCS(s1, s2) << endl;
	}

	return 0;
}