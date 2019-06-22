#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 10001;

string d[MAX];

string calc(string &s1, string &s2){
    int len, len2, a,b, prevCarry, curCarry;
    len = s1.size();
    len2 = s2.size();
    string ans ="";

    if( len < len2){
        for(int i=0; i< len2-len; i++){
            s1.insert(s1.begin(), '0');
        }
        len = len2;
    }else{
        for(int i=0; i< len-len2; i++){
            s2.insert(s2.begin(), '0');
        }
    }

    curCarry = 0;
    for(int i=len-1; i>=0; i--){
        a = s1[i] -'0';
        b = s2[i] -'0';

        prevCarry = curCarry;
        if( a + b +prevCarry < 10){
            ans += a + b +prevCarry +'0';
            curCarry = 0;
        }else{
            ans += (a + b +prevCarry)%10 +'0';
            curCarry = 1;

            if( curCarry == 1 && i == 0 ){
                ans += '1';
            }

        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    d[0] = "0";
    d[1] = "1";
    int n;
    cin >> n;
    for(int i=2; i<=n; i++){
        d[i] = calc(d[i-1], d[i-2]);
    }

    cout<<d[n];
    return 0;
}