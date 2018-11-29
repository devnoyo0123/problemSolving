#include <iostream>

using namespace std;

bool c[9];
int d[8];

int N, M;


void go(int inx, int cnt){

    if( inx >= N){

        return;
    }

    if( cnt+1 == M){ // 0번 인덱싱했기 때문에 +1 함
        for (int i = 0; i < cnt+1; ++i) {
            cout<<d[i]<<" ";
        }
        cout<<"\n";
        return;
    }


    for (int i = 0; i < N; ++i) {
        if( c[i+1] ){
            continue; // 기존에 사용한 숫자면 건너뛰기
        }
        c[i+1] = true;
        d[cnt+1] = i+1;
        go(i, cnt+1);
        c[i+1] = false;
        d[cnt+1] = 0;

    }

}

int main() {

    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; ++i) {
        c[i+1] = true;
        d[0] = i+1;
        go(i, 0); // 0번째 뽑은 숫자는 i다. 0번 인덱싱 했음.
        c[i+1] = false;
        d[0] = 0;
    }


    return 0;
}