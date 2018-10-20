#include <cstdio>
#include <cstring>
#include <cmath>

const int MAX = 100;
const int ARRAYMAX = 1024;

int N;
int dx[] = {1, 0, -1, 0}; // EAST, NORTH, WEST, SOUTH
int dy[] = {0, -1, 0, 1};
bool map[MAX + 1][MAX + 1];
int curves[ARRAYMAX + 30];

int countVertex() {
    int count = 0;
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {

            if (map[i][j] && map[i][j + 1] && map[i + 1][j] && map[i + 1][j + 1]) {
                count++;
            }

        }
    }
    return count;
}

void simulate(int x, int y, int g) {
    int nX = x, nY = y;
    map[nY][nX] = true;
//    printf("check! row: %d, col: %d\n", nY, nX);

    for (int i = 0; i < 1 << g; ++i) {
        if (curves[i] > 3) {
            curves[i] %= 4;
        }
        int tempX = nX + dx[curves[i]];
        int tempY = nY + dy[curves[i]];

        nX = tempX;
        nY = tempY;
        map[nY][nX] = true;
//            printf("check! row: %d, col: %d\n", nY, nX);

    }
}

void getCurves(int d, int g) {
    curves[0] = d;
    for (int i = 1; i <= g; ++i) {
        for (int j = 1 << (i - 1); j < 1 << i; ++j) {
            curves[j] = curves[(1 << i) - (j + 1)] + 1;
        }
    }

}

int main() {

    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        int x1, y1, d1, g1;
        scanf("%d %d %d %d", &x1, &y1, &d1, &g1);
        memset(curves, 0, sizeof(curves));
        getCurves(d1, g1);
        simulate(x1, y1, g1);
    }

    printf("%d\n", countVertex());


    return 0;
}