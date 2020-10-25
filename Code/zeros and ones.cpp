#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string input_s;
	int num_cases;

	int cases = 0;
	while (true)
	{
		cases++;
		cin >> input_s;
		if (!cin) { break; }
		cin >> num_cases;
		
		cout << "Case " << cases << ":" << endl;
		for (int nc = 0; nc < num_cases; nc++) {
			int i, j;
			cin >> i;
			cin >> j;
			bool ans = true;
			char temp = input_s.at(min(i, j));
			for (int index = min(i, j); index <= max(i, j); index++) {
				if (input_s.at(index) != temp) {
					ans = false;
					break;
				}
			}
			if (ans == true) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
	}
	
	return 0;
}