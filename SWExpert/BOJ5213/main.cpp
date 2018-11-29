#include <iostream>
#include <queue>
#include <stack>

using namespace std;

const int MAX = 500;

int n;

int dRow1[] = {-1, -1, 0, 1, 1, 0}; // 행이 짝수일때
int dCol1[] = {-1, 0, 1, 0, -1, -1};

int dRow2[] = {-1, -1, 0, 1, 1, 0};
int dCol2[] = {0, 1, 1, 1, 0, -1}; // 행이 홀수 일때

int num[MAX][MAX];
int dist[MAX][MAX];
int map[MAX][MAX][2]; // 이렇게 자료구조를 할 생각 왜 몼했을까..
int from[MAX][MAX][2];


bool moveable(int curRow, int curCol, int nRow, int nCol){
    if( curRow == nRow){
        if( curCol < nCol){
            return map[curRow][curCol][1] == map[nRow][nCol][0];
        }else{
            return map[curRow][curCol][0] == map[nRow][nCol][1];
        }
    }else{

        if( curRow < nRow){
            if( curCol < nCol){
                return map[curRow][curCol][0] == map[nRow][nCol][1];
            }else{
                return map[curRow][curCol][1] == map[nRow][nCol][0];
            }
        }else{
            if( curCol < nCol){
                return map[curRow][curCol][0] == map[nRow][nCol][1];
            }else{
                return map[curRow][curCol][1] == map[nRow][nCol][0];
            }
        }

    }
}

bool lineCheck(int row, int col) {
    if (row % 2 == 0) {
        return row >= 0 && row < n && col >= 0 && col < n;
    } else {
        return row >= 0 && row < n && col >= 0 && col < n - 1;
    }
}

void solve(int row, int col) {
    queue<pair<int, int> > Q;

    from[row][col][0] = -1;
    from[row][col][1] = -1;

    dist[row][col] = 1;
    Q.push({row, col});

    while (!Q.empty()) {
        pair<int, int> tmp = Q.front();
        Q.pop();
        int nRow, nCol;

        for (int i = 0; i < 6; ++i) {

            if (tmp.first % 2 == 0) {
                // 행이 짝수임
                nRow = tmp.first + dRow1[i];
                nCol = tmp.second + dCol1[i];

                if (lineCheck(nRow, nCol)) {
                    if (moveable(tmp.first, tmp.second, nRow, nCol) && dist[nRow][nCol] != 0) {
                        dist[nRow][nCol] = dist[tmp.first][tmp.second] + 1;
                        Q.push({nRow, nCol});
                        from[nRow][nCol][0] = tmp.first;
                        from[nRow][nCol][1] = tmp.second;
                    }
                }
            } else {
                nRow = tmp.first + dRow2[i];
                nCol = tmp.second + dCol2[i];

                if (lineCheck(nRow, nCol)) {
                    if (moveable(tmp.first, tmp.second, nRow, nCol) && dist[nRow][nCol] != 0) {
                        dist[nRow][nCol] = dist[tmp.first][tmp.second] + 1;
                        Q.push({nRow, nCol});
                        from[nRow][nCol][0] = tmp.first;
                        from[nRow][nCol][1] = tmp.second;
                    }
                }
            }
        }


    }
}

int main() {


    cin >> n;

    int cnt = 1;
    int a, b;
    for (int k = 0; k < n; ++k) {

        for (int i = 0; i < n - 1; ++i) {
            num[k][i] = cnt;
            cnt += 1;

            cin >> a >> b;
            map[k][i][0] = a;
            map[k][i][1] = b;
        }
        if (k % 2 == 0) {
            num[k][n - 1] = cnt;
            cnt += 1;
            cin >> a >> b;
            map[k][n - 1][0] = a;
            map[k][n - 1][1] = b;
        }


    }

    solve(0, 0);
    cout<<dist[n-1][n-1]<<"\n";
    stack<pair<int, int> > st;

    return 0;
}