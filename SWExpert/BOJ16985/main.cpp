#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 5;

int dx[] = {-1,0,1,0,0,0};
int dy[] = {0,1,0,-1,0,0};
int dz[] = {0,0,0,0,1,-1};

class Node{
public:
    int x,y,z;
    Node(int _x, int _y, int _z){
        x= _x;
        y= _y;
        z= _z;
    }
};

int bfs(vector<vector<vector<int> > > &a){

    if( a[0][0][0] == 0) return -1;

    vector<vector<vector<int> > > d(MAX);
    for(int i=0; i<MAX; i++){
        d[i].resize(MAX, vector<int>(MAX, -1));
    }

    queue<Node> q;
    d[0][0][0] = 0;
    q.push(Node(0,0,0));

    while(!q.empty()){
        Node temp = q.front(); q.pop();
        for(int i=0; i<6; i++){
            int nx = temp.x + dx[i];
            int ny = temp.y + dy[i];
            int nz = temp.z + dz[i];

            if( nx >= 0 && ny >=0 && nz >=0 && nx < MAX && ny < MAX && nz < MAX){
                if(d[nx][ny][nz] == -1 && a[nx][ny][nz] == 1){
                    d[nx][ny][nz] = d[temp.x][temp.y][temp.z] + 1;
                    q.push(Node(nx,ny,nz));
                }
            }
        }
    }

    return d[MAX-1][MAX-1][MAX-1];
}

vector<vector<int > > rotate(vector<vector<int> > &a){
    vector<vector<int> > b(MAX, vector<int>(MAX));
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            b[i][j] = a[MAX-j-1][i];
        }
    }
    return b;
}

int main() {

    vector<vector<vector<int> > > a(MAX);

    for(int i=0; i<MAX; i++){
        a[i].resize(MAX, vector<int>(MAX));
        for(int j=0; j<MAX; j++){
            for(int k= 0; k<MAX; k++){
                cin >> a[i][j][k];
            }
        }
    }

    vector<int> miro(MAX);
    for(int i=0; i< MAX; i++){
        miro[i] = i;
    }

    int ans = -1;

    do{
        vector<vector<vector<int> > > tmp(MAX);
        for(int i=0; i<MAX; i++){
            tmp[miro[i]] = a[i];
        }

        for(int l1 =0; l1 < 4; l1++){
            for(int l2 =0; l2 < 4; l2++){
                for(int l3 =0; l3 < 4; l3++){
                    for(int l4 =0; l4 < 4; l4++){
                        for(int l5 =0; l5 < 4; l5++){

                            int cur = bfs(tmp);
                            if( cur != -1){
                                if( ans == -1 || ans > cur){
                                    ans = cur;
                                }
                            }
                            //회전
                            tmp[4] = rotate(tmp[4]);
                        }
                        tmp[3] = rotate(tmp[3]);
                    }
                    tmp[2] = rotate(tmp[2]);
                }
                tmp[1] = rotate(tmp[1]);
            }
            tmp[0] = rotate(tmp[0]);
        }

    }while(next_permutation(miro.begin(), miro.end()));


    cout<< ans<<'\n';

    return 0;
}


//이 문제 2차원 배열 회전시키는거 빡셈..