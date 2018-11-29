#include <iostream>
#include <queue>
using namespace std;
int n, m;
int a[50][50]; // 칸과 칸사이 벽을 나타
int d[50][50]; // 방에 번호를 매길거임.
int room[50*50]; // i번에 몇개의 방이 있나?
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};
int bfs(int x, int y, int rooms) { // room은 다음번
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    d[x][y] = rooms; // 방 번호 입력
    int cnt = 0;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        cnt += 1; // 방문했으면 방의 개수가 늘어났으니 하나 추가
        for (int k=0; k<4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (d[nx][ny] != 0) continue;
            if (a[x][y] & (1<<k)) continue; // 문제보면 방과 방의 정보가 1 2 4 8 로 이뤄지기 때문에
            // 11 & 8 == 8 -> true;

            // 11 & 4 == 0 -> false
            q.push(make_pair(nx,ny));
            d[nx][ny] = rooms;
        }
    }
    return cnt;
}
int main() {
    cin >> m >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }
    int rooms = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (d[i][j] == 0) {
                rooms += 1;
                room[rooms] = bfs(i, j, rooms);
            }
        }
    }
    cout << rooms << '\n';
    int ans = 0;
    for (int i=1; i<=rooms; i++) {
        if (ans < room[i]) {
            ans = room[i];
        }
    }
    cout << ans << '\n';
    ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int x = i;
            int y = j;
            for (int k=0; k<4; k++) {
                int nx = x+dx[k];
                int ny = y+dy[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (d[nx][ny] == d[x][y]) continue;
                if (a[x][y] & (1<<k)) {
                    if (ans < room[d[x][y]]+room[d[nx][ny]]) {
                        ans = room[d[x][y]]+room[d[nx][ny]];
                    }
                }
            }
        }
    }
    cout << ans << '\n';

    return 0;
}