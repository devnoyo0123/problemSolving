#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

struct tuple1{
    tuple1(int a1, int b1, int c1){
        row= a1;
        col= b1;
        cnt= c1;
    }
    int row,col,cnt;
};

const int MAX = 51;

bool dirs[4];

int dRow[] = {-1,0,1,0};
int dCol[] = {0,1,0,-1};
int n, m, max1,max2, ans;
//max1 : 가장 넓은 방의 크기
//ans : 이 성에 있는 방의 개수
//max2 : 하나의 벽을 제거하여 얻을 수 있는 가장 넓은 방의 크기

int map[MAX][MAX];
int dist[MAX][MAX][2]; // [][][0] : 벽을 부순횟수가 0번

void BFS(int row, int col){
    queue<tuple1> queue1;
    dist[row][col][0] = 1;
    queue1.push(tuple1(row, col, 0));

    while(!queue1.empty()){
        tuple1 tmp = queue1.front(); queue1.pop();

        int dir = map[tmp.row][tmp.col];

        memset(dirs, true, sizeof(dirs));

        while(dir >0){

            if( 8 <= dir){
                //남쪽에 벽
                dir-=8;
                dirs[2] = false;
            }else if( 4 <= dir){
                //동쪽에 벽
                dir-=4;
                dirs[1] = false;
            }else if( 2 <= dir){
                // 북쪽에 벽
                dir-=2;
                dirs[0] = false;
            }else if( 1 <= dir){
                // 서쪽에 벽
                dir-=1;
                dirs[3] = false;
            }
        }

        for (int i = 0; i < 4; ++i) {
            if(dirs[i]){
                int nRow = tmp.row + dRow[i];
                int nCol = tmp.col + dCol[i];

                if( nRow < 0 || nRow >= m || nCol < 0 || nCol >= n){
                    continue;
                }

                if( tmp.cnt > 0)

            }
        }

    }
}


int main() {

    scanf("%d %d", &n, &m);
    for (int i = 1; i <=m ; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", map[i][j]);
        }
    }


    for (int k = 1; k <= m; ++k) {
        for (int i = 1; i <= n; ++i) {
            BFS(k,i);
        }
    }

    printf("%d\n%d\n%d\n", ans, max1, max2);



    return 0;
}