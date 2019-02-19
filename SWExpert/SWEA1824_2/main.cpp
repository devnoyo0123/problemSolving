#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;

queue<pair<pair<int ,int>,int> > Q;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

char arr[101][101];
int N,M,T;

int main()
{
    scanf("%d",&T);

    for(int tc=1;tc<=T;tc++)
    {
        scanf("%d %d",&N,&M);
        int cnt=0,current=1;
        for(int i=N-1;i>=0;i--)
            scanf("%s",arr[i]);
        while(!Q.empty())
            Q.pop();
        Q.push(make_pair(make_pair(N-1,0),1));
        int flag=0;
        int total=0;

        while(!Q.empty())
        {
            total++;

            if(total>500)
            {//total--;
                break;

            }
            int y=Q.front().first.first;
            int x=Q.front().first.second;
            int current=Q.front().second;
            //printf("real %d %d\n",y,x);
            Q.pop();
            if(y>N-1)
                y=0;
            else if(y<0)
                y=N-1;
            if(x>M-1)
                x=0;
            else if(x<0)
                x=M-1;

            if(arr[y][x]=='>')
            {

                Q.push(make_pair(make_pair(y,x+1),1));
            }
            else if(arr[y][x]=='<')
            {
                Q.push(make_pair(make_pair(y,x-1),0));
            }
            else  if(arr[y][x]=='^')
            {

                Q.push(make_pair(make_pair(y+1,x),2));
            }
            else if(arr[y][x]=='v')
            {
                Q.push(make_pair(make_pair(y-1,x),3));
            }
            else  if(arr[y][x]=='-')
            {
                cnt--;
                if(cnt<0)
                    cnt=15;
                if(current==0)
                    Q.push(make_pair(make_pair(y,x-1),0));
                else if(current==1)
                    Q.push(make_pair(make_pair(y,x+1),1));
                else if(current==2)
                    Q.push(make_pair(make_pair(y+1,x),2));
                else if(current==3)
                    Q.push(make_pair(make_pair(y-1,x),3));
            }
            else if(arr[y][x]=='+')
            {
                cnt++;
                if(cnt>15)
                    cnt=0;
                if(current==0)
                    Q.push(make_pair(make_pair(y,x-1),0));
                else if(current==1)
                    Q.push(make_pair(make_pair(y,x+1),1));
                else if(current==2)
                    Q.push(make_pair(make_pair(y+1,x),2));
                else if(current==3)
                    Q.push(make_pair(make_pair(y-1,x),3));
            }
            else  if(arr[y][x]=='.')
            {
                if(current==0)
                    Q.push(make_pair(make_pair(y,x-1),0));
                else if(current==1)
                    Q.push(make_pair(make_pair(y,x+1),1));
                else if(current==2)
                    Q.push(make_pair(make_pair(y+1,x),2));
                else if(current==3)
                    Q.push(make_pair(make_pair(y-1,x),3));
            }
            else  if(arr[y][x]=='@')
            {
                flag=1;
                break;
            }
            else if(arr[y][x]=='0')
            {
                cnt=0;
                if(current==0)
                    Q.push(make_pair(make_pair(y,x-1),0));
                else if(current==1)
                    Q.push(make_pair(make_pair(y,x+1),1));
                else if(current==2)
                    Q.push(make_pair(make_pair(y+1,x),2));
                else if(current==3)
                    Q.push(make_pair(make_pair(y-1,x),3));
            }
            else if(arr[y][x]=='1')
            {
                cnt=1;
                if(current==0)
                    Q.push(make_pair(make_pair(y,x-1),0));
                else if(current==1)
                    Q.push(make_pair(make_pair(y,x+1),1));
                else if(current==2)
                    Q.push(make_pair(make_pair(y+1,x),2));
                else if(current==3)
                    Q.push(make_pair(make_pair(y-1,x),3));
            }
            else  if(arr[y][x]=='2')
            {
                cnt=2;
                if(current==0)
                    Q.push(make_pair(make_pair(y,x-1),0));
                else if(current==1)
                    Q.push(make_pair(make_pair(y,x+1),1));
                else if(current==2)
                    Q.push(make_pair(make_pair(y+1,x),2));
                else if(current==3)
                    Q.push(make_pair(make_pair(y-1,x),3));
            }
            else  if(arr[y][x]=='3')
            {
                cnt=3;
                if(current==0)
                    Q.push(make_pair(make_pair(y,x-1),0));
                else if(current==1)
                    Q.push(make_pair(make_pair(y,x+1),1));
                else if(current==2)
                    Q.push(make_pair(make_pair(y+1,x),2));
                else if(current==3)
                    Q.push(make_pair(make_pair(y-1,x),3));
            }
            else  if(arr[y][x]=='4')
            {
                cnt=4;
                if(current==0)
                    Q.push(make_pair(make_pair(y,x-1),0));
                else if(current==1)
                    Q.push(make_pair(make_pair(y,x+1),1));
                else if(current==2)
                    Q.push(make_pair(make_pair(y+1,x),2));
                else if(current==3)
                    Q.push(make_pair(make_pair(y-1,x),3));
            }
            else if(arr[y][x]=='5')
            {
                cnt=5;
                if(current==0)
                    Q.push(make_pair(make_pair(y,x-1),0));
                else if(current==1)
                    Q.push(make_pair(make_pair(y,x+1),1));
                else if(current==2)
                    Q.push(make_pair(make_pair(y+1,x),2));
                else if(current==3)
                    Q.push(make_pair(make_pair(y-1,x),3));
            }
            else if(arr[y][x]=='6')
            {
                cnt=6;
                if(current==0)
                    Q.push(make_pair(make_pair(y,x-1),0));
                else if(current==1)
                    Q.push(make_pair(make_pair(y,x+1),1));
                else if(current==2)
                    Q.push(make_pair(make_pair(y+1,x),2));
                else if(current==3)
                    Q.push(make_pair(make_pair(y-1,x),3));
            }
            else if(arr[y][x]=='7')
            {
                cnt=7;
                if(current==0)
                    Q.push(make_pair(make_pair(y,x-1),0));
                else if(current==1)
                    Q.push(make_pair(make_pair(y,x+1),1));
                else if(current==2)
                    Q.push(make_pair(make_pair(y+1,x),2));
                else if(current==3)
                    Q.push(make_pair(make_pair(y-1,x),3));
            }
            else if(arr[y][x]=='8')
            {
                cnt=8;
                if(current==0)
                    Q.push(make_pair(make_pair(y,x-1),0));
                else if(current==1)
                    Q.push(make_pair(make_pair(y,x+1),1));
                else if(current==2)
                    Q.push(make_pair(make_pair(y+1,x),2));
                else if(current==3)
                    Q.push(make_pair(make_pair(y-1,x),3));
            }
            else if(arr[y][x]=='9')
            {
                cnt=9;
                if(current==0)
                    Q.push(make_pair(make_pair(y,x-1),0));
                else if(current==1)
                    Q.push(make_pair(make_pair(y,x+1),1));
                else if(current==2)
                    Q.push(make_pair(make_pair(y+1,x),2));
                else if(current==3)
                    Q.push(make_pair(make_pair(y-1,x),3));
            }

            else if(arr[y][x]=='_')
            {
                if(cnt==0)
                {
                    Q.push(make_pair(make_pair(y,x+1),1));
                }
                else
                {
                    Q.push(make_pair(make_pair(y,x-1),0));

                }
            }
            else if(arr[y][x]=='|')
            {
                if(cnt==0)
                {
                    Q.push(make_pair(make_pair(y-1,x),3));
                }
                else
                {
                    Q.push(make_pair(make_pair(y+1,x),2));

                }
            }
            else if(arr[y][x]=='?')
            {
                if(current==0)
                {
                    Q.push(make_pair(make_pair(y,x+1),1));
                    Q.push(make_pair(make_pair(y,x-1),0));
                    Q.push(make_pair(make_pair(y-1,x),3));
                    Q.push(make_pair(make_pair(y+1,x),2));
                }
                else if(current==1)
                {
                    Q.push(make_pair(make_pair(y,x-1),0));
                    Q.push(make_pair(make_pair(y,x+1),1));
                    Q.push(make_pair(make_pair(y-1,x),3));
                    Q.push(make_pair(make_pair(y+1,x),2));
                }
                else if(current==2)
                {
                    Q.push(make_pair(make_pair(y-1,x),3));
                    Q.push(make_pair(make_pair(y+1,x),2));
                    Q.push(make_pair(make_pair(y,x+1),1));
                    Q.push(make_pair(make_pair(y,x-1),0));
                }
                else if(current==3)
                {
                    Q.push(make_pair(make_pair(y+1,x),2));
                    Q.push(make_pair(make_pair(y-1,x),3));
                    Q.push(make_pair(make_pair(y,x+1),1));
                    Q.push(make_pair(make_pair(y,x-1),0));
                }


            }
            //printf("%d %d %d %d %c\n",y,x,cnt,current,arr[y][x]);
        }
        printf("#%d ",tc);
        if(flag==1)
            printf("YES\n");
        else
            printf("NO\n");
    }
}