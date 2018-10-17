#include <cstdio>
#include <algorithm>
#include <cstring>

const int MAX = 21;

int TC, N, X, ans;

int map[MAX][MAX];
bool check[MAX];

void colorColBackward(int X, int row) {
    int nRow = row;
    while (X-- > 0) {
        check[nRow] = true;
        nRow -= 1;
    }
}

bool checkColBackward(int X, int row, int col) {
    bool ret = true;

    int nRow = row;
    int nCol = col;
    while (X-- > 0) {

        if (nRow < 0) {
            // 범위를 나가도 false

            ret = false;
            break;

        } else if (check[nRow]) {
            ret = false;
            // 체크가 되어있어도 false

            break;

        } else if (map[nRow][nCol] != map[row][col]) {
            ret = false;

            break;
        }

        nRow -= 1;
    }

    return ret;
}

void colorColForward(int X, int row) {
    int nRow = row;
    while (X-- > 0) {
        check[nRow] = true;
        nRow += 1;

    }
}

bool checkColForward(int X, int row, int col) {
    bool ret = true;
    // inx를 기준으로 inx가 커지는 방향으로
    // 같은 값인지 X-1만큼 이동한 값까지 같은지 확인
    int nRow = row;
    int nCol = col;
    while (X-- > 0) {

        if (nRow == N) {
            // 범위를 나가도 false

            ret = false;
            break;
        } else if (check[nRow]) {
            ret = false;
            // 체크가 되어있어도 false

            break;
        } else if (map[nRow][nCol] != map[row][col]) {
            ret = false;

            break;
        }
        nRow += 1;

    }

    return ret;
}

void colorRowBackward(int X, int col) {
    int nCol = col;

    while (X-- > 0) {

        check[nCol] = true;
        nCol -= 1;
    }
}

bool checkRowBackward(int X, int row, int col) {
    bool ret = true;

    int nRow = row;
    int nCol = col;
    while (X-- > 0) {

        if (nCol < 0) {
            // 범위를 나가도 false

            ret = false;
            break;
        } else if (check[nCol]) {
            ret = false;
            // 체크가 되어있어도 false

            break;
        } else if (map[nRow][nCol] != map[row][col]) {
            ret = false;

            break;
        }
        nCol -= 1;
    }

    return ret;
}

void colorRowForward(int X, int col) {
    int nCol = col;
    while (X-- > 0) {

        check[nCol] = true;
        nCol += 1;
    }
}

//row, col부터 X만큼 인덱스 큰방향으로 같은지 보는 함수
bool checkRowForward(int X, int row, int col) {
    bool ret = true;
    // inx를 기준으로 inx가 커지는 방향으로
    // 같은 값인지 X-1만큼 이동한 값까지 같은지 확인
    int nRow = row;
    int nCol = col;
    while (X-- > 0) {

        if (nCol == N) {
            // 범위를 나가도 false

            ret = false;
            break;

        } else if (check[nCol]) {
            ret = false;
            // 체크가 되어있어도 false

            break;

        } else if (map[nRow][nCol] != map[row][col]) {
            ret = false;

            break;
        }

        nCol += 1;
    }

    return ret;
}

void solve() {

    int tmp = 0;
    // 행 기준  검색
    for (int i = 0; i < N; ++i) {
        int sameCnt = 0;
        bool OK = true;
        memset(check, 0, sizeof(check));
        for (int j = 0; j < N; ++j) {

            if (check[j])
                continue;

            if (j + 1 < N && map[i][j] == map[i][j + 1]) {
                sameCnt++;
            }

            if (j - 1 >= 0 && map[i][j - 1] - map[i][j] == 1) {
                // 3 2
                if (checkRowForward(X, i, j)) {
                    colorRowForward(X, j);
                } else {
                    OK = false;
                    break;// 하나라도 안되면 실패
                }
            } else if (j - 1 >= 0 && abs(map[i][j - 1] - map[i][j]) > 1) {
                OK = false;
                break;
            }

            if (j + 1 < N && map[i][j] - map[i][j + 1] == -1) {
                // 2 3
                if (checkRowBackward(X, i, j)) {
                    colorRowBackward(X, j);
                } else {
                    OK = false;
                    break;
                }
            } else if (j + 1 < N && abs(map[i][j] - map[i][j + 1]) > 1) {
                OK = false;
                break;
            }


        }

        if (sameCnt == N - 1) {
//            printf("row: %d\n", i);
            tmp += 1;
        } else if (OK) {
//            printf("row: %d\n", i);
            tmp += 1;
        }


    }

    // 열 기준 검색
    for (int j = 0; j < N; ++j) {
        int sameCnt = 0;
        bool OK = true;
        memset(check, 0, sizeof(check));
        for (int i = 0; i < N; ++i) {

            if(check[i])
                continue;

            if (i + 1 < N && map[i][j] == map[i + 1][j]) {
                sameCnt++;
            }

            if (i - 1 >= 0 && map[i - 1][j] - map[i][j] == 1) {
                // 3
                // 2
                if (checkColForward(X, i, j)) {
                    colorColForward(X, i);
                } else {
                    OK = false;
                    break; // 하나라도 실패하면 그 라인 실패
                }
            } else if (i - 1 >= 0 && abs(map[i - 1][j] - map[i][j]) > 1) {
                OK = false;
                break;
            }

            if (i + 1 < N && map[i][j] - map[i + 1][j] == -1) {
                // 2
                // 3
                if (checkColBackward(X, i, j)) {
                    colorColBackward(X, i);
                } else {
                    OK = false;
                    break;
                }
            } else if (i + 1 < N && abs(map[i][j] - map[i + 1][j]) > 1) {
                OK = false;
                break;
            }


        }
        if (sameCnt == N - 1) {
//            printf("col: %d\n", j);
            tmp += 1;
        } else if (OK) {
//            printf("col: %d\n", j);

            tmp += 1;
        }

    }


    ans = tmp;
}

int main() {

    scanf("%d", &TC);

    for (int T = 1; T <= TC; T++) {
        scanf("%d %d", &N, &X);
        memset(map, 0, sizeof(map));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                scanf("%d", &map[i][j]);
            }
        }
        ans = 0;
        solve();
        printf("#%d %d\n", T, ans);
    }


    return 0;
}