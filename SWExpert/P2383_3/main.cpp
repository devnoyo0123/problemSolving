#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>

#define p pair<int,int>
using namespace std;

int n;
int ans;
int map[11][11];

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
    return x + y ;
}

void dfs(int idx){
    if(idx == n_v.size()){

        for (int k = 0; k < n_v.size(); ++k) {
            cout<<n_v[k].target<<" ";
        }
        cout<<"\n";

        int people_cnt = (int) n_v.size();
        int time = 0;
        int exit_cnt = 0;

        queue<int> waiting[2];
        queue<int> stair[2];

        // 각자 원하는 계단으로 가기 위한 거리 계산
        for(int i=0; i<people_cnt; i++){
            int dis = distance(i, n_v[i].target);
            waiting[n_v[i].target].push(dis);
        }

        /*
         작업 순서
         1. time++
         2. 계단에 있는 인원 내려가기
         3. 계단에 인원 추가하기
         */
        while (exit_cnt < people_cnt) {
            time ++;

            // 계단에 있는 인원 내려가기
            for(int i=0; i<2; i++){
                int size = (int) stair[i].size();
                for(int j=0; j<size; j++){
                    int top = stair[i].front();
                    stair[i].pop();
                    top--;
                    if(top != 0)
                        stair[i].push(top);
                    else
                        exit_cnt++;
                }
            }

            // 계단에 인원 추가하기
            for(int i=0; i<2; i++){
                int size = (int) waiting[i].size();
                for(int j=0; j<size; j++){
                    int dis = waiting[i].front();
                    waiting[i].pop();
                    dis--;
                    if(dis <= 0){
                        if(stair[i].size() < 3){ // 계단에 도착했지만 내려가는 인원이 Full
                            stair[i].push(s_v[i].value);
                        }
                        else{
                            waiting[i].push(dis);
                        }
                    }
                    else{
                        waiting[i].push(dis);
                    }
                }
            }
        } // end of while
        /*
        time + 1해주는 이유
        000
        130
        000 과 같이 주어졌다고 가정하자.

        내 로직대로라면
        time : 1초 
        3번 작업 수행 --> stair에 push

        time : 2초
        2번 작업 수행 --> 남은 시간 2초

        time : 3초
        2번 작업 수행 --> 남은 시간 1초

        time : 4초
        2번 작업 수행 --> 남은 시간 0초

        이렇게 while문을 탈출한다.

        그런데 이때 답은 4초가 아닌 5초를 출력해야한다.
        그래서 while문을 탈출한 시간(=time)에 +1를 해준다.
        */
        ans = ans < time+1 ? ans : time+1;
    } // end of if
    else {
        for(int i=0; i<2; i++){
            n_v[idx].target = i;
            dfs(idx+1);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC;
    cin >> TC;

    for(int tc=1; tc<=TC; tc++){
        memset(map,0,sizeof(map));
        n_v.clear();
        s_v.clear();
        cin >> n;
        ans = 2e9;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int tmp;
                cin >> tmp;
                if(tmp == 1)
                    n_v.push_back(Node(i,j));
                else if( tmp > 1)
                    s_v.push_back(Node(i,j,tmp));
            }
        }
        dfs(0);
        cout << "#" << tc << " " << ans << '\n';
    }
}
