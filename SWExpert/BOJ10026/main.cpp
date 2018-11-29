#include <cstdio>
#include <queue>

using namespace std;

const int MAX = 101;

int N, res1, res2;

int dRow[] = {-1, 0, 1, 0};
int dCol[] = {0, 1, 0, -1};

char map[MAX][MAX];

bool check1[MAX][MAX];
bool check2[MAX][MAX];

void BFS1(int row, int col) {
    queue<pair<int, int> > qu1;
    check1[row][col] = true;
    qu1.push({row, col});

    while (!qu1.empty()) {
        pair<int, int> tmp = qu1.front();
        qu1.pop();

        for (int i = 0; i < 4; ++i) {
            int nRow = tmp.first + dRow[i];
            int nCol = tmp.second + dCol[i];

            if (nRow < 0 || nRow >= N || nCol < 0 || nCol >= N) {
                continue;
            }

            if (check1[nRow][nCol]) {
                continue;
            }

            if (map[nRow][nCol] == map[tmp.first][tmp.second]) {
                check1[nRow][nCol] = true;
                qu1.push({nRow, nCol});
            }

        }
    }
}

void BFS2(int row, int col) {
    queue<pair<int, int> > qu2;
    check2[row][col] = true;
    qu2.push({row, col});

    while (!qu2.empty()) {
        pair<int, int> tmp = qu2.front();
        qu2.pop();

        for (int i = 0; i < 4; ++i) {
            int nRow = tmp.first + dRow[i];
            int nCol = tmp.second + dCol[i];

            if (nRow < 0 || nRow >= N || nCol < 0 || nCol >= N) {
                continue;
            }

            if (check2[nRow][nCol]) {
                continue;
            }


            if (map[tmp.first][tmp.second] == 'R') {
                if ((map[nRow][nCol] == 'G') || (map[nRow][nCol] == 'R')) {
                    check2[nRow][nCol] = true;
                    qu2.push({nRow, nCol});
                }

            } else if (map[tmp.first][tmp.second] == 'G') {
                if ((map[nRow][nCol] == 'G') || (map[nRow][nCol] == 'R')) {
                    check2[nRow][nCol] = true;
                    qu2.push({nRow, nCol});
                }

            } else {
                if( map[tmp.first][tmp.second] == map[nRow][nCol]){
                    check2[nRow][nCol] = true;
                    qu2.push({nRow, nCol});
                }

            }


        }
    }
}

int main() {

    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
        scanf("%s", map[i]);
    }

    for (int j = 0; j < N; ++j) {
        for (int i = 0; i < N; ++i) {
            if (check1[j][i]) {
                continue;
            }

            BFS1(j, i);
            res1 += 1;
        }
    }

    for (int j = 0; j < N; ++j) {
        for (int i = 0; i < N; ++i) {
            if (check2[j][i]) {
                continue;
            }

            BFS2(j, i);
            res2 += 1;
        }
    }

    printf("%d %d\n", res1, res2);
    return 0;
}