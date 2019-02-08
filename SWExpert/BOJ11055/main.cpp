#include <iostream>

using namespace std;

const int MAX = 1001;

int n, ans;
int val[MAX];
int d[MAX];

int main(){

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> val[i];
    }

    for(int i=1; i<=n; i++){
        d[i] = val[i];
        for(int j=1; j<i; j++){
            if( val[i] > val[j] && d[i] < d[j] + val[i]){
                d[i] = d[j] + val[i];

            }
        }
        if( ans < d[i]){
            ans = d[i];
        }
    }

    cout<<ans<<'\n';

    return 0;
}