#include <iostream>

using namespace std;

const int MAX = 1000001;

bool c[MAX]; // false :  소수, true: 소수가 아니다

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int m,n;
    cin >> m >> n;

    c[0] = c[1] = true;
    for(int i=2; i<=n; i++){
        for(int j=i*2; j<=n; j+=i){
            c[j] = true;
        }
    }

    for(int i=m; i<=n; i++){
        if(!c[i])
            cout<<i<<'\n';
    }
    return 0;
}