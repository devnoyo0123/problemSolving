#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n1, ans=0;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n1;
    vector<int> v1(n1);
    for(int i=0; i< n1; i++){
        cin >> v1[i];
    }

    sort(v1.begin(), v1.end());

    int size = v1.size();
    for(int i=0; i<size; i++){
        for(int j=0; j<=i; j++){
            ans += v1[j];
        }
    }

    cout<<ans<<'\n';


    return 0;
}