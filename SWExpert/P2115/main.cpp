#include <iostream>
#include <cstring>

using namespace std;

const int NMAX = 11;

int TC, N, M, C, ans, ret1, ret2;
int map[NMAX][NMAX];
bool check[NMAX][NMAX];

void getHoney(int row, int startCol, int size, int inx, int sum, int double1){
    if( inx > size ){
        return;
    }

    if( sum == C){

    }

    getHoney(row, startCol, size, inx+1, sum+[])
}

int main() {


    cin >> TC;
    for (int T = 1; T <= TC; ++T) {
        cin >> N >> M >> C;
        memset(map, 0, sizeof(map));
        memset(check, 0, sizeof(check));
        ans = 0;
        int i;
        for (i = 0; i < N; ++i) { // 시작이 가능한 로우 위치
            int j;
            for (j = 0; j <= N-M; ++j) { // 시작이 가능한 컬럼 위치
                int k;
                for (k = 0; k < M; ++k) { // j번째부터 j+M-1번째까지 뽑았음.
                    check[i][j + k] = true;   //일꾼 1
                }

                for (int l = 0; l < N; ++l) {
                    for (int m = 0; m <= N-M; ++m) {
                        for (int n = 0; n < M; ++n) {
                            //일꾼2
                            if (!check[l][m + n]) {

                                // 일꾼 1, 일꾼 2가 모두 벌꿀채취 위치를 정함
                                int a1 = getHoney(i,j,k,0,0,0);
                            }
                        }
                    }
                }

                for (int k = 0; k < M; ++k) {
                    check[i][j + k] = false;   //일꾼 1
                }
            }
        }
    }

    return 0;
}