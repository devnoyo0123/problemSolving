#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;
const int SIZE = 105;

int TC, N, M, K;
long long ans;

int map[SIZE][SIZE][2]; //[][][0]: 미생물수, [][][1]: 이동방향 [2] : swap여부

int dLocation[][2] = {{-1, 0},
                      {1,  0},
                      {0,  -1},
                      {0,  1}};

struct Info {
    int row;
    int col;
    int val;
    int dir;
};

queue<Info> q;


int changeDir(int dir) {
    if (dir == 0) {
        return 1;
    } else if (dir == 1) {
        return 0;
    } else if (dir == 2) {
        return 3;
    } else if (dir == 3) {
        return 2;
    }
}


bool lineCheck(int row, int col) {
    return row == 0 || row == N - 1 || col == 0 || col == N - 1;
}

void solve() {


    while (M--) {
        //이동
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (map[i][j][0] > 0) {

                    int dir = map[i][j][1];
                    int nRow = i + dLocation[dir][0];
                    int nCol = j + dLocation[dir][1];

                    if (lineCheck(nRow, nCol)) {
                        // 투약공간

                        if (map[i][j][0] / 2 == 0) { //  절반을 나눴을때 0이 됌.
                            map[i][j][0] = 0; // 기존 위치 갱신
                            map[i][j][1] = -1;
                        } else {
                            Info info;
                            info.row = nRow;
                            info.col = nCol;
                            info.val = map[i][j][0] / 2;

                            int nDir = changeDir(dir); // 방향 바꾸기

                            info.dir = nDir;
                            q.push(info);


                            map[i][j][0] = 0; // 기존 위치 갱신
                            map[i][j][1] = -1;
                        }

                    } else {

                        // 투약공간아님

                        Info info;
                        info.row = nRow;
                        info.col = nCol;
                        info.val = map[i][j][0];
                        info.dir = dir;
                        q.push(info);

                        map[i][j][0] = 0; // 기존 위치 갱신
                        map[i][j][1] = -1;

                    }


                }

            }
        }

        //충돌했으면 합쳐줘요.
        while (!q.empty()) {
            Info info = q.front();
            q.pop();
            int row = info.row;
            int col = info.col;
            int val = info.val;
            int dir = info.dir;

            if( map[row][col][0] > 0){
//                if( val >= map[row][col][0]){
//                    map[row][col][0] += val;
//                    map[row][col][1] = dir; // 방향 잡아먹기
//                }else{
//                    map[row][col][0] += val;
//                }
            }else{
                map[row][col][0] = val;
                map[row][col][1] = dir;
            }
//            printf("val:%d, dir: %d, row: %d, col: %d\n", val, dir, row, col);
        }

//        printf("t: %d\n",t);
//        for (int k = 0; k < N; ++k) {
//            for (int i = 0; i < N; ++i) {
//                printf("%d  ", map[k][i][0]);
//            }
//            printf("\n");
//        }
//        printf("\n");

    }

    long long cnt = 0;
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            if (map[k][i][0] > 0) {
                cnt += map[k][i][0];
            }

        }
    }
    ans = cnt;
}

void init(){
    while(!q.empty()){
        q.pop();
    }
}

int main() {
    // 입력수가 많을때는 scanf

    scanf("%d", &TC);

    for (int T = 1; T <= TC; T++) {
        scanf("%d %d %d", &N, &M, &K);
        ans = 0;
        memset(map, 0, sizeof(map));
        init();

        int row = 0, col = 0, cnt = 0, dir = 0;
        for (int i = 0; i < K; i++) {
            scanf("%d %d %d %d", &row, &col, &cnt, &dir);
            map[row][col][0] = cnt;
            map[row][col][1] = dir - 1;
        }

//        for (int k = 0; k < N; ++k) {
//            for (int i = 0; i < N; ++i) {
//                printf("%d  ", map[k][i][0]);
//            }
//            printf("\n");
//        }
//        printf("\n");


        solve();
        printf("#%d %d\n", T, ans);
    }


    return 0;
}