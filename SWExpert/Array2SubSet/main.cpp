#include <iostream>

using namespace std;

int main() {
    int i,j;
    int arr[] = {3, 6, 7, 1, 5, 4};
    int n = sizeof(arr) / sizeof(int); // n: 원소의 개수

    for (int k = 0; k < (1<<(n)); ++k) { // 1<<n: 부분집합의 개수
        for (int l = 0; l < n; ++l) { // 원소의 수만큼 Bit를 비교함
            if( k & (1<<l)){ // k의 l번째 Bit가 1이면 l번째 원소 출력
                cout<<arr[l]<<" ";
            }
        }
        cout<<"\n";

    }
    return 0;
}