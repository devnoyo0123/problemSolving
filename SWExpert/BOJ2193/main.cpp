#include <iostream>

using namespace std;

const int MAX = 91;

long long d1[MAX][2]; // n번째 [0]으로 끝난 이친수 개수, [1]으로 끝난 이친수 개수

int n1;



int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n1;

    d1[1][1] = 1;
    d1[2][0] = 1;
    for(int i=3; i<=n1; i++){
        d1[i][0] = d1[i-1][0] + d1[i-1][1];
        d1[i][1] = d1[i-1][0];
    }

//    for(int i=1; i<=n1; i++){
//        cout<<"d1["<<i<<"][0]:"<<d1[i][0]<<" d1["<<i<<"][1]:"<<d1[i][1]<<'\n';
//    }

    cout<< d1[n1][0] + d1[n1][1];


    return 0;
}