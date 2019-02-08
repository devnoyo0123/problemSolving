#include <iostream>

using namespace std;

const int MAX = 1001;

int n, mod = 10007;
int d[MAX][10];



int main() {

    cin >> n;

    for(int i=0; i<10; i++){
        d[1][i] = 1;
    }

    //d[i][j] 수의길이가 i이고, 오른쪽에서 첫번째 숫자가 j인 오르막 수
    for(int i=2; i<=n; i++){
        for(int j=0; j<10; j++){
            for(int k=0; k<=j; k++){
                d[i][j] += d[i-1][k];
                d[i][j] %= mod;
            }
        }
    }

    int ans = 0;
    for(int i=0; i<10; i++){
        ans += d[n][i];
    }

    cout<<ans%mod<<'\n';

    return 0;
}