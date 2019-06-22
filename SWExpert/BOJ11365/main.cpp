#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string tmp = "";
    while(1){
        getline(cin, tmp);
        if( tmp == "END"){
            break;
        }

        reverse(tmp.begin(), tmp.end());
        cout<<tmp<<'\n';
    }
    return 0;
}