#include <iostream>

using namespace std;

const int MAX = 10004;

long long d1[MAX][3]; //[0]; 0번 연속 포도주, 1번 연속 포도주, 2번 연속 포도주
int val[MAX];
int n1;

int main() {


    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n1;
    for(int i=1; i<=n1; i++){
        cin >> val[i];
    }

    d1[1][0] = 0;
    d1[1][1] = val[1];
    d1[1][2] = 0;



    for(int i=2; i<=n1; i++){
        d1[i][0] = max(max(d1[i-1][0], d1[i-1][1]), d1[i-1][2]);
        d1[i][1] = d1[i-1][0] + val[i];
        d1[i][2] = d1[i-1][1] + val[i];
    }

    long long  max = d1[n1][0];
    for(int i=1; i<3; i++){

        if( max < d1[n1][i]){
            max = d1[n1][i];
        }

    }

    cout<<max<<'\n';

//    for(int i=0; i<3; i++){
//        cout<<d1[n1][i]<<" ";
//    }
    return 0;
}