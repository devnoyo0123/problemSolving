#include <iostream>

using namespace std;

int tc;
int M, N, cnt, ans;
int x, y;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a%b);

}

int main() {

	cin >> tc;

	

	for (int t = 1; t <= tc; t++) {
		cin >> M >> N >> x >> y;
		cnt = x;
		ans = -1;
		int lcm = x*y / gcd(x, y);
		
		for ( ; cnt <= N * M; cnt += M) {
			if ( (cnt % N) == y) {
				ans = cnt;
				break;
			}
		}


		cout << ans << '\n';
	}




	return 0;
}

