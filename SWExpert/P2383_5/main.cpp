#include <iostream>
#include <climits>
#include <algorithm>
#include <cstring>
#include <queue>

#define p pair<int, int>

using namespace std;


int N, TC, ans;


struct Node{
    int x;
    int y;
    int target;
    int value;
    Node(int _x, int _y) : x(_x), y(_y) {};
    Node(int _x, int _y, int _value) : x(_x), y(_y), value(_value){};
};
vector<Node> n_v; // n_v is node vector
vector<Node> s_v; // s_v is stair vector

int distance(int n_idx, int s_idx){
    int x = abs(n_v[n_idx].x - s_v[s_idx].x);
    int y = abs(n_v[n_idx].y - s_v[s_idx].y);
    return x + y +1;
}


int choice[15];

int pCnt = 0; // 완료한 사람 수


void simulate() {


    queue<int> qu1; //
    queue<int> qu2;

    queue<int> waitingQ1;
    queue<int> waitingQ2;

    for (int i = 0; i < n_v.size(); ++i) {
        int dist = distance(i,n_v[i].target);
        if(n_v[i].target == 0){
            waitingQ1.push(dist);
        }else{
            waitingQ2.push(dist);
        }
    }

    int t = 0;// 시간초기화
    pCnt = 0; // pSize 처럼 크기보다 1큼.

    while (n_v.size() > pCnt) {

        t++;

        int size = (int)qu1.size();
        for (int i = 0; i < size; ++i) {

            int front = qu1.front(); qu1.pop();
            front--;
            if( front > 0){
                qu1.push(front);
            }else if (front == 0){
                pCnt++;
            }
        }


        size = (int)qu2.size();
        for (int i = 0; i < size; ++i) {

            int front = qu2.front(); qu2.pop();
            front--;
            if( front > 0){
                qu2.push(front);
            }else if (front == 0){
                pCnt++;
            }
        }

        size = (int)waitingQ1.size();
        for (int k = 0; k < size; ++k) {
            int dist = waitingQ1.front(); waitingQ1.pop();
            dist-=1;
            if( dist <= 0){
                if( qu1.size() < 3){
                    qu1.push(s_v[0].value);

                }else{
                    waitingQ1.push(dist);

                }
            }else{
                waitingQ1.push(dist);
            }
        }

        size =  (int)waitingQ2.size();
        for (int k = 0; k < size; ++k) {
            int dist = waitingQ2.front(); waitingQ2.pop();
            dist-=1;
            if( dist <= 0){
                if( qu2.size() < 3){
                    qu2.push(s_v[1].value);

                }else{
                    waitingQ2.push(dist);

                }
            }else{
                waitingQ2.push(dist);
            }
        }


    }

    // 모든 사람이 다 완료했음. 완료한 시간이 최소인지 비교하고 갱신
    ans = ans < t ? ans : t;

}

void go(int inx) {

    if (inx == n_v.size()) {
        simulate();
        return;
    } else {
        n_v[inx].target = 0;
        go(inx + 1);
        n_v[inx].target = 1;
        go(inx + 1);
    }
}


int main() {

    cin >> TC;
    for (int T = 1; T <= TC; ++T) {
        cin >> N;


        ans = INT_MAX;
        n_v.clear();
        s_v.clear();

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                int tmp = 0;
                cin >> tmp;
                if (tmp == 1) {
                    n_v.push_back(Node(i, j));
                } else if (tmp > 1) {
                    s_v.push_back(Node(i, j,tmp));
                }
            }
        }

        go(0);

        cout << "#" << T << " " << ans << "\n";

    }
    return 0;
}