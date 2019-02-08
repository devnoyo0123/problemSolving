#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <set>

using namespace std;

int tc;
int n, m;

int mhex[16][4] = {{0, 0, 0, 0},
                   {0, 0, 0, 1},
                   {0, 0, 1, 0},
                   {0, 0, 1, 1},
                   {0, 1, 0, 0},
                   {0, 1, 0, 1},
                   {0, 1, 1, 0},
                   {0, 1, 1, 1},
                   {1, 0, 0, 0},
                   {1, 0, 0, 1},
                   {1, 0, 1, 0},
                   {1, 0, 1, 1},
                   {1, 1, 0, 0},
                   {1, 1, 0, 1},
                   {1, 1, 1, 0},
                   {1, 1, 1, 1},
};


set<string> decodes; // 기존에 해독한 코드인지 확인하기 위한 셋
vector<string> list; // 해독할 list 위치
vector<string> buf;

int codeLength;


int ans;

int precode[56 * 20] = {0,};
int code[56 * 20] = {0,};
int compressedCode[56] = {0,};
int decode[8] = {0,};

int checkcode() {
    int sum = (decode[7] + decode[5] + decode[3] + decode[1]) * 3 + decode[2] + decode[4] + decode[6];
    if ((sum + decode[0]) % 10 == 0) {

        return decode[0] + decode[1] + decode[2] + decode[3] + decode[4] + decode[5] + decode[6] + decode[7];
    } else
        return 0;
}

int decoder(int n) {
    if (compressedCode[(n * 7)] == 1 && compressedCode[(n * 7 + 1)] == 0 && compressedCode[(n * 7 + 2)] == 1 &&
        compressedCode[(n * 7 + 3)] == 1 && compressedCode[(n * 7 + 4)] == 0 && compressedCode[(n * 7 + 5)] == 0 &&
        compressedCode[(n * 7 + 6)] == 0)
        return 0;
    else if (compressedCode[(n * 7)] == 1 && compressedCode[(n * 7 + 1)] == 0 && compressedCode[(n * 7 + 2)] == 0 &&
             compressedCode[(n * 7 + 3)] == 1 && compressedCode[(n * 7 + 4)] == 1 && compressedCode[(n * 7 + 5)] == 0 &&
             compressedCode[(n * 7 + 6)] == 0)
        return 1;
    else if (compressedCode[(n * 7)] == 1 && compressedCode[(n * 7 + 1)] == 1 && compressedCode[(n * 7 + 2)] == 0 &&
             compressedCode[(n * 7 + 3)] == 0 && compressedCode[(n * 7 + 4)] == 1 && compressedCode[(n * 7 + 5)] == 0 &&
             compressedCode[(n * 7 + 6)] == 0)
        return 2;
    else if (compressedCode[(n * 7)] == 1 && compressedCode[(n * 7 + 1)] == 0 && compressedCode[(n * 7 + 2)] == 1 &&
             compressedCode[(n * 7 + 3)] == 1 && compressedCode[(n * 7 + 4)] == 1 && compressedCode[(n * 7 + 5)] == 1 &&
             compressedCode[(n * 7 + 6)] == 0)
        return 3;
    else if (compressedCode[(n * 7)] == 1 && compressedCode[(n * 7 + 1)] == 1 && compressedCode[(n * 7 + 2)] == 0 &&
             compressedCode[(n * 7 + 3)] == 0 && compressedCode[(n * 7 + 4)] == 0 && compressedCode[(n * 7 + 5)] == 1 &&
             compressedCode[(n * 7 + 6)] == 0)
        return 4;
    else if (compressedCode[(n * 7)] == 1 && compressedCode[(n * 7 + 1)] == 0 && compressedCode[(n * 7 + 2)] == 0 &&
             compressedCode[(n * 7 + 3)] == 0 && compressedCode[(n * 7 + 4)] == 1 && compressedCode[(n * 7 + 5)] == 1 &&
             compressedCode[(n * 7 + 6)] == 0)
        return 5;
    else if (compressedCode[(n * 7)] == 1 && compressedCode[(n * 7 + 1)] == 1 && compressedCode[(n * 7 + 2)] == 1 &&
             compressedCode[(n * 7 + 3)] == 1 && compressedCode[(n * 7 + 4)] == 0 && compressedCode[(n * 7 + 5)] == 1 &&
             compressedCode[(n * 7 + 6)] == 0)
        return 6;
    else if (compressedCode[(n * 7)] == 1 && compressedCode[(n * 7 + 1)] == 1 && compressedCode[(n * 7 + 2)] == 0 &&
             compressedCode[(n * 7 + 3)] == 1 && compressedCode[(n * 7 + 4)] == 1 && compressedCode[(n * 7 + 5)] == 1 &&
             compressedCode[(n * 7 + 6)] == 0)
        return 7;
    else if (compressedCode[(n * 7)] == 1 && compressedCode[(n * 7 + 1)] == 1 && compressedCode[(n * 7 + 2)] == 1 &&
             compressedCode[(n * 7 + 3)] == 0 && compressedCode[(n * 7 + 4)] == 1 && compressedCode[(n * 7 + 5)] == 1 &&
             compressedCode[(n * 7 + 6)] == 0)
        return 8;
    else
        return 9;

}

void compress(int n, int size) {
    compressedCode[n * 7] = code[n * 7];
    compressedCode[n * 7 + 1] = code[(n * 7 + 1) * size];
    compressedCode[n * 7 + 2] = code[(n * 7 + 2) * size];
    compressedCode[n * 7 + 3] = code[(n * 7 + 3) * size];
    compressedCode[n * 7 + 4] = code[(n * 7 + 4) * size];
    compressedCode[n * 7 + 5] = code[(n * 7 + 5) * size];
    compressedCode[n * 7 + 6] = code[(n * 7 + 6) * size];

}

int hexToDecimal(char hex) {
    int res = 0;
    if (hex >= 'A') {
        res = hex - 'A' + 10;
    } else {
        res = hex - '0';
    }
    return res;
}

void solve() {

    int inx = 0;
    int start = 0;

    //16진수를 2진수 표현으로 비트를 -> 배열요소로 넣기

    for (int k = 0; k < list.size(); ++k) {

        memset(compressedCode, 0, sizeof(compressedCode));
        memset(code, 0, sizeof(code)); //2진수로 변환한 값 넣기
        memset(precode, 0, sizeof(precode));

        string str = list[k];

        int length = str.length();
        int inx = 0;

        for (int i = length - 1; i >= 0; i--) {
            precode[inx++] = hexToDecimal(str[i]);
        }

        for (int i = 0; i < inx; i++) {
            if (precode[i] > 0) {
                start = i;
            }
        }

        int idx = 0;
        for (int i = start; i < inx; i++) {
            code[idx++] = precode[i];
        }

        for (int i = 0; i < idx; i++) {
            cout << code[i];
        }
        cout << '\n';


        if (m <= 26) {
            codeLength = 1;
        } else if (m <= 50) {
            codeLength = 2;
        } else if (m <= 126) {
            codeLength = 5;
        } else if (m <= 250) {
            codeLength = 10;
        } else {
            codeLength = 20;
        }


        for (int j = 1; j <= codeLength; j++) {
            for (int i = 0; i < 8; i++) {
                compress(i, j);
            }

            for (int i = 0; i < 8; i++) {
                decode[i] = decoder(i);
            }


            ans += checkcode();
        }
    }


    list.clear(); // 해독 다 한것은 list에서 제거

}


// 문자열에서 암호코드만 list랑 decodes에 넣기
void makeString() {
    int size = buf.size();
    vector<vector<int> > immap(size, vector<int>(buf[0].size(), 0));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < buf[i].size()- 4; j++) {
            int cnt = 0;
            if (buf[i][j] != '0') cnt++;
            if (buf[i][j + 1] != '0') cnt++;
            if (buf[i][j + 2] != '0') cnt++;
            if (buf[i][j + 3] != '0') cnt++;
            if (buf[i][j + 4] != '0') cnt++;

            immap[i][j] += cnt;
        }
    }


    for (int k = 0; k < immap.size(); ++k) {
        int start = -1 , end = -1;
        for (int i = 0; i < immap[i].size(); ++i) {

            if(immap[k][i] > 0 && start == -1){
                start = i;
                end = -1;
            }

            if( immap[k][i] == 0 && start != -1){
                end = i;

                string tmpStr = buf[k].substr(start, end);

                start = -1;
            }

        }
    }

}

int main() {


    cin >> tc;

    for (int t = 1; t <= tc; t++) {

        codeLength = 0;

        cin >> n >> m;

        ans = 0;
        decodes.clear();

        bool flag = false;

        for (int i = 0; i < n; i++) {
            string tmpStr = "";
            cin >> tmpStr;
            buf.push_back(tmpStr);
        }
        makeString();
        solve();

        printf("#%d %d\n", t, ans);
    }
    return 0;
}

