#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#define p pair<int,int>
using namespace std;

// 동서남북
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int map[700][700];

int n,m,k;
int ans;

struct Node{
    int x;
    int y;
    int time;
    Node(int a, int b, int c): x(a),y(b),time(c){};
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int TC;
    cin >> TC;

    for(int tc=1; tc<=TC; tc++){
        memset(map,0,sizeof(map));
        ans = 0;
        cin >> n >> m >> k;

        /*
         생명령을 기준으로 처리할 것이기에
         큐를 11 사이즈로 잡는다.
         (1 ~ 10 까지의 생명력을 갖는다는 조건)
         */
        queue<Node> q[11];

        for(int i=350; i<n+350; i++){
            for(int j=350; j<m+350; j++){
                cin >> map[i][j];
                if(map[i][j])
                    /*
                     초기 상태에서 죽을 때까지
                     총 걸리는 시간은
                     [ 주어진 시간 * 2 ] 시간이다.
                     */
                    q[ map[i][j] ].push( Node(i, j, map[i][j]*2) );
            }
        }

        while (k--) {
            for(int i=10; i>=1; i--){
                int size = (int) q[i].size();
                /*
                 i = 8 일 때
                 8만큼의 생명력을 갖고 있는 줄기 세포만을 갖고 있는
                 큐에 대해서 작업을 할 것이다.
                 */
                for(int j=0; j<size; j++){
                    int x = q[i].front().x;
                    int y = q[i].front().y;
                    int time = q[i].front().time;
                    q[i].pop();

                    time--;
                    /*
                     i = 8 일 때
                     map[x][y] = 8
                     time은 16에서 지속적으로 줄어든다.
                     이 때
                     map[x][y] > time이 된다면
                     즉 [ 비활성화 -> 활성 ] 상태가 되는
                     그 순간에만 번식을 하게 된다.
                     그 이후로는 map[nx][ny]값이 0이 아니기 때문에
                     실질적인 작업이 이뤄지지 않는다.
                     */
                    if(map[x][y] > time){
                        for(int k=0; k<4; k++){
                            int nx = x + dx[k];
                            int ny = y + dy[k];
                            if(map[nx][ny] == 0){
                                map[nx][ny] = map[x][y];
                                q[i].push( Node(nx,ny,map[nx][ny]*2) );
                            }
                        } // end of for k
                    } // end of if

                    /*
                     i = 8 일 때
                     map[x][y] = 8로 고정이 되어 있고
                     time 값은 지속적으로 줄어든다.
                     이 때 8을 기준으로
                     8보다 크면 비활성화
                     8보다 작으면 활성화 상태이다.
                     그리고 time이 0이 된다면 죽은 상태가 된다.
                     그렇기 때문에 활성화 상태에서 죽기까지
                     해당 줄기 세포에 대해서는
                     지속적으로 생존 시간만 감소시켜야 한다.
                     그리고 time이 0이 된다면 죽은 상태가 되기 때문에
                     큐에 다시 push를 하지 않는다.
                     // 물론 활성화 상태에서 위 if문에 들어가지만
                     // map[nx][ny] 값이 0이 아니기 때문에
                     // 실질적인 작업은 이뤄지지 않는다.
                     // 즉 번식은 1번만 이뤄진다.
                     */
                    if(time > 0){
                        q[i].push(Node(x,y,time));
                    }
                } // end of for j
            } // end of for i
        } // end of while

        /*
         i값은 생명력을 뜻한다.
         q[i]에 남아있는 Node들은
         활성화 / 비활성화 상태 종류들 뿐이다.
         죽은 상태는 큐에 다시 push를 해주지 않았기 때문이다.
         */
        for(int i=1; i<11; i++)
            ans += q[i].size();

        cout << "#" << tc << " " << ans << endl;
    }

    return 0;
}