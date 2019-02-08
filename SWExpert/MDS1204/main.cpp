#include <stdio.h>
#include <string.h>

int n1;

int a[32];
char buf[32];

int inx;

void print(){
    printf("+=====================+\n");
    printf("+   ���� ���α׷� ����    +\n");
    printf("+=====================+\n");
    printf("+ 1. 1�� ���� ���ϱ�     +\n");
    printf("+ 2. 2�� ���� ���ϱ�     +\n");
    printf("+ 3. ���� ��ȯ�ϱ�       +\n");
    printf("+ 4. �ֹε�Ϲ�ȣ Ȯ��    +\n");
    printf("+ 0. Exit             +\n");
    printf("+=====================+\n");
}

void func1(){
    // 1�� ���� ���ϱ�
    int num;
    printf("10���� ���� �Է�(��� �Է� �ÿ��� ������ ��޵˴ϴ�):");
    scanf("%d", &num);
    printf("%d��(��) 1�� ������ ǥ���ϸ� : ", -num);


    // 1�� ���� ó��
    inx = 31;
    memset(a, 0, sizeof(a));

    // 10 -> 2����
    while(num > 0){
        a[inx] = num % 2;
        num = num / 2;
        inx--;
    }

    // 2���� 0 -> 1 , 1 -> 0 ���� ������ ���
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
    // 2�� ���� ���ϱ�
    int num;
    printf("10���� ���� �Է�(��� �Է� �ÿ��� ������ ��޵˴ϴ�):");
    scanf("%d", &num);
    printf("%d��(��) 2�� ������ ǥ���ϸ� : ", -num);

    // 1�� ���� ó��
    inx = 31;
    memset(a, 0, sizeof(a));

    // 10 -> 2����
    while(num > 0){
        a[inx] = num % 2;
        num = num / 2;
        inx--;
    }


    // 2���� 0 -> 1 , 1 -> 0 ���� ������ ���
    int i = 0;
    for (i = 0; i < 32; ++i) {
        a[i] = a[i] == 1? 0 : 1;
    }

    if( a[31] == 0){
        a[31] = 1;
    }else{
        // ���� ������ ��Ʈ�� 1�̰� +1�� �������ν� ��Ʈ�� 1�� ��� �������� ��ĭ�� �ø���.
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
    // 1�� ���� ���ϱ�
    int num = 0, i = 0;
    printf("������ ���ڸ� �Է��ϼ���. (10����):");
    scanf("%d", &num);

    int jinbub;
    printf("���ϴ� ������ �Է��ϼ��� (2, 8, 16):");
    scanf("%d", &jinbub);

    switch(jinbub){
        case 2:

            // 10 - > 2��������
            memset(a, 0, sizeof(a));
            inx = 0;
            while(num > 0){
                a[inx] = num % 2;
                num = num / 2;
                inx++;
            }

            //����ϱ�
            i=0;
            for(i=inx-1; i >=0; i--){
                printf("%d", a[i]);
            }
            printf("\n");
            break;
        case 8:
            // 10 - > 8��������
            memset(a, 0, sizeof(a));
            inx = 0;
            while(num > 0){
                a[inx] = num % 8;
                num = num / 8;
                inx++;
            }

            //����ϱ�
            i=0;
            for(i=inx-1; i >=0; i--){
                printf("%d", a[i]);
            }
            printf("\n");
            break;
        case 16:
            // 10 - > 16��������
            memset(a, 0, sizeof(a));
            inx = 0;
            while(num > 0){
                a[inx] = num % 16;
                num = num / 16;
                inx++;
            }

            //����ϱ�
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

    //�ֹε�Ϲ�ȣ ���� �˰���
    /*
     * 1.�ֹι�ȣ ù ��°�ڸ����� 12��°�ڸ����� ������ ����
     * 2 3 4 5 6 7 8 9 2 3 4 5 �� ���� ������ ��� ���� ���Ѵ�.
     *
     * 2.���Ѱ��� 11�� ���� �������� ���Ѵ�.
     * 3.11�� 2.���� ���� �������� �� ���� �ֹι�ȣ 13��° ���� ���Ͽ�
     * ������ ����, �ٸ��� ������ �ֹε�Ϲ�ȣ�� ?��.
     *
     * */


    int i= 0, j=0, num=0, sum =0;
    char ch = 0;

    memset(a,0, sizeof(a));
    while(1) {
        memset(buf, 0, sizeof(buf));
        printf("\"-\"�� ������ Ȯ���� �ֹε�� ��ȣ 13�ڸ��� �Է��ϼ���: ");
        scanf("%s", buf);
        int size = strlen(buf);
        if (size == 13){
            for (i = 0; i < 13; ++i) {
                a[i] = buf[i] - '0';
            }

            // �ֹι�ȣ �� ������ ������ �� �ڸ��� 2,3,4,5,6,7,8,9,2,3,4,5 �� ���ʴ�� ���Ѵ�.
            num=2;
            for (j = 0; j < 12; ++j) {
                // ���� ���� ��� ���Ѵ�.
                sum += a[j]*num;
                num+=1;
                if( num >9){
                    num =2;
                }
            }

            //���� ���� 11�� ���� �������� ���Ѵ�.
            num = sum % 11;
            // 11�� ���� ��������
            num = 11 - num;

            if( num == a[12]){
                printf("�������� �ֹε�Ϲ�ȣ�Դϴ�.\n");
            }else{
                printf("�߸� �Էµ� �ֹε�Ϲ�ȣ�Դϴ�.\n");
            }

            getchar();
            printf("�ٽ� �Է��Ͻðڽ��ϱ�? (y/n)\n");
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