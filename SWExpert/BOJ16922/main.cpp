#include <iostream>

using namespace std;

const int MAX = 50*20+1;

bool check[MAX];

int main() {

    int n;
    cin >> n;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n-i; j++){
            for(int k = 0; k<=n-i-j; k++){
                int l = n - k - j - i ;
                int sum = i + 5*j + 10*k + 50*l;
                check[sum] = true;
            }
        }
    }

    int ans =0;
    for(int i=1; i<=50*20; i++){
        if( check[i]) ans += 1;
    }
    cout<< ans<<'\n';
    return 0;
}