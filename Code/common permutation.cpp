#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	string a, b;
	while (getline(cin, a) && getline(cin, b)) {
		int freq_a[26] = { 0 };
		int freq_b[26] = { 0 };
		int freq[26] = { 0 };
		
		for (int i = 0; i < a.size(); i++) { freq_a[a[i] - 'a']++; }
		for (int i = 0; i < b.size(); i++) { freq_b[b[i] - 'a']++; }
		for (int i = 0; i < 26; i++) {
			if (freq_a[i] < freq_b[i]) { freq[i] = freq_a[i]; }
			else { freq[i] = freq_b[i]; }
			if (freq[i] > 0) {
				for (int j = 0; j < freq[i]; j++) { cout << char('a' + i); }
			}
		}
		cout << endl;
	}

	return 0;
}