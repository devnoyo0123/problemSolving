#include <cstdio>
#include <cstring>

int tc;

const int MAX = 1000010;

int arr[MAX];

int main() {

    scanf("%d", &tc);
    int num;
    long long sum = 0;

    for (int t = 1; t <= tc; t++) {
        sum = 0;
        scanf("%d", &num);
        for (int i = 0; i < num; i++) {
            scanf("%d", &arr[i]);
        }
        int cur = arr[num-1];
        for (int i = num - 1; i >= 0; i--) {
            if (cur > arr[i]) {
                sum += cur - arr[i];
            }else{
                cur = arr[i];
            }
        }

        printf("#%d %lld\n", t, sum);
    }


    return 0;
}