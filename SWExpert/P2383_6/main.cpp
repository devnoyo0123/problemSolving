// 점심식사 새로 짠 코드

#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <queue>

using namespace std;

struct Node {
    int row;
    int col;
    int dist;
    int stairNo;
};

const int MAX = 20;
const int PMAX = 10;

int TC, N, ans , res;
int map[MAX][MAX];
vector<Node> people;
vector<Node> stairs;
int stair[2][3];

int checkStairs(int stairNo) {
    for (int i = 0; i < 3; ++i) {
        if (stair[stairNo][i] == 0) {
            return i;
        }
    }
    return -1;
}

void simulate() {
    queue<Node> waitingQ[2];

    for (int i = 0; i < (int) people.size(); ++i) {
        waitingQ[people[i].stairNo].push(people[i]);
    }

    int pDone = 0; //계단을 나 내려온 사람 수
    int t = 0;
    memset(stair, 0, sizeof(stair));

    while (pDone < (int) people.size()) {
        // 계단 내려가기
        t++;

        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (stair[i][j] > 0) {
                    stair[i][j]--;
                    if (stair[i][j] == 0) {
                        pDone++;
                    }
                }
            }
        }

        // 현재 거리가 다 된사람이 있으면
        for (int k = 0; k < 2; ++k) {
            if( !waitingQ[k].empty() ){ // 코드를 잘 이해해보자. 지금은 큐에있는 애들 전체를 갱신하기 위함이야.
                // 그런데 이 코드는 큐에 노드가 있으면 계속 반복되지?
                // 내가 원하는 로직은 큐에 있는 데이터를 한번 훑어보는건데
                // 이건 한번 훑어보는게 아니고 큐가 빌때까지 계속 반복하네? 이러면
                // 1분동안 거리가 0까지 되게 만드는 이상한 로직이 되네?
                Node tmp = waitingQ[k].front();
                waitingQ[k].pop();
                tmp.dist -= 1;
                if (tmp.dist <= 0) {

                    int ret = checkStairs(tmp.stairNo);
                    if (ret != -1) {
                        //비어잇으면 계단에 넣어주세요.
                        stair[tmp.stairNo][ret] = stairs[tmp.stairNo].dist;
                        //stairs의 dist는 계단을 내려가는 시간을 넣어줬습니다.
                    } else {
                        // 계단이 꽉찼으면 웨이팅큐에 넣어주세요.
                        waitingQ[tmp.stairNo].push(tmp);
                    }
                } else {
                    //아직 거리가 안됐으면 큐에 넣어서 시간 계속 줄여주세요.
                    waitingQ[tmp.stairNo].push(tmp);
                }
            }
        }

    }

    res = t;
}

void calc() {
    int size = (int) people.size();
    for (int i = 0; i < size; i++) {
        int dist = abs(stairs[people[i].stairNo].row - people[i].row) +
                   abs(stairs[people[i].stairNo].col - people[i].col);
        people[i].dist = dist + 1;// 입구에서 1분 더 기다림
    }
}


void solve(int index) {
    // 이 함수는 사람수만큼 어떤계단을 정할지 선택하고 모두가 선택했을시엔
    // 거리 계산과 시뮬레이션함수를 호출하여 답을 구한다.
    if (index == (int) people.size()) {
        calc();
        simulate();
        if( ans > res){
            ans = res;
        }
        return;
    }

    people[index].stairNo = 0;
    solve(index + 1);
    people[index].stairNo = 1;
    solve(index + 1);

}

int main() {

    cin >> TC;
    for (int T = 1; T <= TC; ++T) {
        cin >> N;
        memset(map, 0, sizeof(map));
        ans = 987654321;
        stairs.clear();
        people.clear();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; ++j) {
                cin >> map[i][j];
                if (map[i][j] == 1) {
                    Node p;
                    p.row = i;
                    p.col = j;
                    p.dist = 0;
                    p.stairNo = 0;
                    people.push_back(p);
                } else if (map[i][j] > 1) {
                    Node s;
                    s.row = i;
                    s.col = j;
                    s.dist = map[i][j];
                    s.stairNo = 0;
                    stairs.push_back(s);
                }
            }
        }

        solve(0);
        cout<<"#"<<T<<" "<<ans<<"\n";

    }
    return 0;
}