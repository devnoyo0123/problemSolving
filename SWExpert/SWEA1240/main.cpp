#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int code[56] = { 0, };
int decode[8] = { 0, };

int checkcode(){
    int sum = (decode[0] + decode[2] + decode[4] + decode[6]) * 3 + decode[1] + decode[3] + decode[5];
    if ((sum + decode[7]) % 10 == 0)
        return decode[0] + decode[1] + decode[2] + decode[3] + decode[4] + decode[5] + decode[6] + decode[7];
    else
        return 0;
}

int decoder(int n) {
    if (code[n * 7] == 0 && code[n * 7 + 1] == 0 && code[n * 7 + 2] == 0 && code[n * 7 + 3] == 1 && code[n * 7 + 4] == 1 && code[n * 7 + 5] == 0 && code[n * 7 + 6] == 1)
        return 0;
    else if (code[n * 7] == 0 && code[n * 7 + 1] == 0 && code[n * 7 + 2] == 1 && code[n * 7 + 3] == 1 && code[n * 7 + 4] == 0 && code[n * 7 + 5] == 0 && code[n * 7 + 6] == 1)
        return 1;
    else if (code[n * 7] == 0 && code[n * 7 + 1] == 0 && code[n * 7 + 2] == 1 && code[n * 7 + 3] == 0 && code[n * 7 + 4] == 0 && code[n * 7 + 5] == 1 && code[n * 7 + 6] == 1)
        return 2;
    else if (code[n * 7] == 0 && code[n * 7 + 1] == 1 && code[n * 7 + 2] == 1 && code[n * 7 + 3] == 1 && code[n * 7 + 4] == 1 && code[n * 7 + 5] == 0 && code[n * 7 + 6] == 1)
        return 3;
    else if (code[n * 7] == 0 && code[n * 7 + 1] == 1 && code[n * 7 + 2] == 0 && code[n * 7 + 3] == 0 && code[n * 7 + 4] == 0 && code[n * 7 + 5] == 1 && code[n * 7 + 6] == 1)
        return 4;
    else if (code[n * 7] == 0 && code[n * 7 + 1] == 1 && code[n * 7 + 2] == 1 && code[n * 7 + 3] == 0 && code[n * 7 + 4] == 0 && code[n * 7 + 5] == 0 && code[n * 7 + 6] == 1)
        return 5;
    else if (code[n * 7] == 0 && code[n * 7 + 1] == 1 && code[n * 7 + 2] == 0 && code[n * 7 + 3] == 1 && code[n * 7 + 4] == 1 && code[n * 7 + 5] == 1 && code[n * 7 + 6] == 1)
        return 6;
    else if (code[n * 7] == 0 && code[n * 7 + 1] == 1 && code[n * 7 + 2] == 1 && code[n * 7 + 3] == 1 && code[n * 7 + 4] == 0 && code[n * 7 + 5] == 1 && code[n * 7 + 6] == 1)
        return 7;
    else if (code[n * 7] == 0 && code[n * 7 + 1] == 1 && code[n * 7 + 2] == 1 && code[n * 7 + 3] == 0 && code[n * 7 + 4] == 1 && code[n * 7 + 5] == 1 && code[n * 7 + 6] == 1)
        return 8;
    else
        return 9;

}

int main(){

    int TC = 0;
    scanf("%d\n", &TC);

    for (int T = 1; T <= TC; T++){
        int N, M = 0;
        scanf("%d %d\n", &N, &M);
        int arr[101] = { 0, };
        int check = 0;
        for (int i = 0; i<N; i++){
            int temp = 0;
            for (int j = 0; j < M; j++){
                scanf("%1d", &temp);
                arr[j] |= temp;

            }

        }

        int tail = 0;
        for (int i = 99; i >= 0; i--){
            if (arr[i] != 0){
                tail = i;
                break;
            }
        }

        for (int i = 0; i < 56; i++){
            code[55 - i] = arr[tail];
            tail--;
        }

        for (int i = 0; i < 8; i++)
            decode[i] = decoder(i);

        printf("#%d %d\n", T, checkcode());
    }

    return 0;
}