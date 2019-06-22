#include <iostream>
#include <vector>

using namespace std;

const int MAX = 50;

int dist[MAX][MAX];
bool check[MAX][MAX];
string a[MAX];

int dLocation [][2] = {{-1,0},{0,1},{1,0},{0,-1}};

int n,m;

bool go(int r, int c, int cnt, char color){
    if(check[r][c]) return cnt - dist[r][c] >= 4;
    check[r][c] = true;
    dist[r][c] = cnt;

    for(int i = 0; i< 4; i++){
        int nR = r + dLocation[i][0];
        int nC = c + dLocation[i][1];

        if( 0 <= nR && nR < n && 0 <= nC && nC <m )
        {
            if(a[nR][nC] == color){
                if( go(nR, nC , cnt+1, color) ){
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {



    cin >> n >> m;

    vector<vector<bool> >c(n, vector<bool>(m, false));
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    bool ok = false;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){

            if(check[i][j])
                continue;


            if(go(i,j,0,a[i][j])){
                ok = true;
            }
        }
    }

    if(ok)
    {
        cout<<"Yes";
    }else{
        cout<<"No";
    }

    return 0;
}