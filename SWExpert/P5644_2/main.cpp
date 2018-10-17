#include <cstdio>
#include <algorithm>

using namespace std;

const int maxu = 2;
const int maxn = 100;
const int maxa = 8;
int T, M, A;

struct {
    int x, y;

}user[maxu];

int move1[maxu][maxn];

struct{
    int x, y;
    int d; // 통신범위
    int p; // 성능
    bool u; // 사용했는지 여부
}ap[maxa];

const int dx[5] = {0, 0, 1, 0, -1};
const int dy[5] = {0, -1, 0, 1, 0}; // 이동 x, 북, 동, 남, 서

void init(){
    // 두명의 유저 위치 변경
    user[0].x = 1;
    user[0].y = 1;
    user[1].x = 10;
    user[1].y = 10;
    
    //모든 ap 사용안한 것으로 초기화
    for (int i = 0; i < A; ++i) {
        ap[i].u = 0;
    }        
}

void read(){
    // M: 이동시간 , A: ap 이동시간
    scanf("%d %d", &M, &A);

    // 두명의 유저 이동 정보 저장
    for (int i = 0; i < maxu; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%d", &move1[i][j]);
        }
    }

    //ap 정보저장
    for (int i = 0; i < A; ++i) {
        scanf("%d%d%d%d", &ap[i].x, &ap[i].y, &ap[i].d, &ap[i].p);
    }
}
// ap가 범위 안에 있는지 체크
bool check(int a, int b){
    int dist = abs(user[a].x - ap[b].x) + abs(user[a].y - ap[b].y);
    return dist <= ap[b].d;
}
int ret = 0;
void dfs(int user, int d){ // 사용자 숫자, 현재까지 사용한 데이터양
    if( user == maxu){
        // u명의 사용자를 다 확인한 경
        ret = max(ret, d);
        return;
    }
    
    
    //모든 ap 탐색
    for (int i = 0; i < A; ++i) {
        if(!ap[i].u && check(user, i)){
            //다른사용자가 지금 ap쓰지 않고, 범위 안에 있는경
            ap[i].u = true;
            dfs(user+ 1, d + ap[i].p);
            ap[i].u = false;
        }
    }
    //현재 사용자 u는 ap를 접속하지 않은 경우 다음 사용자로 이동
    dfs(user+1, d);

}

int count(){
    ret = 0;
    dfs(0,0);
    return ret;
}

int solve(){
    int ans = 0;
    ans += count();

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < maxu; ++j) {
            user[j].x += dx[move1[j][i]];
            user[j].y += dy[move1[j][i]];
        }
        ans += count();
    }
    return ans;
}
int main() {
    scanf("%d", &T);
    for (int t = 1; t <= T ; ++t) {
        read();
        init();
        printf("#%d %d\n", t, solve());
    }
    return 0;
}