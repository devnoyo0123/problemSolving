#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n1, ans = 0;

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    if( a.second == b.second){
        return a.first < b.first;
    }else{
        return a.second < b.second;
    }
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(0);

    cin >> n1;
    vector<pair<int, int> > v1(n1);
    for(int i=0; i< n1; i++){
        cin >> v1[i].first >> v1[i].second;
    }

    sort(v1.begin(), v1.end(), cmp);

    int start = v1[0].second;
    ans+=1;
    for (int j = 1; j < v1.size(); ++j) {
        if( start <= v1[j].first){
            start = v1[j].second;
            ans+=1;
        }
    }

    cout<<ans<<'\n';

    return 0;
}