#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 20;
const int NUMMAX = 200;


int TC, N, ans;
int map[MAX + 1][MAX + 1];


int main() {

    cin >> TC;

    for (int T = 1; T <= TC; T++) {

        cin >> N;
        memset(map,0, sizeof(map));
        ans= 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> map[i][j];
            }
        }

        for (int k = 0; k < N; ++k) {
            for (int i = 0; i < N; ++i) {

                for (int a = 1; a < N; ++a) {
                    for (int b = 1; b < N; ++b) {

                        bool check = true;
                        bool nums[NUMMAX];
                        memset(nums, 0, sizeof(nums));
                        int curRow = k;
                        int curCol = i;
                        int temp = 1;
                        nums[map[curRow][curCol]] = true;
//                        printf("새로운 루트 시도 %d -> ",map[curRow][curCol]);

                        for (int c = 1; c <= b; ++c) {
                            if (curRow + 1 >= N || curCol + 1 >= N) {
                                check = false;
//                                printf("\n실패 오른쪽 벽 넘음\n");
                                break;
                            } else{
                                if (nums[map[curRow + 1][curCol + 1]]) {
//                                printf("\n실패 %d는 이전에 나온 숫자임\n",map[curRow + 1][curCol + 1]);
                                    check = false;
                                    break;
                                } else {
                                    curRow += 1;
                                    curCol += 1;
                                    temp += 1;
                                    nums[map[curRow][curCol]] = true;

//                                printf("성공 %d ->", map[curRow][curCol]);

                                }
                            }
                        }


                        for (int c = 1; check && c <= a; ++c) {
                            if (curRow + 1 >= N || curCol - 1 < 0) {
                                check = false;
//                                printf("\n실패 하단 벽 넘음\n");

                                break;
                            } else {
                                if (nums[map[curRow + 1][curCol - 1]]) {
//                                printf("\n실패 %d는 이전에 나온 숫자임\n",map[curRow + 1][curCol - 1]);

                                    check = false;
                                    break;
                                } else {
                                    curRow += 1;
                                    curCol -= 1;
                                    temp += 1;
                                    nums[map[curRow][curCol]] = true;

//                                printf("성공 %d ->", map[curRow][curCol]);

                                }
                            }
                        }

                        for (int c = 1; check && c <= b ; ++c) {
                            if (curRow - 1 < 0 || curCol -1 < 0) {
                                check = false;
//                                printf("\n실패 왼쪽 벽 넘음\n");

                                break;
                            }else {
                                if (nums[map[curRow - 1][curCol - 1]]) {
//                                printf("\n실패 %d는 이전에 나온 숫자임\n",map[curRow - 1][curCol - 1]);

                                    check = false;
                                    break;
                                }  else {
                                    curRow -= 1;
                                    curCol -= 1;
                                    temp += 1;
                                    nums[map[curRow][curCol]] = true;

//                                printf("성공 %d ->", map[curRow][curCol]);

                                }
                            }
                        }

                        for (int c = 1; check && c < a ; ++c) { // <- c < a인 이유 시작한 놈은 탐색할 필요없으니
                            if (curRow - 1 < 0 || curCol + 1 >= N) {
                                check = false;
//                                printf("\n실패 왼쪽 벽 넘음\n");

                                break;
                            }else {
                                if (nums[map[curRow - 1][curCol + 1]] ) {
//                                printf("\n실패 %d는 이전에 나온 숫자임\n",map[curRow - 1][curCol + 1]);

                                    check = false;
                                    break;
                                }  else {
                                    curRow -= 1;
                                    curCol += 1;
                                    temp += 1;
                                    nums[map[curRow][curCol]] = true;

//                                printf("성공 %d ->", map[curRow][curCol]);

                                }
                            }
                        }

                        if (!check) {
                            continue;
                        } else {
                            if (ans < temp)
                                ans = temp;


                        }
                    }
                }
            }
        }
        if( ans == 0){
            ans = -1;
        }
        cout << "#" << T << " " << ans << "\n";
    }
    return 0;
}