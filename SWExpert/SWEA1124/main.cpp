#include <iostream>
#include <queue>
#include <cstring>



using namespace std;

const int ADD = -987654321;
const int SUB = -987654320;
const int MUL = -987654319;
const int MIN = -987654318;
const int BUFMAX = 20;

int tc, ans;
int size;
string str1;

char aa[BUFMAX];

bool checkBrace(char ch) {
    return ch == '+' || ch == '*' || ch == '-';
}

int calc2(string &tmp) {
    int i = 0;
    queue<int> tmpQ;
    while (i < tmp.length()) {

        int tmp2 = 0;
        if (tmp[i] == '(') {
            i++;

            tmp2 = (tmp[i] - '0'); i++;

            while (tmp[i] != ')') {

                if (tmp[i] == '+') {
                    i++;
                    tmp2 += (tmp[i] - '0');
                } else if (tmp[i] == '*') {
                    i++;
                    tmp2 *= (tmp[i] - '0');
                } else if (tmp[i] == '-'){
                    i++;
                    tmp2 -= (tmp[i] - '0');
                }
                i++;


            }
            i++;
            tmpQ.push(tmp2);

        } else if (checkBrace(tmp[i])) {
            if( tmp[i] == '+'){
                tmpQ.push(ADD);

            }else if( tmp[i] == '-'){
                tmpQ.push(SUB);

            }else if( tmp[i] == '*'){
                tmpQ.push(MUL);

            }
            i++;
        } else {
            tmpQ.push(tmp[i] - '0');
            i++;
        }
    }


    int res = tmpQ.front(); tmpQ.pop();
    while(!tmpQ.empty()){
        int tmp3 = tmpQ.front(); tmpQ.pop();
        if( tmp3 == MUL || tmp3 == SUB || tmp3 == ADD){
            if( !tmpQ.empty()){
                int tmp4 = tmpQ.front(); tmpQ.pop();
                if( tmp3 == MUL){
                    res *= tmp4;
                }else if( tmp3 == SUB){
                    res -= tmp4;
                }else if( tmp3 == ADD){
                    res += tmp4;
                }
            }
        }
    }

    return res;
}

string calc1() {
    string tmp = "";
    for (int i = 0; i < str1.length(); ++i) {
        if (aa[i] == 0) {
        } else {
            tmp += aa[i];
        }
        tmp += str1[i];
    }
    if (aa[str1.length()] == ')') {
        tmp += aa[str1.length()];
    }
    return tmp;
}

void solve(int inx) {

    if (inx > size) {

        //앞에서부터 차례대로 계산하기
        string tmp = calc1(); // 괄호 추가하기

        //괄호 있는 것 풀어주고 계산한 값 리턴
        int res = calc2(tmp);
        if (res > ans) {
            cout<<tmp<<'\n';
            ans = res;
        }
        return;
    }


    if (inx + 3 > size) { // 더이상 괄호를 넣지 못할때는 다음 문자열봄.
        solve(inx + 1);
    } else {
        if (!checkBrace(str1[inx])) { // 숫자일때만 괄호 넣음
            aa[inx] = '(';
            for (int i = inx + 3; i <= size; i += 2) {
                aa[i] = ')';
                solve(i + 1);
                aa[i] = 0;
            }
            aa[inx] = 0;
        }
    }

}

int main() {

    cin >> tc;
    for (int T = 1; T <= tc; ++T) {
        cin >> size;
        cin >> str1;
        memset(aa, 0, sizeof(aa));
        ans = MIN;

        for (int i = 0; i < size - 2; ++i) {
            //괄호를 넣을수 있는 마지막 위치 size-2
            solve(i);// 괄호를 둘 수 있는 시작 인덱스
        }

        cout<<"#"<<T<<" "<<ans<<'\n';
    }

    return 0;
}

//tc8
//1
//7 N문자열길이  <=17
//1-3*3-8  ans  : 10

