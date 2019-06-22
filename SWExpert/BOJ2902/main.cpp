#include <iostream>
#include <string>

using namespace std;

int main() {
    string tmp = "", ans ="";
    cin >> tmp;
    for(int i=0; i<tmp.size(); i++){
        if ( 'A' <= tmp[i] && tmp[i] <= 'Z'){
            ans+=tmp[i];
        }
    }
    cout<<ans<<'\n';
    return 0;
}