//#include <cstdio>
//
//const int MAX = 41;
//
//int d[MAX][2];
//
//int main(){
//
//    d[0][0] = 1;
//    d[0][1] = 0;
//    d[1][0] = 0;
//    d[1][1] = 1;
//    int t;
//
//    scanf("%d", &t);
//    int n;
//    while(t--){
//        scanf("%d", &n);
//        for(int i=2; i<=n; i++){
//            d[i][0] = d[i-1][0] + d[i-2][0];
//            d[i][1] = d[i-1][1] + d[i-2][1];
//        }
//
//        printf("%d %d\n", d[n][0], d[n][1]);
//    }
//
//
//
//    return 0;
//}

// DP + DFS
// 일반적인 백트래킹은 2^40 으로 시간초과.. 다른 방법은? 0의 개수와 1의 개수를 기억하자

#include <iostream>
const int MAX =  41;
int zero[MAX]; // i일때 0이 호출된 횟수
int one[MAX];  // i일때 1이 호출된 횟수

void fib(int n){ //n일때 0,1 이 호출 된 횟수를 저장하는 함수

    if( zero[n] == 0 && one[n] == 0){ // 하나라도 0이 아니라는것은 이전에 호출이 되었다는 얘긴데.
        // 시간초과를 피하기 위해서는 중복 호출이 없어야된다. 어떻게 중복호출을 없앨 것인가?

        if(n == 0){
            zero[0]++;
            return;
        }

        if( n== 1){
            one[1]++;
            return;
        }

        fib(n-1); fib(n-2);
        zero[n] = zero[n- 1] + zero[n-2];
        one[n] = one[n-1] + one[n-1];
    }
}

int main(){

    int tc, n;
    scanf("%d", &tc);

    while(tc--){
        scanf("%d", &n);
        fib(n);
        printf("%d %d\n", zero[n], one[n]);
    }

    return 0;
}