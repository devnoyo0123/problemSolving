#include <iostream>
#include <algorithm>

using namespace std;

int alpha[26];

int main(){

    fill(alpha, alpha+sizeof(alpha), -1);

    string str= "";
    cin >> str;

    for(int i=0; i<str.length(); i++){
        int inx = str[i]-'a';
        if(alpha[inx] < 0){
            alpha[inx]=i;
        }

    }

    for(int i='a'; i<='z'; i++){
        cout<<alpha[i-'a']<<" ";
    }



    return 0;
}