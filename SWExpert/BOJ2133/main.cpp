#include <iostream>


using namespace std;

int n;
int dp[31][8]; // n제한 31, 3*n 타일링 i열에서 봤을때 상태를 0~7 8가지로 나누었음.
//dp[i][j]: i 열에서 j 상태일때 3*n 크기를 타일로 채운 경우의수


int main() {

    cin >> n;

    dp[0][0] = 1; // 식을 계산하지 못하는 초기값 정하기

    for(int i=1; i<=n; i++){
        dp[i][1] += dp[i-1][6];

        dp[i][2] += dp[i-1][5];

        dp[i][3] += dp[i-1][4];
        dp[i][3] += dp[i-1][0];

        dp[i][4] += dp[i-1][3];

        dp[i][5] += dp[i-1][2];

        dp[i][6] += dp[i-1][1];
        dp[i][6] += dp[i-1][0];

        dp[i-1][7] += dp[i][1];
        dp[i-1][7] += dp[i][4];

        dp[i][0] += dp[i-1][7];

        if( i-2 >=0){
            dp[i][0] += dp[i-2][0];
        }
    }

    cout<<dp[n][0];



    return 0;
}