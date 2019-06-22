#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int a[500000];
int cnt[8001];

int main() {

    int n;
    int sum= 0;
    int max= 0;
    int maxIdx = 0;
    bool ok = false;
    cin >>n;
    for(int i=0; i<n; i++){
        cin >> a[i];
        sum+=a[i];
        cnt[a[i]+4000]++;
    }

    sort(a, a+n);

    for(int i=0; i<8001; i++){
        if( max < cnt[i]){
            max = cnt[i];
            maxIdx = i-4000;
            ok = true;
        } else if(max == cnt[i] && ok){
            maxIdx = i-4000;
            ok = false;
        }
    }
    cout<< round((double)sum/(double)n) <<'\n';
    cout<< a[n/2]<<'\n';
    cout<< maxIdx<<'\n';
    cout<<a[n-1] - a[0]<<'\n';
    return 0;
}