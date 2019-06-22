#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 32;

int n;

bool c[MAX][MAX];
int a[MAX][MAX];
long long d[MAX][MAX][3];


long long dfs(int row, int col, int dir) {
    if (row == n - 1 && col == n - 1) {
        return 1;
    }

    long long &ans = d[row][col][dir];
    if (ans != -1) return ans;
    ans = 0;


    if (dir == 0) {
        // 180
        if (col + 1 < n) {
            if (!c[row][col + 1] && a[row][col + 1] == 0 ) {
                c[row][col + 1] = true;
                ans += dfs(row, col + 1, 0);
                c[row][col + 1] = false;
            }
        }

        // 225
        if (row+1 < n && col + 1 < n) {
            if (!c[row + 1][col + 1] && a[row + 1][col + 1] == 0 && a[row][col + 1] == 0 && a[row + 1][col] == 0) {
                c[row+1][col + 1] = true;
                ans += dfs(row+1, col + 1, 1);
                c[row+1][col + 1] = false;
            }
        }
    }
    else if (dir == 1) {
        // 180
        if (col + 1 < n) {
            if (!c[row][col + 1] && a[row][col + 1] == 0) {
                c[row][col + 1] = true;
                ans += dfs(row, col + 1, 0);
                c[row][col + 1] = false;
            }
        }
        // 225
        if (row + 1 < n && col + 1 < n) {
            if (!c[row + 1][col + 1] && a[row + 1][col + 1] == 0 && a[row][col + 1] == 0 && a[row + 1][col] == 0) {
                c[row + 1][col + 1] = true;
                ans += dfs(row + 1, col + 1, 1);
                c[row + 1][col + 1] = false;
            }
        }

        // 270
        if (row + 1 < n) {
            if (!c[row + 1][col] && a[row + 1][col] == 0) {
                c[row + 1][col] = true;
                ans += dfs(row + 1, col, 2);
                c[row + 1][col] = false;
            }
        }
    }
    else {
        // 225
        if (row + 1 < n && col + 1 < n) {
            if (!c[row + 1][col + 1] && a[row + 1][col + 1] == 0 && a[row][col + 1] == 0 && a[row + 1][col] == 0) {
                c[row + 1][col + 1] = true;
                ans += dfs(row + 1, col + 1, 1);
                c[row + 1][col + 1] = false;
            }
        }

        // 270
        if (row + 1 < n) {
            if (!c[row + 1][col] && a[row + 1][col] == 0) {
                c[row + 1][col] = true;
                ans += dfs(row + 1, col, 2);
                c[row + 1][col] = false;
            }
        }
    }

    return ans;
}

int main() {

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    memset(d,-1, sizeof(d));

    cout << dfs(0, 1, 0) << '\n';

    return 0;
}