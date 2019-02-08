#include <cstdio>

char * my_token(char p[]){
    static char *mp = NULL;
    static int end = 0; // static은 이렇게 하면 처음만 초기화 된다.


    char *start;
    char *tmp;

    if( end == 1 ){
        // 이 코드의 설명은 아래 나온다.
        return NULL;
    }

    // if(  *mp == 0){ <- 이건 말이 안돼 아무곳도 아닌곳을 가리킨다고? mp가 가리키는데가 0 널이냐 물어보려는거잖아
    // 그런데 원래 의도는 이거잖아. mp가 가리키는곳이 없다고 약속한건 처음 이 함수를 호출한게 처음이라는 표현을 하기 위해서잖아.
    // 그런 의도에 맞게 코드를 구현하려면 아래와 같은 표현이 옳은거지.
    if( mp == NULL){
        start = p;
    }else{
        start = mp+1;
    }

    tmp = start;

    while(1){
        if(*tmp == ' ') {
            break;
        }else if(*tmp == 0){
            break;
        }
        tmp++;
    }

    if( *tmp == 0){
        //return NULL; 을 여기서 해버리면 널의 마지막을 출력하는 부분이 빠져버리잖아.
        // 그래서 한번 더 출력하기 위한 변수가 필요하다. 이 함수 스코프를 넘는 전역변수나 static 변수가 그래서 꼭 필요하다.
        end = 1;
    }else{
        *tmp = 0;
    }

    mp = tmp;

    return start;
}

int main() {

    char str[80] = {0,};
    char *p;

    printf("문장 입력:");
    gets(str);

    while((p = my_token(str)) != NULL){
        printf("\n%s", p);
    }


    return 0;
}