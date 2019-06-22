#include <iostream>

using namespace std;

const int MAX = 20;

int N, S, ans;
int dataa[MAX];

int main() {

	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> dataa[i];
	}

	for (int i = 1; i < (1 << N); i++) {
		int sum = 0;
		for (int j = 0; j < N; j++) {
			if ((i & (1 << j)) == 0)
				continue;
			sum += dataa[j];
		}
		if (S == sum)
			ans++;
	}

	cout << ans << '\n';

	return 0;
}