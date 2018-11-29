#include <iostream>

using namespace std;


int n, r, c;

int pow2(int a){
    return (1 << a);
}

int go(int n, int r, int c){
    if(n==1){
        if( r == 0 && c == 0){
            return 0;
        }else if( r== 0 && c ==1){
            return 1;
        }else if( r== 1 && c ==0){
            return 2;
        }else if( r== 1 && c ==1){
            return 3;
        }
    }else{
        if( r < pow2(n/2)){
            // row 인덱스가 전체 길이의 반으로 나눴을때,
            // 3,4사분면이면
            if( c < pow2(n/2)){
                // 0,1,2,3에서 1,3일때
                return go(n/2, r, c - pow2(n/2));
            }else{

            }
        }else{
            // 1,2사분면이면

            if( c < pow2(n/2)){

            }else{

            }
        }
    }
}

int main() {

    cin >> n >> r >> c;

    int ans = go(n, r, c);

    cout<< ans <<'\n';

    return 0;
}