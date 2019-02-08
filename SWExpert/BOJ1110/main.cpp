#include <iostream>

using namespace std;

int n, cnt, temp, sum, ten;

int main() {


    cin >> n;
    temp = n;

    while(true){

        sum = 0;

        ten = (temp%10);
        temp/=10;
        sum += ten;
        sum += temp%10;

        cnt++;



        temp = ten*10+sum%10;

        if( temp == n){
            break;
        }
    }


    cout<<cnt<<'\n';

    return 0;
}