#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 1004;

int n1,m1,s1;

bool map[MAX][MAX];
bool check[MAX];

void BFS(int startNode){
    queue<int> Q;
    check[startNode] = true;
    Q.push(startNode);

    while(!Q.empty()){
        int tmp = Q.front(); Q.pop();
        printf("%d ", tmp);

        for (int i = 1; i <= n1 ; ++i) {
            if(map[tmp][i] && !check[i]){
                check[i] = true;
                Q.push(i);
            }
        }
    }
}

void DFS(int startNode){

    check[startNode] = true;
    printf("%d ", startNode);


    for (int i = 1; i <= n1; ++i) {
        if( map[startNode][i] && !check[i]){
            DFS(i);
        }
    }


}

int main() {

    scanf("%d %d %d", &n1, &m1, &s1);

    int a,b;
    for (int i = 0; i < m1; ++i) {
        scanf("%d %d", &a, &b);
        map[a][b] = true;
        map[b][a] = true;
    }


    DFS(s1);
    memset(check, false, sizeof(check));
    printf("\n");
    BFS(s1);


    return 0;
}