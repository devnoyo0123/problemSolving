#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,x, cur = 0;
    bool ok = false;
    stack<int> st;
    queue<char> ans;
    cin >> n;
    while(n--){
        cin>> x;
        if( cur <= x){
            for(int i=cur+1; i<=x; i++){
                ans.push('+');
                st.push(i);
            }
            cur = x;

            if( cur == x){
                ans.push('-');
                st.top();
                st.pop();
            }

        }else{
            if(st.empty()){
                ok = true;
                break;
            }

            if( st.top() == x){
                ans.push('-');
                st.pop();
            }else{
                ok = true;
                break;
            }
        }
    }
    if(!ok){
        while(!ans.empty()){
            cout<<ans.front()<<'\n';
            ans.pop();
        }
    }else{
        cout<<"NO";
    }

    return 0;
}