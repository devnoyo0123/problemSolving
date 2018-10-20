// 시간초과나는 실패 소
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 100;
const int WHMAX = 10+2;

struct WORMHOLES {
    int inx;
    pair<int, int> wholes[2];
};

int TC, N;
int map[MAX + 2][MAX + 2]; // 5로 패딩할것임.
int ans, startRow, startCol, score;
int dLocation[][2] = {{-1, 0},
                      {0,  1},
                      {1,  0},
                      {0,  -1}};

WORMHOLES wormholes[WHMAX];


void vecClear() {
    memset(wormholes, 0, sizeof(wormholes));
}

void read() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> map[i][j];
            if (map[i][j] >= 6 && map[i][j] <= 10) {
                int numOfHoles = map[i][j];
                wormholes[numOfHoles].wholes[wormholes[numOfHoles].inx].first = i;
                wormholes[numOfHoles].wholes[wormholes[numOfHoles].inx].second = j;
                wormholes[numOfHoles].inx++;
            }

        }
    }

//    for (int k = 0; k < WHMAX; ++k) {
//        for (int i = 0; i < wormholes[k].inx; ++i) {
//            cout<<k<<"번째 ,row: "<<wormholes[k].wholes[i].first<<", col: "<<wormholes[k].wholes[i].second<<"\n";
//        }
//    }
}

void simulate(int startRow, int startCol, int dir) {

    //현재좌표
    int cRow = startRow;
    int cCol = startCol;

    int cnt = 0;

    while (true) {

        //다음좌표
        int nRow = cRow + dLocation[dir][0];
        int nCol = cCol + dLocation[dir][1];

        if ((nRow == startRow && nCol == startCol) || map[nRow][nCol] == -1) {
            if (ans < cnt) {
                ans = cnt;
            }
            return;
        }

        // 웜홀이면 위치변경
        if (map[nRow][nCol] >= 6 && map[nRow][nCol] <= 10) {
            // 잘못된 로직
//            // 6
//            int numOfHoles = map[nRow][nCol];
//            for (int l = 0; l < wormholes[numOfHoles].inx; ++l) {
//                if (nRow == wormholes[numOfHoles].wholes[l].first && nCol == wormholes[numOfHoles].wholes[l].second) {
//                    continue;
//                } else {
//                    nRow = wormholes[numOfHoles].wholes[l].first;
//                    nCol = wormholes[numOfHoles].wholes[l].second;
//                }
//            }
            // 잘 돌아가는 로직
            int numOfHoles = map[nRow][nCol];
            if(wormholes[numOfHoles].wholes[0].first == nRow && wormholes[numOfHoles].wholes[0].second == nCol){
                nRow = wormholes[numOfHoles].wholes[1].first;
                nCol = wormholes[numOfHoles].wholes[1].second;

            }else{
                nRow = wormholes[numOfHoles].wholes[0].first;
                nCol = wormholes[numOfHoles].wholes[0].second;
            }

        } else if (map[nRow][nCol] >= 1 && map[nRow][nCol] <= 5) {
            //블록임
            cnt += 1;

            //1
            if (map[nRow][nCol] == 1) {
                if (dir == 0) {
                    dir = 2;
                } else if (dir == 1) {
                    dir = 3;
                } else if (dir == 2) {
                    dir = 1;
                } else if (dir == 3) {
                    dir = 0;
                }
            }
                //2
            else if (map[nRow][nCol] == 2) {

                if (dir == 0) {
                    dir = 1;
                } else if (dir == 1) {
                    dir = 3;
                } else if (dir == 2) {
                    dir = 0;
                } else if (dir == 3) {
                    dir = 2;
                }
            }
                //3
            else if (map[nRow][nCol] == 3) {

                if (dir == 0) {
                    dir = 3;
                } else if (dir == 1) {
                    dir = 2;
                } else if (dir == 2) {
                    dir = 0;
                } else if (dir == 3) {
                    dir = 1;
                }
            }
                //4
            else if (map[nRow][nCol] == 4) {

                if (dir == 0) {
                    dir = 2;
                } else if (dir == 1) {
                    dir = 0;
                } else if (dir == 2) {
                    dir = 3;
                } else if (dir == 3) {
                    dir = 1;
                }
            }
                //5
            else if (map[nRow][nCol] == 5) {

                dir += 2;
                dir %= 4;
            }
        }

        cRow = nRow;
        cCol = nCol;

    }
}

void solve() {
    ans = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (map[i][j] != 0)
                continue;
            for (int d = 0; d < 4; ++d) {
                simulate(i, j, d);
            }
        }
    }
}

//가장자리 패딩하는 깔끔 소
void makeWall(){
    for (int i = 0; i < MAX+2; ++i) {
        map[i][0] = map[i][N+1] = map[0][i] = map[N+1][i] = 5;
    }
}

int main() {

    cin >> TC;
    for (int T = 1; T <= TC; ++T) {
        cin >> N;
        memset(map, 0, sizeof(map));
        makeWall();
        vecClear();
//        for (int i = 0; i <= N+1; ++i) {
//            for (int j = 0; j <= N+1; ++j) {
//                cout<<map[i][j]<<" ";
//            }
//            cout<<"\n";
//        }
//        cout<<"\n";
        read();
        solve();
        cout << "#" << T << " " << ans << "\n";

    }


    return 0;
}


