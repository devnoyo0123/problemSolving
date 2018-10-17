#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int n, b;

int main() {

    scanf("%d %d", &n, &b);
    string ans = "";
    while (n > 0){
        int r = n % b;
        n /= b;
        if( r < 10){
            ans += (char)(r + '0');
        }else{
            ans += (char)(r - 10 + 'A');
        }


    }

    reverse(ans.begin(), ans.end());
    printf("%s\n", ans.c_str());
    return 0;
}