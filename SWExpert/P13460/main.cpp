#include <cstdio>
#include <climits>

enum Status {    // 열거형 정의
    HOLE = -4,
    BLUE,
    RED,
    WALL,
    BLANK
};

enum ways {
    RIGHT = 0,
    DOWN,
    LEFT,
    UP
};

struct Marvel {
    int rRow;
    int rCol;
    int bRow;
    int bCol;
    bool rhole;
    bool bhole;
};

const int MAX = 10;
int map[MAX + 2][MAX + 2];


int N, M;
int ans = INT_MAX;


Marvel move(Marvel marvel, int direction) {
    Marvel nextMarvel = marvel;

    if (direction == RIGHT) {
//        printf("RIGHT\n");
        nextMarvel.rhole = nextMarvel.bhole = false;
        for (int i = marvel.rCol + 1; i < M; ++i) {
            if (map[marvel.rRow][i] == WALL) {
                nextMarvel.rCol = i - 1;
                break;
            } else if (map[marvel.rRow][i] == HOLE) {
                nextMarvel.rhole = true;
                break;
            }
        }

        for (int i = marvel.bCol + 1; i < M; ++i) {
            if (map[marvel.bRow][i] == WALL) {
                nextMarvel.bCol = i - 1;
                break;
            } else if (map[marvel.bRow][i] == HOLE) {
                nextMarvel.bhole = true;
                break;
            }
        }

        if (marvel.rRow == marvel.bRow && nextMarvel.rCol == nextMarvel.bCol) {
            if (marvel.rCol < marvel.bCol) {
                nextMarvel.rCol -= 1;
            } else {
                nextMarvel.bCol -= 1;
            }
        }

    } else if (direction == DOWN) {
//        printf("DOWN\n");
        nextMarvel.rhole = nextMarvel.bhole = false;

        for (int i = marvel.rRow + 1; i < N; ++i) {
            if (map[i][marvel.rCol] == WALL) {
                nextMarvel.rRow = i - 1;
                break;
            } else if (map[i][marvel.rCol] == HOLE) {
                nextMarvel.rhole = true;
                break;
            }
        }

        for (int i = marvel.bRow + 1; i < N; ++i) {
            if (map[i][marvel.bCol] == WALL) {
                nextMarvel.bRow = i - 1;
                break;
            } else if (map[i][marvel.bCol] == HOLE) {
                nextMarvel.bhole = true;
                break;
            }
        }

        if (marvel.rCol == marvel.bCol && nextMarvel.rRow == nextMarvel.bRow) {
            if (marvel.rRow < marvel.bRow) {
                nextMarvel.rRow -= 1;
            } else {
                nextMarvel.bRow -= 1;
            }
        }
    } else if (direction == LEFT) {
//        printf("LEFT\n");
        nextMarvel.rhole = nextMarvel.bhole = false;

        for (int i = marvel.rCol - 1; i >= 0; --i) {
            if (map[marvel.rRow][i] == WALL) {
                nextMarvel.rCol = i + 1;
                break;
            } else if (map[marvel.rRow][i] == HOLE) {
                nextMarvel.rhole = true;
                break;
            }
        }

        for (int i = marvel.bCol - 1; i >= 0; --i) {
            if (map[marvel.bRow][i] == WALL) {
                nextMarvel.bCol = i + 1;
                break;
            } else if (map[marvel.bRow][i] == HOLE) {
                nextMarvel.bhole = true;
                break;
            }
        }

        if (marvel.rRow == marvel.bRow && nextMarvel.rCol == nextMarvel.bCol) {
            if (marvel.rCol > marvel.bCol) {
                nextMarvel.rCol += 1;
            } else {
                nextMarvel.bCol += 1;
            }
        }
    } else if (direction == UP) {
//        printf("UP\n");
        nextMarvel.rhole = nextMarvel.bhole = false;

        for (int i = marvel.rRow - 1; i >= 0; --i) {
            if (map[i][marvel.rCol] == WALL) {
                nextMarvel.rRow = i + 1;
                break;
            } else if (map[i][marvel.rCol] == HOLE) {
                nextMarvel.rhole = true;
                break;
            }
        }

        for (int i = marvel.bRow - 1; i >= 0; --i) {
            if (map[i][marvel.bCol] == WALL) {
                nextMarvel.bRow = i + 1;
                break;
            } else if (map[i][marvel.bCol] == HOLE) {
                nextMarvel.bhole = true;
                break;
            }
        }

        if (marvel.rCol == marvel.bCol && nextMarvel.rRow == nextMarvel.bRow) {
            if (marvel.rRow > marvel.bRow) {
                nextMarvel.rRow += 1;
            } else {
                nextMarvel.bRow += 1;
            }
        }
    }

    return nextMarvel;
}


void go(Marvel marvel, int depth) {


    Marvel nextMarvel;

    if (depth > 10 || depth > ans) {
        return;
    }


    for (int i = 0; i < 4; ++i) {
        // i : right, down, left, up

        nextMarvel = move(marvel, i);
        if (!nextMarvel.bhole) {
            if (nextMarvel.rhole) {
                if (ans > depth)
                    ans = depth;
                return;
            } else {
                if (marvel.rRow != nextMarvel.rRow || marvel.rCol != nextMarvel.rCol ||
                    marvel.bRow != nextMarvel.bRow || marvel.bCol != nextMarvel.bCol) {
                    go(nextMarvel, depth + 1);

                }
            }
        }


    }
}


int main() {

    scanf("%d %d", &N, &M);
    int row1, col1, row2, col2;

    for (int i = 0; i < N; ++i) {
        char temp[MAX] = {0};
        scanf("%s", temp);
        for (int j = 0; j < M; ++j) {
            int temp1 = 0;
            if (temp[j] == 'O') {
                temp1 = HOLE;
            } else if (temp[j] == 'B') {
                row2 = i, col2 = j;
            } else if (temp[j] == 'R') {
                row1 = i, col1 = j;
            } else if (temp[j] == '#') {
                temp1 = WALL;
            } else if (temp[j] == '.') {
                temp1 = BLANK;
            }
            map[i][j] = temp1;
        }
    }

//    for (int i = 0; i < N; ++i) {
//
//        for (int j = 0; j < M; ++j) {
//            printf("%d ", map[i][j]);
//        }
//        printf("\n");
//    }

    Marvel marvel;

    marvel.bRow = row2;
    marvel.bCol = col2;
    marvel.rRow = row1;
    marvel.rCol = col1;
    marvel.rhole = marvel.bhole = false;

    go(marvel, 1);

    if (ans == INT_MAX)
        ans = -1;
    printf("%d\n", ans);


    return 0;
}

