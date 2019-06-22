#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 40;

int n, s, ans;

int dataa[MAX];
bool check[MAX];
vector<int> sums[2];

void go(int group, int curidx, int start, int end) {
	if (curidx == end) {

		int sum = 0;
		for (int i = start; i < end; i++) {
			if (check[i])
				sum += dataa[i];
		}

		sums[group].push_back(sum);

		return;
	}

	check[curidx] = true;
	go(group, curidx + 1, start, end);
	check[curidx] = false;
	go(group, curidx + 1, start, end);
}



int main() {

	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> dataa[i];
	}

	go(0, 0, 0, n / 2);

	go(1, n / 2, n / 2, n);

	sort(sums[0].begin(), sums[0].end());
	sort(sums[1].begin(), sums[1].end());

	int left, right, sum;
	left = 0;
	right = sums[1].size() - 1;

	while (left < sums[0].size() && right >= 0 ) {
		if (sums[0][left] + sums[1][right] > s) {
			right--;
		}
		else if (sums[0][left] + sums[1][right] == s) {
			int cur = right -1;
			int upCnt = 1, downCnt = 1;
			while (cur - 1 >= 0 && sums[1][cur - 1] == sums[1][cur]) {
				cur--;
				downCnt++;
			}
			right = cur;
			cur = left + 1;
			while (cur + 1 < sums[0].size() && sums[0][cur + 1] == sums[0][cur]) {
				cur++;
				upCnt++;
			}
			left = cur;
			ans += downCnt * upCnt;
		}
		else {
			left++;
		}
	}

	if (s == 0)
		ans -= 1;
	cout << ans << '\n';

	return 0;
}