#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX = 28;

int tc, N, K;
long long ans;


int chartoint(char ch){
    if( ch =='A'){
        return 10;
    }else if( ch == 'B'){
        return 11;
    }else if( ch == 'C') {
        return 12;
    }else if( ch == 'D'){
        return 13;
    }else if( ch == 'E'){
        return 14;
    }else if( ch == 'F'){
        return 15;
    }
}

bool check(vector<string> &data, string tmp) {
    bool ret = true;
    int size = (int) data.size();
    for (int i = 0; i < size; ++i) {
        if (data[i] == tmp) {
            ret = false;
            return ret;
        }
    }
    return ret;
}

void rotate(string &input){
    int length = input.size();
    char ch[MAX]= {0,};
    strcpy(ch, input.c_str());
    char tmp = ch[length-1];
    for (int i = length-2; i >= 0; --i) {
        ch[i+1] = ch[i];
    }
    ch[0] =tmp; ch[length] = 0;
    input = ch;
//    ans += ch; 라는 건 ch를 문자열로 보고 뒤에 덧붙이는 것입니다
        // 그런데 C 스타일의 문자열은 (std::string 말고) 반드시 널 문자로 끝나야 하고,
                // 널 문자가 없다면 문자열 함수 입장에선 문자열의 끝이 어디인지 알 방법이 없습니다.
                        // 따라서 반드시 널 문자가 뒤에 붙을 수 있게끔 ch의 크기를 4로 잡아주면 정답을 받습니다.
}

void split(vector<string> &data, string &input) {
    bool ret = true;
    int size = (int) input.size();
    int cnt = 0;
    string tmp = "";
    for (int i = 0; i < size; ++i) {
        tmp += input[i];
        if ((i + 1) % (N/4) == 0) {// 인덱스가 0부터 시작하니까 1,2,3,4로 시작하면 계산이 더 편해서 i+1해줬음. 그 값이 n/4 한 값과 나눈나머지가
            // 0 이란 얘기는 나누어 떨어진다는 얘기다.
            if (check(data, tmp)) { // 가존 data 스트링 벡터에 존재하는지 확인하는 함수 O(N)이다.
                data.push_back(tmp); // 기존 문자열에 없으면 벡터에 추가해주고
            }
            tmp = ""; //문자열 비어준다.
        }
    }

}

void convert(vector<string> &data, vector<int> &intData){
    for (int i = 0; i < data.size(); ++i) {
        string tmp = data[i];

        int size,a;
        size = a = (int)tmp.size();
        a -=1;
        int ret = 0;
        for (int j = 0; j < size; ++j) {
            char ch = tmp[j];
            int digit;
            if(ch >= '0' && ch <= '9'){
                digit = ch-'0';
            }else{
                digit = chartoint(ch);
            }

            ret += pow(16,a)*digit; //16진수 원리 그대로. a는 자리수(지수)를 말한다 digit는 16진수의 a번째 자리의 수를 말한다.
            a--;
        }
        intData.push_back(ret);
    }
}

bool cmp1(const int &a, const int &b){
    return a > b; // 내림차순으로 정렬 a < b가 오름 차순
}

void solve(string &input) {
    vector<string> data;

    for (int i = 0; i < N; ++i) { // <- 이게 핵심 N-1번까지만 하기 왜인줄알아? 그러면 모든 인덱스 기준으로 다 돌린게 되잖어. 그게 전체 경우의 수지
        split(data, input); // 문자열을 4등분으로 나누기
        rotate(input); // 회전시키기
    }



    // striing to int
    vector<int> intData;
    convert(data, intData);
    sort(intData.begin(), intData.end() , cmp1); //
//    for (int i = 0; i < intData.size(); ++i) {
//        cout<<intData[i]<<"\n";
//    }
    ans = intData[K-1];
}

int main() {

    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cin >> N >> K;
        ans = 0;
        string input = "";
        cin >> input;

        solve(input);

        cout << "#" << t << " " << ans << "\n";
    }
    return 0;

}