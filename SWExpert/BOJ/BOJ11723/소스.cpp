#include <iostream>
#include <string>

using namespace std;

int M, ans;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M;

	string tmp = "";
	int n;

	for (int i = 0; i < M; i++) {
		cin >> tmp;

		if (tmp == "add") {
			cin >> n;
			n -= 1;

			ans |= (1 << n);
		}
		else if (tmp == "check") {
			cin >> n;
			n -= 1;
			if ((ans & (1 << n)) == 0) {
				cout << 0 << '\n';
			}
			else {
				cout << 1 << '\n';
			}
		}
		else if (tmp == "remove") {
			cin >> n;
			n -= 1;
			ans &= ~(1 << n);
		}
		else if( tmp == "toggle"){
			cin >> n;
			n -= 1;
			ans ^= (1 << n);
		}
		else if (tmp == "all") {
			ans = (1<<20)-1;
		}
		else if (tmp == "empty") {
			ans = 0;
		}
	}


	return 0;
}