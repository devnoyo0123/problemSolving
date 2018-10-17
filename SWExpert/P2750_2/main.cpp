#include <iostream>
// 수 정렬하기 선택정렬로 정렬하려고함.

const int MAX = 1000;
int a[MAX];
int num;

void swap(int a1, int b1){
    int temp = a[a1];
    a[a1] = a[b1];
    a[b1] = temp;
}

void selectionSort(int size){
    int i,j;
    for (i = 0; i < size ; ++i) {
        int min = a[i], mininx = i;
        for (j = i+1; j < size; ++j) {
            if(min > a[j]){
                min = a[j];
                mininx = j;
            }
        }
        swap(i ,mininx);
    }
}

int main() {
    scanf("%d", &num);
    for (int i = 0; i < num ; ++i) {
        scanf("%d", &a[i]);
    }
    selectionSort(num);
    for (int j = 0; j < num; ++j) {
        printf("%d\n", a[j]);
    }
    return 0;
}

//입력
//5
//5
//2
//3
//4
//1