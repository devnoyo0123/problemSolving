#include <iostream>

using namespace std;

const int MAX = 1000;

int tc;
int arr[MAX];

int main() {

    cin >> tc;
    cout << fixed;             //소수점 자리 고정
    cout.precision(3);         //소수점 이하 3자리 표시
    cout.setf(ios::showpoint); //0을 표시

    int n,sum, cnt;
    for(int t = 1; t<=tc; t++){
        sum = cnt = 0;
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            sum += arr[i];
        }

        sum/=n;

        for(int i=0; i<n; i++){
            if( sum < arr[i]){
                cnt++;
            }
        }

        cout<<(double(cnt*100)/n)<<"%"<<'\n';


    }

    return 0;
}