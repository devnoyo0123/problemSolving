#include <iostream>
#include <cstring>

using namespace std;

const int DMAX = 13;
const int WMAX = 20;
int map[DMAX][WMAX];
int choice[DMAX];

int TC,D,W,K, ans;

bool checkRow(int tmp[][WMAX], int col){
    bool ret = false;
    int cnt = 0;
    int temp = tmp[0][col];
    for (int j = 0; j < D; ++j) {
        if(tmp[j][col] == temp){
            cnt+=1;

            if( cnt >= K){
                ret = true;
                return ret;
            }
        }else{
            temp = tmp[j][col];
            cnt =1;
        }

    }

    if( cnt < K){
        ret = false;
    }
    return ret;
}

void add(int tmp[][WMAX]){
    for (int i = 0; i < D; ++i) {
        if( choice[i] == 1){
            //i행을 A: 0으로 채우자.
            for (int j = 0; j < W; ++j) {
                tmp[i][j] = 0;
            }
        }else if( choice[i] == 2){
            for (int j = 0; j < W; ++j) {
                //i 행을 B로 채우자.
                tmp[i][j] = 1;
            }
        }
    }
}

void solve(int cnt, int goal, int inx, int end){


    if( cnt == goal){
        // 약품 검사

        int tmp[DMAX][WMAX];
        for (int j = 0; j < D; ++j) {
            for (int i = 0; i < W; ++i) {
                tmp[j][i] = map[j][i];
            }
        }

        add(tmp); // 투약

//        for (int k = 0; k < D; ++k) {
//            cout<<choice[k]<<" ";
//        }
//        cout<<"\n";
//
//        cout<<"cnt: "<<cnt<<"\n";
//        for (int j = 0; j < D; ++j) {
//            for (int i = 0; i < W; ++i) {
//                cout<< tmp[j][i] <<" ";
//            }
//            cout<<"\n";
//        }
//        cout<<"\n";

        int colCnt = 0;
        for (int i = 0; i < W; ++i) {

            if(checkRow(tmp,i)){
                colCnt += 1;
            }else{
                // 안전검사 실패
                return;
            }

        }

        if( colCnt == W){   //합격한 컬럼수가 w개면 모든 열이 안전하다는 얘기

//            cout<<"모두합격\n";

            ans = goal;

        }
        return;
    }

    if(inx == end){
        return;
    }

    if(ans < D){
        return;
    }
    choice[inx] = 0;
    solve(cnt, goal, inx+1, D); // inx행에 투약안하기
    choice[inx] = 1;
    solve(cnt+1, goal, inx+1, D); // inx행에 A시약 투약
    choice[inx] = 0;
    choice[inx] = 2;
    solve(cnt+1, goal, inx+1, D); // inx행에 B시약 투약
    choice[inx] = 0;


}

int main() {
    cin >> TC;
    for (int T = 1; T <= TC; ++T) {

        cin >> D >> W >> K;
        memset(map, 0, sizeof(map));
        memset(choice, 0, sizeof(choice));


        for (int i = 0; i < D; ++i) {
            for (int j = 0; j < W; ++j) {
                cin >> map[i][j];
            }
        }

        ans = D; // 이건 의미로 파악해낸것  그래서 의미파악이 중요해
        for (int k = 0; k <= D; ++k) {
            solve(0,k,0,D);
            if( ans <D){
                break;
            }
        }

        cout<<"#"<<T<<" "<<ans<<"\n";
    }
    return 0;
}