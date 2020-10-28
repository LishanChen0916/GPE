#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <stack>

using namespace std;

int main() {
	int num;
	cin >> num;

	for (int i = 0; i < num; i++) {
		stack<int> ints;
		char s[1024];
		cin >> s;

		for (int j = strlen(s) - 1; j >= 0; j--) {
			int pow = 1;
			int operand = 0;
			while (s[j] <= '9' && s[j] >= '0') {
				operand += (s[j] - '0') * pow;
				pow *= 10;
				j--;
			}
			ints.push(operand);
		}
		
		// Save one copy for computing maximum
		stack<int>ints_tmp(ints);
		// Min
		stack<int> tmp;
		for (int k = 0; k < strlen(s); k++) {
			if (s[k] == '+') {
				tmp.push(ints_tmp.top());
				ints_tmp.pop();
			}
			else if (s[k] == '*') {
				int tmp1, tmp2, res;
				tmp1 = ints_tmp.top();
				ints_tmp.pop();
				tmp2 = ints_tmp.top();
				ints_tmp.pop();
				res = tmp1 * tmp2;
				ints_tmp.push(res);
			}
		}
		size_t min_value = 0;
		while (!tmp.empty()) {
			min_value += tmp.top();
			tmp.pop();
		}
		// The last result in ints_tmp stack
		min_value += ints_tmp.top();
		ints_tmp.pop();

		// Max
		for (int l = 0; l < strlen(s); l++) {
			if (s[l] == '*') {
				tmp.push(ints.top());
				ints.pop();
			}
			else if (s[l] == '+') {
				int tmp1, tmp2, res;
				tmp1 = ints.top();
				ints.pop();
				tmp2 = ints.top();
				ints.pop();
				res = tmp1 + tmp2;
				ints.push(res);
			}
		}
		size_t max_value = 1;
		while (!tmp.empty()) {
			max_value *= tmp.top();
			tmp.pop();
		}
		// The last result in ints stack
		max_value *= ints.top();

		cout << "The maximum and minimum are " << max_value << " and " << min_value << "." << endl;
	}

	return 0;
}