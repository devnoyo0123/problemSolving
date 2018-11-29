#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int r, c;
    Node(){}
    Node(int r,int c) : r(r),c(c){}
};

int map[50][50];
int tmp[50][50];
bool check[50][50];
int n, L, R, sum;
vector<Node> v;
int dr[] = { 0, 0, 1 , -1 };
int dc[] = { 1,-1,0,0 };

void dfs(int r, int c) {
    check[r][c] = true;
    sum += map[r][c];
    v.push_back(Node(r, c));

    for (int i = 0; i < 4; i++) {
        int ar = r + dr[i];
        int ac = c + dc[i];
        if (ar >= 0 && ac >= 0 && ar < n&&ac < n && !check[ar][ac]) {
            int diff = abs(map[r][c] - map[ar][ac]);
            if (L <= diff && diff <= R) {
                dfs(ar, ac);
            }
        }
    }
}

void clear1() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmp[i][j] = 0;
            check[i][j] = 0;
        }
    }
}

void copyArray() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            map[i][j] = tmp[i][j];
        }
    }
}

int main(){
    scanf("%d %d %d", &n, &L, &R);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    int res = 0;
    while (true) {
        bool flag = false;

        clear1();//배열 초기화

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                //방문하지 않는 곳만 체크
                if (!check[i][j]) {
                    sum = 0;
                    //탐색
                    dfs(i, j);

                    //인구합 / 연합크기
                    int avg = sum / v.size();

                    //연합하지 못했으면 continue
                    if (v.size() == 1) {
                        tmp[i][j] = map[i][j];
                        continue;
                    }

                    //연합 체크
                    flag = true;

                    //tmp배열에 복사
                    for (Node node : v) {
                        tmp[node.r][node.c] = avg;
                    }
                }
            }
        }

        copyArray(); // 배열 복사

        if (!flag) break;

        res++;
    }

    printf("%d\n", res);
}

//http://2youngjae.tistory.com/169