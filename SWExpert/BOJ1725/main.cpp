//
//  main.cpp
//  AlgorithmJobsCourse8_8
//
//  Created by YOSEPH NOH on 2018. 8. 14..
//  Copyright © 2018년 YOSEPH NOH. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <stack>
#include <limits.h>

using namespace std;

int main() {
    long long num = 0;
    long long maxvalue = 0, temp  = 0, left = 0, right = 0;
    pair<long long, long long> tmpPair;
    stack<pair<long long, long long> > st;
    while(1) {

        scanf("%lld", &num);
        if( num == 0){
            break;
        }

        long long *parr = (long long *) malloc(sizeof(long long) * num);
        for (int i = 0; i < num; i++) {
            scanf("%lld", &parr[i]);
        }

        for (long long i = 0; i < num; i++) {
            if (st.empty()) {
                st.push(make_pair(parr[i], i));

            } else {
                tmpPair = st.top();

                if (tmpPair.first <= parr[i]) {
                    // 스택의 top 막대기보다 현재 막대기가 더 큰경우
                    st.push(make_pair(parr[i], i));
                } else {
                    //
                    while (!st.empty() && st.top().first > parr[i]) {

                        tmpPair = st.top();
                        st.pop();
                        if (!st.empty() && st.top().first > tmpPair.first) {
                            st.pop();
                        }

                        if (st.empty()) {
                            // 예외처리
                            left = tmpPair.second;
                        } else {
                            left = st.top().second + 1;
                        }



                        // 오른쪽 끝을 찾는 작업
                        long long l = tmpPair.second;
                        while (l < num) {
                            if (tmpPair.first <= parr[l]) {
//                            printf("first: %d, parr[l]: %d\n", tmpPair.first, parr[l]);
                                l++;
                            } else {
                                break;
                            }
                        }
                        right = l;

//                    printf("left %d, right: %d, height: %d\n", left, right,tmpPair.first);

                        temp = (right - left) * tmpPair.first;

                        if (maxvalue < temp) {
                            maxvalue = temp;
                        }
                    }

                    st.push(make_pair(parr[i], i));
                }
            }
        }
        long long cnt = 1;
        while (!st.empty()) {
            long long a = st.top().first;
            st.pop();
            temp = a * cnt;
            cnt += 1;
            if (maxvalue < temp) {
                maxvalue = temp;
            }
        }
        printf("%lld\n", maxvalue);
        free(parr);
    }
    return 0;
}