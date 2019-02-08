#include <iostream>

using namespace std;

int n,s,ans;
int arr[20];

void go(int idx, int size, int cur, int length){
    if( idx >= size){
        if( cur == s && length != 0){
            ans++;
        }
        return;
    }
    go(idx+1, size, cur+arr[idx] ,length+1);

    go(idx+1, size, cur, length);
}

int main() {

    cin >> n >> s;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    go(0, n, 0, 0);
    cout<<ans<<'\n';
    return 0;
}