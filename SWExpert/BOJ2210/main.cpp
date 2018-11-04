#include <iostream>

using namespace std;

int map[5][5];

int nums[6];
int c[10][10][10][10][10][10];

int dRow[] = {-1, 0, 1, 0};
int dCol[] = {0, 1, 0, -1};

int ans = 0;

void solve(int i, int j, int cnt) {
    if (cnt == 6) {
        //계산하고
        if (!c[nums[0]][nums[1]][nums[2]][nums[3]][nums[4]][nums[5]]) {
            c[nums[0]][nums[1]][nums[2]][nums[3]][nums[4]][nums[5]] = true;
//            for (int k = 0; k < 6; ++k) {
//                cout << nums[k] << " ";
//            }
//            cout << "\n";
            ans++;
        }
        return;
    }

    for (int k = 0; k < 4; ++k) {
        int nRow = i + dRow[k];
        int nCol = j + dCol[k];
        if (nRow < 0 || nRow > 4 || nCol < 0 || nCol > 4) {
            continue;
        } else {
            nums[cnt] = map[nRow][nCol];
            solve(nRow, nCol, cnt + 1);

        }
    }
}

int main() {

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; ++j) {
            cin >> map[i][j];
        }
    }

    for (int k = 0; k < 5; ++k) {
        for (int i = 0; i < 5; ++i) {
            nums[0] = map[k][i];
            solve(k, i, 1);
        }
    }
    cout << ans << '\n';

    return 0;
}