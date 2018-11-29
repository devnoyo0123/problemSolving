#include <cstdio>
#include <cstring>

const int MAX = 100010; //맨마지막엔 '\0'

struct Stack{
    Stack(){
        memset(arr, 0, sizeof(arr));
        top = 0;
    }
    char arr[MAX];
    int top; // 데이터가 들어갈 위치

};

void push(Stack &stack, char ch){
    stack.arr[stack.top] = ch;
    stack.top++;
}

char top(Stack &stack){
    return stack.arr[stack.top-1];
}

void pop(Stack &stack){
    if( stack.top == 0){
        return;
    }else{
        stack.top--;
    }
}

int size1(Stack &stack){
    return stack.top;
}


char buf[MAX];

int ans;

int main() {

    Stack st;

    scanf("%s", buf);
    int size = (int)strlen(buf);

    for (int i = 0; i < size; ++i) {
        if( buf[i] == '('){
            push(st, buf[i]);
        }else if( buf[i] == ')'){
            char tmp = top(st); pop(st);
            if( i > 0 && buf[i-1] == tmp){
                ans+= size1(st);
            }else{
                ans+= 1;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}