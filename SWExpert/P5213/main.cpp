#include <cstdio>

long long testCase;
long long L[100010];
long long R[100010];
long long sum;

long long f2(long long num){
    long long tmp = 0;
    for (int i = 1; i <= num ; i++) {
        if( num % i == 0){
            tmp += i;
        }
    }

    return tmp;
}

long long f(long long num){
    long long tmp = 0;
    for (int i = 1; i <= num ; i+=2) {
        if( num % i == 0){
            tmp += i;
        }
    }

    return tmp;
}


int main() {

    scanf("%ld", &testCase);
    for (long long i = 1; i <=testCase ; ++i) {
        scanf("%ld %ld", &L[i], &R[i]);

    }

    for (long long i  = 1; i <=testCase ; i++) {
        sum = 0;
        for (long long j = L[i]; j <= R[i] ; ++j) {
            if (j % 2 == 0) {
                sum += f(j);
            }
            else{
                sum += f2(j);
            }
        }

        printf("#%d %ld\n",i, sum);
    }



    return 0;
}