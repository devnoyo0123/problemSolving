#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int MAX = 500050;

struct Stack {
    Stack() {
        memset(arr, 0, sizeof(arr));
        top = 0;
    }

    pair<int, int> arr[MAX]; // first : 탑 높이 , second: 인덱스
    int top; // 데이터가 들어갈 위치

};

void push(Stack &stack, pair<int, int> num) {
    stack.arr[stack.top] = num;
    stack.top++;
}

pair<int, int> top(Stack &stack) {
    return stack.arr[stack.top - 1];
}

void pop(Stack &stack) {
    if (stack.top == 0) {
        return;
    } else {
        stack.top--;
    }
}

int size1(Stack &stack) {
    return stack.top;
}

int N;

int arr1[MAX];

int main() {

    Stack st;

    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
        int a;
        scanf("%d", &a);
        arr1[i] = a;



        if (i > 0 && arr1[i - 1] >= arr1[i]) {
            // 자기 앞에 있는 자신보다 탑을 기억하기 위해서
            // 자기 자신이 앞에 탑보다 높은 탑과 그 인덱스를 스택에 추가
            push(st, {arr1[i - 1], i - 1});
        }


        while(size1(st) > 0 && top(st).first < arr1[i]){
            pop(st);
            if( top(st).first >= arr1[i]){
                break;
            }
        }

        if (size1(st) == 0) {
            printf("0 ");
        }else{
            printf("%d ", top(st).second+1);
        }

    }


    return 0;
}