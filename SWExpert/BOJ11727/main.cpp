#include <iostream>

using namespace std;

const int MAX = 1001;

int d1[MAX];

int n;

int dp(int n){
    if( n <3){
        if( n == 1){
            d1[n] = 1;
            return d1[n];
        }else if( n == 2){
            d1[n] = 3;
            return d1[n];
        }else{
            return 0;
        }
    }

    if( d1[n] > 0){
        return d1[n];
    }

    d1[n] = dp(n-1) + 2*dp(n-2);
    d1[n] %= 10007;
    return d1[n];
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;



    cout<<dp(n)<<'\n';
//    for(int i=1; i<=n; i++){
//        cout<<d1[i]<<" ";
//    }

    return 0;
}