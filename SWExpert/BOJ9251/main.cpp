#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int d[1004][1004];

int main(){

    string a,b;

    cin >> a >> b;

    int row = a.length();
    int col = b.length();



    for(int i=1; i<=row; i++){
        for(int j=1; j<=col; j++){
            if( a[i-1] == b[j-1]){
                d[i][j] = d[i-1][j-1] + 1;
            }else{
                d[i][j] = max(d[i][j-1], d[i-1][j]);
            }
        }
    }


    cout<<d[row][col];


    return 0;
}
