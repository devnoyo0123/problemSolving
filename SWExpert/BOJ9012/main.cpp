#include <iostream>
#include <stack>

using namespace std;

int tc;

int main() {

    cin >> tc;

    for(int i=0; i<tc; i++){
        string tmp = "";
        cin >> tmp;
        bool fail = false;
        stack<char> st1;


        for (int j = 0; j < tmp.size(); ++j) {
            if( tmp[j] == '('){
                st1.push(tmp[j]);
            }else{
                if( st1.empty()){
                    fail = true;
                    break;
                }

                st1.pop();
            }
        }


        if(fail){
            cout<<"NO\n";
        }else{

            if(st1.empty()){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
        }

    }

    return 0;
}