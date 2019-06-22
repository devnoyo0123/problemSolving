#include <iostream>

using namespace std;

int main() {

    int n, idx= 0, ans = 0;
    cin >> n;

    for(int i=666; i<=10000666; i++){
        int count = 0;
        int temp = i;
        bool ok = false;
        while(temp){
            if(temp%10 == 6){
                count++;
                if( count >= 3){
                    //666이 들어갔으면
                    ok = true;
                    break;
                }
            }else{
                count=0;
            }

            temp/=10;
        }

        if(ok)
            idx++;

        if( idx == n) {
            ans = i;
            break;
        }
    }

    cout<<ans<<'\n';



    return 0;
}