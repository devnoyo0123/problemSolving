#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long x,y, dist,t;
    cin >>t;
    while(t--) {
        cin >> x >> y;
        dist = y - x;

        long long i = 1;
        while( i*i <=dist){
            i++;
        }
        i--;

        long long left = dist - i*i;
        cout<< 2*i-1 +ceil(double(left)/(double)i)<<'\n';
    }





    return 0;
}