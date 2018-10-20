#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

enum way {
    RIGHT = 0,
    DOWN,
    LEFT,
    UP
};

const int MAX = 20;

int map[MAX + 2][MAX + 2];
int num;
int ans;


void go(int cnt) {
    // goal횟수만큼 보드를 기울여서 보드판의 최대값을 갱신하는 함수
    if (cnt == 5) {
        //최대값 확인 2중 for문
        //만약 최대값보다 큰 값이 있다면 갱신
        //함수 끝내기
        for (int k = 1; k <= num; ++k) {
            for (int i = 1; i <= num; ++i) {
                ans = max(ans, map[k][i]);
            }
        }
        return;
    } else {

        int temp[MAX + 2][MAX + 2];
        memset(temp, -1, sizeof(temp));
        for (int i = 1; i <= num; i++)
            for (int j = 1; j <= num; j++)
                temp[i][j] = map[i][j];


        for (int k = 0; k < 4; ++k) {
            // i 0      1       2       3
            //   right  down    left    up
            //왼쪽으로 기울임
            if (k == LEFT) {
                int i = 1, j = 2;
                for (i = 1; i <= num; ++i) {
                    for (j = 1; j <= num; ++j) {


                        for (int pos = j + 1; pos <= num; pos++) {
                            if (map[i][j] == 0) {
                                map[i][j] = map[i][pos];
                                map[i][pos] = 0;
                            } else if (map[i][j] > 0) {
                                if (map[i][j] == map[i][pos]) {
                                    map[i][j] = map[i][pos] * 2;
                                    map[i][pos] = 0;
                                    break;
                                } else if (map[i][j] != map[i][pos]) {
                                    if (map[i][pos] == 0) {
                                        continue;
                                    } else
                                        break;
                                }
                            }
                        }

                    }
                }
            } else if (k == RIGHT) {    //오른쪽으로 기울임

                int i = 1, j = num - 1;
                for (i = 1; i <= num; ++i) {
                    for (j = num; j >= 1; --j) {


                        for (int pos = j - 1; pos >= 1; pos--) {
                            if (map[i][j] == 0) {
                                map[i][j] = map[i][pos];
                                map[i][pos] = 0;
                            } else if (map[i][j] > 0) {
                                if (map[i][j] == map[i][pos]) {
                                    map[i][j] = map[i][pos] * 2;
                                    map[i][pos] = 0;
                                    break;
                                } else if (map[i][j] != map[i][pos]) {
                                    if (map[i][pos] == 0) {
                                        continue;
                                    } else
                                        break;
                                }
                            }
                        }

                    }
                }
            } else if (k == UP) {   //위로 기울임
                int j = 1, i = 1;
                for (j = 1; j <= num; ++j) { //열
                    for (i = 1; i <= num; ++i) { //행


                        for (int pos = i + 1; pos <= num; pos++) {
                            if (map[i][j] == 0) {
                                map[i][j] = map[pos][j];
                                map[pos][j] = 0;
                            } else if (map[i][j] > 0) {
                                if (map[i][j] == map[pos][j]) {
                                    map[i][j] = map[pos][j] * 2;
                                    map[pos][j] = 0;
                                    break;
                                } else if (map[i][j] != map[pos][j]) {
                                    if (map[pos][j] == 0) {
                                        continue;
                                    } else
                                        break;
                                }
                            }
                        }

                    }
                }
            } else if (k == DOWN) { //아래로 기울임
                int j = 1, i = num - 1;
                for (j = 1; j <= num; ++j) { //열
                    for (i = num; i >= 1; --i) { //행

                        for (int pos = i - 1; pos >= 1; pos--) {
                            if (map[i][j] == 0) {
                                map[i][j] = map[pos][j];
                                map[pos][j] = 0;
                            } else if (map[i][j] > 0) {
                                if (map[i][j] == map[pos][j]) {
                                    map[i][j] = map[pos][j] * 2;
                                    map[pos][j] = 0;
                                    break;
                                } else if (map[i][j] != map[pos][j]) {
                                    if (map[pos][j] == 0) {
                                        continue;
                                    } else
                                        break;
                                }
                            }
                        }

                    }
                }
            }

            go(cnt + 1);

            for (int i = 1; i <= num; i++)
                for (int j = 1; j <= num; j++)
                    map[i][j] = temp[i][j];
        }
    }
}

int main() {

    memset(map, -1, sizeof(map));       //-1로 보드 패딩

    scanf("%d", &num);
    for (int i = 1; i <= num; ++i) {
        for (int j = 1; j <= num; ++j) {
            scanf("%d", &map[i][j]);
        }
    }

    go(0);
    printf("%d\n", ans);

    return 0;
}