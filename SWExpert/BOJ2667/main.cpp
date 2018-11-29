#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct points{
    points(int r, int c){
        row = r;
        col = c;
    }
    int row,col;
};

const int MAX = 25;
const int VILLMAX = 525;

int n1;
char buf[MAX+2];

int dRow[] = {-1, 0, 1, 0};
int dCol[] = {0, 1, 0, -1};

int cnt[VILLMAX];
int map[MAX][MAX];
bool check[MAX][MAX];
vector<points> danji[VILLMAX];

bool cmpSize(const vector<points> &a, const vector<points> &b) {
    return a.size() < b.size();
}


void DFS(int row, int col, int danjiNum) {
    danji[danjiNum].push_back(points(row,col));
    check[row][col] = true;
    map[row][col] = danjiNum;
    cnt[danjiNum] += 1;
    for (int i = 0; i < 4; ++i) {
        int nRow = row + dRow[i];
        int nCol = col + dCol[i];

        if (nRow < 0 || nRow >= n1 || nCol < 0 || nCol >= n1) {
            continue;
        }

        if (check[nRow][nCol]) {
            continue;
        }

        if (map[nRow][nCol] == 1) {
            DFS(nRow, nCol, danjiNum);
        }
    }
}

int main() {

    int danjiNum = 1;
    scanf("%d", &n1);
    for (int i = 0; i < n1; ++i) {
        memset(buf, 0, sizeof(buf));
        scanf("%s", buf);
        for (int j = 0; j < n1; ++j) {
            map[i][j] = buf[j] - '0';
        }
    }

    for (int k = 0; k < n1; ++k) {
        for (int i = 0; i < n1; ++i) {
            if (map[k][i] == 1 && !check[k][i]) {
                DFS(k, i, danjiNum);
                danjiNum += 1;
            }
        }
    }

    sort(danji, danji + VILLMAX, cmpSize);
//    sort(cnt, cnt+VILLMAX);
    printf("%d\n", danjiNum - 1);
    for (int l = 0; l < VILLMAX; ++l) {
        if ((int)danji[l].size() == 0) {
            continue;
        } else {
            printf("%d\n", (int)danji[l].size());
        }
    }

//    for (int l = 0; l < VILLMAX; ++l) {
//        if( cnt[l] == 0){
//            continue;
//        }else{
//            printf("%d\n", cnt[l]);
//        }
//    }


    return 0;
}
/*
25
0110100011010001101000110
0110101011010101101010110
1110101111010111101011110
0000111000011100001110000
0100000010000001000000100
0111110011111001111100111
0111000011100001110000111
0110100011010001101000110
0110101011010101101010110
1110101111010111101011110
0000111000011100001110000
0100000010000001000000100
0111110011111001111100111
0111000011100001110000111
0110100011010001101000110
0110101011010101101010110
1110101111010111101011110
0000111000011100001110000
0100000010000001000000100
0111110011111001111100111
0111000011100001110000111
0110100011010001101000110
0110101011010101101010110
1110101111010111101011110
0000111000011100001110000
*/