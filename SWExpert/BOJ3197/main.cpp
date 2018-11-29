#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>


using namespace std;

const int MAX = 1502;

struct Swan {
    int row, col;
};


Swan swan[2];

int R, C, ans;
int dLocation[][2] = {{-1, 0},
                      {0,  1},
                      {1,  0},
                      {0,  -1}};

char map[MAX][MAX];
bool check[MAX][MAX];
bool flag;

void BFS1(int row, int col) {
    // 빙하 녹이는 BFS
    int cnt = 0;
    queue<pair<int, int> > qu1;
    check[row][col] = true;
    qu1.push({row, col});

    while (!qu1.empty()) {
        pair<int, int> tmp = qu1.front();
        qu1.pop();

        for (int i = 0; i < 4; ++i) {
            int nRow = tmp.first + dLocation[i][0];
            int nCol = tmp.second + dLocation[i][1];

            if (nRow < 0 || nRow >= R || nCol < 0 || nCol >= C) {
                continue;
            }

            if (check[nRow][nCol]) {
                continue;
            }

            if (map[nRow][nCol] == 'X') {
                check[nRow][nCol] = true;
                qu1.push({nRow, nCol});
            } else if (map[nRow][nCol] == '.') {
                map[tmp.first][tmp.second] = '.';
            } else if (map[nRow][nCol] == 'L') {
                map[tmp.first][tmp.second] = '.';
            }
        }
    }

}

void BFS2(int row, int col) {
    // 백조 찾는 BFS
    queue<pair<int, int> > qu1;
    check[row][col] = true;
    qu1.push({row, col});

    while (!qu1.empty()) {
        pair<int, int> tmp = qu1.front();
        qu1.pop();

        for (int i = 0; i < 4; ++i) {
            int nRow = tmp.first + dLocation[i][0];
            int nCol = tmp.second + dLocation[i][1];

            if (nRow < 0 || nRow >= R || nCol < 0 || nCol >= C) {
                continue;
            }

            if (check[nRow][nCol]) {
                continue;
            }

            if (map[nRow][nCol] == '.') {
                check[nRow][nCol] = true;
                qu1.push({nRow, nCol});
            } else if (map[nRow][nCol] == 'L') {
                flag = true;
                return;
            }
        }
    }
}

void solve(vector<pair<int, int> > &ice) {

    int cnt = 0;
    while (!flag) {
        cnt++;
        memset(check, false, sizeof(check));

        //얼음 녹이기

        for (int i = 0; i < ice.size(); ++i) {
            pair<int, int> tmp = ice[i];

            if (map[tmp.first][tmp.second] == 'X' && !check[tmp.first][tmp.second]) {
                BFS1(tmp.first, tmp.second);

            }
        }


//        printf("cnt: %d\n", cnt);
//        for (int j = 0; j < R; ++j) {
//            for (int i = 0; i < C; ++i) {
//                printf("%c", map[j][i]);
//            }
//            printf("\n");
//        }
//        printf("\n");


        memset(check, false, sizeof(check));

        BFS2(swan[0].row, swan[0].col);


    }
    ans = cnt;
}

int main() {

    vector<pair<int, int> > ice;
    scanf("%d %d", &R, &C);

    int cnt = 0;
    for (int i = 0; i < R; ++i) {
        scanf("%s", map[i]);
        for (int j = 0; j < C; ++j) {
            if (map[i][j] == 'L') {
                swan[cnt].row = i;
                swan[cnt].col = j;
            } else if (map[i][j] == 'X') {
                ice.push_back({i, j});
            }
        }
    }

    solve(ice);

    printf("%d\n", ans);
    return 0;
}