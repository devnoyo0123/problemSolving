#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    if( n < 2){
        cout<<0<<'\n';
        return 0;
    }

    int ans = -1;
    for(int d1 = -1; d1<=1; d1++){
        for(int d2 = -1; d2<=1; d2++){

            int diff = (a[1] + d2)- (a[0] + d1);
            int cnt = 0;
            if( d1 != 0) cnt += 1;
            if( d2 != 0) cnt += 1;

            bool ok = true;
            int an = a[1] + d2;
            for(int i= 2; i<n; i++){
                an += diff;
                if( a[i] == an){
                    continue;
                }else if( a[i] == an-1 ){
                    cnt++;
                }else if(a[i] == an+1){
                    cnt++;
                }else{
                    ok = false;
                    break;
                }
            }
            if(ok){
                if( ans == -1  || ans > cnt){
                    ans = cnt;
                }
            }

        }
    }

    cout<< ans<<'\n';
    return 0;
}