#include<bits/stdc++.h>
using namespace std;
int n,m;
int group[2010][2010];
int dp[2010][2010];
int dfs(int x,int y){
    if(y==1) return group[x][y];
    if(dp[x][y]!=-1) return dp[x][y];
    if(y>n||y<1||x>m+1||x<0) return 0;
    int v1,v2;
    if(x==1){
        v1=dfs(m,y-1)+group[x][y];
        v2=dfs(x,y-1)+group[x][y];
    }
    else{
        v1=dfs(x-1,y-1)+group[x][y];
        v2=dfs(x,y-1)+group[x][y];
    }
    if(v1<=v2) dp[x][y]=v1;
    else dp[x][y]=v2;
    return dp[x][y];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    int minn=0x3f3f3f3f;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        cin>>group[i][j];
    for(int i=1;i<=m;i++) dp[i][1]=group[i][1];//起点
    for(int i=1;i<=n;i++) group[0][i]=group[m][i],group[m+1][i]=group[1][i];//保护边界
    for(int i=1;i<=m;i++) dfs(i,n);
    for(int i=1;i<=m;i++) minn=min(minn,dp[i][n]);
    cout<<minn;
    return 0;
}