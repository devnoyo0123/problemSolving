#include <iostream>

using namespace std;

int main() {

    int tc, num;
    string ch;
    cin >> tc;

    while(tc--){
        cin >> num >> ch;
        for(int j=0; j<ch.length(); j++){
            for(int i=0; i<num; i++){
                cout<<ch[j];
            }
        }
        cout<<'\n';

    }

    return 0;
}