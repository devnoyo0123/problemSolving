#include <iostream>
#include <stack>
using namespace std;
int main() {

    stack<int> st;
    int n,x;
    cin >> n;
    while(n--){
        cin>>x;
        if( x == 0){
            st.pop();
        }else{
            st.push(x);
        }
    }

    int sum = 0;
    while(!st.empty()){
        sum += st.top(); st.pop();
    }

    cout<<sum<<'\n';
    return 0;
}