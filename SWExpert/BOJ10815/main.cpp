#include <cstdio>

const int MAX = 20500000;

int n1, m1;
bool nums[MAX];

int main() {

    scanf("%d" , &n1);
    int a;
    for (int i = 0; i < n1; ++i) {
        scanf("%d", &a);
        a+=10000000;
        nums[a] = true;

    }

    scanf("%d", &m1);
    for (int j = 0; j < m1; ++j) {
        scanf("%d", &a);
        a+=10000000;
        if(nums[a]){
            printf("1 ");
        }else{
            printf("0 ");
        }
    }


    return 0;
}