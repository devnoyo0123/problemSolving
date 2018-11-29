#include <cstdio>

using namespace std;

int N, M;

bool check[10];

void go(int inx, int M) {


    if( inx > N+1){
        return;
    }

    if (M == 0) {
        for (int i = 1; i <= N; ++i) {
            if(check[i]){
                printf("%d ", i);
            }
        }
        printf("\n");
        return;
    }


    for (int j = inx; j <= N ; ++j) {
        check[j] = true;
        go(j+1, M-1);
        check[j] = false;
    }

}

int main() {

    scanf("%d %d", &N, &M);

    go(1,M);
    return 0;
}