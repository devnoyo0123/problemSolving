#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 100;

int tc, n1, ans;

int dRow[] = {-1,0,1,0};
int dCol[] = {0,1,0,-1};

int map[MAX][MAX];
int dist[MAX][MAX];
bool check[MAX][MAX];


void init(){
    memset(map,0, sizeof(map));
    memset(dist,0, sizeof(dist));
}

void BFS(int row, int col){
    queue<pair<int, int> > qu;
    dist[row][col] = map[row][col];
    check[row][col] = true;
    qu.push({row,col});

    while(!qu.empty()){
        pair<int, int> tmp = qu.front(); qu.pop();

        for (int i = 0; i < 4; ++i) {
            int nRow = tmp.first + dRow[i];
            int nCol = tmp.second + dCol[i];

            if( nRow < 0 || nRow >= n1 || nCol < 0 || nCol >= n1){
                continue;
            }


            if(!check[nRow][nCol]|| (dist[nRow][nCol] > dist[tmp.first][tmp.second] + map[tmp.first][tmp.second])){
                dist[nRow][nCol] = dist[tmp.first][tmp.second] + map[tmp.first][tmp.second];
                check[nRow][nCol]=  true;
                qu.push({nRow, nCol});
            }
        }
    }
}

void solve(){
    BFS(0,0);

    ans = dist[n1-1][n1-1];
}

int main() {

    scanf("%d", &tc);
    for (int t = 1; t <= tc ; ++t) {

        init();

        scanf("%d", &n1);

        for (int i = 0; i < n1; ++i) {
            char buf[MAX] = {0,};
            scanf("%s", buf);
            for (int j = 0; j < n1; ++j) {
                map[i][j] = buf[j] - '0';
            }
        }

        solve();

        printf("#%d %d\n", t, ans);

    }

    return 0;
}