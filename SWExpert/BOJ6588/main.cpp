#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX = 100000;
bool c[MAX];
int primes[MAX+1];
int pn;

int main() {

    ios_base::sync_with_stdio(false);
    cout.tie(0);

    c[0] = c[1] = true;
    for(int i =2; i<=MAX; i++){
        if(!c[i])
            primes[pn++] = i;
        for(int j=i*2; j<=MAX; j+=i){
            c[j] = true;

        }
    }


    int n;
    while(1){
        cin >> n;
        if( n == 0){
            break;
        }
        bool ok = false;
        for(int i=1; i< pn; i++){
            if( !c[n-primes[i]] ){
                ok = true;
                cout << n << " = " << primes[i] << " + " << n - primes[i] << '\n';
                break;
            }
        }

        if(!ok){
            cout<<"Goldbach's conjecture is wrong.\n";
        }


    }

    return 0;
}