#include <cstdio>

using namespace std;

const int NMAX = 100001;

int N,M;
int arr[NMAX];
int sum[NMAX];

int main() {

    scanf("%d %d", &N, &M);

    for (int i = 1; i <=N ; ++i) {
        scanf("%d", &arr[i]);
        sum[i] = sum[i-1] + arr[i];
    }

    int a, b;
    for (int j = 1; j <= M ; ++j) {
        scanf("%d %d", &a, &b);
        int ans = sum[b] - sum[a-1];
        printf("%d\n", ans);
    }

    return 0;
}