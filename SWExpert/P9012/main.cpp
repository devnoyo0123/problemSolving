//
//  main.cpp
//  AlgorithmJobsCourse8_5
//
//  Created by YOSEPH NOH on 2018. 8. 14..
//  Copyright © 2018년 YOSEPH NOH. All rights reserved.
//

#include <cstdio>
#include <stack>

using namespace std;

char ch[100];
int num;
bool flag;
int main() {

    scanf("%d", &num);
    while (num-- > 0) {
        stack<char> st;
        scanf("%s", ch);
        int i = 0;
        while (ch[i] != 0) {
            if (ch[i] == '(') {
                st.push(ch[i]);
            } else {
                if (!st.empty()) {
                    char temp = st.top();
                    if (temp == '(') {
                        st.pop();
                    }
                } else {
                    break;
                }
            }
            i += 1;
        }


        if (st.empty()) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}