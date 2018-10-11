#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int DESKMAX = 11;
const int CUSTOMERMAX = 1010;

int TC, N, M, K, A, B, ans, DONE;

int a1[DESKMAX]; // a창구들의 처리시간 저장
int b1[DESKMAX]; // b창구들의 처리시간 저장

int k[CUSTOMERMAX]; // 고객들의 도착시간

int forget[CUSTOMERMAX];

queue<int> qa; // 접수대기열
queue<int> qb; // 정비대기열

int reCepDesk[DESKMAX][2]; // 접수창구가 가져야할 변수 [][0]: 처리하고있는 고객번호, [][1]: 남은 처리시간
int rePairDesk[DESKMAX][2];

int whereisEmptyRepair() {
    int ret = -1;

    for (int i = 1; i <= M; ++i) {
        //접수 창구중에서
        if (rePairDesk[i][0] == 0) {
            // 빈 창구는 고객번호가 0으로 처리했음.
            ret = i; // 빈 창구의 번호를 알려줍시다.
            return ret;
        }
    }

    return ret;
}

int whereisEmptyRecep() {
    int ret = -1;

    for (int i = 1; i <= N; ++i) {
        //접수 창구중에서
        if (reCepDesk[i][0] == 0) {
            // 빈 창구는 고객번호가 0으로 처리했음.
            ret = i; // 빈 창구의 번호를 알려줍시다.
            return ret;
        }
    }

    return ret;
}

void initDesk() {
    memset(reCepDesk, 0, sizeof(reCepDesk));
    memset(rePairDesk, 0, sizeof(rePairDesk));
    memset(forget,0, sizeof(forget));
}

void find(vector<int> memoRecep[], vector<int> memoRepair[]) {


    int tmp = 0;
    for (int i = 0; i < memoRecep[A].size(); ++i) {
        forget[memoRecep[A][i]]+=1;
    }

    for (int j = 0; j < memoRepair[B].size(); ++j) {
        forget[memoRepair[B][j]]+=1;
    }

    for (int l = 1; l <= K; ++l) {
        if( forget[l] == 2){
            tmp+=l;
        }
    }

    ans = tmp;
}

void run(vector<int> memoRecep[], vector<int> memoRepair[]) {
    int t = 0;

    initDesk();

    while (DONE != K) {
        for (int i = 1; i <= K; ++i) {
            if (t == k[i]) { // 현재시간에 도착하신분들은
                qa.push(i); // 고객번호를 가지고 줄서세요.
            }else if( t < k[i]){
                break;
            }
        }

        //줄에 사람있어요.
        while (!qa.empty()) {
            int ret = whereisEmptyRecep();
            if (ret != -1) {
                //비어있는 창구가 있네요.
                int num = qa.front();
                qa.pop();
                reCepDesk[ret][0] = num;// 창구로 보낼게요.
                //접수창구 기록에 추가할게여.
                reCepDesk[ret][1] = a1[ret]; //남은 처리시간 카운트
                memoRecep[ret].push_back(num);

            }else{
                break;
            }
        }

        while (!qb.empty()) {
            int ret = whereisEmptyRepair();
            if (ret != -1) {
                int num = qb.front();
                qb.pop();
                rePairDesk[ret][0] = num;
                rePairDesk[ret][1] = b1[ret];
                memoRepair[ret].push_back(num);
            }else{
                break;
            }
        }

        t++; //시간 갱신

        //접수창구 처리시간 갱신
        for (int j = 1; j <= N; ++j) {
            if (reCepDesk[j][0] > 0) {
                reCepDesk[j][1]--; // 처리시간 줄이기
                if (reCepDesk[j][1] == 0) { // j번 접수 창구 다 처리했습니다.
                    qb.push(reCepDesk[j][0]); // 접수창구에 있던 고객 정비대기열로
                    reCepDesk[j][0] = 0; // 접수창구 고객번호 갱신 0: 창구에 고객없음.
                }
            }
        }
        //정비창구 처리시간 갱신
        for (int l = 1; l <= M; ++l) {
            if (rePairDesk[l][0] > 0) {
                rePairDesk[l][1]--;
                if (rePairDesk[l][1] == 0) {
                    DONE+=1; // 정비끝난 고객은 서베이 하세요.
                    rePairDesk[l][0] = 0;
                }
            }
        }
    }
}



void init() {
    memset(a1, 0, sizeof(a1));
    memset(b1, 0, sizeof(b1));
    memset(k, 0, sizeof(k));
    ans = 0;
    DONE = 0; // 서베이한 고객 수
}

int main() {
    cin >> TC;

    for (int T = 1; T <= TC; ++T) {
        cin >> N >> M >> K >> A >> B;

        init();

        for (int i = 1; i <= N; ++i) {
            cin >> a1[i];
        }

        for (int i = 1; i <= M; ++i) {
            cin >> b1[i];
        }

        for (int i = 1; i <= K; ++i) {
            cin >> k[i];
        }

        vector<int> memoRecep[DESKMAX];
        vector<int> memoRepair[DESKMAX];

        run(memoRecep, memoRepair); // 정비소 영업

//        for (int j = 1; j <= N ; ++j) {
//            for (int i = 0; i < memoRecep[j].size(); ++i) {
//                cout<<memoRecep[j][i]<<" ";
//            }
//            cout<<"\n";
//        }
//        cout<<"\n";
//
//
//        for (int l = 1; l <= M ; ++l) {
//            for (int i = 0; i < memoRepair[l].size(); ++i) {
//                cout<<memoRepair[l][i]<<" ";
//            }
//            cout<<"\n";
//        }
//        cout<<"\n";


        find(memoRecep, memoRepair); // 지갑잃어버린 고객찾을게요.

        cout << "#" << T << " ";
        if( ans == 0){
            cout<<-1<<"\n";
        }else{
            cout<<ans<<"\n";
        }

    }
    return 0;
}