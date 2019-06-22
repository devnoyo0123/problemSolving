#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000;

int d[MAX][MAX];
int N, T, M, A, B;

int near(vector<int> &s, int start){
    int ans = -1;
    int where = -1;
    for(int i = 0; i< N; i++){
        if( s[i] == 0) continue;
        if( ans == -1 || ans  > d[start][i]){
            ans = d[start][i];
            where = i;
        }
    }
    return where;
}

int calc(vector<int> &s, int a, int b){
    int ans = d[a][b];
    if( s[a] == 1 && s[b] == 1){
        if( ans > T) ans = T;
    }

    int _a = near(s,a);
    int _b = near(s,b);
    if( _a != -1 && _b != -1 ){
        int temp = d[a][_a] + T +  d[_b][b];
        if( ans > temp) ans = temp;
    }

    return ans;

}

int getDist(vector<int> &x, vector<int> &y, int a, int b){
    int l1 = x[a] - x[b];
    int l2 = y[a] - y[b];
    if( l1 < 0) l1 = -l1;
    if( l2 < 0) l2 = -l2;
    return l1 + l2;
}

int main() {


    cin >> N >> T;
    vector<int> s(N), x(N), y(N);
    for(int i=0; i<N; i++){
        cin >> s[i] >> x[i]>> y[i];
    }

    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            d[i][j] = d[j][i] = getDist(x,y,i,j);
        }
    }


    cin >> M;
    for(int i=0; i < M; i++){
        cin >> A >> B;

        cout<< calc(s,A-1,B-1)<<'\n';
    }

    return 0;
}