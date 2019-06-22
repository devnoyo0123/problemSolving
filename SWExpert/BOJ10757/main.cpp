#include <iostream>
#include <algorithm>

using namespace std;


int main() {

    string a,b;
    cin >> a >> b;

    string ans = "";
    int len,len2;
    len = a.size();
    len2 = b.size();

    string temp = "";
    if( len < len2){
        len = len2;

        for(int i=0; i<len2-len; i++){
            temp += '0';
        }
        a = temp + a;
    }else{
        for(int i=0; i<len-len2; i++){
            temp += '0';
        }
        b = temp + b;
    }

    int carry,d1,d2;
    carry = 0; // 올림수 발생안함
    for(int i=len-1; i>=0; i--){

        d1 = a[i]-'0';
        d2 = b[i]-'0';

        ans += (d1 + d2 + carry)%10 +'0';
        carry = (d1 + d2 + carry)/10;
    }

    if(carry){
        ans += '1';
    }

    reverse(ans.begin(), ans.end());
    cout<<ans;
    return 0;
}
