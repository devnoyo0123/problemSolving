#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 300;

int N, M, R;

int a[MAX][MAX];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> R;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> a[i][j];
        }
    }

    //그룹짓기
    vector<vector<int> > groups;
    int groupn = min(N, M)/2;
    for(int k = 0; k< groupn; k++){
        vector<int> group;
        for(int j=k; j<M-k; j++){
            group.push_back(a[k][j]);
        }

        for(int i=k+1; i<N-(k+1); i++){
            group.push_back(a[i][M-(k+1)]);
        }

        for(int j = M-(k+ 1); j >k ; j--){
            group.push_back(a[N-(k+1)][j]);
        }

        for(int i = N-(k+1); i > k ; i--){
            group.push_back(a[i][k]);
        }

        groups.push_back(group);
    }

    //회전시키기
    for(int k = 0; k< groupn; k++){
        vector<int> &group = groups[k]; // 꼭 reference로! 데이터 복사 시간 줄어듬
        int len = group.size();
        int idx = R % len;

        for(int j = k; j< M-k; j++, idx = (idx+1) % len){
            a[k][j] = group[idx];
        }

        for(int i = k+1; i < N-(k+1); i++, idx = (idx+1) % len){
            a[i][M-(k+1)] = group[idx];
        }

        for(int j = M-(k+1); j>k; j--, idx = (idx+1) % len){
            a[N-(k+1)][j] = group[idx];
        }

        for(int i = N-(k+1); i>k; i--, idx = (idx+1) % len){
            a[i][k] = group[idx];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout<< a[i][j]<<" ";
        }
        cout<<'\n';
    }




    return 0;
}