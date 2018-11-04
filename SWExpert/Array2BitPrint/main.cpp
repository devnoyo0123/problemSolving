#include <iostream>

using namespace std;

void bitPrint(char i){
    for (int j = 7; j >= 0 ; --j) {
        printf("%d", (i >> j) & 1);
    }
}

int main() {

    char j;

    for ( j = -5; j < 6; ++j) {
        printf("%3d = ", j); // 10진수
        bitPrint(j); // 2진수
        printf("\n");
    }


    return 0;
}