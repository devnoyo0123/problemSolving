#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> bricks)
{
    int answer = 0, max = 0;
    stack<int> st;
    for(int i=0; i<bricks.size(); i++){
        if( st.empty()){
            st.push(bricks[i]);
        }else{
            if( st.top() < bricks[i]){
                while(!st.empty()){
                    int temp = st.top(); st.pop();
                    if(!st.empty()){
                        answer+=st.top()-temp;
                    }
                    if(st.empty() || st.top() >= bricks[i]){
                        break;
                    }
                }
                st.push(bricks[i]);
            }else{
                st.push(bricks[i]);
            }
        }
    }


    return answer;
}

int main() {

    vector<int> input={1, 2, 3, 4, 5, 6, 7};
    cout<<solution(input);

    return 0;
}