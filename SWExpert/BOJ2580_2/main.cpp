#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
FILE *in = fopen("input.txt", "r");
FILE *out = fopen("output.txt", "w");
using namespace std;

int n;

int board[10][10];

int check(int x, int y, int num) {
    int i, j;
    for (i = 0; i < 9; i++)
    {
        if (board[x][i] == num) {
            return 0;
        }
        if (board[i][y] == num) {
            return 0;
        }
    }
    x = (x / 3) * 3;
    y = (y / 3) * 3;
    for (i = x; i < x + 3; i++)
    {
        for (j = y; j < y + 3; j++)
        {
            if (board[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}
int f()
{
    int i, j, k;
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            if (board[i][j] == 0) {
                for (k = 1; k <= 9; k++)
                {
                    if (check(i, j, k) == 1) {
                        board[i][j] = k;
                        if (f() == 1)
                        {
                            return 1;
                        }
                        else {
                            board[i][j] = 0;
                        }
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int i, j, k;
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            fscanf(in,"%d", &board[i][j]);
        }
    }

    f();


    for (int l = 0; l < 9; ++l) {
        for (int m = 0; m < 9; ++m) {
            fprintf(out,"%d ", board[l][m]);
        }
        fprintf(out,"\n");
    }

    return 0;
}