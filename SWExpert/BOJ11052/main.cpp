#include <iostream>

using namespace std;

const int MAX = 1001;

int n1;
int p[MAX];
int d1[MAX]; // i개의 카드를 판매했을 때 최대 수익

int dp(int n){
    // n개를 판매했을 때 최대 수익을 반환하는 함수
    if( n == 0){
        return 0;
    }

    if( d1[n] > 0){
        return d1[n];
    }

    int max = 0;
    for(int i=1; i<=n; i++){
        int temp = dp(n-i) + p[i];
        if( temp > max) {
            max = temp;
        }
    }
    d1[n] = max;
    return d1[n];
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n1;

    for(int i = 1; i<= n1; i++){
        cin >> p[i];
    }

    int ans = dp(n1);
//    for(int i=1; i<=n1; i++){
//        cout<<"d["<<i<<"]:"<<d1[i]<<'\n';
//    }
    cout<<ans<<'\n';

    return 0;
}