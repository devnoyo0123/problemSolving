#include <cstdio>
#include <cstring>

const int MAX = 10000000;

int tc, ans;

int dRow[] = {-1,0,1,0};
int dCol[] = {0,1,0,-1};

int digit[8];
bool nums[MAX];
int map[4][4];
bool check[4][4];

int calc(int inx){

    int op = 1;
    int res = 0;
    for (int i = inx-1; i >= 0 ; --i) {
        res += op * digit[i];
        op *= 10;
    }
    return res;
}

void DFS(int row, int col, int inx){


    if( inx == 7){
        int res = calc(inx);
        if(!nums[res]){
            nums[res] = true;
            ans++;
        }

        return;
    }


    digit[inx] = map[row][col];

    for (int i = 0; i < 4; ++i) {

        int nRow = row + dRow[i];
        int nCol = col + dCol[i];

        if( nRow < 0 || nRow >=4 || nCol <0 || nCol >=4){
            continue;
        }


        DFS(nRow, nCol, inx+1);
    }


}

int main() {
    scanf("%d", &tc);
    for(int t=1; t<=tc; t++){

        memset(map, 0, sizeof(map));
        memset(nums,false, sizeof(nums));
        ans = 0;

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                scanf("%d", &map[i][j]);
            }
        }

        for (int k = 0; k < 4; ++k) {
            for (int i = 0; i < 4; ++i) {

                memset(digit,0, sizeof(digit));
                DFS(k,i,0);
            }
        }

        printf("#%d %d\n", t, ans);
    }

}