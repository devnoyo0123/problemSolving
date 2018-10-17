#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#define p pair< pair<int,int> ,int>
using namespace std;

const int HMAX = 15;
const int WMAX = 12;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int map[HMAX][WMAX];
int ans;
int row,col;

void merge_map(){
    for(int c=0; c<col; c++){
        int tmp_col[15] = {0,};
        int idx = 0;

        for(int r=row-1; r>=0; r--){
            if(map[r][c] != 0){
                tmp_col[idx] = map[r][c];
                idx++;
            }
        }

        idx = 0;
        for(int r=row-1; r>=0; r--){
            map[r][c] = tmp_col[idx];
            idx++;
        }

    }
}

int cal(){
    int cnt = 0 ;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(map[i][j])
                cnt++;
        }
    }
    return cnt;
}
bool inRange(int x, int y){
    if( x < 0 || x >= row || y < 0 || y >= col)
        return false;
    return true;
}

void work(int st_col){
    for(int i=0; i<row; i++){
        if(map[i][st_col] == 0)
            continue;

        queue<p> q;
        q.push({ {i,st_col}, map[i][st_col] });

        int v[HMAX][WMAX] = {0,}; // 체크맵인듯
        v[i][st_col] = 1;

        while (! q.empty()) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int value = q.front().second - 1; // 자기 자신은 이미 포함했으니 -1
            q.pop();

            map[x][y] = 0;
            for(int j=1; j<=value; j++){ // 갖고 있는 크기만큼 반복
                int nx = x + j;
                if(inRange(nx, y)){ // 범위 체크
                    if(map[nx][y] != 0 && v[nx][y] == 0){ // 기존에 방문했었나? 배열의값이 0이 아닌가
                        v[nx][y] = 1;
                         q.push( {{nx,y}, map[nx][y]} );
                    }
                }
                nx = x - j;
                if(inRange(nx, y)){
                    if(map[nx][y] != 0 && v[nx][y] == 0){
                        v[nx][y] = 1;
                         q.push( {{nx,y}, map[nx][y]} );
                    }
                }

                int ny = y + j;
                if(inRange(x, ny)){
                    if(map[x][ny] != 0 && v[x][ny] == 0){
                        v[x][ny] = 1;
                         q.push( {{x,ny}, map[x][ny]} );
                    }
                }

                ny = y - j;
                if(inRange(x, ny)){
                    if(map[x][ny] != 0 && v[x][ny] == 0){
                        v[x][ny] = 1;
                         q.push( {{x,ny}, map[x][ny]} );
                    }
                }
            } // end of for j
        } // end of while
        merge_map();
        return ;
    } // end of for i
}

void dfs(int n){
    if(n == 0){
        int res = cal();
        ans = ans < res ? ans : res;
        return ;
    }

    int tmp_map[HMAX][WMAX];
    for(int i=0; i<row; i++) for(int j=0; j<col; j++) tmp_map[i][j] = map[i][j];
    for(int i=0; i<col; i++){
        work(i);
        dfs(n-1);
        for(int i=0; i<row; i++) for(int j=0; j<col; j++) map[i][j] = tmp_map[i][j];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC;
    cin >> TC;
    for(int tc=1; tc<=TC; tc++){
        ans = 987654321;
        int n;
        cin >> n >> col >> row;
        for(int i=0; i<row; i++) for(int j=0; j<col; j++) cin >> map[i][j];
        dfs(n);
        cout << "#" << tc << " " << ans << endl ;
    }
    return 0;
}