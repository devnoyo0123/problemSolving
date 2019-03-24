#include <iostream>
#include <cstring>

using namespace std;

bool check[10];
int map[10][10];

int n;
int ans = 987654321;

void go(int start, int curidx,int cnt, int sum) {
	if (cnt >= n-1 && map[curidx][start] > 0) {
		sum += map[curidx][start];
		if (ans > sum) {
			ans = sum;
		}
		return;
	}

	for (int i = 0; i < n; i++) {

		if (check[i] || map[curidx][i] == 0)
			continue;

		if (sum + map[curidx][i] > ans) {
			continue;
		}
		
		check[i] = true;
		go(start, i, cnt+1, sum + map[curidx][i]);
		check[i] = false;
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		memset(check, 0, sizeof(check));
		check[i] = true;
		go(i, i, 0, 0);
		check[i] = false;
	}

	cout << ans << '\n';

	return 0;
}
