#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

const int MAX = 10001;

string d[MAX];

string calc(string &s1, string &s2){
    int len, len2, a,b, curCarry;
    len = s1.size();
    len2 = s2.size();
    string ans ="";

//    if( len < len2){
//        for(int i=0; i< len2-len; i++){
//            ans += "0";
//        }
//        len = len2;
//        s1 = ans + s1;
//    }else{
//        for(int i=0; i< len-len2; i++){
//            ans += "0";
//        }
//        s2 = ans + s2;
//    }

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
        ans += (a + b +curCarry)%10 +'0';
        curCarry = (a + b +curCarry)/10;
    }
    if(curCarry) ans += '1';

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {

    clock_t start;
    start = clock();
    string a,b;
    cin >> a >> b;

    cout<< calc(a, b)<<'\n';
    double laps = (double)(clock()-start)/ CLOCKS_PER_SEC;
    cout<< laps<<'\n';
    return 0;
}