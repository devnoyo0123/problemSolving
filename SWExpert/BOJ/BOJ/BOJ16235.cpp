#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

const int NMAX = 14;



vector<int> vec[NMAX][NMAX];
queue<tuple<int, int, int> > summer;
queue<pair<int, int> > fall;
int nutrients[NMAX][NMAX];

int ans;

int N, M, K;

int cmap[NMAX][NMAX];

int dLocation[][2] = { { -1,-1 },{ -1,0 },{ -1,1 },{ 0,-1 },{ 0,1 },{ 1,-1 },{ 1,0 },{ 1,1 } };


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K;

	

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> nutrients[i][j];
			cmap[i][j] = 5;
		}
	}

	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		vec[a][b].push_back(c);
	}

	while (K--) {
		//봄
		
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (vec[i][j].size() == 0) {
					continue;
				}
				vector<int> tempVec;
				sort(vec[i][j].begin(), vec[i][j].end());
				for (int k = 0; k < vec[i][j].size(); k++) {
						

					if (cmap[i][j] >= vec[i][j][k]) {
						cmap[i][j] -= vec[i][j][k];
						tempVec.push_back(vec[i][j][k]+1);
						if (vec[i][j][k]+1 % 5 == 0) {
							fall.push({i,j});
						}
					}
					else {
						int temp = vec[i][j][k] / 2;
						summer.push({ i,j,temp});
					}
				}

				//바꿔치기
				vec[i][j].clear();
				for (int tmp : tempVec)
					vec[i][j].push_back(tmp);
			}
		}

		//여름
		while (!summer.empty()) {
			int x, y, z;
			tie(x, y, z) = summer.front(); summer.pop();
			cmap[x][y] += z;
		}
		

		//가을

		while (!fall.empty()) {
			pair<int, int> temp;
			temp = fall.front(); fall.pop();
			for (int i = 0; i < 8; i++) {
				int nRow = temp.first + dLocation[i][0];
				int nCol = temp.second + dLocation[i][1];
				if (nRow < 0 || nRow == N || nCol < 0 || nCol == N)
					continue;
				vec[nRow][nCol].push_back(1);
			}
		}

		//겨울

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cmap[i][j] += nutrients[i][j];
			}
		}

	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ans += vec[i][j].size();
		}
	}

	cout << ans << '\n';

	return 0;
}