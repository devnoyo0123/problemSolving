#include <cstdio>
#include <cstring>

int map[10][10];
bool visited[10][10];
int n, m, c, res;

int max(int a, int b) {
    return (a > b) ? a : b;
}

//비용 구하기
// x: row, y: col a: 탐색한 위치, sum 현재까지 벌꿀, price 벌꿀 제곱한것
void getPrice(int x, int y, int a, int sum, int price) {
    if (sum > c) return ;
    res = max(res, price);
    if (a == m) return;

    getPrice(x, y + 1, a + 1, sum + map[x][y], price + map[x][y] * map[x][y]);
    //뽑음
    getPrice(x, y + 1, a + 1, sum, price);
    //안뽑음
}

int solve(int x, int y) {
    //먼저 고른 m개의 벌통에 대해 비용 구하기
    for (int i = 0; i < m; i++) {
        visited[x][y + i] = true;
    }
    res = 0;
    getPrice(x, y, 0, 0, 0);
    int priceA = res;

    //나중에 고른 m개의 벌통에 대해 비용 구하며 비교하기
    int priceB = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-m+1; j++) {
            if (!visited[i][j]) {
                res = 0;
                getPrice(i, j, 0, 0, 0);
                priceB = max(priceB, res);
            }
        }
    }

    return priceA + priceB;
}

void init() {
    memset(visited, 0, sizeof(visited));
    memset(map, 0, sizeof(map));
}

int main() {
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++) {
        init();
        scanf("%d %d %d", &n, &m, &c);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &map[i][j]);
            }
        }

        int mm = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n-m+1; j++) {
                mm = max(mm, solve(i, j));
            }
        }
        printf("#%d %d\n", tc, mm);
    }
}

//http://2youngjae.tistory.com/92?category=731883