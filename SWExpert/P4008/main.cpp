#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

const int MAX = 12;

long long ans = 0;
long long TC, N, max1, min1;
int pCnt, sCnt, mCnt, dCnt;
int digit[MAX]; // 숫자들을 가지고 있는 배열
int nums[4]; // 가지고 있는 연산자를 저장
int used[MAX - 1]; // 어떤 연산자를 사용했는지 알기 위함.
int operandCnt;

long long calc() {
    long long res = 0;
    int operator1 = -1;
    for (int i = 0; i < N; ++i) {
        if (operator1 == -1) {
            res = digit[i];
            operator1 = used[i];
        } else if (operator1 == 0) {// +
            res += digit[i];
            operator1 = used[i];
        } else if (operator1 == 1) {// -
            res -= digit[i];
            operator1 = used[i];
        } else if (operator1 == 2) {// *
            res *= digit[i];
            operator1 = used[i];
        } else if (operator1 == 3) {// /
            res /= digit[i];
            operator1 = used[i];
        }

    }
    return res;
}

void solve(int cnt) {

    if (cnt == N - 1) {

//        for (int i = 0; i < N-1; ++i) {
//            cout<< used[i]<<" ";
//        }
//        cout<<"\n";

        long long tmp = calc();
        if (tmp < min1) {
            min1 = tmp;
        }
        if (tmp > max1) {
            max1 = tmp;
        }
        return;
    }

    int tmp[MAX - 1];
    memset(tmp, 0, sizeof(tmp));
    //기본 연산자 배열 복사
    for (int i = 0; i < 4; ++i) {
        tmp[i] = nums[i];
    }

    for (int j = 0; j < 4; ++j) { // 4가지 연산자 종류 중

        if (nums[j] > 0) { // 연산할 연산자가 있으면
            nums[j]--;

            used[cnt] = j;
            solve(cnt + 1);

            for (int i = 0; i < 4; ++i) {
                nums[i] = tmp[i];
            }
        }
    }
}

int main() {

    cin >> TC;
    for (int T = 1; T <= TC; ++T) {
        cin >> N;
//        cout<<"N:"<<N<<"\n";
        operandCnt = 0;
        max1 = LLONG_MIN;
        min1 = LLONG_MAX;
        memset(digit,0, sizeof(digit));
        memset(nums,0, sizeof(nums));
        memset(used,0, sizeof(used));

        cin >> pCnt >> sCnt >> mCnt >> dCnt;


        operandCnt += pCnt;
        operandCnt += sCnt;
        operandCnt += mCnt;
        operandCnt += dCnt;

        nums[0] = pCnt;
        nums[1] = sCnt;
        nums[2] = mCnt;
        nums[3] = dCnt;

        for (int i = 0; i < N; ++i) {
            cin >> digit[i];
        }

        solve(0);
        cout << "#" << T << " " << max1-min1<< "\n";
    }

    return 0;
}