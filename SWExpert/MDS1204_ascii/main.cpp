#include <stdio.h>

int main() {

#if 0
    int ch;

    printf("문자 A의 아스키 코드값:%d\n", 'A');
    printf("아스키 코드값이 65인 문자: %c\n", 0101); // 65
    printf("문자 상수의 크기: %d바이트\n", sizeof('A'));

    ch = 'A';
    ch++;
    printf("문자 %c의 아스키 코드값: %d\n", ch, ch);

#endif

#if A
    char ch1, ch2;

    //scanf("%c%c", &ch1, &ch2);
    scanf("%c %c",&ch1, &ch2); //ch1, ch2 입력 사이에 화이트 스페이스 무시
    printf("[%c %c]", ch1, ch2);
    //scanf("%c ", &ch1);
    scanf(" %c", &ch1); // 화이트 스페이스 무시
    printf("ch : %c", ch1);

#endif

#if B
    char ch;
    scanf("%c", &ch);
    printf("%d", ch); //쓰레기 값으로 인해 문자 A의 아스키 코드값이 출력되지 않음
#endif

    char buf[512] = {0};
    int res = 0;
    res = scanf("%s", buf);

    printf("scanf리턴값: %d, 문자열:%s\n", res, buf);
    return 0;
}