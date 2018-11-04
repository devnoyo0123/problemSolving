#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>


using namespace std;

const int MAX = 100;

int r,c, n;

char map[MAX][MAX];
bool check[MAX][MAX];
int dRow[] = {-1, 0, 1, 0};
int dCol[] = {0, 1, 0, -1};
vector<pair<int, int> > group;

void dfs(int row, int col){
    if( map[row][col] == '.'){
        return;
    }
    check[row][col] = true;
    group.push_back({row, col});
    for (int i = 0; i < 4; ++i) {
        int nRow = row + dRow[i];
        int nCol = col + dCol[i];
        if( nRow < 0 || nRow >= r || nCol < 0 || nCol >= c){
            continue;
        }
        if(!check[nRow][nCol]){
            dfs(nRow, nCol);
        }
    }
}

void simulate(){
    memset(check, false, sizeof(check));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if( map[i][j] == '.'){
                continue;
            }

            //진짜 좋은아이디어 내렸던 애들은 다시 내리지 않는다. 최적화
            if( check[i][j] ){
                continue;
            }

            group.clear();
            dfs(i,j);

            vector<int> low(c, -1);
            for ( auto tmp : group) {
                low[tmp.second] = max( low[tmp.second], tmp.first);
                // 이것도 배워야할 포인트 어차피 이동할거니까 지워버리자.
                map[tmp.first][tmp.second] = '.';
            }

            int lowest = r;
            for (int l, k = 0; k < c; ++k) {
                if( low[k] == -1){
                    continue; // 이것도 배울 점 최적화.
                }
                for ( l = low[k]; l < r && map[l][k] == '.'; ++l) {
                    lowest = min ( lowest, l - low[k] - 1);
                }
            }

            for (auto &tmp : group) {
                tmp.first += lowest;
                map[tmp.first][tmp.second] = 'x';
                check[tmp.first][tmp.second] = true;
            }
        }
    }
}


int main() {

    cin >> r >> c;
    for (int i = 0; i < r; ++i) {
        cin >> map[i];
    }

    cin >> n;
    for (int k = 0; k < n; ++k) {
        int height;
        cin >> height;
        height = r - height;
        if( (k % 2) == 0){
            //왼쪽에서 오른쪽으로
            for (int i = 0; i < c; ++i) {
                if( map[height][i] == '.'){
                    continue;
                }else{
                    map[height][i] = '.';
                    break;
                }
            }
        }else{
            //오른쪽에서 왼쪽으로
            for (int i = c-1; i >=0 ; --i) {
                if( map[height][i] == '.'){
                    continue;
                }else{
                    map[height][i] = '.';
                    break;
                }
            }
        }

        simulate();
        for (int i = 0; i < r; ++i) {
            cout<<map[i]<<'\n';
        }
        cout<<'\n';

    }

    for (int i = 0; i < r; ++i) {
        cout<<map[i]<<'\n';
    }
    cout<<'\n';

    return 0;
}