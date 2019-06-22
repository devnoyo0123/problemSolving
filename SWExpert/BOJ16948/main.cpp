#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 200;

int dLocation[][2]={{-2,-1},{-2,1},{0,-2},{0,2},{2,-1},{2,1}};

int d[MAX][MAX];
int a[MAX][MAX];
int N;

int main() {

    cin >> N;
    int r1,r2,c1,c2;
    cin >> r1 >> c1 >> r2 >> c2;

    memset(d,-1, sizeof(d));
    queue<pair<int, int> > q;
    d[r1][c1] = 0;
    q.push({r1,c1});

    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();

        for(int i=0; i<6; i++){
            int nR = cur.first + dLocation[i][0];
            int nC = cur.second + dLocation[i][1];

            if( 0<= nR && nR < MAX && 0 <= nC && nC < MAX){
                if( d[nR][nC] == -1){
                    d[nR][nC] = d[cur.first][cur.second] + 1;
                    q.push({nR,nC});
                }
            }
        }
    }

    if( d[r2][c2] == -1){
        cout<< -1;
    }else{
        cout<<d[r2][c2];
    }

    return 0;
}