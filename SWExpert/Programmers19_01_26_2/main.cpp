#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int l, vector<int> v) {
    int answer = 0;
    sort(v.begin(), v.end());
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    vector<int> diff;
    int max = 0;
    int maxIdx = 0;
    for(int i=1; i<v.size(); i++){
        int tmp = v[i] - v[i-1];
        if(max < tmp){
            max = tmp;
            maxIdx = i-1;
        }
        diff.push_back(tmp-1);
    }

    if( maxIdx == diff.size()-1){
        answer = diff[maxIdx] - diff[maxIdx-1];
    }else if( maxIdx == 0){
        answer = diff[maxIdx] - diff[maxIdx+1];
    }else{
        int temp = diff[maxIdx]- diff[maxIdx-1];
        temp = min(temp, diff[maxIdx]- diff[maxIdx+1]);
        answer = temp;
    }

    return answer;
}

int main() {
    vector<int> temp;
//    temp.push_back(5);
//    temp.push_back(2);
    temp.push_back(15);
    temp.push_back(5);
    temp.push_back(3);
    temp.push_back(7);
    temp.push_back(9);
    temp.push_back(14);
    temp.push_back(0);


    int res = solution(5, temp);
    cout<< res<<'\n';

    return 0;
}
/*
15, [15, 5, 3, 7, 9, 14, 0]
기댓값 〉	3
*/