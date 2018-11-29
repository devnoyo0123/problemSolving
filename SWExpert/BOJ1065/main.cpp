#include <iostream>

using namespace std;

int N, ans;
int a[5];

int main() {

    cin >> N;

    if( N < 10){
       ans += N;
    }else if( N < 100){
        ans += N;
    }else if( N <= 1000){

        ans += 99;

        for(int i=100; i<=N; i++){

            int n = i;
            int inx = 0;

            while( n > 0){
                a[inx++] = n%10;
                n/=10;

            }

            if( inx <=3){
                if( a[0] - a[1] == a[1] - a[2]){
                    ans+=1;
                }
            }else{
                if( a[0] - a[1] == a[1] - a[2]
                        == a[2] - a[3]){
                    ans+=1;

                }
            }

        }

    }

    cout<<ans<<'\n';

    return 0;
}