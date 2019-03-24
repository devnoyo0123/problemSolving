#include <iostream>
#include <queue>

using namespace std;

int dist[100001];

int N, K;

int main()
{
	for (int i = 0; i < 100001; i++) {
		dist[i] = -1;
	}
	cin >> N >> K;

	queue <int> qu;

	dist[N] = 0;
	qu.push(N);

	while (!qu.empty()) {
		int temp = qu.front(); qu.pop();

		if (temp == K) {
			break;
		}

		if (temp - 1 >= 0 && dist[temp - 1] < 0) {
			dist[temp - 1] = dist[temp] + 1;
			qu.push(temp - 1);
		}

		if (temp +1 < 100001 && dist[temp + 1] < 0) {
			dist[temp + 1] = dist[temp] + 1;
			qu.push(temp + 1);
		}

		if (temp*2 < 100001 && dist[temp*2] < 0) {
			dist[temp*2] = dist[temp] + 1;
			qu.push(temp*2);
		}
	}

	cout << dist[K] << '\n';


	return 0;
}