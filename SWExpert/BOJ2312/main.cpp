#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100001;

bool prime[MAX]; //false: 소수
void solve(int x, vector<pair<int, int> > &pn){
    int idx = 0;
    while(idx< pn.size()){
        if( x % pn[idx].first == 0 ){
            x/=pn[idx].first;
            pn[idx].second++;
        }else{
            idx++;
        }
    }

    sort(pn.begin(), pn.end());
    for(int i=0; i<pn.size(); i++){
        if( pn[i].second>0){
            cout<< pn[i].first <<" "<< pn[i].second<<'\n';
        }
    }
}

int main() {

    vector<pair<int, int> > pn;
    prime[0] = prime[1] = true;
    for(int i=2; i<MAX;i++){
        if(!prime[i]){
            pn.push_back({i,0});
            for(int j=i+i; j<MAX; j+=i){
                prime[j] = true;
            }
        }
    }

    int n,x;
    cin >> n;
    while(n--){
        cin >> x;
        for(int i=0; i<pn.size();i++){
            pn[i].second = 0;
        }
        solve(x, pn);
    }

    return 0;
}