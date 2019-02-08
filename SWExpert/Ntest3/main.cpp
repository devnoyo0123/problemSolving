#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string encrypted_text, string key, int rotation) {
    string answer = "";


    if( rotation >=0){
        string tempA = encrypted_text.substr(0, rotation);
        string tempB = encrypted_text.substr(rotation, encrypted_text.size());
        answer = tempB + tempA;
    }else{
        int location = encrypted_text.size() + rotation;
        string tempA = encrypted_text.substr(location, encrypted_text.size());
        string tempB = encrypted_text.substr(0, location);
        answer = tempA + tempB ;
    }



    for(int i=0; i<key.size(); i++){
        char temp = answer[i]; // 암호화된 문자

        int j = key[i] - 'a' + 1;
        if( temp - j < 'a'){
            int diff = 'a' - (temp - j);
            temp = 'z'-diff+1;
        }else{
            temp -= j;
        }

        answer[i] = temp;

    }

    return answer;
}

int main() {

    //qyyigoptvfb
    string ans = solution("qyyigoptvfb", "abcdefghijk", 3);
    cout<<ans<<'\n';
    return 0;
}