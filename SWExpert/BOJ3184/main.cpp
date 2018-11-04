#include <iostream>
#include <queue>

using namespace std;

const int MAX = 251;

int dRow[] = {-1, 0, 1, 0};
int dCol[] = {0, 1, 0, -1};

int R,C;
int oNum, vNum, oCnt, vCnt;

char a[MAX][MAX];
bool visited[MAX][MAX];

void BFS(int row, int col){
    queue<pair<int, int> > Q;
    visited[row][col] = true;
    Q.push({row,col});

    while(!Q.empty()){
        pair<int, int> tmp = Q.front(); Q.pop();

        if( a[tmp.first][tmp.second] == 'o'){
            oCnt++;
        }else if( a[tmp.first][tmp.second] == 'v'){
            vCnt++;
        }

        for (int i = 0; i < 4; ++i) {
            int nRow = tmp.first + dRow[i];
            int nCol = tmp.second + dCol[i];

            if( nRow < 0 || nRow >= R || nCol < 0 || nCol >= C){
                continue;
            }


            if( visited[nRow][nCol]){
                continue;
            }

            if( a[nRow][nCol] == '#'){
                continue;
            }

            visited[nRow][nCol] = true;
            Q.push({nRow, nCol});
        }
    }
}

int main() {

    cin >> R >> C;

    for (int i = 0; i < R; ++i) {
        cin >> a[i];
        for (int j = 0; j < C; ++j) {
            if( a[i][j] == 'o'){
                oNum++;
            }else if( a[i][j] == 'v'){
                vNum++;
            }
        }
    }

    for (int k = 0; k < R; ++k) {
        for (int i = 0; i < C; ++i) {
            vCnt = 0;
            oCnt = 0;
            if( a[k][i] == 'o' || a[k][i] == 'v' ){ // 이거 안하면 시간초과.. O(V+E)*O(N^2)
                if( !visited[k][i]){

                    BFS(k,i);
                    if( vCnt >= oCnt){
                        oNum -= oCnt;
                    }else{
                        vNum -= vCnt;
                    }

                }
            }
        }
    }

    cout<<oNum<<" "<<vNum<<'\n';


    return 0;
}