#include <iostream>

using namespace std;

const int MAX = 10001;
const int NMAX = 100;

int n1, k1;

int d1[MAX];
int val[NMAX];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n1 >> k1;

    for(int i=0; i<n1; i++){
        cin >> val[i];
    }

    for(int i=1; i<=k1; i++){
        int temp = 987654321;
        for(int j =0; j<n1;j++){
            if( i-val[j]>= 0){
                if( temp > (d1[i-val[j]] + 1)){
                    temp = d1[i-val[j]] + 1;
                }
            }
        }
        d1[i] = temp;

    }

    int ans = d1[k1] == 987654321 ? -1 : d1[k1];
    cout<<ans<<'\n';

    return 0;
}