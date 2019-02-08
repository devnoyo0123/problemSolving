#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 100001;

int tc;
int arr[MAX][3];
int d[MAX][3];

int main() {

    cin >> tc;
    for(int t = 1; t<= tc; t++){
        int n;
        cin >> n;
        memset(d, 0, sizeof(d));
        memset(arr, 0, sizeof(arr));
        for(int i = 1; i< 3; i++){
            for(int j = 1; j<= n; j++){
                cin >> arr[j][i];
            }
        }

        d[1][1] = arr[1][1];
        d[1][2] = arr[1][2];


        // d[i][0] : i번째에서 스티커를 뜯지 않음
        // d[i][1] : i번째에서 위에 스티커 뜯기
        // d[i][2] : i번째에서 아래 스티커 뜯기

        for(int i=2; i<=n; i++){
            d[i][0] = max(max(d[i-1][0], d[i-1][1]), d[i-1][2]);
            d[i][1] = max(d[i-1][0], d[i-1][2]) + arr[i][1];
            d[i][2] = max(d[i-1][0], d[i-1][1]) + arr[i][2];
        }

        cout<< max(max(d[n][0], d[n][1]), d[n][2])<<'\n';


    }


    return 0;
}