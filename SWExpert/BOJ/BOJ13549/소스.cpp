#include <iostream>
#include <queue>

using namespace std;

const int NMAX = 100001;

int dist[NMAX];

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(false);

	int N, K;

	cin >> N >> K;

	for (int i = 0; i < NMAX; i++) {
		dist[i] = -1;
	}

	queue<int> qu, nextQu;
	dist[N] = 0;
	qu.push(N);

	while (!qu.empty()) {
		int temp = qu.front(); qu.pop();

		if (temp == K) {
			break;
		}

		if (temp * 2 < NMAX && dist[temp * 2] < 0) {
			dist[temp * 2] = dist[temp];
			qu.push(temp * 2);
		}

		if (temp + 1 < NMAX && dist[temp + 1] < 0) {
			dist[temp + 1] = dist[temp] + 1;
			nextQu.push(temp + 1);
		}

		if (temp - 1 >= 0 && dist[temp - 1] < 0) {
			dist[temp - 1] = dist[temp] + 1;
			nextQu.push(temp - 1);
		}

		if (qu.empty()) {
			qu = nextQu;
			nextQu = queue<int>();
		}
	}

	cout << dist[K];




	return 0;
}