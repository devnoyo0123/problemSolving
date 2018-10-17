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
}

void split(vector<string> &data, string &input) {
    bool ret = true;
    int size = (int) input.size();
    int cnt = 0;
    string tmp = "";
    for (int i = 0; i < size; ++i) {
        tmp += input[i];
        if ((i + 1) % (N/4) == 0) {
            if (check(data, tmp)) {
                data.push_back(tmp);
            }
            tmp = "";
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

            ret += pow(16,a)*digit;
            a--;
        }
        intData.push_back(ret);
    }
}

bool cmp1(const int &a, const int &b){
    return a > b;
}

void solve(string &input) {
    vector<string> data;

    for (int i = 0; i < N; ++i) { // <- 이건 니가 잘못한거야 얼마나 반복해야되는지는 제발 계산좀해줘...
        split(data, input);
        rotate(input);
    }



    // striing to int
    vector<int> intData;
    convert(data, intData);
    sort(intData.begin(), intData.end() , cmp1);
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