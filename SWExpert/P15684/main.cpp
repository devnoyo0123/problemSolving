#include <cstdio>
#include <climits>

const int MAXROW = 30;
const int MAXCOL = 10;

bool map[MAXROW+1][MAXCOL+2]; //좌우 패딩
int N,M,H; //열의수, 주어진 사다리 수, 행의 수
int ans = INT_MAX;
int recur;

bool simulate(){
    bool ret = false;
    int corret = 0, copy = 0;
    int j = 1, i = 1;
    for (j = 1; j <= N ; ++j) { // 열 반복
        copy = j;
        for (i = 1; i <= H; ++i) { //행 반복
            if(map[i][copy]){
                copy++;
            }else if( map[i][copy-1]){
                copy--;
            }
        }
        if(copy == j){
            corret+=1;
//            printf("original: %d, copy:%d\n", j, copy);
        }else{
            break;  //하나라도 다르면 의미없음.
        }
    }
    if(corret == N){
        ret = true;
    }

    return ret;
}

void go(int rowPos, int cnt, int goal){
    // rowPos부터 사다리 cnt를 추가하여 i번째 열이 사다리 타고 i번째로 갔는지 확인하는 함수

//    recur++;
//    printf("cnt: %d 사다리 나무: %d\n", recur, cnt);
//    for (int k = 1; k <= H ; ++k) {
//        for (int i = 1; i <= N; ++i) {
//            printf("%d ", map[k][i]);
//        }
//        printf("\n");
//    }
//    printf("\n");


    if( cnt == goal){
        if(simulate()){
//            printf("here\n");
            ans = cnt;
        }
        return;
    }else{
        for (int i = rowPos; i <= H ; ++i) { // 행 반복
            for (int j = 1; j < N ; ++j) { // 열 반복 마지막 열에는 사다리 추가의미 없
                if(!map[i][j] && !map[i][j-1] && !map[i][j+1]){
                    map[i][j] = true;
                    if(ans != INT_MAX){
                        return;
                    }
                    go(i, cnt+1, goal);

                    map[i][j] = false;
                }
            }
        }
    }
}

int main() {

    scanf("%d %d %d", &N, &M, &H);

    for (int i = 0; i < M ; ++i) {
        int a,b;
        scanf("%d %d", &a, &b);
        map[a][b] = true;
    }

    for (int i = 0; i < 4; ++i) {
        go(1,0,i);
        if( ans != INT_MAX){
            break;
        }
    }
    if( ans == INT_MAX){
        ans = -1;
    }
    printf("%d\n", ans);


    return 0;
}