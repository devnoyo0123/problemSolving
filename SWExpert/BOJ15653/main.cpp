#include <iostream>
#include <queue>

using namespace std;

const int MAX = 11;

struct game {
    int bRow;
    int bCol;
    int rRow;
    int rCol;

    int cnt;

    game() {}

    game(int bRow, int bCol, int rRow, int rCol, int cnt) {
        this->bRow = bRow;
        this->bCol = bCol;
        this->rRow = rRow;
        this->rCol = rCol;
        this->cnt = cnt;
    }
};

int n, m, ans;

int dRow[] = {-1, 0, 1, 0};
int dCol[] = {0, 1, 0, -1};

char map[MAX][MAX];
bool check[MAX][MAX][MAX][MAX];

void solve(game &game1) {

    queue<game> qu;
    check[game1.bRow][game1.bCol][game1.rRow][game1.rCol] = true;
    qu.push(game1);
    game1.cnt = 0;

    while (!qu.empty()) {
        game tmp = qu.front();
        qu.pop();

        int curRRow = tmp.rRow;
        int curRCol = tmp.rCol;
        int curBRow = tmp.bRow;
        int curBCol = tmp.bCol;
        // left

        for (int i = 0; i < 4; ++i) {

            int nRRow = curRRow;
            int nRCol = curRCol;
            int nBRow = curBRow;
            int nBCol = curBCol;
            bool nRHole = false;
            bool nBHole = false;

            while (true) {
                if (map[nRRow + dRow[i]][nRCol + dCol[i]] != '#') {
                    nRRow += dRow[i];
                    nRCol += dCol[i];
                    if (map[nRRow][nRCol] == 'O') {
                        nRHole = true;
                        break;
                    }
                } else {

                    break;
                }
            }


            while (true) {
                if ((map[nBRow + dRow[i]][nBCol + dCol[i]] != '#')) {
                    nBRow += dRow[i];
                    nBCol += dCol[i];
                    if (map[nBRow][nBCol] == 'O') {
                        nBHole = true;
                        break;
                    }
                } else {

                    break;
                }
            }

            if (nBHole) {
                continue;
            }

            if (nRHole) {
                ans = tmp.cnt + 1;
                return;
            }

            if (nRRow == nBRow && nRCol == nBCol) {
                if (i == 0) {
                    tmp.rRow > tmp.bRow ? nRRow++ : nBRow++;
                } else if (i == 1) {
                    tmp.rCol > tmp.bCol ? nBCol-- : nRCol--;
                } else if (i == 2) {
                    tmp.rRow > tmp.bRow ? nBRow-- : nRRow--;
                } else {
                    tmp.rCol > tmp.bCol ? nRCol++ : nBCol++;
                }
            }

            if (!check[nBRow][nBCol][nRRow][nRCol]) {
                check[nBRow][nBCol][nRRow][nRCol] = true;
                qu.push(game(nBRow, nBCol, nRRow, nRCol, tmp.cnt + 1));

            }


        }


    }


}


int main() {

    cin >> n >> m;
    game game1;
    ans = -1;

    for (int i = 0; i < n; ++i) {
        string str = "";
        cin >> str;
        for (int j = 0; j < m; ++j) {
            map[i][j] = str[j];
            if (map[i][j] == 'R') {
                game1.rRow = i;
                game1.rCol = j;

            }

            if (map[i][j] == 'B') {
                game1.bRow = i;
                game1.bCol = j;
            }
        }
    }

    solve(game1);

    cout << ans << "\n";


    return 0;
}