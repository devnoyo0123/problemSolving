#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 1000000;


long long f[MAX+1];
long long sum[MAX+1];
int testCase;


int L, R;

int main() {


    for(long long i = 1; i<= MAX; i++){
        if( i % 2 == 1){
            f[i] += i;
            for (long long j = i*2; j <= MAX; j+=i) {
                f[j] += i;

            }
        }

        if( i == 1)
            sum[i] = f[i];
        else{
            sum[i] = sum[i-1] + f[i];
        }
        printf("sum[%ld]: %ld\n", i, sum[i]);
        if(i == 1000){
            return 0;
        }
    }




    cin >> testCase;
    for (int l = 1; l <= testCase; ++l) {

        cin >> L >> R;
        cout << "#" << testCase << " " << sum[R]-sum[L-1];
    }

    return 0;
}