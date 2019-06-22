#include <iostream>
#include <string>

using namespace std;

int map[4][4];
int check[4][4];
int N, M;
int ans;

void go(int cnt) {

	if (cnt == N*M) {
		//vertical

		int sero = 0;
		for (int i = 0; i < M; i++) {
			int cnt = 0;
			int temp = 0;
			for (int j = 0; j < N; j++) {
				if (check[j][i] == 1) {
					if (cnt > 0) {
						temp *=10;
					}
					temp += map[j][i];
					cnt++;
				}else{
					sero += temp;
					cnt = 0;
					temp = 0;
				}
			}
			sero += temp;
		}

		//horizontal

		int garo = 0;
		for (int i = 0; i < N; i++) {
			int cnt = 0;
			int temp = 0;
			for (int j = 0; j < M; j++) {
				if (check[i][j] == 2) {
					if (cnt > 0) {
						temp *=10;
					}
					temp += map[i][j];


					cnt++;
				}
				else {
					garo += temp;
					cnt = 0;
					temp = 0;
				}
			}
			garo += temp;
		}


		if (garo + sero > ans) {
			ans = garo + sero;
		}

		return;
	}



	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			if (check[i][j])
				continue;

			check[i][j] = 1; // vertical
			go(cnt+1);
			check[i][j] = 0;

			check[i][j] = 2; // horizontal
			go(cnt+1);
			check[i][j] = 0;

		}
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string temp = "";
		cin >> temp;
		for (int j = 0; j < M; j++) {
			map[i][j] = temp[j] - '0';
		}
	}

	go(0);

	cout << ans << '\n';

	return 0;
}