#include <cstdio>

const int MAX = 100;

int data[MAX+2][MAX+2]; // 패딩추가
int testCase = 0;
int num, row, col, predirection;
bool flag;

int main() {

    while(testCase++ <= 10){
        scanf("%d", &num); // 의미없는 데이터

        for (int i = 1; i <= MAX ; ++i) {
            for (int j = 1; j <= MAX ; ++j) {
                scanf("%d", &data[i][j]);
                if( data[i][j] == 2){
                    row = i;
                    col = j;
                }
            }
        }

        predirection = 0;

        while (row >= 1) {
            if (row == 1) {
                printf("#%d %d\n", testCase,col-1);
                break;
            } else if (data[row][col - 1] == 1 && predirection != 2) {
                predirection = 1;
                col -= 1;
                continue;
            } else if (data[row][col + 1] == 1 && predirection != 1) {
                predirection = 2;
                col += 1;
                continue;
            } else if (data[row - 1][col] == 1) {
                predirection = 3;
                row -= 1;
                continue;
            }

        }



    }

    return 0;
}