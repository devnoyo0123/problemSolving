#include <stdio.h>
#include <string.h>

typedef struct
{
    int x, y;
}point;

typedef struct
{
    int x, y,len, p;
}Charger;

typedef struct
{
    int num, p;
}where;

int abs(int a, int b)
{
    return (a - b) < 0 ? -1 * (a - b) : a - b;
}

int Length(int y1, int x1, int y2, int x2)
{
    return abs(y1, y2) + abs(x1, x2);
}

int map[14][14];
int BC[8][14][14];
int A_Way[100];
int B_Way[100];
point A;
point B;
Charger AP[8];

int T, BC_num, MAX;

void move(int *y, int *x, int d)
{
    switch (d)
    {
        case 0:
            break;
        case 1:
            *y -= 1;
            break;
        case 2:
            *x += 1;
            break;
        case 3:
            *y += 1;
            break;
        case 4:
            *x -= 1;
            break;
    }
    return;
}

int main()
{
    int Test_Case;
    scanf("%d", &Test_Case);

    for (int Test = 1; Test <= Test_Case; Test++)
    {
        MAX = -1;
        memset(BC, 0, sizeof(BC));
        memset(map, -1, sizeof(map));
        memset(A_Way, -1, sizeof(A_Way));
        memset(B_Way, -1, sizeof(B_Way));
        A.y = 1; A.x = 1;
        B.y = 10; B.x = 10;

        scanf("%d %d", &T, &BC_num);

        for (int i = 0; i < T; i++)
        {
            scanf("%d",&A_Way[i]);
        }

        for (int i = 0; i < T; i++)
        {
            scanf("%d", &B_Way[i]);
        }

        for (int i = 0; i < BC_num; i++)
        {
            scanf("%d %d %d %d", &AP[i].x, &AP[i].y, &AP[i].len, &AP[i].p);
            //printf("%d %d %d %d\n", AP[i].x, AP[i].y, AP[i].len, AP[i].p);
            for (int a = 1; a <= 10; a++)
            {
                for (int b = 1; b <= 10; b++)
                {
                    int L = Length(AP[i].y, AP[i].x, a, b);
                    if (L <= AP[i].len)
                        BC[i][a][b] = 1;
                }
            }
        }

        int total = 0;
        where AP_A = { 0, }, AP_B = { 0, };
        int A_visit[8], B_visit[8];
        int A_visitcount = 0, B_visitcount = 0;

        for (int i = 0; i <= T; i++)
        {
            //printf("A position : %d %d          B position : %d %d\n", A.y, A.x, B.y, B.x);
            AP_A.p = 0; AP_B.p = 0;
            AP_B.num = -1, AP_A.num = -1;
            A_visitcount = 0, B_visitcount = 0;
            memset(A_visit, 0, sizeof(A_visit));
            memset(B_visit, 0, sizeof(B_visit));

            for (int j = 0; j < BC_num; j++)
            {
                if (BC[j][A.y][A.x] == 1)
                {
                    A_visit[A_visitcount] = AP[j].p;
                    A_visitcount++;
                    if (AP[j].p>AP_A.p)
                    {
                        AP_A.p = AP[j].p;
                        AP_A.num = j;
                    }
                }

                if (BC[j][B.y][B.x] == 1)
                {
                    B_visit[B_visitcount] = AP[j].p;
                    B_visitcount++;
                    if (AP[j].p>AP_B.p)
                    {
                        AP_B.p = AP[j].p;
                        AP_B.num = j;
                    }
                }
            }

            if (AP_B.num == AP_A.num && AP_B.p == AP_A.p && A_visitcount != 0 && B_visitcount != 0)
            {
                int M = AP_B.p / 2;
                int A_Second_MAX = 0;
                int B_Second_MAX = 0;
                int Second_MAX = 0;
                for (int a = 0; a < A_visitcount; a++)
                {
                    if (A_visit[a] > A_Second_MAX && A_visit[a] != AP_A.p)
                        A_Second_MAX = A_visit[a];
                }

                for (int a = 0; a < B_visitcount; a++)
                {
                    if (B_visit[a] > B_Second_MAX && B_visit[a] != AP_B.p)
                        B_Second_MAX = B_visit[a];
                }

                Second_MAX = A_Second_MAX < B_Second_MAX ? B_Second_MAX : A_Second_MAX;
                total += (M*2 < (AP_A.p + Second_MAX) ? (AP_A.p + Second_MAX) : M);
            }
            else
            {
                total += (AP_A.p + AP_B.p);
            }

            //printf("T : %d    total : %d\n", i, total);
            move(&A.y, &A.x, A_Way[i]);
            move(&B.y, &B.x, B_Way[i]);
        }

        printf("#%d %d\n", Test, total);
    }

    return 0;
}
