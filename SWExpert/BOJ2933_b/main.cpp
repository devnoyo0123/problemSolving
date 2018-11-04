#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm> // min, max

using namespace std;
char a[111][111];
int c[111][111];
int n, m;
vector<pair<int,int>> group;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
void dfs(int x, int y) {
    if (a[x][y] == '.') return;
    if (c[x][y]) return;
    c[x][y] = true;
    group.push_back(make_pair(x,y));
    for (int k=0; k<4; k++) {
        int nx = x+dx[k];
        int ny = y+dy[k];
        if (0 <= nx && nx < n && 0 <= ny && ny < m) {
            dfs(nx,ny);
        }
    }
}
void simulate() {
    memset(c, false, sizeof(c));
    for (int x=0; x<n; x++) {
        for (int y=0; y<m; y++) {
            if (a[x][y] == '.') continue;
            if (c[x][y]) continue;
            group.clear();
            dfs(x,y);
            vector<int> low(m, -1);
            for (auto &p : group) {
                // 이 코드는 덩어리중에 제일 아래있는 칸을 찾는것인데,
                // 아래에 있다는 얘기는 행의 인덱스가 크다는 얘기다.
                // 각 열마다 가장 큰 행의 인덱스를 구해놓는다.
                // 그리고 이동할거니까 미리 다 빈칸으로 만들어놓는다.
                low[p.second] = max(low[p.second], p.first);
                a[p.first][p.second] = '.';
            }
            int lowest = n;
            // 가장 낮은 칸은 행의 크기지.
            for (int i, j=0; j<m; j++) {
                if (low[j] == -1) continue;
                // -1이라는것은 갱신되지 않았다는 얘기고, 그말은 미네랄이 없으면 low의 값이 갱신이 안되니까
                // 미네랄이 없다는 얘기임.

                for (i=low[j]; i<n && a[i][j]=='.'; i++);
                lowest = min(lowest, i-low[j]-1);
            }

            for (auto &p : group) {
                p.first += lowest;
                a[p.first][p.second] = 'x';
                c[p.first][p.second] = true; // 이게 필요한가? 필요해 31번 코드보면 2중 for문 돌면서
                // 내릴지 안내릴지 체크하는 부분있어.
            }
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    int k;
    cin >> k;
    for (int i=0; i<k; i++) {
        int height;
        cin >> height;
        height = n - height;
        if (i%2 == 0) {
            for (int j=0; j<m; j++) {
                if (a[height][j] == 'x') {
                    a[height][j] = '.';
                    break;
                }
            }
        } else {
            for (int j=m-1; j>=0; j--) {
                if (a[height][j] == 'x') {
                    a[height][j] = '.';
                    break;
                }
            }
        }
        simulate();
    }
    for (int i=0; i<n; i++) {
        cout << a[i] << '\n';
    }
    return 0;
}