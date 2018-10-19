#include <iostream>

using namespace std;

const int MAX = 50;

int map[MAX][MAX];
int dLocation[][2]= {{-1,0},{0,1},{1,0},{0,-1}}; // 북남동서

int N, M, ans;

struct {
    int row, col, dir;
}Robot;

void solve(){
    int curRow = Robot.row;
    int curCol = Robot.col;
    int curDir = Robot.dir;
    while(true){
        map[curRow][curCol] = 2;

        if( map[curRow-1][curCol] != 0 && map[curRow][curCol+1] != 0
                && map[curRow+1][curCol] != 0 && map[curRow][curCol-1] != 0)
        {
            //2 - 3,4
            //바라보는 방향을 유지하고 한칸 후진
            int nRow = curRow - dLocation[curDir][0];
            int nCol = curCol - dLocation[curDir][1];
            if( map[nRow][nCol] == 1){
                //벽이면
                break;
            }else{
                curRow = nRow;
                curCol = nCol;
            }
        }
        else
            {
            //2-1,2
            int nDir = (curDir + 3) % 4;
            int nRow = curRow + dLocation[nDir][0];
            int nCol = curCol + dLocation[nDir][1];
            if(map[nRow][nCol] == 0){
                //왼쪽방향이 아직 청소안했으면 청소해라
                curRow = nRow;
                curCol = nCol;
                curDir = nDir;
            }else{
                curDir = nDir;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if(map[i][j]==2){
                cnt++;
            }
        }
    }
    ans = cnt;
}


int main() {

    cin >> N >> M;

    int a, b, dir;

    cin >> a >> b >> dir;

    Robot.row = a; Robot.col = b; Robot.dir = dir;

    for(int i = 0; i< N; i++){
        for (int j = 0; j < M; ++j) {
            cin >> map[i][j];
        }
    }

    solve();

    cout<<ans<<"\n";

    return 0;
}