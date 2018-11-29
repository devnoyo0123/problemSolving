#include <cstdio>
#include <queue>
#include <cstring>


using namespace std;

const int MAX = 1500;

struct Swan{
    int row,col;
};


Swan swan[2];

int R, C, ans;
int dLocation[][2] = {{-1,0},{0,1},{1,0},{0,-1}};

char map[MAX][MAX];
bool check[MAX][MAX];
bool flag;

void BFS1(int row, int col){
    // 빙하 녹이는 BFS
    queue<pair<int, int> > qu1;
    check[row][col] = true;
    qu1.push({row, col});

    while(!qu1.empty()){
        pair<int, int> tmp = qu1.front(); qu1.pop();

        for (int i = 0; i < 4; ++i) {
            int nRow = tmp.first + dLocation[i][0];
            int nCol = tmp.second + dLocation[i][1];

            if( nRow < 0 || nRow >= R || nCol <0 || nCol >= C){
                continue;
            }

            if( check[nRow][nCol]){
                continue;
            }

            if( map[nRow][nCol] == 'X'){
                check[nRow][nCol] = true;
                qu1.push({nRow, nCol});
            }else if( map[nRow][nCol] == '.'){
                map[tmp.first][tmp.second] = '.';
            }
        }
    }
}

void BFS2(int row, int col){
    // 백조 찾는 BFS
    queue<pair<int, int> > qu1;
    check[row][col] = true;
    qu1.push({row, col});

    while(!qu1.empty()){
        pair<int, int> tmp = qu1.front(); qu1.pop();

        for (int i = 0; i < 4; ++i) {
            int nRow = tmp.first + dLocation[i][0];
            int nCol = tmp.second + dLocation[i][1];

            if( nRow < 0 || nRow >= R || nCol <0 || nCol >= C){
                continue;
            }

            if( check[nRow][nCol]){
                continue;
            }

            if( map[nRow][nCol] == '.'){
                check[nRow][nCol] = true;
                qu1.push({nRow, nCol});
            }else if( map[nRow][nCol] == 'L'){
                flag = true;
                return;
            }

        }
    }
}

void solve(){
    int cnt = 0;

    while(!flag){
        memset(check, false, sizeof(check));



        //얼음 녹이기
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if(map[i][j] == 'X' && !check[i][j]){
                    BFS1(i,j);

                }
            }
        }

        memset(check, false, sizeof(check));

        //백조 만나는지 시뮬
        BFS2(swan[0].row, swan[0].col);
        cnt++;
    }
    ans = cnt;
}

int main() {

    scanf("%d %d", &R, &C);

    int cnt = 0;
    for (int i = 0; i < R; ++i) {
        scanf("%s", map[i]);
        for (int j = 0; j < C; ++j) {
            if( map[i][j] == 'L'){
                swan[cnt].row = i;
                swan[cnt].col = j;
            }
        }
    }

    solve();

    printf("%d\n", ans);
    return 0;
}