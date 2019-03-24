#include <iostream>
#include <queue>

using namespace std;

int dist[1001][1001]; //[screen][clipboard]

int main() {
	
	queue<pair<int, int> > qu;
	int n;

	cin >> n;

	dist[1][0] = 0;
	qu.push({ 1,0 });
	
	while (!qu.empty()) {
		pair<int, int> temp = qu.front(); qu.pop();

		if (temp.first == n) {
			break;
		}

		if (dist[temp.first][temp.first] == 0) {
			dist[temp.first][temp.first] = dist[temp.first][temp.second] + 1;
			qu.push({ temp.first, temp.first });
		}


		if (temp.second > 0) {
			int ns, nc;
			ns = temp.first + temp.second;
			nc = temp.second;
			if (ns <= 1000 && dist[ns][nc] == 0) {
				dist[ns][nc] = dist[temp.first][temp.second] + 1;
				qu.push({ns, nc });
			}

		}


		if (temp.first > 0) {
			int ns, nc;
			ns = temp.first-1;
			nc = temp.second;
			if (ns >= 0 && dist[ns][nc] == 0) {
				dist[ns][nc] = dist[temp.first][temp.second] + 1;
				qu.push({ ns, nc });
			}
		}

	}

	int ans = 987654321;
	for (int i = 0; i <= 1000; i++) {
		if (ans > dist[n][i] && dist[n][i] > 0) {
			ans = dist[n][i];
		}
	}
	cout << ans << '\n';

	

	return 0;
}