#include <iostream>
#include <cstring>

using namespace std;

const int DMAX = 13;
const int WMAX = 20;
int map[DMAX][WMAX];
int choice[DMAX];

int TC,D,W,K, ans;

bool check(){
    bool res;
    for (int i = 0; i < W; ++i) {
        int cnt = 0, maxSame = 0;
        for (int j = 1; j < D; ++j) {
            if( map[j-1][i] == map[j][i]){
                cnt++;
                if( cnt > maxSame){
                    maxSame = cnt;
                }
            }else{
                cnt = 0;
            }
        }

        if( maxSame < K-1){
            res = false;
            return res;
        }
    }
    return true;
}

void add(){
    for (int i = 0; i < D; ++i) {
        if( choice[i] == 1){
            //i행을 A: 0으로 채우자.
            for (int j = 0; j < W; ++j) {
                map[i][j] = 0;
            }
        }else if( choice[i] == 2){
            for (int j = 0; j < W; ++j) {
                //i 행을 B로 채우자.
                map[i][j] = 1;
            }
        }
    }
}

bool solve(int cnt, int goal, int inx, int end){
    bool res;
    if(inx == end){ // 더이상 넘어갈 행이 없음.
        res = false;
        return res;
    }

    if( cnt == goal){
        int tmp[DMAX][WMAX];

        for (int i = 0; i < D; ++i) {
            for (int j = 0; j < W; ++j) {
                tmp[i][j] = map[i][j];
            }
        }

        add();// 투약

        if(check()){ // 안점검사
            ans = cnt;
            res = true;
        }else{
            res = false;
        }

        for (int i = 0; i < D; ++i) {
            for (int j = 0; j < W; ++j) {
                map[i][j] = tmp[i][j];
            }
        }

        return res;
    }

    solve(cnt, goal, inx+1, D); // inx행에 투약안하기
    choice[inx] = 1;
    solve(cnt+1, goal, inx+1, D); // inx행에 A시약 투약
    choice[inx] = 2;
    solve(cnt+1, goal, inx+1, D); // inx행에 B시약 투약


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

        for (int k = 0; k <= D; ++k) {
            if(solve(0,k,0,D)){
                break;
            }
        }

        cout<<"#"<<T<<" "<<ans<<"\n";
    }
    return 0;
}