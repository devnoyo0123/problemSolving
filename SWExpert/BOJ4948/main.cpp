#include <iostream>

using namespace std;

const int MAX = 123457*2;

int d[MAX];
bool c[MAX];

int main(){
    int n;

    c[0]=c[1]= true;
    for(int i=2; i<MAX; i++){
        if(!c[i]){
            for(int j=i+i; j<MAX; j+=i){
                c[j] = true;
            }
        }
    }

    for(int i=1; i<MAX; i++){
        d[i] += d[i-1];
        if(!c[i]) d[i] += 1;
    }

    while(true){
        cin >> n;
        if( n == 0){
            break;
        }

        cout<<d[2*n]-d[n]<<"\n";

    }
    return 0;
}