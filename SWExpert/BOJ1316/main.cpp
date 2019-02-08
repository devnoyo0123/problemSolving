#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int tc;
int ans = 0;
int alpha[26];

int main() {

    string str = "";
    cin >> tc;
    ans = tc;
    for(int t = 1; t<=tc; t++){
        memset(alpha, 0, sizeof(alpha));

        cin >> str;
        alpha[str[0]-'a']++;

        for(int i=0; i<str.length(); i++){
            if( i - 1 >= 0 && str[i-1] != str[i]){
               if( alpha [ str[i] - 'a'] > 0){
                   ans-=1;
                   break;
               }

               alpha[str[i] -'a']++;
            }

            if( i - 1 >= 0 && str[i-1] == str[i]){
                alpha[str[i-1]-'a']++;
            }

        }


    }

    cout<<ans<<'\n';


    return 0;
}