#include <iostream>

const int MAX = 1000;

using namespace std;

int a[MAX];

int main() {

    int n, k;

    cin >> n >> k;

    for(int i=1; i<=n; i++){
        cin >> a[i];
    }

    int ans = -1;
    for(int i = 1; i<=1000; i++){
        int cnt = 0;
        for(int j=1; j<=n; j++){
            if( a[j] != i*j*k){
                cnt +=1;
            }
        }
        if( ans == -1 || ans > cnt){
            ans = cnt;
        }
    }

    cout<<ans<<'\n';

    return 0;
}