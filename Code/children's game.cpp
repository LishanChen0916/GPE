#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(const string & a, const string & b) {
	if (a.size() == b.size()) return a > b;
	string tmp1 = a + b, tmp2 = b + a;
	return tmp1 > tmp2;
}

int main() {
	int num;
	
	while (true)
	{
		string input_s;
		vector<string> inputs;

		cin >> num;
		if (num == 0) { break; }

		for (int i = 0; i < num; i++) {
			cin >> input_s;
			inputs.push_back(input_s);
		}

		sort(inputs.begin(), inputs.end(), cmp);
		for (int i = 0; i < num; i++) {
			cout << inputs[i];
		}
		cout << endl;
	}
	
	return 0;
}