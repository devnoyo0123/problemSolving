#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

const int MAX = 1001;

int N, M, K;
int ans = 0;

int dRow[] = {-1,0,1,0};
int dCol[] = {0,1,0,-1};
char map[MAX][MAX];
int dist[MAX][MAX][11];


void solve(){
    queue<tuple<int, int, int> > qu;
    dist[0][0][0] = 1;
    qu.push(make_tuple(0,0,0));

    while(!qu.empty()){
        int curRow, curCol, cnt;
        tie(curRow, curCol, cnt) =  qu.front(); qu.pop();
        for (int i = 0; i < 4; ++i) {

            int nRow = curRow + dRow[i];
            int nCol = curCol + dCol[i];


            if( nRow < 0 || nRow >= N || nCol < 0 || nCol >= M){
                continue;
            }


            if( map[nRow][nCol] == '1' && cnt < K && dist[nRow][nCol][cnt+1] == 0){
                dist[nRow][nCol][cnt+1] = dist[curRow][curCol][cnt] + 1;
                qu.push(make_tuple(nRow, nCol, cnt+1));
            }

            if( map[nRow][nCol] == '0' && dist[nRow][nCol][cnt] == 0){
                dist[nRow][nCol][cnt] = dist[curRow][curCol][cnt] + 1;
                qu.push(make_tuple(nRow, nCol, cnt));
            }

        }
    }

    ans = -1;
    for (int j = 0; j <= K; ++j) {



        if (dist[N-1][M-1][j] == 0){
            continue;
        }

        if( ans == -1){
            ans = dist[N-1][M-1][j];
        }



        if( ans > dist[N-1][M-1][j]){
            ans = dist[N-1][M-1][j];
        }

    }
}

int main() {

    cin >> N >> M >> K;

    for (int i = 0; i < N; ++i) {
        cin >> map[i];
    }


    solve();
    cout<<ans<<'\n';

    return 0;
}