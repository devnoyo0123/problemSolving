#include <cstdio>
#include <queue>

using namespace std;

const int MAX = 1000000100; //10억 100

bool check[MAX];
char ans[MAX],flag;

int s,t, ans1;

void go(int s, int t, int inx){
    queue<int> qu1;
    check[s] = true;
    qu1.push(s);

    while(!qu1.empty()){
        int tmp = qu1.front(); qu1.pop();

        if( tmp == t){
            flag = true;
            return;
        }

        if( check[tmp+tmp]){
            continue;
        }

        check[tmp+tmp] = true;
        qu1.push(tmp+tmp);

        if( check[tmp-tmp]){
            continue;
        }

        check[tmp-tmp] = true;
        qu1.push(tmp-tmp);

        if( check[tmp*tmp]){
            continue;
        }

        if( tmp*tmp <= MAX){
            check[tmp*tmp] = true;
            qu1.push(tmp*tmp);
        }


        if( tmp > 0 && check[tmp/tmp]){
            continue;
        }

        check[tmp/tmp] = true;
        qu1.push(tmp/tmp);

    }
}

int main() {
    scanf("%d %d", &s, &t);

    if( s == t){
        printf("%d", 0);
    }
    go(s,t, 0);
    if(!flag){
       printf("%d\n",-1);
    }
    return 0;
}