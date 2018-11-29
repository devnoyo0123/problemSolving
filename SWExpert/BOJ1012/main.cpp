#include <cstdio>
#include <cstring>

const int MAX = 50;

int tc, m1, n1, k1;
int map[MAX][MAX];
bool check[MAX][MAX];
int ans = 0;

int dRow[]= {-1,0,1,0};
int dCol[]= {0,1,0,-1};

void DFS(int row, int col){
    check[row][col] = true;
    for (int i = 0; i < 4; ++i) {
        int nRow = row + dRow[i];
        int nCol = col + dCol[i];

        if( nRow < 0 || nRow >= n1 || nCol < 0 || nCol >= m1){
            continue;
        }

        if(check[nRow][nCol]){
            continue;
        }

        if(map[nRow][nCol] == 1){
            DFS(nRow, nCol);

        }

    }
}
int main() {

    scanf("%d", &tc);
    for (int i = 0; i < tc; ++i) {
        scanf("%d %d %d", &m1, &n1, &k1);
        memset(map, 0, sizeof(map));
        memset(check, false, sizeof(check));
        ans = 0;
        int a,b;
        for (int j = 0; j < k1; ++j) {
            scanf("%d %d", &a, &b);
            map[b][a] = 1;
        }


        for (int k = 0; k < n1; ++k) {
            for (int j = 0; j < m1 ; ++j) {
                if( map[k][j] == 1 && !check[k][j]){
                    ans+=1;
                    DFS(k,j);
                }
            }
        }


        printf("%d\n", ans);
    }

    return 0;
}