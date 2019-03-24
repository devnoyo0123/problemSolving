#include <iostream>
#include <string>
#include <queue>

using namespace std;

const int NMAX = 1000;
const int MMAX = 1000;

char map[NMAX][MMAX];
int visited[NMAX][MMAX][2];
int N, M;

int dLocation[][2] = { { -1,0 },{ 0,1 },{ 1,0 },{ 0,-1 } };
bool done;

class Node {
public:
	int row;
	int col;
	int wall;
	Node(int r, int c, int w) {
		row = r;
		col = c;
		wall = w;
	}
};

int main()
{
	queue<Node> qu;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string temp = "";
		cin >> temp;
		for (int j = 0; j < temp.length(); j++) {
			map[i][j] = temp[j];
		}
	}

	visited[0][0][0] = 1;
	qu.push(Node(0, 0, 0));

	while (!qu.empty())
	{
		Node temp = qu.front(); qu.pop();

		if (temp.row == N - 1 && temp.col == M - 1) {

			if (visited[temp.row][temp.col][0] == 0) {
				cout << visited[temp.row][temp.col][1];
			}
			else if (visited[temp.row][temp.col][1] == 0) {
				cout << visited[temp.row][temp.col][0];
			}
			else {
				if (visited[temp.row][temp.col][0] > visited[temp.row][temp.col][1]) {
					cout << visited[temp.row][temp.col][1];
				}
				else {
					cout << visited[temp.row][temp.col][0];
				}
			}


			done = true;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nR = temp.row + dLocation[i][0];
			int nC = temp.col + dLocation[i][1];

			if (nR < 0 || nC < 0 || nR == N || nC == M) {
				continue;
			}

			if (map[nR][nC] == '1') {

				if (temp.wall == 1 || visited[nR][nC][1] > 0)
					continue;

			
				visited[nR][nC][temp.wall+1] = visited[temp.row][temp.col][temp.wall] + 1;
				qu.push(Node(nR, nC, temp.wall+1));
				
			}
			

			if(map[nR][nC] == '0'){
				if (visited[nR][nC][temp.wall] > 0)
					continue;

				visited[nR][nC][temp.wall] = visited[temp.row][temp.col][temp.wall] + 1;
				qu.push(Node(nR, nC, temp.wall));
			}
		}
	}

	if (!done)
		cout << -1 << '\n';


	return 0;
}