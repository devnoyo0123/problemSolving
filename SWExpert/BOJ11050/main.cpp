//이항계수를 재귀함수를 통해 구하기

#include <iostream>


using namespace std;

const int MAX = 1001;

int arr[MAX][MAX];

int go(int n, int k){

    if( arr[n][k] > 0){
        return arr[n][k];
    }

    if(n == k){
        arr[n][k] = 1;
        return 1;
    }

    if(k == 0){
        arr[n][k] = 1;
        return 1;
    }
    arr[n][k] = go(n-1, k-1) + go(n-1, k);
    arr[n][k] %= 10007;
    return arr[n][k];
}

int main() {

    int n,k;
    cin >> n >> k;
    cout<<go(n,k)<<'\n';
    return 0;
}