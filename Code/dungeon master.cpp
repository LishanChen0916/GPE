#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct Node {
	int levels;
	int rows;
	int cols;
};

int BFS(vector< vector< vector<char> > >& maze, vector< vector< vector<int> > >& distance, const Node& s) {
	queue<Node> q;
	q.push(s);
	maze[s.levels][s.rows][s.cols] = '#';
	const int dir[6][3] = { {-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1} };

	while (!q.empty()) {
		Node next, current = q.front();
		q.pop();

		for (int i = 0; i < 6; i++) {
			next.levels = current.levels + dir[i][0];
			next.rows = current.rows + dir[i][1];
			next.cols = current.cols + dir[i][2];

			if (maze[next.levels][next.rows][next.cols] != '#') {
				distance[next.levels][next.rows][next.cols] = distance[current.levels][current.rows][current.cols] + 1;
				if (maze[next.levels][next.rows][next.cols] == 'E') { return distance[next.levels][next.rows][next.cols]; }
				maze[next.levels][next.rows][next.cols] = '#';
				q.push(next);
			}
		}
	}

	return -1;
}

int main() {
	while (true) {
		int L, R, C;
		cin >> L >> R >> C;

		if (L == 0 && R == 0 && C == 0) { break; }

		vector< vector< vector<char> > > maze(L + 2, vector< vector<char> >(R + 2, vector<char>(C + 2, '#')));
		vector< vector< vector<int> > > distance(L + 2, vector< vector<int> >(R + 2, vector<int>(C + 2, 0)));

		Node S;
		// Init the maze
		for (int levels = 1; levels <= L; levels++) {
			for (int rows = 1; rows <= R; rows++) {
				string tmp;
				cin >> tmp;
				for (int cols = 1; cols <= C; cols++) {
					// Assign starting position
					if (tmp[cols - 1] == 'S') {
						S.levels = levels;
						S.rows = rows;
						S.cols = cols;
					}
					maze[levels][rows][cols] = tmp[cols - 1];
				}
			}
		}
		int minutes = BFS(maze, distance, S);
		if (minutes != -1) {
			cout << "Escaped in " << minutes << " minute(s)." << endl;
		}
		else { cout << "Trapped!" << endl; }
	}

	return 0;
}