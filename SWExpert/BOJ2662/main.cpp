#include <iostream>

using namespace std;

const int NMAX = 301;
const int MMAX = 21;

int N,M;
int ans;
int cost[NMAX]; // 각 회사에 얼마를 투자했나
int a[NMAX][MMAX];
int d[NMAX][MMAX];


int main() {

    cin >> N >> M;

    for(int i=1; i<=N; i++){
        for(int j=1; j<= M; j++){
            cin >> a[i][j];
        }
    }

    //초기상태
    for(int i=1; i<=N; i++){

        d[i][1] = a[i][1]; // 1번째 기업까지 고려, i금액을 사용했을때 최대 이익
        cost[i] = i; // i번째 기업에 얼마를 썻는지?

    }

    for(int i=2; i<=M; i++){

        for(int j=1; j<=N; j++){

            for(int k = 0; k <=j; k++){
                if( d[i][j] < d[i-1][k] + a[i][j-k]){
                    d[i][j] = d[i-1][k] + a[i][j-k];
                    cost[i]+= (j-k);
                }

            }

            if( ans < d[i][j]){
                ans = d[i][j];
            }
        }
    }

    cout<< ans <<'\n';
    for(int i=1; i<=M; i++){
        cout<<cost[i]<<" ";
    }


    return 0;
}