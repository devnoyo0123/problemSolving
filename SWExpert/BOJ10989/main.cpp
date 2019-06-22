#include <iostream>

using namespace std;

int cnt[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,x;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> x;
        cnt[x]++;
    }

    for(int i=0; i<=10000; i++){
        for(int j=0; j<cnt[i]; j++){
            cout<<i<<'\n';
        }
    }

    return 0;
}