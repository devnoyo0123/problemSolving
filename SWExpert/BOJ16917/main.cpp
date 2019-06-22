#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int a,b,c,x,y;

    cin >> a >> b>> c >> x >> y;

    int minCost = a*x+b*y;

    for(int i=1; i<=100000; i++){
        if(  minCost > 2*i*c + max(0, x-i)*a + max(0, y-i)*b){
            minCost = 2*i*c + max(0, x-i)*a + max(0, y-i)*b;
        }
    }

    cout<< minCost;

    return 0;
}