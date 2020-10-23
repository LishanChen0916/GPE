#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	while (true) {
		string s;
		cin >> s;

		if (!cin) { break; }

		int matched = 0;
		for (auto it = s.begin(); it != s.end(); it++) {
			for (auto r_it = s.rbegin(); r_it != s.rend(); r_it++) {
				if (*it == *r_it) { 
					matched += 1;
					if (it + 1 != s.end()) { it++; }
					else { break; }
				}
				else { 
					matched = 0;
					break; 
				}
			}
		}

		cout << s;
		for (auto r_it = s.rbegin() + matched; r_it != s.rend(); r_it++) {
			cout << *r_it;
		}
		cout << endl;
	}

	return 0;
}