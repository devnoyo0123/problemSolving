#include <cstdio>

char board[10][11];
int N, M, ans;
const int INF = 987654321;

void rotate(int _rx, int _ry, int _bx, int _by, int cnt)
{
    if (cnt > 10 || cnt > ans) return;

    //이동 후 구슬의 좌표
    int rx, ry, bx, by;
    //구슬이 구멍에 빠졌는지
    bool R, B;

    //위
    R = B = false;
    for (int i = _rx - 1; i >= 0; i--)
    {
        if ( board[i][_ry] == '#' )
        {
            rx = i + 1;
            break;
        }
        else if (board[i][_ry] == 'O')
        {
            R = true;
            break;
        }
    }
    for (int i = _bx - 1; i >= 0; i--)
    {
        if (board[i][_by] == '#')
        {
            bx = i + 1;
            break;
        }
        else if (board[i][_by] == 'O')
        {
            B = true;
            break;
        }
    }

    if (!B)
    {
        if (R)
        {
            if (ans > cnt) ans = cnt;
            return;
        }
        else
        {
            if (rx == bx && _ry == _by)
            {
                if (_rx > _bx) rx++;
                else bx++;
            }

            if(rx != _rx || bx != _bx)
                rotate(rx, _ry, bx, _by, cnt + 1);
        }
    }

    //아래
    R = B = false;

    for (int i = _rx  + 1; i < N; i++)
    {
        if (board[i][_ry] == '#')
        {
            rx = i - 1;
            break;
        }
        else if (board[i][_ry] == 'O')
        {
            R = true;
            break;
        }
    }
    for (int i = _bx + 1; i < N; i++)
    {
        if (board[i][_by] == '#')
        {
            bx = i - 1;
            break;
        }
        else if (board[i][_by] == 'O')
        {
            B = true;
            break;
        }
    }

    if (!B)
    {
        if (R)
        {
            if (ans > cnt) ans = cnt;
            return;
        }
        else
        {
            if (rx == bx && _ry == _by)
            {
                if (_rx < _bx) rx--;
                else bx--;
            }

            if (rx != _rx || bx != _bx)
                rotate(rx, _ry, bx, _by, cnt + 1);
        }
    }

    //좌
    R = B = false;

    for (int i = _ry - 1; i >= 0; i--)
    {
        if (board[_rx][i] == '#')
        {
            ry = i + 1;
            break;
        }
        else if (board[_rx][i] == 'O')
        {
            R = true;
            break;
        }
    }
    for (int i = _by - 1; i >= 0; i--)
    {
        if (board[_bx][i] == '#')
        {
            by = i + 1;
            break;
        }
        else if (board[_bx][i] == 'O')
        {
            B = true;
            break;
        }
    }

    if (!B)
    {
        if (R)
        {
            if (ans > cnt) ans = cnt;
            return;
        }
        else
        {
            if (ry == by && _rx == _bx)
            {
                if (_ry > _by) ry++;
                else by++;
            }

            if (ry != _ry || by != _by)
                rotate(_rx, ry, _bx, by, cnt + 1);
        }
    }

    //우
    R = B = false;

    for (int i = _ry + 1; i < M; i++)
    {
        if (board[_rx][i] == '#')
        {
            ry = i - 1;
            break;
        }
        else if (board[_rx][i] == 'O')
        {
            R = true;
            break;
        }
    }
    for (int i = _by + 1; i < M; i++)
    {
        if (board[_bx][i] == '#')
        {
            by = i - 1;
            break;
        }
        else if (board[_bx][i] == 'O')
        {
            B = true;
            break;
        }
    }

    if (!B)
    {
        if (R)
        {
            if (ans > cnt) ans = cnt;
            return;
        }
        else
        {
            if (ry == by && _rx == _bx)
            {
                if (_ry < _by) ry--;
                else by--;
            }

            if (ry != _ry || by != _by)
                rotate(_rx, ry, _bx, by, cnt + 1);
        }
    }
}

int main()
{

    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        scanf("%s", board[i]);
    }

    int rX, rY, bX, bY;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == 'R')
            {
                rX = i;
                rY = j;
            }
            if (board[i][j] == 'B')
            {
                bX = i;
                bY = j;
            }
        }
    }

    ans = INF;

    rotate(rX, rY, bX, bY, 1);
    if (ans == INF) ans = -1;
    printf("%d\n", ans);

    return 0;
}

