#include <iostream>
#include <vector>

using namespace std;

int n1, k1;

int main() {

    int ans =0 ;
    cin >> n1 >>  k1;
    vector<int> v1(n1);
    for(int i=0; i< n1; i++){
        cin>> v1[i];
    }

    for (int j = v1.size()-1; j >=0 ; --j) {
        ans += k1/v1[j]; // 거슬러준 동전의 개수를 더해준다.
        k1 = k1 % v1[j]; // 거슬러주지 못한 크기를 남겨준다.
    }

    cout<<ans<<'\n';

    return 0;
}