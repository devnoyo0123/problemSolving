
#include<iostream>
#include<cstdio>
#include<map>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<set>
#include<ctime>
using namespace std;

int N,M,K,ans;
int _size;
string s;
int dp[103][103][88];   // caution 1
char a[103][103];
int row_move[]={-1,1,0,0};
int col_move[]={0,0,-1,1};

// caution 2
int dfs(int row,int col,int idx){
    if(idx==s.size()-1)
        return 1;

    int& ret = dp[row][col][idx];
    if(ret!=-1) return ret;

    ret=0;
    for(int i=0;i<4;i++){
        for(int k=1;k<=K;k++){
            int nrow = row+row_move[i]*k;
            int ncol = col+col_move[i]*k;
            if(nrow<0||nrow>=N||ncol<0||ncol>=M)
                continue;
            if(a[nrow][ncol]!=s[idx+1])
                continue;
            ret+=dfs(nrow,ncol,idx+1);
        }
    }
    return ret;
}
int main(){
    memset(dp,-1,sizeof(dp));
    cin >> N >> M >> K;
    for(int i=0;i<N;i++){
        scanf("%s",a[i]);
    }
    cin >> s;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(a[i][j]==s[0]){
                ans+=dfs(i,j,0);
            }
        }
    }
    printf("%d",ans);
    return 0;
}