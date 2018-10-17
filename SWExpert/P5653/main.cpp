#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int COLMAX = 50 * 3;
const int ROWMAX = 50 * 3;
const int MAX = 50;

int map[ROWMAX][COLMAX][5];
// [][][0]:비활성 남은시간, [][][1]:활성상태 남은시간, [][][2]: 0: 죽은상태, 1:활성, 2: 비활성, 3:번식, [][][3]: 배열값, [][][4]: 점유

struct Cell {
    int row, col, status, active, nonactive;
};

int TC, N, M, K, ans;
int dLocation[][2] = {{-1, 0},
                      {0,  1},
                      {1,  0},
                      {0,  -1}}; // 북 동 남 서
queue<Cell> queue1;

void calc() {
    int cnt = 0;
    for (int i = 0; i < ROWMAX; ++i) {
        for (int j = 0; j < COLMAX; ++j) {
            if (map[i][j][2] == 1 || map[i][j][2] == 2) {
                // 비활성 또는 활성상태면
                cnt++;
            }
        }
    }
    ans = cnt;
}

void solve() {
    int count = 0;
    while (true) {


        for (int i = 0; i < ROWMAX; ++i) {
            for (int j = 0; j < COLMAX; ++j) {

                if (map[i][j][2] == 1) {
                    // 활성상태임

                    // 번식
                    for (int k = 0; k < 4; ++k) {
                        int nRow = i + dLocation[k][0];
                        int nCol = j + dLocation[k][1];

                        if (nRow >= 0 && nRow < ROWMAX && nCol >= 0 && nCol < COLMAX) { // 범위체크

                            // 번식하자
                            if (map[nRow][nCol][4] == 0) {
                                //번식가능

                                map[nRow][nCol][4] = 1; // 점유
                                map[nRow][nCol][3] = map[i][j][3]; // 비활성 상태, 활성상태 남은시간 세팅을 큐가 따로 관리하는거로 바꿈
                                map[nRow][nCol][2] = 2; //번식상태로 세팅
                                Cell cell;
                                cell.row = nRow;
                                cell.col = nCol;
                                cell.status = 2;
                                cell.active = map[i][j][3];
                                cell.nonactive = map[i][j][3];
                                queue1.push(cell);
                            } else if (map[nRow][nCol][2] == 2 && map[i][j][3] > map[nRow][nCol][3]) {
                                //번식상태인데 더 큰 애가 번식하려고하면 덮어씌우기
                                map[nRow][nCol][4] = 1; // 점유
                                map[nRow][nCol][3] = map[i][j][3];
                                map[nRow][nCol][2] = 2; //번식상태로 세팅
                                Cell cell;
                                cell.row = nRow;
                                cell.col = nCol;
                                cell.status = 2;
                                cell.active = map[i][j][3];
                                cell.nonactive = map[i][j][3];
                                queue1.push(cell);
                            }
                        }
                    }

                }else{
                    continue;
                }


            }
        }


        // 줄기세포 비활성 활성 갱신
        vector<Cell> tmpVector;
        while (!queue1.empty()) {

            Cell tmp = queue1.front();
            queue1.pop();

            if (tmp.status == 3) { //번식이면 비활성으로
                tmp.status = 2;
                tmpVector.push_back(tmp);
                map[tmp.row][tmp.col][2] = 2;

            } else if (tmp.status == 2) {
                tmp.nonactive--;
                if (tmp.nonactive == 0) {
                    tmp.status = 1;
                    map[tmp.row][tmp.col][2] = 1;
                    tmpVector.push_back(tmp);

                } else {
                    tmpVector.push_back(tmp);

                }

            } else if (tmp.status == 1) {
                tmp.active--;
                if (tmp.active != 0) {
                    tmpVector.push_back(tmp);
                }else{
                    //죽은상태는 push하지않는다.
                    map[tmp.row][tmp.col][2] = 0;
                }
            }
        }

        int size = (int)tmpVector.size();
        for (int l = 0; l < size; ++l) {
            queue1.push(tmpVector[l]);
        }

        if (count == K) {
            calc();
            break;
        }
//        cout << count << "단계\n";
//        for (int i = 0; i < ROWMAX; ++i) {
//            for (int j = 0; j < COLMAX; ++j) {
//                if (map[i][j][3] == 0) {
//                    cout << " ";
//                } else {
//                    cout << map[i][j][2];
//                }
//            }
//            cout << "\n";
//        }
//        cout << "\n";
        count++;
    }


}

int main() {

    cin >> TC;

    for (int T = 1; T <= TC; ++T) {

        memset(map, 0, sizeof(map));
        ans = 0;


        cin >> N >> M >> K;


        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                int temp;

                cin >> temp;
                if (temp > 0) {
                    Cell cell;
                    cell.row = i+MAX;
                    cell.col = j+MAX;
                    cell.status = 2;
                    cell.active = temp;
                    cell.nonactive = temp;
                    queue1.push(cell);
                }


                map[i + MAX][j + MAX][3] = temp;
                map[i + MAX][j + MAX][4] = 1; // 점유
                map[i + MAX][j + MAX][0] = map[i + MAX][j + MAX][1] = map[i + MAX][j + MAX][3]; // 비활성, 활성 남은시간 세팅
                map[i + MAX][j + MAX][2] = 2; // 번식 상태 세팅
            }
        }


        solve();
        cout << "#" << T << " " << ans << "\n";
    }

    return 0;
}