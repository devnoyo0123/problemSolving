#include <iostream>

using namespace std;

const int MAX = 1000001;

int d1[MAX];

int n1;

int dp(int n){
    // n을 1로 만드는 최소 연산수
    if( n < 2){

        if( n == 1){
            d1[n] = 0;
            return d1[n];
        }

        d1[n] = 0;
        return d1[n];

    }

    if( d1[n] != MAX){
        return d1[n];
    }


    int temp = dp(n-1) + 1;
    if( d1[n] > temp){
        d1[n] = temp;
    }



    if( n % 2 == 0){
        temp = dp(n/2) + 1;
        if( d1[n] > temp){
            d1[n] = temp;
        }
    }

    if( n % 3 == 0){
        temp = dp(n/3) + 1;
        if( d1[n] > temp){
            d1[n] = temp;
        }
    }


    return d1[n];
}

int main() {

    fill(d1, d1+MAX, MAX);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n1;

    cout<<dp(n1)<<'\n';
//    for(int i=1; i<=n1; i++){
//        cout<<d1[i]<<" ";
//    }

    return 0;
}