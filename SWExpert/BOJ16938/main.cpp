#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = (int)1e6;

int a[MAX];
bool c[MAX];
int N,L,R,X;

int go(int cnt, int idx){
    if( idx == N){
        int sum = 0;
        int _max,_min;
        _max = _min = -1;
        for(int i=0; i<idx; i++){
            if(c[i]){
                sum += a[i];
                if( _max == -1 || _max < a[i]){
                    _max = a[i];
                }
                if(_min == -1 || _min > a[i]){
                    _min = a[i];
                }
            }
        }

        if( cnt >=2 && sum >= L && sum <= R && _max - _min >= X )
            return 1;
        else
            return 0;
    }
    int ans = 0;
    c[idx] = true;
    ans += go(cnt+1, idx+1);
    c[idx] = false;
    ans += go(cnt, idx+1);

    return ans;
}

int main() {

    cin >> N >> L >> R >> X;

    for(int i=0; i<N; i++){
        cin >> a[i];
    }

    cout<< go(0,0)<<'\n';

    return 0;
}