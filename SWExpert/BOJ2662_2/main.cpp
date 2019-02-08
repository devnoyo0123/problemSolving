#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

const int NMAX = 301;
const int MMAX = 21;

int a[NMAX][MMAX];
int d[NMAX][MMAX];
int from[NMAX][MMAX];

int ans;
int N, M;


int main() {

    stack<int>st;

    cin >> N >> M;
    int temp ;
    for(int i=1; i<=N; i++){
        for(int j=0; j<=M; j++){
            cin >> a[i][j];
        }
    }

    for(int i=1; i<=N; i++){
        d[i][1] = a[i][1];
    }

//    for(int i=1; i<=N; i++){
//        for(int j=1; j<=M; j++){
//            cout << a[i][j]<<" ";
//        }
//        cout<<'\n';
//    }

    for(int i=2; i<=N; i++){
        for(int j=1; j<=M; j++){
            int tempMax = 0;
            for(int k=1; k<j; k++){


                if( tempMax < d[i][k] + a[N-i][j]){
                    from[i][j] = k;
                    tempMax = d[i][k] + a[N-i][j];
                }

                if( tempMax < d[i][j-1]){
                    tempMax = d[i][j-1];
                    from[i][j] = j-1;
                }

                if( tempMax < a[i][j]){
                    tempMax = a[i][j];
                    from[i][j] = 0;
                }

            }
            d[i][j] = tempMax;
        }
    }

    cout<<d[N][M]<<'\n';

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cout << d[i][j]<<" ";
        }
        cout<<'\n';
    }

    return 0;
}