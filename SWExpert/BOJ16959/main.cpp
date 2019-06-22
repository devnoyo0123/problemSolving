#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 3000;

int N;

int adj[MAX+1][MAX+1];
int check[MAX+1];
int dist[MAX+1];

int go(int x, int pre){
    if( check[x] == 1){
        return x;
    }

    check[x] = 1;
    for(int i=1; i<=N; i++){
        int tmp = adj[x][i];
        if( tmp == 0 || i == pre) continue;
        int cur = go(i, x);
        if( cur == -2) return -2;
        if( cur > 0){
            check[x] = 2;
            if( x == cur) return -2;
            else return cur;
        }
    }

    return -1;
}


int main() {

    cin >> N;

    int a,b;
    for(int i=0; i<N; i++){
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    go(a,-1);

    queue<int> q;
    for (int i=1; i<=N; i++) {
        if (check[i] == 2) {
            dist[i] = 0;
            q.push(i);
        } else {
            dist[i] = -1;
        }
    }

    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int i=1; i<=N;i++){
            int tmp = adj[cur][i];
            if( tmp > 0 && dist[i] == -1){
                q.push(i);
                dist[i] = dist[cur] + 1;
            }
        }
    }

    for (int i=1; i<=N; i++) {
        cout << dist[i] << ' ';
    }
    return 0;
}