#include <cstdio>

using namespace std;

const int MAX = 1000000;

int n,m;

int a[MAX];
int b[MAX];
int c[MAX];

int aInx, bInx, cInx;

int main() {

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    for (int j = 0; j < m; ++j) {
        scanf("%d", &b[j]);
    }

    while( aInx < n && bInx < m ){
        if( a[aInx] >= b[bInx] ){
            c[cInx++] = b[bInx++];
        }else{
            c[cInx++] = a[aInx++];
        }

    }
    while(bInx < m){
        c[cInx++] = b[bInx++];
    }

    while(aInx < n){
        c[cInx++] = a[aInx++];
    }

    for (int k = 0; k < cInx; ++k) {
        printf("%d ", c[k]);
    }

    return 0;
}