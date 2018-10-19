#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int MAX = 100;

int TC, N, X, ans;

int map[MAX][MAX];

bool check(vector<int> &a) {
    //오르막 검사

    int n = a.size();
    vector<bool> c(n, false);
    for (int i = 1; i < n; i++) {
        if (a[i - 1] != a[i]) {
            // 인접한 칸의 높이가 다르면, 경사로를 놓아야 한다.
            int diff = a[i] - a[i - 1];
            if (diff < 0) diff *= -1;
            if (diff != 1) {
                // 낮은 칸과 높은 칸의 높이 차이는 1이어야 한다.
                return false;
            }
            if (a[i - 1] < a[i]) {
                for (int j = 1; j <= X; j++) {
                    if (i - j < 0) {
                        // 경사로를 놓다가 범위를 벗어나는 경우
                        return false;
                    }
                    if (a[i - 1] != a[i - j]) {
                        // 낮은 지점의 칸의 높이가 모두 같지 않거나, L개가 연속되지 않은 경우

                        return false;
                    }
                    if (c[i - j]) {
                        // 경사로를 놓은 곳에 또 경사로를 놓는 경우
                        return false;
                    }
                    c[i - j] = true;
                }
            } else {
                // a[i-1] > a[i]
                for (int j = 0; j < X; j++) {
                    if (i + j >= n) {
                        // 경사로를 놓다가 범위를 벗어나는 경우
                        return false;
                    }
                    if (a[i] != a[i + j]) {
                        // 낮은 지점의 칸의 높이가 모두 같지 않거나, L개가 연속되지 않은 경우

                        return false;
                    }
                    if (c[i + j]) {
                        // 경사로를 놓은 곳에 또 경사로를 놓는 경우
                        return false;
                    }
                    c[i + j] = true;
                }
            }
        }
    }
    return true;


}

void solve() {
    //행부터 검사

    for (int i = 0; i < N; i++) {
        // 행 검사
        vector<int> d;
        for (int j = 0; j < N; j++) {
            d.push_back(map[i][j]);
        }
        if (check(d)) ans += 1;
    }
    for (int j = 0; j < N; j++) {
        // 열 검사
        vector<int> d;
        for (int i = 0; i < N; i++) {
            d.push_back(map[i][j]);
        }
        if (check(d)) ans += 1;
    }

}

int main() {

    cin >> N >> X;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    solve();
    cout << ans << "\n";


    return 0;
}