#include <iostream>
#include <vector>

using namespace std;

struct Point {
	int x;
	int y;
};

struct Line {
	Point p1, p2;

	bool onTheLine(Point p) {
		int dx, dy, Dx, Dy;
		dx = p2.x - p1.x;
		dy = p2.y - p1.y;
		Dx = p.x - p1.x;
		Dy = p.y - p1.y;

		if (dx == 0) { return p.x == p1.x; }
		else if (dy == 0) { return p.y == p1.y; }
		else { return dx * Dy == Dx * dy; }
	}

	bool operator==(const Line& l) {
		return onTheLine(l.p1) && onTheLine(l.p2);
	}
};

int main() {
	int num_of_cases;
	cin >> num_of_cases;

	for (int i = 0; i < num_of_cases; i++) {
		int num_of_points;
		cin >> num_of_points;
		vector<Point> p;
		for (int j = 0; j < num_of_points; j++) {
			Point tmp;
			cin >> tmp.x >> tmp.y;
			p.push_back(tmp);
		}

		vector<Line> line;
		for (int k = 0; k < num_of_points; k++) {
			for (int l = k + 1; l < num_of_points; l++) {
				Line tmp;
				tmp.p1 = p[k];
				tmp.p2 = p[l];
				bool found = false;
				for (int q = 0; q < line.size(); q++) {
					if (line[q] == tmp) { found = true; }
				}
				if (!found) { line.push_back(tmp); }
			}
		}
		cout << line.size() << endl;
	}

	return 0;
}