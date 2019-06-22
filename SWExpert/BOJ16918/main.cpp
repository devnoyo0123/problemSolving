#include <iostream>
#include <queue>

using namespace std;

const int MAX = 200;

int dx[] = {-1,0,1,0}; // R
int dy[] = {0,1,0,-1}; // C
int R,C,N;
string a[MAX];
int b[MAX][MAX];

queue<pair<int, int> > q[3];

void solve(){
    vector<vector<bool> >c(R, vector<bool>(C,false));


    for(int i=0; i<N; i++){
        while(!q[2].empty()){
            pair<int, int> temp = q[2].front(); q[2].pop();
            b[temp.first][temp.second] = 1;
            c[temp.first][temp.second] = true;
        }

        while(!q[1].empty()){
            pair<int, int> temp = q[1].front(); q[1].pop();
            b[temp.first][temp.second] = 0;
            c[temp.first][temp.second] = true;
        }

        while(!q[0].empty()){
            pair<int, int> temp = q[0].front(); q[0].pop();
            c[temp.first][temp.second] = true;

            b[temp.first][temp.second] = 2;
            for(int j=0; j<4; j++){

                int nR = temp.first + dx[j];
                int nC = temp.second + dy[j];

                if( nR < 0 || nC < 0 || nR == R || nC == C) continue;

                b[nR][nC] = 2;
            }
        }

        for (int k = 0; k < R; ++k) {
            for (int j = 0; j < C; ++j) {
                q[b[k][j]].push(make_pair(k,j));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> R >> C >> N;
    for(int i=0; i<R; i++){
        cin >> a[i];
        for(int j=0; j<C; j++){
            if( a[i][j] == '0'){
                b[i][j] = 2;
                q[2].push(make_pair(i,j));
            }else{
                b[i][j] = 0;
                q[0].push(make_pair(i,j));
            }
        }
    }

    solve();

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if( b[i][j] == 0){
                cout<<'.';
            }else{
                cout<<'0';
            }
        }
        cout<<'\n';
    }

    return 0;
}