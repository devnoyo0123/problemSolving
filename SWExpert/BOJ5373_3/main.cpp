#include <cstdio>

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

void rollU1() {
    //윗면을 반시계

    char temp2[9];
    for (int j = 0; j < 9; ++j) {
        temp2[j] = dice[U][j];
    }

    dice[U][6] = temp2[0];
    dice[U][3] = temp2[1];
    dice[U][0] = temp2[2];
    dice[U][7] = temp2[3];
    dice[U][1] = temp2[5];
    dice[U][8] = temp2[6];
    dice[U][5] = temp2[7];
    dice[U][2] = temp2[8];

    char temp[3];
    for (int i = 0; i < 3; ++i) {
        temp[i] = dice[F][i];
    }

    dice[F][2] = dice[L][2];
    dice[F][1] = dice[L][1];
    dice[F][0] = dice[L][0];

    dice[L][2] = dice[B][6];
    dice[L][1] = dice[B][7];
    dice[L][0] = dice[B][8];

    dice[B][6] = dice[R][2];
    dice[B][7] = dice[R][1];
    dice[B][8] = dice[R][0];

    dice[R][2] = temp[2];
    dice[R][1] = temp[1];
    dice[R][0] = temp[0];


}


void rollU2() {
    //시계

    char temp2[9];
    for (int j = 0; j < 9; ++j) {
        temp2[j] = dice[U][j];
    }

    dice[U][2] = temp2[0];
    dice[U][5] = temp2[1];
    dice[U][8] = temp2[2];
    dice[U][1] = temp2[3];
    dice[U][7] = temp2[5];
    dice[U][0] = temp2[6];
    dice[U][3] = temp2[7];
    dice[U][6] = temp2[8];


    char temp[3];
    for (int i = 0; i < 3; ++i) {
        temp[i] = dice[F][i];
    }

    dice[F][0] = dice[R][0];
    dice[F][1] = dice[R][1];
    dice[F][2] = dice[R][2];

    dice[R][0] = dice[B][8];
    dice[R][1] = dice[B][7];
    dice[R][2] = dice[B][6];

    dice[B][8] = dice[L][0];
    dice[B][7] = dice[L][1];
    dice[B][6] = dice[L][2];

    dice[L][2] = temp[2];
    dice[L][1] = temp[1];
    dice[L][0] = temp[0];


}

void rollF1() {
    //앞면을 반시계

    // tmp <- U <- R <- D <- L <- tmp

    char temp2[9];
    for (int j = 0; j < 9; ++j) {
        temp2[j] = dice[F][j];
    }

    dice[F][6] = temp2[0];
    dice[F][3] = temp2[1];
    dice[F][0] = temp2[2];
    dice[F][7] = temp2[3];
    dice[F][1] = temp2[5];
    dice[F][8] = temp2[6];
    dice[F][5] = temp2[7];
    dice[F][2] = temp2[8];

    char temp[3];
    temp[0] = dice[U][8];
    temp[1] = dice[U][7];
    temp[2] = dice[U][6];

    dice[U][8] = dice[R][6];
    dice[U][7] = dice[R][3];
    dice[U][6] = dice[R][0];

    dice[R][6] = dice[D][0];
    dice[R][3] = dice[D][1];
    dice[R][0] = dice[D][2];

    dice[D][0] = dice[L][2];
    dice[D][1] = dice[L][5];
    dice[D][2] = dice[L][8];

    dice[L][2] = temp[0];
    dice[L][5] = temp[1];
    dice[L][8] = temp[2];


}

void rollF2() {
    // 시계

    char temp2[9];
    for (int j = 0; j < 9; ++j) {
        temp2[j] = dice[F][j];
    }

    dice[F][2] = temp2[0];
    dice[F][5] = temp2[1];
    dice[F][8] = temp2[2];
    dice[F][1] = temp2[3];
    dice[F][7] = temp2[5];
    dice[F][0] = temp2[6];
    dice[F][3] = temp2[7];
    dice[F][6] = temp2[8];

    // tmp <- U <- L <- D <- R <- tmp
    char temp[3];

    temp[0] = dice[U][8];
    temp[1] = dice[U][7];
    temp[2] = dice[U][6];

    dice[U][8] = dice[L][2];
    dice[U][7] = dice[L][5];
    dice[U][6] = dice[L][8];

    dice[L][2] = dice[D][0];
    dice[L][5] = dice[D][1];
    dice[L][8] = dice[D][2];

    dice[D][0] = dice[R][6];
    dice[D][1] = dice[R][3];
    dice[D][2] = dice[R][0];

    dice[R][6] = temp[0];
    dice[R][3] = temp[1];
    dice[R][0] = temp[2];


}

void rollB1() {
    //앞면을 반시계

    char temp2[9];
    for (int j = 0; j < 9; ++j) {
        temp2[j] = dice[B][j];
    }

    dice[B][6] = temp2[0];
    dice[B][3] = temp2[1];
    dice[B][0] = temp2[2];
    dice[B][7] = temp2[3];
    dice[B][1] = temp2[5];
    dice[B][8] = temp2[6];
    dice[B][5] = temp2[7];
    dice[B][2] = temp2[8];

    // temp <- D < R < U < L < temp
    char temp[3];
    temp[0] = dice[D][8];
    temp[1] = dice[D][7];
    temp[2] = dice[D][6];

    dice[D][8] = dice[R][2];
    dice[D][7] = dice[R][5];
    dice[D][6] = dice[R][8];

    dice[R][2] = dice[U][0];
    dice[R][5] = dice[U][1];
    dice[R][8] = dice[U][2];

    dice[U][0] = dice[L][6];
    dice[U][1] = dice[L][3];
    dice[U][2] = dice[L][0];

    dice[L][6] = temp[0];
    dice[L][3] = temp[1];
    dice[L][0] = temp[2];


}

void rollB2() {
    // 시계
    char temp2[9];
    for (int j = 0; j < 9; ++j) {
        temp2[j] = dice[B][j];
    }

    dice[B][2] = temp2[0];
    dice[B][5] = temp2[1];
    dice[B][8] = temp2[2];
    dice[B][1] = temp2[3];
    dice[B][7] = temp2[5];
    dice[B][0] = temp2[6];
    dice[B][3] = temp2[7];
    dice[B][6] = temp2[8];

    // temp <- D < L < U < R < temp;
    char temp[3];
    temp[0] = dice[D][8];
    temp[1] = dice[D][7];
    temp[2] = dice[D][6];

    dice[D][8] = dice[L][6];
    dice[D][7] = dice[L][3];
    dice[D][6] = dice[L][0];

    dice[L][6] = dice[U][0];
    dice[L][3] = dice[U][1];
    dice[L][0] = dice[U][2];

    dice[U][0] = dice[R][2];
    dice[U][1] = dice[R][5];
    dice[U][2] = dice[R][8];

    dice[R][2] = temp[0];
    dice[R][5] = temp[1];
    dice[R][8] = temp[2];


}

void rollL1() {
    //왼쪽면을 반시계

    char temp2[9];
    for (int j = 0; j < 9; ++j) {
        temp2[j] = dice[L][j];
    }

    dice[L][6] = temp2[0];
    dice[L][3] = temp2[1];
    dice[L][0] = temp2[2];
    dice[L][7] = temp2[3];
    dice[L][1] = temp2[5];
    dice[L][8] = temp2[6];
    dice[L][5] = temp2[7];
    dice[L][2] = temp2[8];

    // temp < U < F < D < B < temp;
    char temp[3];

    temp[0] = dice[U][0];
    temp[1] = dice[U][3];
    temp[2] = dice[U][6];

    dice[U][0] = dice[F][0];
    dice[U][3] = dice[F][3];
    dice[U][6] = dice[F][6];

    dice[F][0] = dice[D][0];
    dice[F][3] = dice[D][3];
    dice[F][6] = dice[D][6];

    dice[D][0] = dice[B][0];
    dice[D][3] = dice[B][3];
    dice[D][6] = dice[B][6];

    dice[B][0] = temp[0];
    dice[B][3] = temp[1];
    dice[B][6] = temp[2];


}

void rollL2() {
    //시계
    char temp2[9];
    for (int j = 0; j < 9; ++j) {
        temp2[j] = dice[L][j];
    }

    dice[L][2] = temp2[0];
    dice[L][5] = temp2[1];
    dice[L][8] = temp2[2];
    dice[L][1] = temp2[3];
    dice[L][7] = temp2[5];
    dice[L][0] = temp2[6];
    dice[L][3] = temp2[7];
    dice[L][6] = temp2[8];
    // temp < U < B < D < F < temp;
    char temp[3];

    temp[0] = dice[U][0];
    temp[1] = dice[U][3];
    temp[2] = dice[U][6];

    dice[U][0] = dice[B][0];
    dice[U][3] = dice[B][3];
    dice[U][6] = dice[B][6];

    dice[B][0] = dice[D][0];
    dice[B][3] = dice[D][3];
    dice[B][6] = dice[D][6];

    dice[D][0] = dice[F][0];
    dice[D][3] = dice[F][3];
    dice[D][6] = dice[F][6];

    dice[F][0] = temp[0];
    dice[F][3] = temp[1];
    dice[F][6] = temp[2];


}

void rollR1() {
    //왼쪽면을 반시계
    char temp2[9];
    for (int j = 0; j < 9; ++j) {
        temp2[j] = dice[R][j];
    }

    dice[R][6] = temp2[0];
    dice[R][3] = temp2[1];
    dice[R][0] = temp2[2];
    dice[R][7] = temp2[3];
    dice[R][1] = temp2[5];
    dice[R][8] = temp2[6];
    dice[R][5] = temp2[7];
    dice[R][2] = temp2[8];
    // temp < U < B < D < F < temp
    char temp[3];
    temp[0] = dice[U][2];
    temp[1] = dice[U][5];
    temp[2] = dice[U][8];

    dice[U][2] = dice[B][2];
    dice[U][5] = dice[B][5];
    dice[U][8] = dice[B][8];

    dice[B][2] = dice[D][2];
    dice[B][5] = dice[D][5];
    dice[B][8] = dice[D][8];

    dice[D][2] = dice[F][2];
    dice[D][5] = dice[F][5];
    dice[D][8] = dice[F][8];

    dice[F][2] = temp[0];
    dice[F][5] = temp[1];
    dice[F][8] = temp[2];


}

void rollR2() {
    //시계

    char temp2[9];
    for (int j = 0; j < 9; ++j) {
        temp2[j] = dice[R][j];
    }

    dice[R][2] = temp2[0];
    dice[R][5] = temp2[1];
    dice[R][8] = temp2[2];
    dice[R][1] = temp2[3];
    dice[R][7] = temp2[5];
    dice[R][0] = temp2[6];
    dice[R][3] = temp2[7];
    dice[R][6] = temp2[8];

    // temp < U < F < D< B< temp;
    char temp[3];

    temp[0] = dice[U][2];
    temp[1] = dice[U][5];
    temp[2] = dice[U][8];

    dice[U][2] = dice[F][2];
    dice[U][5] = dice[F][5];
    dice[U][8] = dice[F][8];

    dice[F][2] = dice[D][2];
    dice[F][5] = dice[D][5];
    dice[F][8] = dice[D][8];

    dice[D][2] = dice[B][2];
    dice[D][5] = dice[B][5];
    dice[D][8] = dice[B][8];

    dice[B][2] = temp[0];
    dice[B][5] = temp[1];
    dice[B][8] = temp[2];


}


void rollD1() {
    //윗면을 반시계
    char temp2[9];
    for (int j = 0; j < 9; ++j) {
        temp2[j] = dice[D][j];
    }

    dice[D][6] = temp2[0];
    dice[D][3] = temp2[1];
    dice[D][0] = temp2[2];
    dice[D][7] = temp2[3];
    dice[D][1] = temp2[5];
    dice[D][8] = temp2[6];
    dice[D][5] = temp2[7];
    dice[D][2] = temp2[8];

    // temp < F < R < B < L < temp
    char temp[3];

    temp[0] = dice[F][8];
    temp[1] = dice[F][7];
    temp[2] = dice[F][6];

    dice[F][8] = dice[R][8];
    dice[F][7] = dice[R][7];
    dice[F][6] = dice[R][6];

    dice[R][8] = dice[B][0];
    dice[R][7] = dice[B][1];
    dice[R][6] = dice[B][2];

    dice[B][0] = dice[L][8];
    dice[B][1] = dice[L][7];
    dice[B][2] = dice[L][6];

    dice[L][8] = temp[0];
    dice[L][7] = temp[1];
    dice[L][6] = temp[2];


}


void rollD2() {
    //시계
    char temp2[9];
    for (int j = 0; j < 9; ++j) {
        temp2[j] = dice[D][j];
    }

    dice[D][2] = temp2[0];
    dice[D][5] = temp2[1];
    dice[D][8] = temp2[2];
    dice[D][1] = temp2[3];
    dice[D][7] = temp2[5];
    dice[D][0] = temp2[6];
    dice[D][3] = temp2[7];
    dice[D][6] = temp2[8];

    // temp < F < L < B < R < temp;
    char temp[3];

    temp[0] = dice[F][6];
    temp[1] = dice[F][7];
    temp[2] = dice[F][8];

    dice[F][6] = dice[L][6];
    dice[F][7] = dice[L][7];
    dice[F][8] = dice[L][8];

    dice[L][6] = dice[B][2];
    dice[L][7] = dice[B][1];
    dice[L][8] = dice[B][0];

    dice[B][2] = dice[R][6];
    dice[B][1] = dice[R][7];
    dice[B][0] = dice[R][8];

    dice[R][6] = temp[0];
    dice[R][7] = temp[1];
    dice[R][8] = temp[2];


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
        if (clockwise == 0) {
            rollR1();
        } else {
            rollR2();
        }
    }
}

int main() {

    scanf("%d", &tc);
    for (int i = 0; i < tc; ++i) {
        int n;
        scanf("%d", &n);

        for (int i = 0; i < 9; ++i) {
            dice[U][i] = 'w';
            dice[F][i] = 'r';
            dice[L][i] = 'g';
            dice[D][i] = 'y';
            dice[R][i] = 'b';
            dice[B][i] = 'o';
        }

        for (int j = 1; j <= n; ++j) {
            char str[512] = {0,};
            scanf("%s", str);
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



        }

        for (int k = 0; k < 9; ++k) {
            printf("%c", dice[U][k]);
            if ( (k+1) % 3 == 0) {
                printf("\n");
            }
        }


    }

    return 0;


}