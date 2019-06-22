#include <iostream>

using namespace std;

const int MAX = 500;

int R,C;
int a[MAX][MAX];
int parent[MAX*MAX];
int ans[MAX*MAX];

int dx[]={-1,-1,-1,0,1,1,1,0}; // R
int dy[]={-1,0,1,1,1,0,-1,-1};

int go(int x){
    if( parent[x] == x){
        return x;
    }else{
        return parent[x] = go(parent[x]);
    }
}

int main() {

    cin >> R >> C;

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> a[i][j];
        }
    }

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            int x = i,y = j;
            for(int k = 0; k<8; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if( 0 <= nx && nx < R && 0 <= ny && ny < C){
                    if( a[nx][ny] < a[x][y]){
                        x = nx;
                        y = ny;
                    }
                }
            }
            parent[i*C+j] = x*C+y;
        }
    }

    for(int i=0; i<R;i++){
        for(int j=0; j<C; j++){
            ans[go(i*C+j)] += 1;
        }
    }

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cout<<ans[i*C+j]<<" ";
        }
        cout<<"\n";
    }



    return 0;
}