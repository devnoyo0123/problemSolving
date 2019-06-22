#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b){
    while(b > 0){
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main() {

    int t;
    cin >> t;

    for(int i=0; i<t; i++){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int j=0; j<n; j++){
            cin >> a[j];
        }

        int tmp = a[0];
        for(int j=1; j<n; j++){
            tmp = gcd(tmp, a[j]);
        }
        cout<<tmp<<'\n';
    }

    return 0;
}