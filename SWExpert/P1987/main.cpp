#include <cstdio>

const int MAX = 22;
const int ALPHAMAX = 26;

int R,C,ans;
bool check[ALPHAMAX];
int map[MAX][MAX];
int dLocation[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

void go(int row, int col, int cnt){
    if( ans < cnt){
        ans = cnt;
    }

    int curRow = row;
    int curCol = col;
    for (int i = 0; i < 4; ++i) {
        int nRow = curRow + dLocation[i][0];
        int nCol = curCol + dLocation[i][1];

        if( nRow >=1 && nRow <= R && nCol >=1 && nCol <= C){
            if(!check[map[nRow][nCol]-'A']){
                check[map[nRow][nCol]-'A']= true;
                go(nRow,nCol,cnt+1);
                check[map[nRow][nCol]-'A']= false;
            }
        }
    }
}

int main() {

    scanf("%d %d", &R, &C);

    for (int i = 1; i <= R; ++i) {
        char ch[MAX];
        scanf("%s", ch);
        for (int j = 0; j < C; ++j) {
            map[i][j+1] = ch[j];
        }
    }



    check[map[1][1]-'A']= true;
    go(1,1,1);
    printf("%d\n", ans);

    return 0;
}