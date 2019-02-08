#include <iostream>

using namespace std;

int n,m,k;

int main() {
    int count = 0;
    cin >> n >> m >> k;

    while(true){

        n-=2;
        m-=1;

        if( n + m <=k){
            break;
        }
        count++;
    }

    cout<<count;
    return 0;
}