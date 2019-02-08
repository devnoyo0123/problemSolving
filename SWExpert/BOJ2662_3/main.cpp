#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

const int NMAX = 301;
const int MMAX = 21;

int a[NMAX][MMAX];
int d[NMAX][MMAX];
int from[NMAX][MMAX];


int N, M;

void f(int x, int y) { // x : 투자한 금액, y: 회사 번호
    if (!y) return;
    f(from[x][y], y - 1);
    cout<<x - from[x][y]<<" ";
}

int main() {

    stack<int>st;

    cin >> N >> M;
    int temp ;
    for(int i=1; i<=N; i++){
        for(int j=0; j<=M; j++){
            cin >> a[i][j];
        }
    }

//    for(int i=1; i<=N; i++){
//        for(int j=1; j<=M; j++){
//            cout << a[i][j]<<" ";
//        }
//        cout<<'\n';
//    }

    for(int i=1; i<=N; i++){ //사용한 금액
        for(int j=1; j<=M; j++){ // 살펴본 회사
            for(int k=0; k<=i; k++){ // i-k : 쓰고 남은 돈을 표현하기 위한 변수
                if( d[i][j] < d[i-k][j-1] + a[k][j]){
                    d[i][j] = d[i-k][j-1] + a[k][j];
                    from[i][j] = i-k; //이 전에 최대로 투자한 금액
                }

            }

        }
    }

    cout<<d[N][M]<<'\n';

//    for(int i=1; i<=N; i++){
//        for(int j=1; j<=M; j++){
//            cout << d[i][j]<<" ";
//        }
//        cout<<'\n';
//    }

    f(N,M);

    return 0;
}