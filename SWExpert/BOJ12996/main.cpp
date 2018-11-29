#include <cstdio>

const int MAX = 51;

int S, A, B, C;

int d[MAX][MAX][MAX][MAX]; // N번째 곡을 부른 경우의 수

int main() {

    scanf("%d %d %d %d", &S, &A, &B, &C);




    for (int i = 2; i <= S; ++i) {
        d[i][A][B][C] =
        d[i-1][A-1][B][C] +
        d[i-1][A][B-1][C] +
        d[i-1][A][B][C-1] +
        d[i-1][A-1][B-1][C] +
        d[i-1][A-1][B][C-1] +
        d[i-1][A-1][B-1][C-1];
    }

    return 0;
}