#include <iostream>
#include <cstdio>

using namespace std;

int n,m;
bool check[1000000];



int main() {

    check[0] = check[1] = true;

    for (int i = 2; i*i <= 1000000 ; ++i) {
        if(!check[i]){

            for (int j = i+i; j <=1000000 ; j+=i) {
                check[j] = true;
            }
        }
    }

    cin >> n >> m;

    for (int k = n; k <= m ; ++k) {
        if(!check[k]){
            printf("%d\n", k);
        }
    }


    return 0;
}