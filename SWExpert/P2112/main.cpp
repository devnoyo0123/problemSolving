#include <iostream>
#include <cstdio>

using namespace std;

const int ROWMAX = 13;
const int COLMAX = 20;

int TC, K, D, W;
int map[ROWMAX+1][COLMAX+1];
int ans;

bool checkRow(int col){
    bool ret = false;
    int cnt = 0;
    int temp = map[0][col];
    for (int j = 0; j < D; ++j) {
        if(map[j][col] == temp){
            cnt+=1;

            if( cnt >= K){
                ret = true;
                return ret;
            }
        }else{

            temp = map[j][col];
            cnt =1;
        }


    }

    if( cnt < K){
        ret = false;
    }
    return ret;
}

void go(int curRow, int inputCnt, int goal){



    // curRow까지 inputCnt약을 투입했을때 약품이 안전하면 ans값을 갱신하는 함수
    if( curRow > D){
        return;
    }

    if( inputCnt == goal){
        // 약품 검사
        int colCnt = 0;
        for (int i = 0; i < W; ++i) {

            if(checkRow(i)){
                colCnt += 1;
            }else{
                return;
            }

        }
        if( colCnt == W){
            ans = inputCnt;
            return;
        }
    }

    //아무것도 투입안했음
    go(curRow+1, inputCnt, goal);

    //curRow에 A시약 투입
    int temp[COLMAX];
    memset(temp, 0, sizeof(temp));
    for (int j = 0; j < W ; ++j) {
        temp[j] = map[curRow][j];
        map[curRow][j] = 0;
    }
    go(curRow+1, inputCnt+1, goal);
    for (int j = 0; j < W ; ++j) {
        map[curRow][j] = temp[j];
    }


    //curCol에 B시약 투입
    memset(temp, 0, sizeof(temp));
    for (int j = 0; j < W ; ++j) {
        temp[j] = map[curRow][j];
        map[curRow][j] = 1;
    }
    go(curRow+1, inputCnt+1, goal);
    for (int j = 0; j < W ; ++j) {
        map[curRow][j] = temp[j];
    }

}

int main() {

    cin >> TC;

    for (int T = 1; T <= TC ; ++T) {
        cin >> D >> W >> K;

        for (int i = 0; i < D; ++i) {
            for (int j = 0; j < W; ++j) {
                cin >> map[i][j];
            }
        }

        ans = D;

        for (int i = 0; i <= D; ++i) {
            go(0,0,i);
            if( ans < D){
                break;
            }
        }
        cout<<"#"<<T<<" "<<ans<<"\n";
    }

    return 0;
}



//1
//4 4 3
//0 0 1 0
//0 1 0 0
//0 1 1 1
//1 1 1 1
