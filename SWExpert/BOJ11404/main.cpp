#include <iostream>

using namespace std;
const int MAX = 101;

int N, M;
int dist[MAX][MAX]; // i에서 j로 가는 최소 비용

int main() {

    cin >> N >> M;

    // 최소 비용 초기화

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){

        }
    }


    int start,end,cost;
    for(int i=0; i<N; i++){
        cin >> start >> end >> cost;
        dist[start][end] = dist[start][end] > cost ? cost : dist[start][end];
    }

    return 0;
}