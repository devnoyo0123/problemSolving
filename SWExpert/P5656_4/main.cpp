#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>


using namespace std;

const int WMAX = 12;
const int HMAX = 15;
const int NMAX = 4;

int dLocation[][2]={{-1,0},{0,1},{1,0},{0,-1}}; // 북동남서

int map[HMAX][WMAX];

int TC, N, W, H, ans; // N: 구슬 쏘는 횟수,

int calc(){
    int res = 0;
    for(int i=0; i< H; i++){
        for (int j = 0; j < W ; ++j) {
            if( map[i][j] > 0){
                res+=1;
            }
        }
    }
//    cout<<"res: "<<res<<"\n";
    return res;
}

void reshape(){
    queue<int> queue1;

    // 한 열씩
    for (int i = 0; i < W; ++i) {
        for (int j = H-1; j >= 0; --j) {
            if(map[j][i] > 0){
                queue1.push(map[j][i]);
                map[j][i] = 0;
            }
        }

        int inx = H-1;
        while(!queue1.empty()){
            map[inx--][i] = queue1.front(); queue1.pop();
        }
    }
    //
//            cout<<"after reshape\n";
//    for (int k = 0; k < H; ++k) {
//        for (int i = 0; i < W; ++i) {
//            cout<<map[k][i]<<" ";
//        }
//        cout<<"\n";
//    }
//    cout<<"\n";
}

void BFS(int col){

    //col 에 구슬을 쏠거에요.
    for (int i = 0; i < H; ++i) {
        // 맨 위에서부터 0이 아닌 벽이 있으면 구슬 쏠겁니다.
        if( map[i][col] == 0)
            continue;

        // BFS 할거니까 큐를 쓸게요.
        // 그리고 한번씩 방문하는 것을 알기 위해 체크맵을 쓸게요.
        bool check[HMAX][WMAX];
        memset(check, 0, sizeof(check));
        queue<tuple<int, int, int> > qu; // 값에 따라서 벽을 부수는 크기가 달라요.
        // row , col , 크기를 담는 튜플형식 큐를 생성합니다.
        check[i][col] = true;
        qu.push(make_tuple(i,col,map[i][col]));

        while (! qu.empty()) {
            int x,y,value;
            tie(x,y,value) = qu.front(); qu.pop();
            value-=1;
            map[x][y] = 0;


            // 여기로직만 _2랑 똑같이 바꾸면 해결돼 이 로직의 문제점을 찾아내라.

            for (int j = 0; j < 4; ++j) {
                int curRow = x; int curCol = y;
                for (int k = 1; k <= value; ++k) {
                    int nRow = curRow + dLocation[j][0];
                    int nCol = curCol + dLocation[j][1];
                    if( nRow >= 0 && nRow < H && nCol >=0 && nCol < W){

                        if(!check[nRow][nCol] && map[nRow][nCol] != 0){

                            check[nRow][nCol] = true;
                            qu.push(make_tuple(nRow, nCol, map[nRow][nCol]));
                        }
                    }
                }
            }
        }
        break;
    }
}

void solve(int cnt){

    if (cnt == 0){

        // 더이상 쏠 구슬이 없음.
        int res = calc(); // 현재 맵에서 0이 아닌 칸이 개수 세기
        if( ans > res){ // 최소값 갱신
            ans = res;
        }
        return;


    }
    // 쐇다고 치고 구슬 부시고 다시 모형 재정비까지해

    // 현재 맵에다가 시뮬레이션 작업할거잖아. 그럼 원본애를 저장해줘야지.
    // 재귀 트리 모형을 생각해 자식이 1,2,3,4가 있는데 각각 다른 상황이면
    // 현재 내 상태를 저장해놔야지 1번 하고 나서 다시 원복하고 2번하지.
    int tmp[HMAX][WMAX];
    for (int j = 0; j < H; ++j) {
        for (int i = 0; i < W; ++i) {
            tmp[j][i] = map[j][i];
        }
    }

    for (int i = 0; i < W; ++i) {
        BFS(i); // i열 쐈어.
        reshape(); // 남은애들다 아래로 깔았어.
        solve(cnt-1);
        // 맵 원상복귀
        for (int j = 0; j < H; ++j) {
            for (int k = 0; k < W; ++k) {
                map[j][k] = tmp[j][k];
            }
        }
    }

}

int main() {

    cin >> TC;

    for (int T = 1; T <= TC ; ++T) {
        cin >> N >> W >> H;
        ans = 2e9;
        memset(map, 0, sizeof(map));
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                cin >> map[i][j];
            }
        }

        solve(N);
        cout<<"#"<<T<<" "<<ans<<"\n";
    }

    return 0;
}