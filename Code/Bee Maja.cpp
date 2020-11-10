#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pair {
	int x;
	int y;
};

vector<Pair> create(int SIZE) {
	vector<Pair> table;
	Pair tmp;
	tmp.x = 0, tmp.y = 0;
	table.push_back(tmp);

	int current_x = 0, current_y = 0, index = 2;
	for (int i = 1; index <= SIZE; i++) {
		for (int j = 0; j < i && index <= SIZE; j++, index++) { 
			tmp.y++; 
			table.push_back(tmp); 
		}
		for (int j = 0; j < i - 1 && index <= SIZE; j++, index++) {
			tmp.x--;
			tmp.y++;
			table.push_back(tmp);
		}
		for (int j = 0; j < i && index <= SIZE; j++, index++) {
			tmp.x--;
			table.push_back(tmp);
		}
		for (int j = 0; j < i && index <= SIZE; j++, index++) {
			tmp.y--;
			table.push_back(tmp);
		}
		for (int j = 0; j < i && index <= SIZE; j++, index++) {
			tmp.x++;
			tmp.y--;
			table.push_back(tmp);
		}
		for (int j = 0; j < i && index <= SIZE; j++, index++) {
			tmp.x++;
			table.push_back(tmp);
		}
	}
	return table;
}

int main() {
	vector<Pair> table = create(100000);

	while (true) {
		int Willi_num;
		cin >> Willi_num;
		if (!cin) { break; }

		cout << table[Willi_num - 1].x << " " << table[Willi_num - 1].y << endl;
	}

	return 0;
}