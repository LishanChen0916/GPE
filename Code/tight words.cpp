#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>

using namespace std;

int main() {
	while (true) {
		int k, n;
		cin >> k >> n;

		if (!cin) { break; }
		if (n == 1 || k == 0) { 
			cout << "100.00000" << endl; 
			continue;
		}

		vector< vector<double> > dp(k+1, vector<double>(n)); 
		for (int i = 0; i <= k; i++) { dp[i][0] = 1; }
		for (int i = 1; i < n; i++) {
			for (int j = 0; j <= k; j++) {
				if (j == 0) { dp[j][i] = dp[j][i - 1] + dp[j + 1][i - 1]; }
				else if (j == k) { dp[j][i] = dp[j][i - 1] + dp[j - 1][i - 1]; }
				else { dp[j][i] = dp[j - 1][i - 1] + dp[j][i - 1] + dp[j + 1][i - 1]; }
			}
		}

		double total = 0.0;
		for (int i = 0; i <= k; i++) { total += dp[i][n - 1]; }

		double percentage = total / pow(k + 1, n) * 100;
		printf("%.5f\n", percentage);
	}

	return 0;
}