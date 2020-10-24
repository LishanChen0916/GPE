#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
	int num_of_cases;
	cin >> num_of_cases;

	for (int i = 0; i < num_of_cases; i++){
		int num_of_instr;
		cin >> num_of_instr;
		vector<int> steps;
		int res = 0;
		for (int j = 0; j < num_of_instr; j++) {
			string instr;
			cin >> instr;

			if (instr == "LEFT") { steps.push_back(-1); }
			else if (instr == "RIGHT") { steps.push_back(1); }
			else {
				int same_as;
				// Skip "SAME" and "AS"
				cin >> instr >> instr;
				same_as = atoi(instr.c_str());
				steps.push_back(steps.at(same_as - 1));
			}
		}
		for (auto it = steps.begin(); it != steps.end(); it++) {
			res += *it;
		}
		cout << res << endl;
	}

	return 0;
}