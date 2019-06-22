#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 100000;
pair<int, int> pos[MAX];

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> pos[i].first >> pos[i].second;
    }

    sort(pos, pos+n);
    for(int i=0; i<n; i++){
        cout<< pos[i].first <<" "<<pos[i].second<<'\n';
    }
    return 0;
}