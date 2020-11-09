#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pair {
	int l;
	int r;
};

bool cmp1(const Pair& x, const Pair& y) {
	if (x.l == y.l) { return x.r > y.r; }
	return x.l < y.l;
}

bool cmp2(const Pair& x, const Pair& y) {
	if (x.r == y.r) { return x.l > y.l; }
	return x.r > y.r;
}

int main() {
	int num_of_cases;
	cin >> num_of_cases;

	for (int i = 0; i < num_of_cases; i++) {
		int M;
		cin >> M;
		vector<Pair> segments;
				
		while (true) { 
			Pair tmp;
			cin >> tmp.l >> tmp.r;
			if (tmp.l == 0 && tmp.r == 0) { break; }
			segments.push_back(tmp);
		}
		// Sorted with the smallest left boundary
		sort(segments.begin(), segments.end(), cmp1);

		vector<Pair> res;
		int left = 0;
		bool success = false;
		for (int i = 0; i < segments.size(); i++) {
			// Not overlapped
			if (segments[i].r <= left) { continue; }

			vector<Pair> tmp;
			for (int j = i; j < segments.size(); j++) {
				if (segments[j].l <= left) {
					tmp.push_back(segments[j]);
				}
			}

			if (!tmp.empty()) {
				sort(tmp.begin(), tmp.end(), cmp2);
				left = tmp[0].r;
				res.push_back(tmp[0]);
			}
			if (left >= M) { 
				success = true;
				break; 
			}
		}

		if (!success) { cout << '0' << endl; }
		else {
			cout << res.size() << endl;
			for (int k = 0; k < res.size(); k++) {
				cout << res[k].l << " " << res[k].r << endl;
			}
		}
		if(i < num_of_cases - 1){ cout << endl; }
	}
	
	return 0;
}