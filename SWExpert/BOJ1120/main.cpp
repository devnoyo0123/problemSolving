#include <iostream>

using namespace std;

string a,b;

int main() {

    int ans = 987654321;
    cin >> a >> b;

    int size = b.length() - a.length();
    for(int i=0; i<=size; i++){
        int cnt= 0;
        for(int j=0; j<a.length(); j++){
            if( a[j] != b[j+i] ){
                cnt++;
            }
        }
        if( ans > cnt){
            ans = cnt;
        }
    }

    cout<<ans<<'\n';


    return 0;
}