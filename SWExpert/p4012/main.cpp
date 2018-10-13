#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

const int MAX = 16;

int TC, N, ans;
int food[MAX];
int map[MAX][MAX];

int calc(){
    int sumA = 0;
    int sumB = 0;
    for (int i = 0; i < N; ++i) {
        if( food[i] == 1){
            for (int j = 0; j < N; ++j) {
                if( i == j ){
                    continue;
                }

                if( food[j] == 1){
                    sumA += map[i][j];
                }
            }
        }else if ( food[i] ==2){
            for (int j = 0; j < N; ++j) {
                if( i == j){
                    continue;
                }
                if( food[j] == 2){
                    sumB += map[i][j];
                }
            }
        }
    }

    return abs(sumA - sumB);
}

void solve(int inx, int aCnt, int bCnt){

    if( aCnt > N/2 || bCnt > N/2){
        return;
    }

    if( inx == N){
        int tmp = calc();
        if(ans > tmp){
            ans = tmp;
        }
        return;
    }

    food[inx] = 1;
    solve(inx+1, aCnt+1, bCnt);
    food[inx] = 2;
    solve(inx+1, aCnt, bCnt+1);
}

int main() {

    scanf("%d", &TC);
    for (int T = 1; T <= TC ; ++T) {
        scanf("%d", &N);
        ans = 987654321;
        memset(map,0, sizeof(map));
        memset(food,0, sizeof(food));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                scanf("%d", &map[i][j]);
            }
        }

        solve(0,0,0);
        printf("#%d %d\n", T, ans);

    }
    return 0;
}