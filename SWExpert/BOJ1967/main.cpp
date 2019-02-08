#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 10010;

int dist[MAX];
vector<pair<int, int> > list[MAX];


int n1, ans, max1, maxInx;

void BFS(int startNode) {
    queue<int> Q;
    dist[startNode] = 0;
    Q.push(startNode);

    while (!Q.empty()) {
        int node = Q.front();
        Q.pop();


        for (int i = 0; i < list[node].size(); ++i) {
            //list[node][i].first node노드에서 연결된 i번째 노드 번호
            //list[node][i].second i번째 노드와 연결된 가중치
            if ( dist[list[node][i].first] == 0) {
                dist[list[node][i].first] = dist[node]  +  list[node][i].second;
                Q.push({list[node][i].first});
            }
        }
    }
}

int main() {

    scanf("%d", &n1);
    int p, a, val;

    for (int i = 1; i < n1; ++i) {
        scanf("%d %d %d", &p, &a, &val);
        list[p].push_back({a,val}); // 노드번호, 가중치
        list[a].push_back({p,val});
    }

    memset(dist, false, sizeof(dist));
    BFS(1);

    for (int j = 1; j <= n1 ; ++j) {
        if( max1 < dist[j]){
//            printf("maxval: %d, maxInx: %d\n", dist[j], j);
            max1 = dist[j];
            maxInx = j;
        }
    }
    memset(dist, false, sizeof(dist));

    BFS(maxInx);
    for (int k = 1; k <= n1 ; ++k) {
        if( ans < dist[k]){
            ans = dist[k];
        }
    }
    printf("%d\n", ans);

    return 0;
}

