#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 50;

int map[MAX][MAX];
int temp[MAX][MAX];
bool check[MAX][MAX];

int N, L, R;
int dLocation[][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int sum, ans;
bool flag;

vector<pair<int, int> > points;

bool lineCheck(int row, int col){
    return row >= 0 && row < N && col >=0 && col < N;
}

void BFS(int row, int col){
    queue<pair<int, int> > qu;

    check[row][col] = true;
    sum += map[row][col];
    qu.push({row, col});
    points.push_back({row,col});

    while(!qu.empty()){
        pair<int, int> temp = qu.front(); qu.pop();
        for(int i=0; i<4; i++){
            int nRow = temp.first + dLocation[i][0];
            int nCol = temp.second + dLocation[i][1];

            if(lineCheck(nRow, nCol) && !check[nRow][nCol]){
                int diff = abs(map[temp.first][temp.second] - map[nRow][nCol]);
                if( L <= diff && diff <= R){
                    check[nRow][nCol] = true;
                    sum += map[nRow][nCol];
                    qu.push({nRow, nCol});
                    points.push_back({nRow,nCol});

                }
            }
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> L >> R;

    for(int i=0; i< N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
        }
    }

    while(true){
        flag = false;
        memset(check, 0, sizeof(check));
        memset(temp,0, sizeof(temp));
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                sum = 0;
                points.clear();
                if(!check[i][j]){

                    BFS(i,j);
                }

                int size = points.size();
                if( size == 0){
                    continue;
                }

                if( size == 1){
                    temp[i][j] = map[i][j];
                }else{

                    int avg = sum/size;
                    for(pair<int, int> pair1 : points){
                        temp[pair1.first][pair1.second] = avg;
                    }

                    flag = true;


                }

            }
        }

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                map[i][j] = temp[i][j];
            }
        }

        if( !flag ){
            break;
        }
        ans++;
    }

    cout<<ans<<'\n';

    return 0;
}