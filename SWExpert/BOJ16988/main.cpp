#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 20;

int N, M;

int a[MAX][MAX];
bool check[MAX][MAX];

int dx[]= {-1,0,1,0};
int dy[]= {0,1,0,-1};


int bfs(){
    memset(check,false,sizeof(check));
    int res = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (a[i][j] == 2 && !check[i][j]) {
                bool dead = true;
                queue<pair<int,int>> q;
                q.push(make_pair(i,j));
                check[i][j] = true;
                int cur = 0;
                while (!q.empty()) {
                    cur += 1;
                    int x, y;
                    pair<int, int>temp = q.front(); q.pop();
                    x= temp.first, y= temp.second;
                    for (int k=0; k<4; k++) {
                        int nx = x+dx[k];
                        int ny = y+dy[k];
                        if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                            if (a[nx][ny] == 0) {
                                dead = false;
                            } else if (a[nx][ny] == 2 && !check[nx][ny]) {
                                q.push(make_pair(nx,ny));
                                check[nx][ny] = true;
                            }
                        }
                    }
                }
                if (dead) {
                    res += cur;
                }
            }
        }
    }
    return res;
}


int go(int row, int col, int cnt){
    if( row == N){
        int cur = bfs();
        return cur;
    }

    if( cnt == 0){
        int cur = bfs();
        return cur;
    }

    int ans = 0;

    for(int i=row; i<N; i++){
        for(int j=col; j< M; j++){
            if( a[i][j] == 0){
                int cur;
                if( j + 1 == M){
                    a[i][j] = 1;
                    cur = go(i+1, 0,cnt-1);
                    a[i][j] = 0;
                }else{
                    a[i][j] = 1;
                    cur = go(i, j+1, cnt-1);
                    a[i][j] = 0;
                }

                if( ans < cur){
                    ans = cur;
                }
            }else{
                int cur;
                if( col + 1 == M){
                    cur = go(i+1,0,cnt);
                }else{
                    cur = go(i, j+1, cnt);
                }

                if( ans < cur){
                    ans = cur;
                }
            }
        }
    }



    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin >> N >> M;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> a[i][j];
        }
    }

    cout<<go(0,0,2)<<'\n';

    return 0;
}