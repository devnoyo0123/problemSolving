#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

enum colors {
	RED = 0,
	BLUE
};

class Node {

public:

	int color, r, c;
	bool movable;

	Node(int color, int row, int col, bool movable) {
		color = color, r = row, c = col, movable = movable;
	}

};

int num, ans, nodecnt;
int map[100][100];

void BFS(vector<Node> &temp) {
	queue<Node> qu;
	for (int i = 0; i < temp.size(); i++) {
		qu.push(temp[i]);
	}

	while (!qu.empty()) {
		Node temp = qu.front(); qu.pop();

		if (temp.color == RED) {

			if (temp.r + 1 >= 100) {
				map[temp.r][temp.c] = 0;
				continue;
			}


			int nextRow = temp.r + 1;
			int nextCol = temp.c;
			if (map[nextRow][nextCol] == 1) {
				qu.push(temp);
				continue;
			}
			else if (map[nextRow][nextCol] == 2) {
				continue;
			}
			else {
				map[temp.r][temp.c] = 0;
				map[nextRow][nextCol] = 1;
				temp.r = nextRow;
				qu.push(temp);
			}


		}
		else {
			//BLUE
			if (temp.r - 1 < 0) {

				map[temp.r][temp.c] = 0;
				continue;
			}


			int nextRow = temp.r - 1;
			int nextCol = temp.c;
			if (map[nextRow][nextCol] == 2) {
				qu.push(temp);
				continue;
			}

			else if (map[nextRow][nextCol] == 1) {
				continue;
			}
			else {
				map[temp.r][temp.c] = 0;
				map[nextRow][nextCol] = 1;
				temp.r = nextRow;
				qu.push(temp);
			}
		}
	}
}

int main() {

	for (int t = 1; t <= 10; t++) {
		ans = 0;
		memset(map, 0, sizeof map);
		cin >> num;

		int temp, color;
		vector<Node> nodes;
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				cin >> temp;
				map[i][j] = temp;
				if (temp > 0) {
					nodecnt++;
					color = temp == 1 ? RED : BLUE;
					nodes.push_back(Node(color, i, j, true));
				}
			}
		}

		BFS(nodes);
		
		int save = 0;
		for (int i = 0; i < 100; i++) {
			save = 0;
			for (int j = 0; j < 100; j++) {
				
				if (map[i][j] > 0) {

					if (save == 0) {
						save = map[i][j];
					}
					else {
						if (save != map[i][j]) {
							save = 0;
							ans++;
						}
					}
				}
			}
		}

		cout << "#" << t << " " << ans << '\n';
	}
	return 0;
}