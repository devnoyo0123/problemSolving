#include <iostream>
#include <string>

using namespace std;
int j;

int main() {

    string s = "";

    string ans = "";

    cin >> s;

    if( s.size() == 1 && s[0] == '0'){
        cout<< 0;
        return 0;
    }

    for (int i = 0; i < s.size(); ++i) {
        int temp = s[i]-'0'; j=2;
        char ch[4] = {0};
        while(j>=0){
            ch[j--] = temp % 2 + '0';
            temp/=2;
        }
        ans += ch;
    }

    if( ans[0] == '0' && ans[1] != '0'){
        ans.erase(0,1);
    }else if(ans[0] == '0' && ans[1] == '0' && ans[2] != '0'){
        ans.erase(0,2);
    }else if(ans[0]== '0' && ans[1] == '0' && ans[2] == '0'){
        ans.erase(0,3);
    }

    cout<< ans;


    return 0;
}