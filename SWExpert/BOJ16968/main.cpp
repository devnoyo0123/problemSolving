#include <iostream>
#include <string>

using namespace std;

int main() {

    string a;
    int alpha = 26;
    int decimal = 10;

    cin >> a;

    int sum = 0;
    if( a[0] == 'c'){
        sum = alpha;
    }else{
        sum = decimal;
    }
    for (int i = 1; i < a.size(); i++) {

        if (a[i - 1] == a[i]) {
            if (a[i] == 'c') {
                sum *= (alpha-1);
            } else {
                sum *= (decimal-1);
            }
        } else {
            if( a[i] == 'c'){
                sum *= alpha;
            }else{
                sum *= decimal;
            }
        }

    }

    cout<<sum<<'\n';

    return 0;
}