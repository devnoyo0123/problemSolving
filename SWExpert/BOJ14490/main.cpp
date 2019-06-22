#include <iostream>
#include <string>

using namespace std;

int gcd(int a,int b){
    if( a % b == 0){
        return b;
    }else{
        return gcd(b, a%b);
    }
}

int main() {
    string str;
    cin >> str;
    int pos;
    int a, b;
    for(int i=0; i< str.size(); i++){
        if( str[i] == ':'){
            pos = i;
        }
    }

    a = stoi(str.substr(0,pos+1));
    b = stoi(str.substr(pos+1,str.size()-pos));

    cout<<a/gcd(a,b)<<":"<<b/gcd(a,b);
    return 0;
}