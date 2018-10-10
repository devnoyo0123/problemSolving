#include <iostream>
#include <cstring>

using namespace std;

const int STUDENTMAX = 1000;
const int MAX = 100;

int TC, max1, ans;
int arr[MAX+1];

int main() {

    cin >> TC;
    for (int T = 1; T <= TC; ++T) {
        int num;
        cin >> num;

        int tmp;
        memset(arr,0, sizeof(arr));
        max1 = 0;
        ans = 0;
        for (int i = 0; i < STUDENTMAX; ++i) {
            cin >> tmp;
            arr[tmp]++;
        }

        for (int j = 0; j < MAX+1; ++j) {
            if( max1 <= arr[j]){
                max1 = arr[j];
                ans = j;
            }
        }

        cout<<"#"<<num<<" "<<ans<<"\n";
    }

    return 0;
}