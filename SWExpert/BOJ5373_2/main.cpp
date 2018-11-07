#include <iostream>

using namespace std;

enum WAY1 {
    U = 0,
    F,
    L,
    D,
    R,
    B
};

char dice[6][9];

int tc;

void rollF1(){
    //앞면을 반시계
    char temp = dice[D][0];
    dice[D][0] = dice[D][1] = dice[D][2] = dice[L][2];
    dice[L][2] = dice[L][5] = dice[L][8] = dice[U][6];
    dice[U][6] = dice[U][7] = dice[U][8] = dice[R][0];
    dice[R][0] = dice[R][3] = dice[R][6] = temp;

}

void rollF2(){
    // 시계
    char temp = dice[D][0];

    dice[D][0] = dice[D][1] = dice[D][2] = dice[R][0];
    dice[R][0] = dice[R][3] = dice[R][6] = dice[U][6];
    dice[U][6] = dice[U][7] = dice[U][8] = dice[L][2];
    dice[L][2] = dice[L][5] = dice[L][8] = temp;
}

void rollB1(){
    //앞면을 반시계
    char temp = dice[U][0];
    dice[U][0] = dice[U][1] = dice[U][2] = dice[L][0];
    dice[L][0] = dice[L][3] = dice[L][6] = dice[D][6];
    dice[D][6] = dice[D][7] = dice[D][8] = dice[R][2];
    dice[R][2] = dice[R][5] = dice[R][8] = temp;
}

void rollB2(){
    // 시계
    char temp = dice[U][0];

    dice[U][0] = dice[U][1] = dice[U][2] = dice[R][2];
    dice[R][2] = dice[R][5] = dice[R][8] = dice[D][6];
    dice[D][6] = dice[D][7] = dice[D][8] = dice[L][0];
    dice[L][0] = dice[L][3] = dice[L][6] = temp;
}

void rollL1(){
    //왼쪽면을 반시계
    char temp = dice[D][0];
    dice[D][0] = dice[D][3] = dice[D][6] = dice[B][0];
    dice[B][0] = dice[B][3] = dice[B][6] = dice[U][0];
    dice[U][0] = dice[U][3] = dice[U][6] = dice[F][0];
    dice[F][0] = dice[F][3] = dice[F][6] = temp;
}

void rollL2(){
    //시계
    char temp = dice[D][0];
    dice[D][0] = dice[D][3] = dice[D][6] = dice[F][0];
    dice[F][0] = dice[F][3] = dice[F][6] = dice[U][0];
    dice[U][0] = dice[U][3] = dice[U][6] = dice[B][0];
    dice[B][0] = dice[B][3] = dice[B][6] = temp;
}

void rollR1(){
    //왼쪽면을 반시계
    char temp = dice[D][2];
    dice[D][2] = dice[D][5] = dice[D][8] = dice[F][2];
    dice[F][2] = dice[F][5] = dice[F][8] = dice[U][2];
    dice[U][2] = dice[U][5] = dice[U][8] = dice[B][2];
    dice[B][2] = dice[B][5] = dice[B][8] = temp;
}

void rollR2(){
    //시계
    char temp = dice[D][2];
    dice[D][2] = dice[D][5] = dice[D][8] = dice[B][2];
    dice[B][2] = dice[B][5] = dice[B][8] = dice[U][2];
    dice[U][2] = dice[U][5] = dice[U][8] = dice[F][2];
    dice[F][2] = dice[F][5] = dice[F][8] = temp;
}

void rollU1(){
    //윗면을 반시계
    char temp = dice[F][0];
    dice[F][0] = dice[F][1] = dice[F][2] = dice[L][0];
    dice[L][0] = dice[L][1] = dice[L][2] = dice[B][6];
    dice[B][6] = dice[B][7] = dice[B][8] = dice[R][0];
    dice[R][0] = dice[R][1] = dice[R][2] = temp;
}


void rollU2(){
    //시계
    char temp = dice[F][0];
    dice[F][0] = dice[F][1] = dice[F][2] = dice[R][0];
    dice[R][0] = dice[R][1] = dice[R][2] = dice[B][6];
    dice[B][6] = dice[B][7] = dice[B][8] = dice[L][0];
    dice[L][0] = dice[L][1] = dice[L][2] = temp;
}

void rollD1(){
    //윗면을 반시계
    char temp = dice[F][6];
    dice[F][6] = dice[F][7] = dice[F][8] = dice[R][6];
    dice[R][6] = dice[R][7] = dice[R][8] = dice[B][0];
    dice[B][0] = dice[B][1] = dice[B][2] = dice[L][6];
    dice[L][6] = dice[L][7] = dice[L][8] = temp;
}


void rollD2(){
    //시계
    char temp = dice[F][6];
    dice[F][6] = dice[F][7] = dice[F][8] = dice[L][6];
    dice[L][6] = dice[L][7] = dice[L][8] = dice[B][0];
    dice[B][0] = dice[B][1] = dice[B][2] = dice[R][6];
    dice[R][6] = dice[R][7] = dice[R][8] = temp;
}

void roll(int dir, int clockwise) {

    if (dir == U) {

        if (clockwise == 0) {
            rollU1();
        } else {
            rollU2();
        }

    } else if (dir == D) {
        if (clockwise == 0) {
            rollD1();
        } else {
            rollD2();
        }
    } else if (dir == F) {
        if (clockwise == 0) {
            rollF1();
        } else {
            rollF2();
        }
    } else if (dir == B) {
        if (clockwise == 0) {
            rollB1();
        } else {
            rollB2();
        }
    } else if (dir == L) {
        if (clockwise == 0) {
            rollL1();
        } else {
            rollL2();
        }
    } else if (dir == R) {
        if( clockwise == 0){
            rollR1();
        }else{
            rollR2();
        }
    }
}

int main() {




    cin >> tc;
    for (int i = 0; i < tc; ++i) {
        int n;
        cin >> n;

        for (int i = 0; i < 9; ++i) {
            dice[U][i] = 'w';
            dice[F][i] = 'r';
            dice[L][i] = 'g';
            dice[D][i] = 'y';
            dice[R][i] = 'b';
            dice[B][i] = 'o';
        }

        for (int j = 1; j <= n; ++j) {
            string str = "";
            cin >> str;
//            cout << str << '\n';
            int dir, clockwise;
            if (str[0] == 'U') {
                dir = U;
                clockwise = str[1] == '-' ? 0 : 1;
            } else if (str[0] == 'D') {
                dir = D;
                clockwise = str[1] == '-' ? 0 : 1;
            } else if (str[0] == 'F') {
                dir = F;
                clockwise = str[1] == '-' ? 0 : 1;
            } else if (str[0] == 'B') {
                dir = B;
                clockwise = str[1] == '-' ? 0 : 1;
            } else if (str[0] == 'L') {
                dir = L;
                clockwise = str[1] == '-' ? 0 : 1;
            } else if (str[0] == 'R') {
                dir = R;
                clockwise = str[1] == '-' ? 0 : 1;
            }
//            cout<<"dir:"<<dir<<", clockwise:"<<clockwise<<'\n';
            roll(dir, clockwise);
//            cout<<"tc:"<<i<<"\n";
//            for (int k = 0; k < 9; ++k) {
//                cout << dice[U][k];
//                if ((k + 1) % 3 == 0) {
//                    cout << '\n';
//                }
//            }
//            cout<<'\n';
            cout<<"tc:"<<i<<'\n';
            cout<<"U\n";
            for (int k = 0; k < 9; ++k) {
                cout << dice[U][k];
                if ((k + 1) % 3 == 0) {
                    cout << '\n';
                }
            }

            cout<<"F\n";

            for (int k = 0; k < 9; ++k) {
                cout << dice[F][k];
                if ((k + 1) % 3 == 0) {
                    cout << '\n';
                }
            }

            cout<<"D\n";

            for (int k = 0; k < 9; ++k) {
                cout << dice[D][k];
                if ((k + 1) % 3 == 0) {
                    cout << '\n';
                }
            }

            cout<<"B\n";

            for (int k = 0; k < 9; ++k) {
                cout << dice[B][k];
                if ((k + 1) % 3 == 0) {
                    cout << '\n';
                }
            }

            cout<<"L\n";

            for (int k = 0; k < 9; ++k) {
                cout << dice[L][k];
                if ((k + 1) % 3 == 0) {
                    cout << '\n';
                }
            }

            cout<<"R\n";

            for (int k = 0; k < 9; ++k) {
                cout << dice[R][k];
                if ((k + 1) % 3 == 0) {
                    cout << '\n';
                }
            }
        }

    }

    return 0;


}