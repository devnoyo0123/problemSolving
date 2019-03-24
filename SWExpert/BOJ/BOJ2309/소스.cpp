#include <iostream>
#include <algorithm>

using namespace std;


int tmp[9];
int data1[9];
bool check[9];
bool done;


void go(int sum, int cnt) {


	if ( !done && sum == 100 && cnt == 7) {

		int idx = 0;
		for (int i = 0; i < 9; i++) {
			if(check[i])
				tmp[idx++] = data1[i];
		}

		sort(tmp, tmp + 7);

		for (int i = 0; i < 7; i++) {
			cout << tmp[i] << '\n';
		}

		done = true;
		return;
	}


	if (cnt > 7 || sum > 100)
		return;


	for (int i = 0; i < 9; i++) {
		if (check[i]) {
			continue;
		}

		if (done) {
			return;
		}

		check[i] = true;
		go(sum + data1[i], cnt + 1);
		check[i] = false;
	}

}

int main() {

	for (int i = 0; i < 9; i++) {
		cin >> data1[i];
	}

	go(0, 0);

	return 0;
}