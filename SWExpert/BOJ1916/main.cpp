#include <iostream>
#include <vector>
#include <queue>


using namespace std;

const int MAX = 1001;

vector<pair<int, int> > cities[MAX];
int dist[MAX];

int N, M;

void BFS(int start){
    queue<int> qu;
    dist[start] = 0;
    qu.push(start);

    while(!qu.empty()){
        int temp = qu.front(); qu.pop();

        for(int i=0; i<cities[temp].size(); i++){
            int nextNode = cities[temp][i].first;
            int val = cities[temp][i].second;

            if(dist[nextNode] > dist[temp] + val){
                dist[nextNode] = dist[temp] +val;
                qu.push(nextNode);
            }
        }
    }
}

int main() {


    cin >> N >> M;
    for(int i=0; i<=N; i++){
        dist[i] = 987654321;
    }
    int a,b,c,start,end;
    for(int i=0; i<M; i++){
        cin >> a >> b >> c;
        cities[a].push_back({b,c});
    }
    cin >> start >> end;
    BFS(start);
    cout<<dist[end]<<'\n';
    return 0;
}