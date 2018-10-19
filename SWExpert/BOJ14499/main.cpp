#include <iostream>

using namespace std;

const int MAX = 20;
const int DICEMAX = 6;
const int CMDMAX = 1001;

int N,M,x,y,K;
int map[MAX][MAX];
int dir[CMDMAX];
int dice[DICEMAX+1];

int dLocation[][2]={{0,0},{0,1},{0,-1},{-1,0},{1,0}}; //1:동, 서, 북, 남

void diceRoll(int dir){
    if( dir == 1){
        //동
        int temp = dice[4];
        dice[4] = dice[3];
        dice[3] = dice[2];
        dice[2] = dice[6];
        dice[6] = temp;
    }else if( dir == 2){
        //서

        int temp = dice[2];
        dice[2] = dice[3];
        dice[3] = dice[4];
        dice[4] = dice[6];
        dice[6] = temp;
    }else if( dir == 3){
        //북
        int temp = dice[1];
        dice[1]=dice[3];
        dice[3]=dice[5];
        dice[5]=dice[6];
        dice[6]=temp;
    }else if( dir == 4){
        //남

        int temp = dice[6];
        dice[6]= dice[5];
        dice[5]= dice[3];
        dice[3]= dice[1];
        dice[1]= temp;
    }
}

void solve(){
    int tmpX = x;
    int tmpY = y;

//    cout<<"x: "<<tmpX<<" y: "<<tmpY<<", val:"<<map[tmpX][tmpY]<<"\n";
    for (int i = 0; i < K; ++i) {

        int nX = tmpX + dLocation[dir[i]][0];
        int nY = tmpY + dLocation[dir[i]][1];

        if( nX >=0 && nX <N && nY >=0 && nY < M){
//            cout<<"x: "<<tmpX<<" y: "<<tmpY<<", val:"<<map[tmpX][tmpY]<<"\n";

            diceRoll(dir[i]);

            if( map[nX][nY] != 0){
                dice[3] = map[nX][nY];
                map[nX][nY] = 0;

            }else{
                map[nX][nY] = dice[3];
            }


            cout<<dice[6]<<"\n";
            tmpX = nX;
            tmpY = nY;
        }

    }
}

int main() {

    cin >> N >> M >> x >> y >> K;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> map[i][j];
        }
    }

    for(int i = 0; i< K; i++){
        cin >> dir[i];
    }

    solve();

    return 0;
}