#include <iostream>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

char map[100][100];
bool check[100][100];

pair<int, int> end1;

int dLocation[][2] = { {0,-1},{-1,0},{0,1},{1,0} };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int t = 1; t <= 10; t++) {
		int n;
		cin >> n;
		queue<pair<int, int> > qu;
		int ans = 0;
		memset(check, 0, sizeof(check));
		memset(map, 0, sizeof(map));
		for (int i = 0; i < 100; i++) {
			string temp = "";
			cin >> temp;
			int length = temp.length();
			for (int j = 0; j < length; j++) {
				map[i][j] = temp[j];
				if (map[i][j] == '2') {
					check[i][j] = true;
					qu.push({ i,j });
				}
				else if( map[i][j] == '3'){
					end1.first = i;
					end1.second = j;
				}
			}
		}
	
		while (!qu.empty()) {
			pair<int, int> tmp = qu.front(); qu.pop();

			for (int i = 0; i < 4; i++) {
				int nRow = tmp.first + dLocation[i][0];
				int nCol = tmp.second + dLocation[i][1];

				if (nRow < 0 || nRow == 100 || nCol < 0 || nCol == 100) {
					continue;
				}

				if (check[nRow][nCol] || map[nRow][nCol] == '1') {
					continue;
				}


				check[nRow][nCol] = true;
				qu.push({ nRow,nCol });
			}
		}

		if (check[end1.first][end1.second]) {
			ans = 1;
		}
		else {
			ans = 0;
		}

		cout << "#" << t << " " << ans << '\n';

	}


	return 0;

}