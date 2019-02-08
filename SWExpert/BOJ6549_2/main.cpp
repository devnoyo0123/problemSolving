#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>

using namespace std;
long long n, arr[100001];

long long histogram() {
    stack<long long> st;
    long long i, ret = 0;
    st.push(-1);
    for (i = 0; i < n; i++) {
        while (!st.empty() && arr[i] < arr[st.top()]) {
            int tmp = st.top();
            st.pop();
            if (!st.empty())

                ret = max(ret, arr[tmp] * (i - st.top() - 1));
        }
        st.push(i);
    }

    while (!st.empty()) {
        int tmp = st.top();
        st.pop();
        if (!st.empty())
            ret = max(ret, arr[tmp] * (n - st.top()-1));
    }
    return ret;
}

int main() {


    while (true) {
        scanf("%lld", &n);
        if (n == 0) {
            break;
        }
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < n; i++)
            scanf("%lld", &arr[i]);
        printf("%lld\n", histogram());

    }


}