#include <iostream>
#include <string>

using namespace std;

const int MAX = 50;

int N, K, ans;

string strs[MAX];
bool alphabet[26];

void DFS(int idx, int cnt) {

	if (cnt > K)
		return;

	if (idx == 26) {

		int res = 0;
		for (int i = 0; i < N; i++) {
			bool fail = false;

			for (int j = 0; j < strs[i].size(); j++) {
				int idx = strs[i][j] - 'a';
				if (!alphabet[idx]) {
					fail = true;
					break;
				}
					
			}
			if(!fail)
				res++;
		}

		if (res > ans)
			ans = res;


		return;
	}

	alphabet[idx] = true;
	DFS(idx + 1, cnt + 1);
	alphabet[idx] = false;

	if (idx != 'a' - 'a' && idx != 'n' - 'a' && idx != 't' - 'a'
		&& idx != 'i' - 'a' && idx != 'c' - 'a') {
		DFS(idx + 1, cnt);
	}
	
}


int main()
{
	cin >> N >> K;

	string temp = "";
	for (int i = 0; i < N; i++) {
		cin >> temp;
		strs[i] = temp;
	}

	DFS(0,0);

	cout << ans << '\n';


	return 0;
}