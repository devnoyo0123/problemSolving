#include <iostream>
#include <algorithm>

using namespace std;

const int PMAX = 10001;
const int NMAX = 1001;

int N;
int p[PMAX];
int d[NMAX];


int main() {

    cin>> N;

    for(int i=1; i<=N; i++){
        cin >> p[i];
    }

    for(int i=1; i<=N; i++){
        d[i] = -1;
        for(int j=1; j<=i; j++){
            if( d[i] == -1 || d[i] > d[i-j]+p[j])
                d[i] = d[i-j]+p[j];
        }
    }

    cout<<d[N];


    return 0;
}