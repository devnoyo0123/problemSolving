#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int NMAX = 4;
const int WMAX = 12;
const int HMAX = 15;
int TC, N, W, H, ans, pre;

int map[HMAX][WMAX];

struct Info {
    int row, col, val;
};

void reshape() {
    queue<int> qu1;

    for (int i = 0; i < W; ++i) { // 열
        for (int j = H - 1; j >= 0; --j) { // 행
            if (map[j][i] > 0) {
                qu1.push(map[j][i]);
            }
            map[j][i] = 0;
        }

        int start = H - 1;
        while (!qu1.empty()) {
            map[start--][i] = qu1.front();
            qu1.pop();
        }
    }

}

void BFS(int row, int col) {
    bool check[HMAX][WMAX];
    memset(check, 0, sizeof(check));
    Info info;
    info.row = row;
    info.col = col;
    info.val = map[row][col];
    queue<Info> qu1;
    check[row][col] = true;
    qu1.push(info);

    while (!qu1.empty()) {
        Info tmp = qu1.front();
        qu1.pop();
        int curRow = tmp.row;
        int curCol = tmp.col;
        int size = tmp.val - 1; //크기 -1만큼 반복
        map[curRow][curCol] = 0;
        //북쪽부터 시계방향으로 내가 가지고 있는 크기 -1만큼 다 0으로 만들고 check해줘요.
        while (size-- > 0) {
            curRow -= 1;
            if (curRow < 0) {
                break;
            } else {
                if (map[curRow][curCol] > 1) {
                    Info tmp;
                    tmp.row = curRow;
                    tmp.col = curCol;
                    tmp.val = map[curRow][curCol];
                    qu1.push(tmp);

                    check[curRow][curCol] = true;
                    map[curRow][curCol] = 0;
                } else {
                    check[curRow][curCol] = true;
                    map[curRow][curCol] = 0;
                }

            }
        }

        size = tmp.val - 1;
        curRow = tmp.row;
        curCol = tmp.col;
        while (size-- > 0) {
            curCol++;
            if (curCol == W) {
                break;
            } else {
                if (map[curRow][curCol] > 1) {
                    Info tmp;
                    tmp.row = curRow;
                    tmp.col = curCol;
                    tmp.val = map[curRow][curCol];
                    qu1.push(tmp);

                    check[curRow][curCol] = true;
                    map[curRow][curCol] = 0;

                } else {
                    check[curRow][curCol] = 0;
                    map[curRow][curCol] = 0;
                }
            }
        }

        size = tmp.val - 1;
        curRow = tmp.row;
        curCol = tmp.col;
        while (size-- > 0) {
            curRow++;
            if (curRow == H) {
                break;
            } else {
                if (map[curRow][curCol] > 1) {
                    Info tmp;
                    tmp.row = curRow;
                    tmp.col = curCol;
                    tmp.val = map[curRow][curCol];
                    qu1.push(tmp);

                    check[curRow][curCol] = true;
                    map[curRow][curCol] = 0;

                } else {
                    check[curRow][curCol] = 0;
                    map[curRow][curCol] = 0;
                }
            }
        }

        size = tmp.val - 1;
        curRow = tmp.row;
        curCol = tmp.col;
        while (size-- > 0) {
            curCol--;
            if (curCol < 0) {
                break;
            } else {
                if (map[curRow][curCol] > 1) {
                    Info tmp;
                    tmp.row = curRow;
                    tmp.col = curCol;
                    tmp.val = map[curRow][curCol];
                    qu1.push(tmp);

                    check[curRow][curCol] = true;
                    map[curRow][curCol] = 0;

                } else {
                    check[curRow][curCol] = 0;
                    map[curRow][curCol] = 0;
                }
            }
        }


    }
}

void crash(int pos) {
    for (int i = 0; i < H; ++i) {
        if (map[i][pos] == 0) {
            continue;
        } else {
            BFS(i, pos); // i,pos에 폭탄이 터졌을때 크기-1만큼 동서남북으로 0으로 만들기
            break;
        }
    }
}



int countRest() {
    int cnt = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (map[i][j] > 0)
                cnt++;
        }
    }
    return cnt;
}

void solve( int cnt) {
    if( cnt > N){
        return;

    }


    //맵에서 남은 숫자 카운트
    if( cnt == N){
        int tmp = countRest();

        if (ans > tmp) {
            ans = tmp;
        }

    }

    int tmpMap[HMAX][WMAX];

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            tmpMap[i][j] = map[i][j];
        }
    }

    for (int i = 0; i < W; ++i) {
//        printf("%d째, %d열 선택\n", cnt, i);
        crash(i); // 벽돌 부수기 BFS
//        int tmp2 = countRest(map);
        reshape(); // 맵 다시 만들기

        solve(cnt + 1);
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                map[i][j] = tmpMap[i][j];
            }
        }

    }

}

int main() {

    scanf("%d", &TC);

    for (int T = 1; T <= TC; T++) {
        scanf("%d %d %d", &N, &W, &H);

        memset(map, 0, sizeof(map));
        ans = 987654321;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                scanf("%d", &map[i][j]);
            }
        }


        solve(0);

        printf("#%d %d\n", T, ans);
    }
    return 0;
}

//https://goodgid.github.io/SWEA-5656/ 참조