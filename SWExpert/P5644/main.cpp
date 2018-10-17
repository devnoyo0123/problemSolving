#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

const int MAX = 101;
const int MAPMAX = 11;
const int APMAX = 8;

int tc, ans, M, A;
int map[MAPMAX][MAPMAX];
int bc[MAPMAX][MAPMAX][APMAX]; // [row][col][bc순서]

int posA[MAX];
int posB[MAX];

int dLocation[][2] = {{0,  0,},
                      {-1, 0},
                      {0,  1},
                      {1,  0},
                      {0,  -1}};
// 0: 이동안하고 [][0] :row, [][1]:col;

struct AP {
    int row;
    int col;
    int coverage;
    int capacity;
};

struct Human {
    int row;
    int col;
    int curAP;
};

Human human[2];

void solve(vector<AP> &aps, vector<int> &sum) {

    int size = (int)aps.size();


    for (int i = 0; i <= M; ++i) {

        //  이동
        human[0].row += dLocation[posA[i]][0];
        human[0].col += dLocation[posA[i]][1];

        human[1].row += dLocation[posB[i]][0];
        human[1].col += dLocation[posB[i]][1];


        //  충전량 계산.
        int max = 0;
        for (int j = 0; j < size ; ++j) {
            int aRow = human[0].row;
            int aCol = human[0].col;
            int tmp = 0;
            if( bc[aRow][aCol][j] > 0){
                tmp += bc[aRow][aCol][j];
                human[0].curAP = j;
            }else{
                human[0].curAP = -1;
            }

            for (int k = 0; k < size; ++k) {

                int bRow = human[1].row;
                int bCol = human[1].col;
                if( bc[bRow][bCol][k] > 0){
                    tmp += bc[bRow][bCol][k];
                    human[1].curAP = k;
                }else{
                    human[1].curAP = -1;
                }

                if( human[0].curAP == human[1].curAP && human[0].curAP != -1){
                    tmp/=2;
                }


                if( max < tmp){
                    max = tmp;
                }
            }
        }
        sum[i] = max;
    }
}

void BFS(AP ap, int order) {
    queue<AP> q;
    int row = ap.row;
    int col = ap.col;
    int capacity = ap.capacity;
    bc[row][col][order] = capacity;
    q.push(ap);
    while (!q.empty()) {
        AP tmp = q.front();
        q.pop();

        if (tmp.coverage == 0) {
            continue;
        }

        for (int i = 1; i < 5; ++i) {
            int nRow = tmp.row + dLocation[i][0];
            int nCol = tmp.col + dLocation[i][1];

            if (nRow >= 1 && nRow <= 10 && nCol >= 1 && nCol <= 10) {
                if (bc[nRow][nCol][order] == 0) {
                    AP nAP;
                    nAP.row = nRow;
                    nAP.col = nCol;
                    nAP.coverage = tmp.coverage - 1;
                    nAP.capacity = tmp.capacity;
                    bc[nRow][nCol][order] = tmp.capacity;
                    q.push(nAP);
                }
            }
        }
    }
}

int main() {

    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> M >> A;

        // 초기화
        human[0].row = 1;
        human[0].col = 1;
        human[0].curAP = -1;


        human[1].row = 10;
        human[1].col = 10;
        human[1].curAP = -1;


        vector<AP> aps;
        memset(posA, 0, sizeof(posA));
        memset(posB, 0, sizeof(posB));
        memset(bc, 0, sizeof(bc));


        for (int i = 1; i <= M; ++i) {
            cin >> posA[i];
        }

        for (int i = 1; i <= M; ++i) {
            cin >> posB[i];
        }

        for (int i = 0; i < A; i++) {
            AP tmp;
            cin >> tmp.col >> tmp.row >> tmp.coverage >> tmp.capacity;
            aps.push_back(tmp);
        }

        //map making
        int size = (int) aps.size();
        for (int j = 0; j < size; ++j) {
            BFS(aps[j], j);
        }

        vector<int> sum(MAX);
        solve(aps, sum);


        int ans = 0;
        for (int i = 0; i <=M; ++i) {
            ans += sum[i];
        }

        printf("#%d %d\n", t, ans);

    }

    return 0;
}