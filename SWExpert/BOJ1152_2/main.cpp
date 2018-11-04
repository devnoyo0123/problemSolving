#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 1000000;
char ch[MAX];

int main() {

    int cnt = 0;
    scanf("%[^\n]s,", ch);

    int size = (int)strlen(ch);

    if( size == 1){
        printf("0\n");
    }else{
        for (int i = 0; i < size; ++i) {
            if( i - 1 >=0 && i + 1 < size){
                if( ch[i-1] != ' ' && ch[i] == ' ' && ch[i+1] != ' '){
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt + 1);

    }




    return 0;
}