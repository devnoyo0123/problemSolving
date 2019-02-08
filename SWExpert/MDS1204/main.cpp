#include <stdio.h>
#include <string.h>

int n1;

int a[32];
char buf[32];

int inx;

void print(){
    printf("+=====================+\n");
    printf("+   실행 프로그램 선택    +\n");
    printf("+=====================+\n");
    printf("+ 1. 1의 보수 구하기     +\n");
    printf("+ 2. 2의 보수 구하기     +\n");
    printf("+ 3. 진법 변환하기       +\n");
    printf("+ 4. 주민등록번호 확인    +\n");
    printf("+ 0. Exit             +\n");
    printf("+=====================+\n");
}

void func1(){
    // 1의 보수 구하기
    int num;
    printf("10진수 정수 입력(양수 입력 시에도 음수로 취급됩니다):");
    scanf("%d", &num);
    printf("%d을(를) 1의 보수로 표현하면 : ", -num);


    // 1의 보수 처리
    inx = 31;
    memset(a, 0, sizeof(a));

    // 10 -> 2진수
    while(num > 0){
        a[inx] = num % 2;
        num = num / 2;
        inx--;
    }

    // 2진수 0 -> 1 , 1 -> 0 으로 뒤집고 출력
    for (int i = 0; i < 32; ++i) {
        a[i] = a[i] == 1? 0 : 1;
        printf("%d",a[i]);

        if( (i+ 1) % 4 ==0){
            printf(" ");
        }
    }
    printf("\n");

}

void func2(){
    // 2의 보수 구하기
    int num;
    printf("10진수 정수 입력(양수 입력 시에도 음수로 취급됩니다):");
    scanf("%d", &num);
    printf("%d을(를) 2의 보수로 표현하면 : ", -num);

    // 1의 보수 처리
    inx = 31;
    memset(a, 0, sizeof(a));

    // 10 -> 2진수
    while(num > 0){
        a[inx] = num % 2;
        num = num / 2;
        inx--;
    }


    // 2진수 0 -> 1 , 1 -> 0 으로 뒤집고 출력
    int i = 0;
    for (i = 0; i < 32; ++i) {
        a[i] = a[i] == 1? 0 : 1;
    }

    if( a[31] == 0){
        a[31] = 1;
    }else{
        // 가장 오른쪽 비트가 1이고 +1을 해줌으로써 비트가 1인 경우 왼쪽으로 한칸씩 올린다.
        a[31] = 0;
        for(i = 30; i>=0; i--){
            if( a[i] == 0){
                a[i] = 1;
                break;
            }else{
                a[i] = 0;
            }
        }
    }

    for (int i = 0; i < 32; ++i) {
        printf("%d",a[i]);

        if( (i+ 1) % 4 ==0){
            printf(" ");
        }
    }
    printf("\n");
}

void func3(){
    // 1의 보수 구하기
    int num = 0, i = 0;
    printf("변경할 숫자를 입력하세요. (10진수):");
    scanf("%d", &num);

    int jinbub;
    printf("원하는 진법을 입력하세요 (2, 8, 16):");
    scanf("%d", &jinbub);

    switch(jinbub){
        case 2:

            // 10 - > 2진법으로
            memset(a, 0, sizeof(a));
            inx = 0;
            while(num > 0){
                a[inx] = num % 2;
                num = num / 2;
                inx++;
            }

            //출력하기
            i=0;
            for(i=inx-1; i >=0; i--){
                printf("%d", a[i]);
            }
            printf("\n");
            break;
        case 8:
            // 10 - > 8진법으로
            memset(a, 0, sizeof(a));
            inx = 0;
            while(num > 0){
                a[inx] = num % 8;
                num = num / 8;
                inx++;
            }

            //출력하기
            i=0;
            for(i=inx-1; i >=0; i--){
                printf("%d", a[i]);
            }
            printf("\n");
            break;
        case 16:
            // 10 - > 16진법으로
            memset(a, 0, sizeof(a));
            inx = 0;
            while(num > 0){
                a[inx] = num % 16;
                num = num / 16;
                inx++;
            }

            //출력하기
            i=0;
            for(i=inx-1; i >=0; i--){

                if( a[i] >= 10){
                    printf("%c", 'A'+ (a[i] - 10));
                }else{
                    printf("%d", a[i]);
                }
            }
            printf("\n");
            break;
    }
}

void func4(){

    //주민등록번호 검증 알고리즘
    /*
     * 1.주민번호 첫 번째자리부터 12번째자리까지 각각의 수를
     * 2 3 4 5 6 7 8 9 2 3 4 5 와 각각 곱한후 모든 값을 더한다.
     *
     * 2.더한값을 11과 나눈 나머지를 구한다.
     * 3.11에 2.에서 구한 나머지를 뺀 값과 주민번호 13번째 수와 비교하여
     * 같으면 정상, 다르면 비정상 주민등록번호가 ?다.
     *
     * */


    int i= 0, j=0, num=0, sum =0;
    char ch = 0;

    memset(a,0, sizeof(a));
    while(1) {
        memset(buf, 0, sizeof(buf));
        printf("\"-\"를 제외한 확인할 주민등록 번호 13자리를 입력하세요: ");
        scanf("%s", buf);
        int size = strlen(buf);
        if (size == 13){
            for (i = 0; i < 13; ++i) {
                a[i] = buf[i] - '0';
            }

            // 주민번호 맨 마지막 전까지 각 자리에 2,3,4,5,6,7,8,9,2,3,4,5 를 차례대로 곱한다.
            num=2;
            for (j = 0; j < 12; ++j) {
                // 곱한 값을 모두 더한다.
                sum += a[j]*num;
                num+=1;
                if( num >9){
                    num =2;
                }
            }

            //더한 값을 11로 나눈 나머지를 구한다.
            num = sum % 11;
            // 11을 나눈 나머지에
            num = 11 - num;

            if( num == a[12]){
                printf("정상적인 주민등록번호입니다.\n");
            }else{
                printf("잘못 입력된 주민등록번호입니다.\n");
            }

            getchar();
            printf("다시 입력하시겠습니까? (y/n)\n");
            scanf("%c", &ch);
            if( ch == 'y'){
                continue;
            }

            break;
        }
    }

}
int main() {


    while(1){
        print();
        printf("Input number :");
        scanf("%d", &n1);

        if( n1 == 0){
            break;
        }else if( n1 == 1){
            func1();
        }else if( n1 == 2){
            func2();
        }else if( n1 == 3){
            func3();
        }else if( n1 == 4){
            func4();
        }
    }

    return 0;
}