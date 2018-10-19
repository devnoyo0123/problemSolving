// 점심식사 새로 짠 코드 PASS한 코드


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
    memset(stair, 0, sizeof(stair));

    for (int i = 0; i < (int) people.size(); ++i) {
        waitingQ[people[i].stairNo].push(people[i]);
    }

    int pDone = 0; //계단을 나 내려온 사람 수
    int t = 0;

    while (pDone < (int)people.size()){
            t ++;

            // 계단에 있는 인원 내려가기
            for(int i=0; i<2; i++){
                for(int j=0; j<3; j++){
                    if( stair[i][j] > 0){
                        stair[i][j]-=1;
                        if( stair[i][j] == 0){
                            pDone++;
                        }
                    }
                }
            }

            // 계단에 인원 추가하기
            for(int i=0; i<2; i++){
                int size = (int) waitingQ[i].size();
                for(int j=0; j<size; j++){
                    Node tmp = waitingQ[i].front();
                    waitingQ[i].pop();
                    tmp.dist--;
                    if(tmp.dist <= 0){
                        int ret = checkStairs(tmp.stairNo);
                        if(ret != -1){ // 계단에 도착했지만 내려가는 인원이 Full
                            stair[tmp.stairNo][ret] = stairs[tmp.stairNo].dist;
                        }
                        else{
                            waitingQ[i].push(tmp);
                        }
                    }
                    else{
                        waitingQ[i].push(tmp);
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