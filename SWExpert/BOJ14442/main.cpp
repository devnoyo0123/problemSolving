// 틀린 코드

#include <iostream>
#include <queue>

using namespace std;

const int MAX = 1000;


struct Status{
    int row, col, wall;
    Status(int r, int c, int w) : row(r), col(c), wall(w) {}
};

int dRow[] = {-1, 0, 1, 0};
int dCol[] = {0, 1, 0, -1};

int n, m, k;

string a[MAX];
int dist[MAX][MAX];
bool check[MAX][MAX];
int ans;

void BFS(int row,int col, int wall){
    Status s1(row,col,wall);
    queue<Status> queue1;
    dist[row][col] = 1;
    check[row][col] = true;
    queue1.push(s1);

    while(!queue1.empty()){
        Status tmp = queue1.front(); queue1.pop();

        for (int i = 0; i < 4; ++i) {
            int nRow = tmp.row + dRow[i];
            int nCol = tmp.col + dCol[i];

            if( nRow < 0 || nRow == n || nCol < 0 || nCol == m){
                continue;
            }

            if( check[nRow][nCol]){
                continue;
            }

            if( a[nRow][nCol] == '0'){
                check[nRow][nCol] = true;
                Status s1(nRow,nCol,tmp.wall);
                dist[nRow][nCol] = dist[tmp.row][tmp.col] + 1;
                queue1.push(s1);
            }else{
                if( tmp.wall >0 ){
                    check[nRow][nCol] = true;
                    a[nRow][nCol] = '0';
                    Status s1(nRow,nCol,tmp.wall-1);
                    dist[nRow][nCol] = dist[tmp.row][tmp.col] + 1;
                    queue1.push(s1);
                }
            }
        }
    }

    ans = dist[n-1][m-1] != 0 ? dist[n-1][m-1] : -1;
}

int main() {

    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    BFS(0,0,k);

    cout<<ans<<'\n';

    return 0;
}