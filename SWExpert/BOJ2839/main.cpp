#include <iostream>

using namespace std;

int N;
int ans= 987654321;

void go(int num, int cnt){

    if( num > N){
        cout<<'\n';
        return;
    }

    if( num == N){
        if( ans > cnt){
            ans = cnt;
        }
        cout<<'\n';

        return;
    }

    go(num+3, cnt+1);

    go(num+5, cnt+1);
}

int main() {

    cin >> N;

    go(0,0);

    if( ans == 987654321){
        cout<<-1<<'\n';
    }else{
        cout<<ans<<'\n';

    }
    return 0;
}