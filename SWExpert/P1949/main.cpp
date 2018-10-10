#include <iostream>
#include <cstring>

using namespace std;

const int PEAKMAX = 5;
const int MAX = 20;
int TC, N, K, max1, ans;
int map[MAX][MAX];

int dRow[] = {-1, 0, 1, 0};
int dCol[] = {0, 1, 0, -1};

pair<int, int> highestPoint[PEAKMAX];

void DFS(int row, int col, int cnt) {
    //봉우리의 위치에서부터 등산로 조성하고 등산로 길이 갱신하는 함수

    for (int i = 0; i < 4; ++i) {
        int nextRow = row + dRow[i];
        int nextCol = col + dCol[i];

        if (nextRow >= 0 && nextRow < N && nextCol >= 0 && nextCol < N) {
            if (map[nextRow][nextCol] < map[row][col]) {
//                cout<<"row: "<<nextRow<<", col: "<<nextCol<<"인 "<<map[nextRow][nextCol]<<"에 방문\n";
                DFS(nextRow, nextCol, cnt + 1);
                if (cnt + 1 > ans) {
                    ans = cnt + 1;
                }
            }
        }
    }
}

int main() {
    cin >> TC;

    int cnt = 0;


    for (int T = 1; T <= TC; ++T) {
        cin >> N >> K;

        max1 = 0;
        ans = 0;
        cnt = 0;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> map[i][j];

                if (max1 < map[i][j]) {
                    max1 = map[i][j];
                    memset(highestPoint, 0, sizeof(highestPoint));
                    cnt = 0;
                    highestPoint[cnt].first = i;
                    highestPoint[cnt].second = j;
                    cnt += 1;
                } else if (max1 == map[i][j]) {
                    highestPoint[cnt].first = i;
                    highestPoint[cnt].second = j;
                    cnt += 1;
                }
            }
        }

        for (int k = 0; k < N; ++k) {
            for (int i = 0; i < N; ++i) {
                for (int j = 1; j <= K; ++j) {

                    map[k][i] -= j;
//                        cout<<"row: "<<k<<", col:"<<i<<" 을 "<<j<<"만큼 깍아서 "<<map[k][i]<<"로 깍였음\n";
                    for (int l = 0; l < cnt; ++l) {
                        int row = highestPoint[l].first;
                        int col = highestPoint[l].second;
//                            cout<<"row: "<<row<<", col: "<<col<<"인 "<<map[row][col]<<"에 방문\n";
                        DFS(row, col, 1);
//                            cout<<"봉우리 높이:"<<map[row][col]<<"에서"<<" row: "<<row<<", col: "<<col<<", 현재 제일 긴 등산로 길이: "<<ans<<"입니다\n";
                    }
                    map[k][i] += j;

                }
            }
        }

        cout << "#" << T << " " << ans << "\n";

    }


    return 0;
}
