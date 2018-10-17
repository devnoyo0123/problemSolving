#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 25;

int TC, N, M, ans;
int map[MAX][MAX];

void check(int K, int row, int col) {
    int cnt = 0; // 서비스 제공받는 집 수
    int s = col, e = col;
//    printf("length: %d, row:%d, col:%d search \n", length, row, col);


    for (int i = row - K+1; i <= row + K-1; ++i) { // 행 마름모의 세로를 표현
        if (i >= 0 && i < N)
        {        // 마름모중 맵 안에 범위만 탐색
            for (int j = s; j <= e; ++j) {
                if (j >= 0 && j < N) {
                    if (map[i][j] == 1) {
//                        printf("row:%d, col:%d is house\n", i, j);
                        cnt++;
                    }
                }
            }
        }


        if (i < row) {
            // 마름모 모양으로 탐색할 열의수를 row, col을 중심으로 col-1에서 col+1씩 늘려주면
            // 한 행당 열의 수가 1,3,5,7 으로 늘어나게 되어있다.
            s--;
            e++;
        } else {
            s++;
            e--;
        }

    }


    //계산
    if (cnt * M >= K * K + (K - 1) * (K - 1)) {
        if (ans < cnt) {
            ans = cnt;
        }
    }

//    printf("row: %d, col: %d에서 탐색\n", row,col);
//    printf("운영지역크기: %d\n", size);
//    printf("서비스 제공받는집: %d\n", cnt);
//    printf("서비스 매출: %d\n", cnt * M);
//    printf("운영비용: %d\n", (size*size + (size-1)*(size-1)));
//    printf("순이익:%d\n", tmp);


}

void solve() {
    for (int x = 0; x < N; ++x) { //  마름모 중심 row
        for (int y = 0; y < N; ++y) { // 마름모 중심 col
            for (int size1 = 1; size1 <= (2 * N); ++size1) { // size: 마름모(운영영역의 크기)
                check(size1, x, y);
            }
        }
    }


}

int main() {

    scanf("%d", &TC);

    for (int T = 1; T <= TC; ++T) {
        scanf("%d %d", &N, &M);
        memset(map, 0, sizeof(map));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                scanf("%d", &map[i][j]);


            }
        }
        ans = 0;
        solve();
        printf("#%d %d\n", T, ans);
    }

    return 0;
}