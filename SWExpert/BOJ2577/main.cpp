#include <iostream>

using namespace std;

const int MAX = 11;


int A,B,C;
int a[MAX];

int main() {

    cin >>A >>B >> C;

    int sum = A*B*C;

    while(sum >0){
        int tmp = sum%10;
        a[tmp]++;
        sum/=10;
    }
    cout<<a[0]<<'\n';
    for (int i = 1; i <10; ++i) {
        cout<<a[i]<<'\n';
    }
    return 0;
}