#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> d(n+1);
    d[0] = 2;
    for(int i=1; i<=n; i++){
        d[i] = 2*d[i-1]-1;
    }

    cout<<d[n]*d[n];
    return 0;
}