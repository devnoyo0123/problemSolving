//PASS 코드
//////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;
// float b = 1.0, c = 2.0;
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;


const int MAX = 4000;
const int ELEMENTMAX = 1000;


struct Atom {
    int x;
    int y;
    int dir;
    int energy;
};
//x -> row y -> col UP : col+=1, LEFT: row-1;
int dy[] = {1, -1, 0, 0}; // 0: UP, DOWN, LEFT, RIGHT
int dx[] = {0, 0, -1, 1};

int num, ans;
bool check[MAX + 4][MAX + 4];
int map[MAX + 4][MAX + 4];
Atom atom[MAX + 2];


void go() {

    int turn = 1;

    while (turn <= 4000) {

        int tempEnergy = 0;
        //원소체크 각각 원소 비교

        // 이동

        for (int i = 1; i <= num; ++i) {

            if (atom[i].energy == 0) {
                continue;
            }


            int nextX = dx[atom[i].dir] + atom[i].x;
            int nextY = dy[atom[i].dir] + atom[i].y;
            if (nextX >= 0 && nextX <=4000 && nextY >= 0 && nextY <= 4000) {
//                printf("%d번째 요소 X: %d, Y: %d, Dir: %d, energy: %d\n", i, atom[i].x, atom[i].y, atom[i].dir,
//                       atom[i].energy);
                map[atom[i].x][atom[i].y] -= 1;
                atom[i].x = nextX;
                atom[i].y = nextY;
                map[atom[i].x][atom[i].y] += 1;
                if (map[atom[i].x][atom[i].y] > 1) {
                    check[atom[i].x][atom[i].y] = true;
                }
            }else{
                map[atom[i].x][atom[i].y] -= 1;
                atom[i].energy = 0;
            }

        }


        //충돌체크


        for (int i = 1; i <= num; ++i) {


            if (atom[i].energy == 0) {
                continue;
            }

            int tempX = atom[i].x;
            int tempY = atom[i].y;

            if (check[tempX][tempY]) {
                if (map[tempX][tempY] == 1) {
                    check[tempX][tempY] = false;
                }
                map[tempX][tempY] -= 1;
                tempEnergy += atom[i].energy;
                atom[i].energy = 0;
            }
        }



        ans += tempEnergy;
        turn += 1;


    }

}


int main(int argc, char **argv) {
    int test_case;
    int T;
    /*
       아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
       앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
       //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
       freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
       따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
       freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
       단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
    */
    //freopen("input.txt", "r", stdin);
    cin >> T;
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    for (test_case = 1; test_case <= T; ++test_case) {
        num = 0;
        scanf("%d", &num);
        memset(atom, 0, sizeof(struct Atom));
        memset(check, 0, sizeof(check));
        memset(map, 0, sizeof(map));
        ans = 0;
        for (int i = 1; i <= num; ++i) {

            scanf("%d %d %d %d", &atom[i].x, &atom[i].y, &atom[i].dir, &atom[i].energy);
            atom[i].x += 1000;
            atom[i].y += 1000;
            atom[i].x *= 2;
            atom[i].y *= 2;
            map[atom[i].x][atom[i].y] += 1;

        }
        go();
        printf("#%d %d\n", test_case, ans);
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}