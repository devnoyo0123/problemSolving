#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int arr[26];

int main() {

    string str;

    cin >> str;

    for(char ch : str){
        if( ch >= 'a' && ch <= 'z'){
            arr[ch-'a']++;
        }

        if( ch >= 'A' && ch <= 'Z'){
            arr[ch-'A']++;
        }
    }

    int max = 0;
    int maxIdx = 0;
    int cnt = 0;

    for(int i=0; i<26; i++){
        if( arr[i] > max){
            max = arr[i];
            maxIdx = i;
        }
    }

    for(int i=0; i<26; i++){
        if( max == arr[i]){
            cnt++;
        }
    }

    if( cnt > 1 ){
        cout<<"?";
    } else{
        cout<<(char)('A'+maxIdx);
    }


    return 0;
}