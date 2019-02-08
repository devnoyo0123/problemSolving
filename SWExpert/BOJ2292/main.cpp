#include <iostream>

using namespace std;

int num;

int main() {

    cin >> num;
    if( num <= 1){
        cout<<1<<'\n';
    }else{
        int a = 2, b = 6;
        for(int i=1; ; i++){
            if( a <= num && num < (a + b*i)){
                cout<<i + 1;
                break;
            }
            a = a + b*i;
        }
    }

}