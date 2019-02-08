#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;


const int ARRMAX = 2002;

int n, ans;

int arr[ARRMAX];
set<int> check;




void solve(){
    int tmp;
    for(int i=0; i< n; i++){
        for(int j=i+1; j< n; j++){

            tmp = arr[i] + arr[j];

            if( check.count(tmp) > 0){
                check.erase(check.find(tmp));
                ans++;
            }
        }
    }
}

int main(){
    scanf("%d", &n);
    for(int i=0; i< n; i++){
        scanf("%d", &arr[i]);
        check.insert(arr[i]);
    }

    solve();

    printf("%d\n", ans);
}