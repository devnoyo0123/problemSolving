#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 8;

int N, M, ans, zeroCnt;
int map[MAX][MAX];
int dLocation[][2] ={{-1,0},{0,1},{1,0},{0,-1}};
vector<pair<int, int> > virus;

void BFS(int row, int col){
    bool check[MAX][MAX]={0,};
    queue<pair<int, int> > q;
    q.push({row,col});
    check[row][col] = true;

    while(!q.empty()){
        pair<int, int> tmp = q.front(); q.pop();

        for (int i = 0; i < 4; ++i) {
            int nRow = tmp.first + dLocation[i][0];
            int nCol = tmp.second + dLocation[i][1];

            if( nRow >= 0 && nRow <N && nCol >=0 && nCol < M){
                if( map[nRow][nCol] == 0 && !check[nRow][nCol]){
                    check[nRow][nCol] = true;
                    map[nRow][nCol] = 2;
                    q.push({nRow, nCol});
                }
            }
        }
    }
}

void solve(int cnt){
    if( cnt == 0){
        //안전영역 구하기

        //기본 맵 복사
        int tmp[MAX][MAX];
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                tmp[i][j] = map[i][j];
            }
        }
        int size = (int)virus.size();
        for (int l = 0; l < size; ++l) {
            pair<int, int> tmp = virus[l];
            BFS(tmp.first, tmp.second);
        }
        int cnt = 0;
        for (int k = 0; k < N; ++k) {
            for (int i = 0; i < M; ++i) {
                if( map[k][i] == 0){
                    cnt++;
                }
            }
        }

        int res = cnt;
        if( ans < res){
            ans = res;
        }

        //안전영역 구한후 다시 기존맵 복원
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                map[i][j] = tmp[i][j];
            }
        }
        return;
    }


    // 벽을 세우기
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if( map[i][j] == 0){
                //빈칸이면 벽을 세워보자
                map[i][j] = 1;
                solve(cnt-1);
                map[i][j] = 0;
            }
        }
    }
}

int main() {

    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> map[i][j];
            if( map[i][j] == 2){
                virus.push_back({i,j});
            }else if(map[i][j] == 0){
                zeroCnt++;
            }
        }
    }

    solve(3);

    cout<<ans<<"\n";

    return 0;
}