#include <iostream>

using namespace std;

int c[42];

int main() {

    int a,cnt= 0;

    for(int i=0; i<10; i++){
        cin>> a;
        c[a%42] = true;
    }

    for (int j = 0; j < 42; ++j) {
        if(c[j]){
            cnt++;
        }
    }
    cout<<cnt;

    return 0;
}