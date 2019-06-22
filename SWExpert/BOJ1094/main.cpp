#include <iostream>

using namespace std;

int main() {

    int x, n=64, cnt = 0;
    cin >> x;
    while(x){
        if( x >= n ){
            x -=n;
            cnt++;
        }
        n/=2;
    }
    cout<<cnt<<'\n';
    return 0;
}