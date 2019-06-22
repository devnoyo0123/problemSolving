#include <iostream>
#include <stack>

using namespace std;

int main() {
    while (true) {
        stack<char> st;
        string strs="";
        bool ok = true;
        getline(cin,strs);
        if( strs[0]=='.' && strs.size() == 1){
            break;
        }
        for(int i=0; i<strs.size(); i++){
            if( strs[i] == '[' || strs[i] == '(' ){
                st.push(strs[i]);
            }

            if( strs[i] == ']' || strs[i] == ')' ){
                if( st.empty()){
                    ok = false;
                    break;
                }
                char a = st.top();
                char b = strs[i];
                if( a == '[' && b == ']'){
                    st.pop();
                }else if(a == '(' && b == ')') {
                    st.pop();
                }
                else{
                    ok = false;
                    break;
                }
            }
        }

        if(ok){
            cout<<"yes\n";
        }else{
            cout<<"no\n";
        }
    }
}