#include <iostream>
#include <climits>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int PMAX = 11;
const int StairMAX = 3;

int N, TC, ans;

struct Person1 {
    int row;
    int col;
    int stairNo;
    int dist;

};

struct Stair1 {
    int row;
    int col;
    int restTime;
    int rest[StairMAX][2]; //[][0]: 사람번호, [][1] : 남은시간

};

Person1 p[PMAX];
Stair1 s[StairMAX];

int pSize = 1; // 사이즈보다 1큼.
int sSize = 1;

int pCnt = 0; // 완료한 사람 수



int isEmptyStair(int stairNo) {
    int ret = -1; // 꽉차있어요.

    for (int j = 0; j < StairMAX; ++j) {
        if (s[stairNo].rest[j][0] == 0) { // 사람번호가 0 은 비어있음으로 표시

            ret = j;
            return ret;
        }
    }

    return ret;
}

bool cmp1(const Person1 &a, const Person1 &b) {
    return a.dist < b.dist;
}

void getDist(int inx) {
    if (p[inx].stairNo == 1) {
        int temp1 = abs(p[inx].row - s[1].row);
        int temp2 = abs(p[inx].col - s[1].col);
        int dist = temp1 + temp2;

        //계단입구에서 1분 더 기다려야하므로
        p[inx].dist = dist + 1;
    } else if (p[inx].stairNo == 2) {
        int temp1 = abs(p[inx].row - s[2].row);
        int temp2 = abs(p[inx].col - s[2].col);
        int dist = temp1 + temp2;

        //계단입구에서 1분 더 기다려야하므로
        p[inx].dist = dist + 1;
    }
}

void simulate() {

    queue<pair<int,int> >qu1; // first: 사람번호, second: 계단번호
    queue<pair<int,int> >qu2;

    for (int i = 1; i < pSize; ++i) {
        getDist(i);
    }

    sort(p, p + pSize, cmp1);

    int t = 0;// 시간초기화
    pCnt = 1; // pSize 처럼 크기보다 1큼.






    while (pSize != pCnt) {

        for (int i = pCnt; i < pSize; ++i) {
            if (t == p[i].dist) {
                // 내려갈 시간이 돼었으면 내려갈 사람이 계단 큐로 들어갑니다.
                {
                    int No = i;
                    int StairNo = p[i].stairNo;
                    //내려가려는 계단이 1입니다.

                    (StairNo == 1 ? qu1 : qu2).push(make_pair(No,StairNo)); // 첫번째 계단에 기다리는 사람의 번호를 넣어줄게요.
                }
            }else if(t < p[i].dist){
                break;
            }
        }

        while (!qu1.empty()) {
            // 대기하는 사람이 없으면 할 작업이 없어요.

            // 대기하는 사람이 있으면
            int ret = isEmptyStair(qu1.front().second);
            if (ret != -1) {
                //비어있음
                int No = qu1.front().first; qu1.pop();
                s[1].rest[ret][0] = No;
                s[1].rest[ret][1] = s[1].restTime; // 남은시간 세팅
            }else{
                // 계단이 꽉찼으면 넣을 곳이 없어요. 기다리세요.
                break;
            }
        }

        while (!qu2.empty()) {

            // 대기하는 사람이 있으면
            int ret = isEmptyStair(qu2.front().second);
            if (ret != -1) {
                //비어있음
                int No = qu2.front().first; qu2.pop();
                s[2].rest[ret][0] = No;
                s[2].rest[ret][1] = s[2].restTime; // 남은시간 세팅
            }else{
                break;
            }
        }


        // 현재 계단에 사람있으면 시간 갱신
        for (int j = 1; j < sSize; ++j) {
            for (int i = 0; i < StairMAX; ++i) {
                int No = s[j].rest[i][0];
                if( No > 0){
                    //내려가는 사람이 있어요.
                    int rest = s[j].rest[i][1];
                    rest-=1;
                    s[j].rest[i][1]=rest;
                    // 왜 s[j].rest[i][1] -=1; 안먹히지?

                    if(rest == 0){
                        s[j].rest[i][0] = 0; // 계단 내려갈수 있다고 표시
                        // 다 내려갔으면
                        pCnt+=1;
                    }
                }
            }
        }

        t+= 1;

    }

    // 모든 사람이 다 완료했음. 완료한 시간이 최소인지 비교하고 갱신
    if( ans > t){
        ans = t;
    }
}

void go(int inx, int Size) {


    if (inx > Size) {

        // 계단 초기화
        for (int j = 1; j < sSize; ++j) {
            for (int i = 0; i < StairMAX; ++i) {
                s[j].rest[i][0] = 0;
                s[j].rest[i][1] = 0;
            }
        }

        simulate();

        return;
    }
    p[inx].stairNo = 1;
    go(inx + 1, pSize);
    p[inx].stairNo = 2;
    go(inx + 1, pSize);

}

void init(){
    for (int i = 0; i < PMAX; ++i) {
        p[i].row = 0;
        p[i].col = 0;
        p[i].stairNo = 0;
        p[i].dist = 0;
    }

    for (int j = 0; j < StairMAX; ++j) {
        s[j].row = 0;
        s[j].col = 0;
        s[j].restTime = 0;
        for (int i = 0; i < StairMAX; ++i) {
            for (int k = 0; k < 2; ++k) {
                s[j].rest[i][k] = 0;
            }
        }
    }
}

int main() {

    cin >> TC;
    for (int T = 1; T <= TC; ++T) {
        cin >> N;
        pSize = 1;
        sSize = 1;
        ans = INT_MAX;

        memset(p, 0, sizeof(p));
        memset(s, 0, sizeof(s));

        init();

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                int tmp = 0;
                cin >> tmp;
                if (tmp == 1) {

                    p[pSize].row = i;
                    p[pSize].col = j;
                    p[pSize].stairNo = 0;
                    p[pSize].dist =0;

                    pSize+=1;
                } else if (tmp > 1) {

                    s[sSize].row = i;
                    s[sSize].col = j;
                    s[sSize].restTime = tmp;
                    sSize+=1;
                }
            }
        }

        go(1, pSize);

        cout << "#" << T << " " << ans << "\n";

    }
    return 0;
}