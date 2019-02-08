#include <iostream>

using namespace std;

int main() {
    int a,b;

    cin >> a >> b;

    int temp, c=0, d=0;
    temp = a;

    while (temp > 0){
        c += temp % 10;
        temp /=10;
        c *= 10;
    }
    c/=10;
    temp = b;
    while (temp > 0){
        d += temp % 10;
        temp /=10;
        d *= 10;
    }
    d/=10;

    cout<< (c > d ? c : d);
    return 0;
}