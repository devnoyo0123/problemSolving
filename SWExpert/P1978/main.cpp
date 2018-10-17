#include <cstdio>

int n;
int cnt;

bool isPrime(int num){
    bool ret = false;

    if( num < 2){
        return true;
    }

    for (int i = 2; i <= num ; ++i) {
        if( num % i == 0){
            ret = true;
        }
    }

    return ret;
}

int main() {

    scanf("%d", &n);
    int temp = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &temp);

        if(!isPrime(temp)){
            cnt++;
        }

    }

    printf("%d\n", cnt);

    return 0;
}