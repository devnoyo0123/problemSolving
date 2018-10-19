#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct {
    int row;
    int col;
    int length;
    int dir;
} snake;

int dLocation[][2] = {{-1, 0},
                      {0,  1},
                      {1,  0},
                      {0,  -1}}; //북 동 남 서

const int MAX = 102; // 상하좌우 -1로 패딩

int N, K, L, ans;
int map[MAX][MAX];

queue<pair<int, int> > q;

void solve() {
    int t = 0;
    snake.row = 1;
    snake.col = 1;
    snake.length = 1;
    snake.dir = 1;

    map[snake.row][snake.col] = t;
//    cout<<"row:"<<snake.row<<" "<<"col:"<<snake.col<<"\n";
    while (true) {
        //다음칸 보기

        if (q.front().first == t) {
            pair<int, int> tmp = q.front();
            q.pop();

            snake.dir = (snake.dir + tmp.second) % 4;

        }

        int nRow = snake.row + dLocation[snake.dir][0];
        int nCol = snake.col + dLocation[snake.dir][1];

        if (map[nRow][nCol] == -1) {
            t++;
            break;
        } else {
            if (map[nRow][nCol] > 0) {
                if (t - map[nRow][nCol] < snake.length) {
                    // 뱀의 길이보다 현재시간 - 이전방문한 시각이 작다는 얘기는
                    // 뱀이 꼬였다는 얘기다. 이 문제에선 자기자신을 만나면 종료해야함.
                    t++;
                    break;
                }
            } else if (map[nRow][nCol] == -2) {
                //사과를 만났으면 몸길이 증가
                snake.length += 1;
            }
        }


        t++; //시간 증가
        snake.row = nRow;
        snake.col = nCol;
        map[snake.row][snake.col] = t;
//        cout<<"row:"<<snake.row<<" "<<"col:"<<snake.col<<"\n";

    }
    ans = t;
}

void makeWall() {
    for (int i = 0; i < N; ++i) {
        map[0][i] = -1;
        map[N+1][i] = -1;
        map[i][0] = -1;
        map[i][N+1] = -1;
    }
}

int main() {

    cin >> N >> K;
    makeWall();
    for (int i = 0; i < K; ++i) {
        int a, b;
        cin >> a >> b;
        map[a][b] = -2; // 사과는 -2로 표시
    }
    cin >> L;
    for (int j = 0; j < L; ++j) {
        int a;
        string b;
        int c;
        cin >> a >> b;
        if (b == "D") {
            // 90도 회전
            c = 1;
        } else if (b == "L") {
            // -90도 회전
            c = 3;
        }

        q.push({a, c});
    }

    solve();
    cout << ans << "\n";

    return 0;
}