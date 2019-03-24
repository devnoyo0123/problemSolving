#include <iostream>
#include <string>
#include <queue>

const int MAX = 100;

using namespace std;
char map[MAX][MAX];
int dist[MAX][MAX];

int dLocation[][2] = { {0, -1}, {-1,0}, {0,1}, {1,0} };

int main()
{


	int N, M;
	cin >> M >> N;
	

	for (int i = 0; i < N; i++) {
		string temp = "";
		cin >> temp;
		for (int j = 0; j < temp.length(); j++) {
			map[i][j] = temp[j];
			dist[i][j] = -1;
		}
	}



	queue<pair<int, int> > qu, nextQu;
	dist[0][0] = 0;
	qu.push({ 0,0 });

	while (!qu.empty()) {
		pair<int, int> temp = qu.front(); qu.pop();

		for (int i = 0; i < 4; i++) {
			int nR = temp.first + dLocation[i][0];
			int nC = temp.second + dLocation[i][1];

			if (nR < 0 || nC < 0 || nR == N || nC == M)
				continue;

			if (dist[nR][nC] >= 0)
				continue;


			if (map[nR][nC] == '1') {

				dist[nR][nC] = dist[temp.first][temp.second] + 1;
				nextQu.push({ nR,nC });

			}
			else {
				
				dist[nR][nC] = dist[temp.first][temp.second];
				qu.push({ nR,nC });


			}
		}

		if (qu.empty()) {
			qu = nextQu;
			nextQu = queue<pair<int, int> >();
		}
	}

	cout << dist[N - 1][M - 1];


	return 0;
}