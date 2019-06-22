#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 10001;

bool c[MAX];

int main(){

    c[0] = c[1] = true;
    for(int i=2; i<MAX; i++){
        if(!c[i]){
            for(int j=i+i; j<MAX; j+=i){
                c[j] = true;
            }
        }
    }

    int t,x;
    cin >> t;

    while(t--){
        cin >> x;
        vector<pair<int, int> > v;
        int i,j;
        for( i = j = x/2; i < x; i++, j--){
            if(!c[i] && !c[j]){
                cout<<j<<" "<<i<<'\n';
                break;
            }
        }


    }

    return 0;
}