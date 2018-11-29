#include <iostream>

using namespace std;

const int MAX = 10001;

bool check[MAX];

void d(int num){

    if( num > 10000){
        return;
    }

    int tmp = num;
    int tmp2 = tmp;
    while(tmp > 0){
        tmp2 += tmp%10;
        tmp/=10;
    }

    check[tmp2] = true;
    d(tmp2);
}

int main() {

    for (int i = 1; i < MAX ; ++i) {

        if(check[i]){
            continue;
        }else{
            cout<<i<<'\n';
            d(i);
        }
    }

    return 0;
}