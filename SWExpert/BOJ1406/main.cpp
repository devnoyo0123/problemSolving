#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {

    string str;
    int n;
    char a,b;

    stack<char> left;
    stack<char> right;

    cin >> str >> n;

    for(char ch : str){
        left.push(ch);
    }

    for(int i=0; i<n; i++){
        cin >> a;
        if( a == 'P'){
            cin >> b;
            left.push(b);
        }else if( a == 'L'){
            if(!left.empty()){
                char temp = left.top(); left.pop();
                right.push(temp);
            }

        }else if( a == 'D'){
            if(!right.empty()){
                char temp = right.top(); right.pop();
                left.push(temp);
            }

        }else{
            if(!left.empty()){
                left.pop();
            }
        }
    }

    while(!left.empty()){
        right.push(left.top());
        left.pop();
    }

    while(!right.empty()){
        cout<<right.top();
        right.pop();
    }

    return 0;
}