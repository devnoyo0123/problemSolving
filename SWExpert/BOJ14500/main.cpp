#include <iostream>

using namespace std;

const int MAX = 500;

int dRow[] = {-1, 0, 1, 0};
int dCol[] = {0, 1, 0, -1};

int a[MAX][MAX];
bool c[MAX][MAX];
int ans;
int n, m;

void go(int row, int col, int sum, int cnt) {
    if (cnt == 0) {
        if (ans < sum) {
            ans = sum;
        }


        return;
    }

    if( row < 0 || row == n || col < 0 || col == m){
        return;
    }

    if(c[row][col])
        return;

    c[row][col] = true;

    for (int i = 0; i < 4; ++i) {

        go(row + dRow[i], col + dCol[i], sum + a[row][col], cnt - 1);

    }

    c[row][col] = false;

}

int main() {

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < m; ++i) {

            go(k, i, 0, 4);

            if (k + 2 < n) {
                int tmp = a[k][i] + a[k + 1][i] + a[k + 2][i];
                if (i + 1 < m) {

                    int tmp2 = tmp + a[k + 1][i + 1];
                    if (tmp2 > ans) {
                        ans = tmp2;
                    }

                }

                if (i - 1 >= 0) {

                    int tmp2 = tmp + a[k + 1][i - 1];
                    if (tmp2 > ans) {
                        ans = tmp2;
                    }

                }


            } else if (i + 2 < m) {
                int tmp = a[k][i] + a[k][i + 1] + a[k][i + 2];
                if (k + 1 < n) {

                    int tmp2 = tmp + a[k + 1][i + 1];
                    if (tmp2 > ans) {
                        ans = tmp2;
                    }

                }

                if (k - 1 >= 0) {

                    int tmp2 = tmp + a[k - 1][i + 1];
                    if (tmp2 > ans) {
                        ans = tmp2;
                    }

                }
            }


        }
    }

    cout << ans << "\n";

    return 0;
}