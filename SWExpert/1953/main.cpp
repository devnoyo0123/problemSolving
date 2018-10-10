#include <iostream>
#include <cstring>
#include <queue>

using namespace std;


const int MAX = 55;

enum WAY1 {
    UP = 0,
    RIGHT,
    DOWN,
    LEFT
};

int TC, N, M, R, C, L;
int map[MAX][MAX];
int dist[MAX][MAX];
int dRow[] = {-1,0,1,0};
int dCol[] = {0,1,0,-1};
bool isConnected[4][8] = {{false, true, true,  false, false, true,  true,  false},
                          {false, true, false, true,  false, false, true,  true},
                          {false, true, true,  false, true,  false, false, true},
                          {false, true, false, true,  true,  true,  false, false},
};

bool isValid(int row, int col) {
    return row >= 0 && row < N && col >= 0 && col < M;
}


void BFS(int row, int col) {
    queue<pair<int, int> > q;
    q.push(make_pair(row, col));
    dist[row][col] = 1;

    while (!q.empty()) {
        pair<int, int> tmp = q.front();
        q.pop();
        int curRow = tmp.first;
        int curCol = tmp.second;
//        cout << "row:" << curRow << " col:" << curCol << ", val:" << map[curRow][curCol] << "방문\n";


        if (map[curRow][curCol] == 1) {
            // 상 우 하 좌
            for (int i = 0; i < 4; ++i) {
                int nRow = curRow + dRow[i];
                int nCol = curCol + dCol[i];
                if (isValid(nRow, nCol)) {

                    if (map[nRow][nCol] > 0 && dist[nRow][nCol] == 0 && isConnected[i][map[nRow][nCol]]) {
//                        cout << "nRow:" << curRow << " nCol:" << curCol << ", val:" << map[nRow][nCol] << "방문\n";
                        dist[nRow][nCol] = dist[curRow][curCol] + 1;
                        q.push(make_pair(nRow, nCol));
                    }
                }
            }
        } else if (map[curRow][curCol] == 2) {
            // 상 하
            for (int i = 0; i < 4; ++i) {
                if (i == RIGHT || i == LEFT) {
                    continue;
                }
                int nRow = curRow + dRow[i];
                int nCol = curCol + dCol[i];
                int nVal = map[nRow][nCol];
                if (isValid(nRow, nCol)) {
                    if (nVal > 0 && dist[nRow][nCol] == 0 && isConnected[i][nVal]) {
                        dist[nRow][nCol] = dist[curRow][curCol] + 1;
                        q.push(make_pair(nRow, nCol));
                    }
                }
            }
        } else if (map[curRow][curCol] == 3) {
            // 좌 우
            for (int i = 0; i < 4; ++i) {
                if (i == UP || i == DOWN) {
                    continue;
                }
                int nRow = curRow + dRow[i];
                int nCol = curCol + dCol[i];
                if (isValid(nRow, nCol)) {
                    if (map[nRow][nCol] > 0 && dist[nRow][nCol] == 0 && isConnected[i][map[nRow][nCol]]) {
                        dist[nRow][nCol] = dist[curRow][curCol] + 1;
                        q.push(make_pair(nRow, nCol));
                    }
                }
            }
        } else if (map[curRow][curCol] == 4) {
            // 상 우
            for (int i = 0; i < 4; ++i) {
                if (i == DOWN || i == LEFT) {
                    continue;
                }
                int nRow = curRow + dRow[i];
                int nCol = curCol + dCol[i];
                if (isValid(nRow, nCol)) {
                    if (map[nRow][nCol] > 0 && dist[nRow][nCol] == 0 && isConnected[i][map[nRow][nCol]]) {
                        dist[nRow][nCol] = dist[curRow][curCol] + 1;
                        q.push(make_pair(nRow, nCol));
                    }
                }
            }
        } else if (map[curRow][curCol] == 5) {
            // 우 하
            for (int i = 0; i < 4; ++i) {
                if (i == UP || i == LEFT) {
                    continue;
                }
                int nRow = curRow + dRow[i];
                int nCol = curCol + dCol[i];
                if (isValid(nRow, nCol)) {
                    if (map[nRow][nCol] > 0 && dist[nRow][nCol] == 0 && isConnected[i][map[nRow][nCol]]) {
                        dist[nRow][nCol] = dist[curRow][curCol] + 1;
                        q.push(make_pair(nRow, nCol));
                    }
                }
            }
        } else if (map[curRow][curCol] == 6) {
            // 좌 하
            for (int i = 0; i < 4; ++i) {
                if (i == UP || i == RIGHT) {
                    continue;
                }
                int nRow = curRow + dRow[i];
                int nCol = curCol + dCol[i];
                if (isValid(nRow, nCol)) {
                    if (map[nRow][nCol] > 0 && dist[nRow][nCol] == 0 && isConnected[i][map[nRow][nCol]]) {
                        dist[nRow][nCol] = dist[curRow][curCol] + 1;
                        q.push(make_pair(nRow, nCol));
                    }
                }
            }
        } else if (map[curRow][curCol] == 7) {
            // 상 좌
            for (int i = 0; i < 4; ++i) {
                if (i == DOWN || i == RIGHT) {
                    continue;
                }
                int nRow = curRow + dRow[i];
                int nCol = curCol + dCol[i];
                if (isValid(nRow, nCol)) {
                    if (map[nRow][nCol] > 0 && dist[nRow][nCol] == 0 && isConnected[i][map[nRow][nCol]]) {
                        dist[nRow][nCol] = dist[curRow][curCol] + 1;
                        q.push(make_pair(nRow, nCol));
                    }
                }
            }
        }
    }
}

int main() {

    cin >> TC;

    for (int T = 1; T <= TC; T++) {
        cin >> N >> M >> R >> C >> L;
        memset(map, 0, sizeof(map));
        memset(dist, 0, sizeof(dist));

        for (int k = 0; k < N; ++k) {
            for (int i = 0; i < M; ++i) {
                cin >> map[k][i];
            }
        }

        BFS(R, C);
        int cnt = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (dist[i][j] > 0 && dist[i][j] <= L) {
                    cnt++;
                }
            }
        }

        cout << "#" << T << " " << cnt << "\n";
    }


    return 0;
}