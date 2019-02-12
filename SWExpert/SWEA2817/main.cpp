#include <iostream>

using namespace std;

#define MAX 1000

int tc, n, k, ans;

int data[MAX];

void solve(int idx, int sum){
    if( idx == n){

        if( sum == k ){
            ans++;
        }
        return;
    }


    // 뽑는다
    solve(idx+ 1, sum + data[idx]);
    // 안 뽑는다.
    solve(idx + 1, sum);
}

int main() {

    cin >> tc;

    for(int t = 1; t<=tc; t++){
        ans = 0;
        cin >> n >> k;


        for(int i=0; i< n; i++){
            cin >> data[i];
        }

        solve(0, 0);

        cout<<"#"<<t<<" "<<ans<<'\n';
    }





    return 0;
}