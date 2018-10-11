#include <iostream>
#include <queue>

using namespace std;

#define MAX_SIZE 10
#define MAX_CUS_SIZE 1001

int T;
int N, M, K, A, B;
int ans = 0;

queue<int> qa;
queue<int> qb;

int a[MAX_SIZE];
int b[MAX_SIZE];
int a_using[MAX_SIZE];
int b_using[MAX_SIZE];
int a_time[MAX_SIZE];
int b_time[MAX_SIZE];
bool check[MAX_CUS_SIZE];
int k[MAX_CUS_SIZE];

void print()
{
    for(int i=1; i<=N; i++)
    {
        cout << a_using[i] << ' ';
    }
    cout << '\n';
    for(int i=1; i<=M; i++)
    {
        cout << b_using[i] << ' ';
    }
    cout << '\n';
}

void init_customer()
{
    for(int i=1; i<=K; i++)
    {
        cin >> k[i];
        check[i] = false;
    }
}

void init_map()
{
    for(int i=1; i<=N; i++)
    {
        cin >> a[i];
        a_time[i] = a[i];
        a_using[i] = -1;
    }

    for(int i=1; i<=M; i++)
    {
        cin >> b[i];
        b_time[i] = b[i];
        b_using[i] = -1;
    }
}

void go(int time, int cnt)
{
    if( cnt == K )
        return;

    /* 시간에 따라 고객 접수창고 대기 줄에 넣기 */
    for(int i=1; i<=K; i++)
    {
        if(time == k[i])
            qa.push(i);
        else if(time < k[i])
            break;
    }

    /* 접수창구 배정 */
    for(int i=1; i<=N; i++)
    {
        if(qa.empty())
            break;
        if(a_using[i] == -1)
        {
            if( i == A )
                check[qa.front()] = true;
            a_using[i] = qa.front();
            qa.pop();
        }
    }

    /* 정비창구 배정 */
    for(int i=1; i<=M; i++)
    {
        if(qb.empty())
            break;
        if(b_using[i] == -1)
        {
            if( i == B && check[qb.front()] == true)
                ans += qb.front();
            b_using[i] = qb.front();
            qb.pop();
            cnt += 1;
        }
    }

    /* 1초 경과 : a */
    for(int i=1; i<=N; i++)
    {
        if(a_using[i] != -1)
        {
            a_time[i]--;
            if(a_time[i] == 0)
            {
                a_time[i] = a[i];
                qb.push(a_using[i]);
                a_using[i] = -1;
            }
        }
    }

    /* 1초 경과 : b */
    for(int i=1; i<=M; i++)
    {
        if(b_using[i] != -1)
        {
            b_time[i]--;
            if(b_time[i] == 0)
            {
                b_time[i] = b[i];
                b_using[i] = -1;
            }
        }
    }

    go(time+1,cnt);

}

int main()
{
    cin >> T;

    for(int i=1; i<=T; i++)
    {
        cin >> N >> M >> K >> A >> B;
        ans = 0;
        init_map();
        init_customer();
        go(0, 0);
        if( ans == 0 )
            ans = -1;
        cout << "#" << i << ' ' << ans << '\n';
    }

    return 0;
}
