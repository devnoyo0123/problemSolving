#include <iostream>
#include <algorithm>

using namespace std;

int data[8];
int temp[8];
bool check[8];

int num, ans;

int calc(){
    int tmp = 0;
    for(int i=0; i+1<num; i++){
        tmp += abs(temp[i]- temp[i+1]);
    }
    return tmp;
}

void go(int idx){
    // data[start] 값을 start번째 배열에 넣고,
    // 모든 수가 차면 수를 빼서 최대값을 갱신하는 함수

    if( idx == num){
        //
        int res = calc();
        if( ans < res){
            ans = res;
        }
        return;
    }

    for(int i=0; i<num; i++){
        if(!check[i]){
            check[i] = true;
            temp[idx] = data[i];
            go(idx+1);
            check[i] = false;
            temp[idx] = 0;
        }
    }
}

int main() {

    cin >> num;
    for (int i = 0; i < num; ++i) {
        cin >> data[i];
    }

    go(0);

    cout<<ans<<'\n';
    return 0;
}