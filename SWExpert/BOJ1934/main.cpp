#include <iostream>

using namespace std;

int gcd(int a, int b){
    if( b == 0) return a;
    return gcd(b, a%b);
}

int main() {

    int t,a,b;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> a >> b;
        cout<< a*b/gcd(a,b)<<'\n';
    }


    return 0;
}