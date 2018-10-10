//#include <cstdio>
//
//
//const int MAX = 100;
//
//int data[MAX+2][MAX+2]; // 패딩추가
//int testCase = 0;
//int num, row, col, predirection, cnt, min, ans, ori;
//
//
//int main() {
//
//    while(testCase++ <= 10){
//        scanf("%d", &num);
//
//        for (int i = 1; i <= MAX ; ++i) {
//            for (int j = 1; j <= MAX ; ++j) {
//                scanf("%d", &data[i][j]);
//            }
//        }
//
//        min = 1000000000;
//        for (int i = 1; i <=MAX ; ++i) {
//
//            if(data[1][i] == 1){
//                row = 1;
//                col = i;
//                ori = i;
//                cnt = 1;
//                while (row <= MAX) {
//
////                    printf("row:%d col:%d\n", row, col);
//
//                    if( min <= cnt){
//                        break;
//                    }
//
//                    if (row == MAX) {
////                        printf("min: %d, cnt: %d\n", min, cnt);
//                        if( min >= cnt){
//                            min = cnt;
//                            ans = ori-1;
//                        }
//                        break;
//                    } else if (data[row][col - 1] == 1 && predirection != 2) {
//                        predirection = 1; // left
//                        col -= 1;
//
//                    } else if (data[row][col + 1] == 1 && predirection != 1) {
//                        predirection = 2; // right
//                        col += 1;
//
//                    } else if (data[row + 1][col] == 1) {
//                        predirection = 3;
//                        row += 1;
//
//                    }
//
//                    cnt+=1;
//
//
//                }
//            }
//        }
//
//
//
//        printf("#%d %d\n", num, ans);
//
//    }
//
//    return 0;
//}

//2차원 배열 초기화 memset

#include <cstdio>
#include <cstring>

const int MAX  = 100;

int a[MAX][MAX];

int main(){

    a[1][1] = 22;
    printf("%d\n", a[1][1]);
    printf("%d\n", sizeof(a)/4);

    memset(a, 0, sizeof(a));
    printf("%d\n", a[1][1]);
    return 0;
}
