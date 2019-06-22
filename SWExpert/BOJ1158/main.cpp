#include <iostream>
#include <vector>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k, m;

    cin >> n >> k;
    m = k-1;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = i+1;
    }

    cout<<'<';
    while(a.size()>0){
        cout<<a[m];
        a.erase(a.begin()+m);
        if(a.size() > 0){
            m += (k-1);
            m %= a.size();
            cout<<", ";
        }
    }
    cout<<'>';

    return 0;
}