#include<bits/stdc++.h>
using namespace std;
int mapp[110][110];//只能往小了走，回不来
int dp[110][110];//存在某一个格子
int r,c;
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int dfs(int x,int y){
    int best=1;
    if(dp[x][y]!=-1) return dp[x][y];//已经算过
    for(int i=0;i<=3;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(nx<1||nx>r||ny<1||ny>c) continue;//边界
        if(mapp[x][y]>mapp[nx][ny]){
            dp[x][y]=best;
            if(dfs(nx,ny)+1>dp[x][y]) best=dfs(nx,ny)+1;
        }
    }
    return dp[x][y]=best;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>r>>c;
    int maxn=0;
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            cin>>mapp[i][j],dp[i][j]=-1;
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
        dfs(i,j);
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
        maxn=max(maxn,dp[i][j]);
    cout<<maxn;
    return 0;
}
