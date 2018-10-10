#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

const int MAX = 1010;

int arr[MAX];
int size1;

int main() {

    for (int T = 1; T <= 10 ; ++T) {
        cin >> size1;
        memset(arr,0, sizeof(arr));
        int cnt = 0;
        for (int i = 0; i < size1; ++i) {
            cin >> arr[i];

        }

        for (int j = 2; j <= size1-2; ++j) {
            int pos = j;
            int max1 = max(arr[pos-2], arr[pos-1]);
            int max2 = max(arr[pos+1], arr[pos+2]);
            int max3 = max(max1, max2);
            if( arr[pos] - max3 > 0){
                cnt += (arr[pos] - max3);
            }
        }
        cout<<"#"<<T<<" "<<cnt<<"\n";
    }

    return 0;
}