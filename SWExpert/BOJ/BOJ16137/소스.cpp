#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int NMAX = 10;

int N, M;

int ans;
int map[NMAX][NMAX];
int dist[NMAX][NMAX];
int dLocations[][2] = { {0,-1} ,{-1,0} ,{0,1} ,{1,0} };

bool enable(int row, int col) {
	bool dir[4] = { false, };
	if (col - 1 > 0 && map[row][col - 1] == 0) {
		dir[0] = true;
	}
	if (col + 1 < N && map[row][col + 1] == 0) {
		dir[1] = true;
	}
	if (row - 1 > 0 && map[row - 1][col] == 0) {
		dir[2] = true;
	}
	if (row + 1 < N && map[row + 1][col] == 0) {
		dir[3] = true;
	}
	
	if (dir[0] && ( dir[3] || dir[2])){
		return false;
	}
	else if (dir[1] && (dir[2] || dir[3])) {
		return false;
	}
	else {
		return true;
	}
}

class Node {
public:
	int row,  col,  time;
	
	Node(int r, int c, int t) {
		row = r;
		col = c;
		time = t;
	}
};

int bfs(int row, int col) {
	memset(dist, 0, sizeof(dist));
	queue<Node> qu;
	dist[row][col] = 1;
	qu.push(Node(row, col, 0));
	
	while (!qu.empty()) {
		Node temp = qu.front(); qu.pop();

		if (map[temp.row][temp.col] > 1 && temp.time % map[temp.row][temp.col] != 0) {
			dist[temp.row][temp.col] += temp.time;
			qu.push(Node(temp.row, temp.col, temp.time + 1));
		}
		else {
			for (int i = 0; i < 4; i++) {
				int nR = dLocations[i][0] + temp.row;
				int nC = dLocations[i][1] + temp.col;

				if (nR < 0 || nC < 0 || nR == N || nC == N)
					continue;

				if (dist[nR][nC] > 0) {
					continue;
				}

				if (map[nR][nC] == 0) {
					continue;
				}

				if (map[temp.row][temp.col] >=2 && map[nR][nC] >=2 )
					continue;

				if (nR == N-1 && nC == N-1) {
					int res = temp.time + 1;
					return res;
				}

				dist[nR][nC] = temp.time + 1;
				
				qu.push(Node(nR, nC, temp.time + 1));

			}
		}


	}
}

int main()
{

	cin >> N >> M;
	ans = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];


		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 0 && enable(i, j)) {
				map[i][j] = M;
	
				int temp = bfs(0, 0);
				if (ans == -1 || ans > temp) {
					ans = temp;
				}
				map[i][j] = 0;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}