#include <iostream>

using namespace std;

int N, ans;

void solve(){





    for (int i = N; i >=5; --i) {

        int cnt = 0;
        if( i % 5 == 0){
            cnt +=  i/5;


            if( i == N){
                ans = cnt;
                return;
            }

            int a = N - i;

            if( a % 3 == 0){
                cnt+= a/3;
                ans = cnt;
                return;
            }
        }

    }


    if( N % 3 == 0){
        ans = N/3;
        return;
    }

    ans = -1;


}

int main() {
    
    cin >> N;

    solve();

    cout<<ans<<'\n';
    
    return 0;
}