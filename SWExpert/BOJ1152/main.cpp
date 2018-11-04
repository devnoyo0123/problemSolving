#include <cstdio>
#include <cstring>


const int MAX = 1000000;

char ch[MAX];
int cnt;

int main() {

    cnt = 0;
    scanf("%[^\n]", ch);

    char * pstr;
    pstr = strtok(ch, " ");
    while(pstr!=NULL){
        cnt++;
        pstr = strtok(NULL, " ");
    }

    printf("%d", cnt);

    return 0;
}