#include <cstdio>

char map[100][200];

int main() {

    //FILE * in  = fopen("input.txt","r");
    //FILE * out = fopen("output.txt","w");

    int num, left, right;
    scanf("%d", &num);

    for (int i = 0; i < num; ++i) {
        for (int j = num-i-1; j>0; --j) {
            printf(" ");
        }

        for (int k = 0; k < 2*i + 1; ++k) {
            printf("*");
        }
        printf("\n");
    }



    return 0;
}#include <cstdio>

char map[100][200];

int main() {

    //FILE * in  = fopen("input.txt","r");
    //FILE * out = fopen("output.txt","w");

    int num, left, right;
    scanf("%d", &num);

    for (int i = 0; i < num; ++i) {
        for (int j = num-i-1; j>0; --j) {
            printf(" ");
        }

        for (int k = 0; k < 2*i + 1; ++k) {
            printf("*");
        }
        printf("\n");
    }



    return 0;
}