#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 13;

int TC;
int DAYFEE, MONTHFEE, THREEMONTHSFEE, YEARFEE;
int fees[MAX];
int ans = 987654321;

void go(int inx, int sum){

    if( inx >= 13){
        if( ans > sum){
            ans = sum;
        }
        return;
    }

    if( fees[inx] > 0){

        go(inx + 1, sum + fees[inx]*DAYFEE);
        go(inx + 1, sum + MONTHFEE);
        go(inx + 3, sum + THREEMONTHSFEE);
        go(inx + 12, sum + YEARFEE);

    }else{

        go(inx+1, sum);

    }
}

int main() {

    cin >> TC;
    for(int T = 1; T<= TC; T++){
        cin >> DAYFEE >> MONTHFEE >> THREEMONTHSFEE >> YEARFEE;
        memset(fees,0, sizeof(fees));
        ans = 987654321;
        for (int i = 1; i <= 12; ++i) {
            cin >> fees[i];
        }

        go(1,0);
        cout<<"#"<<T<<" "<<ans<<"\n";
    }
    return 0;
}