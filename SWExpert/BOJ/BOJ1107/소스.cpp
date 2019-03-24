#include <iostream>


using namespace std;

int error[10];
int num[6];
int sz = 0;
int ans = 0;
int n, m;

void dfs(int idx, int curNum) {
	if (idx > sz+1) {
		return;
	}

	int res = curNum - n;
	if (res < 0) {
		res = -res;
	}

	res += idx; // pressed count 

	if (ans > res) {
		ans = res;
	}

	for (int i = 0; i < 10; i++) {
		if (!error[i]) {
			int nNum;
			if (curNum > 0) {
				nNum = curNum * 10 + i;
			}
			else {
				nNum = i;
			}

			dfs(idx+1, nNum);
		}
	}

}

int main() {



	cin >> n >> m;

	int temp = n;
	while (temp > 0) {
		sz++;
		temp /= 10;
	}

	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		error[temp] = true;
	}

	ans = n - 100;
	if (ans < 0) {
		ans = -ans;
	}

	for (int i = 0; i < 10; i++) {
		if (!error[i]) {
			dfs(1, i);
		}
	}

	cout << ans << '\n';

	return 0;
}
