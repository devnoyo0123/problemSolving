#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
char alpha[128];
int calc(vector<string> &a, vector<char> &letters, vector<int> &d) {
	int m = letters.size();
	int sum = 0;
	for (int i = 0; i < m; i++) {
		alpha[letters[i]] = d[i];
	}
	for (string s : a) {
		int now = 0;
		for (char x : s) {
			now = now * 10 + alpha[x];
		}
		sum += now;
	}
	return sum;
}
int main() {
	int n;
	cin >> n;
	vector<string> a(n);
	vector<char> letters;
	int letterr = 0;
	int sz = 0;
	int xx = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (char x : a[i]) {
			xx = x - 'A';
			if (!(letterr & (1 << xx))) {
				letterr |= (1 << xx);
				sz++;
			}
		}
	}
	int temp = 'Z' - 'A';
	for (int i = 0; i <= 'Z' - 'A'; i++) {
		if (letterr & (1 << i)) {
			letters.push_back('A' + i);
		}
	}
	sort(letters.begin(), letters.end());
	int m = letters.size();
	vector<int> d;
	for (int i = 9; i > 9 - m; i--) {
		d.push_back(i);
	}
	sort(d.begin(), d.end());
	int ans = 0;
	do {
		int now = calc(a, letters, d);
		if (ans < now) {
			ans = now;
		}

		for (int i = 0; i < d.size(); i++) {
			cout << d[i] << " ";
		}
		cout<<'\n';

	} while (next_permutation(d.begin(), d.end()));
	cout << ans << '\n';
	return 0;
}