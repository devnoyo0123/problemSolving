#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;


int num;
char ch[100000];
long long length;
long long cnt;



int main() {

    stack<pair<int, char>> st;
    scanf("%d", &num);
    for (int i = 0; i < num; ++i) {
        memset(ch, 0, 100000);

        scanf("%s", ch);
        length = strlen(ch);
        cnt =0;
        for (int j = 0; j < length; ++j) {
            if( ch[j] == '('){
                st.push(make_pair(j,ch[j]));
            }else if( ch[j] == ')'){
                pair<int,char> tmp = st.top(); st.pop();
                if(tmp.first + 1 == j){
                    cnt+= st.size();
                }else{
                    cnt+=1;
                }
            }
        }

        printf("#%d %ld", i+1,cnt);
    }




    return 0;
}