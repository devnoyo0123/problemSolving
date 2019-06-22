#include <iostream>
#include <cmath>

using namespace std;
int cnt[10];
int main() {
    int n;
    cin >>n;
    int temp =n;
    while(temp){
        cnt[temp%10]+=1;
        temp/=10;
    }

    int minCnt = -1;

    for(int i=0; i<9; i++){
        if( i == 6 || cnt[i] == 0) continue;
        if( minCnt == -1 || minCnt > cnt[i]){
            minCnt = cnt[i];
        }

    }

    if( minCnt > (int)ceil(double(cnt[6] + cnt[9])/double(2)) && (int)ceil(double(cnt[6] + cnt[9])/double(2)) > 0){
        cout<< ceil(double(cnt[6] + cnt[9])/double(2));
    }else{
        cout<< minCnt;
    }


    return 0;
}