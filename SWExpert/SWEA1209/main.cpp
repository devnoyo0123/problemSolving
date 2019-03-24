#include <iostream>

using namespace std;

#define MAX 100

int n, ans;
int map[MAX][MAX];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int t =1; t<=10; t++){
        cin >> n;
        ans = 0;

        for(int i=0; i<100; i++){
            int sum = 0;
            for(int j=0; j<100; j++){
                cin >> map[i][j];
                sum += map[i][j];
            }

            if( ans < sum){
                ans = sum;
            }
        }


        for(int j=0; j<100; j++){
            int sum = 0;
            for(int k = 0; k<100; k++){
                sum += map[k][j];
            }

            if( ans < sum){
                ans = sum;
            }
        }


        int i = 0, j =0;
        int sum = 0;
        while(i<100 && j < 100){
            sum += map[i][j];
            i++;
            j++;
        }

        if( ans < sum){
            ans = sum;
        }

        i = 0, j =99; // row, col
        sum = 0;
        while(i < 100 && j >= 0){
            sum += map[i][j];
            i++;
            j--;
        }

        if( ans < sum){
            ans = sum;
        }


        cout<<"#"<<t<<" "<<ans<<'\n';
    }


    return 0;
}