#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;//数量，时间
int dp[510][510][2];//一维：当前节点 二维：消耗的时间(送和不送消耗的时间不同) 三维：回不回来(0:回来 1:不回来)
int mon[510],start[510];
struct node{
    int fro,to;
}shop[1000];
void dfs(int x,int fa){
    for(int i=0;i<=m;i++) dp[x][i][0]=0,dp[x][i][1]=0;//从x出发 用i时间 回/不回
    dp[x][1][0]=mon[x];
    dp[x][1][1]=mon[x];//首页初始化
    for(int i=start[x];i<=cnt;i++){
        if(shop[i].fro!=x) break;
        if(fa==shop[i].to) continue;
        dfs(shop[i].to,x);
            for(int j=m;j>=0;j--)
                for(int k=0;k<=j;k++){
                if(j>=k+2)
                dp[shop[i].fro][j][0]=max(dp[shop[i].fro][j][0],dp[shop[i].fro][j-2-k][0]+dp[shop[i].to][k][0]);//不能再加mon,dp里面已经包含//已经停过必须全部回来
                if(j>=k+1)
                dp[shop[i].fro][j][1]=max(dp[shop[i].fro][j][1],dp[shop[i].fro][j-1-k][0]+dp[shop[i].to][k][1]);//停在shop[i].to或子树
                if(j>=k+2)
                dp[shop[i].fro][j][1]=max(dp[shop[i].fro][j][1],dp[shop[i].fro][j-2-k][1]+dp[shop[i].to][k][0]);//停在另一子树
                //dp[3][0][0]=0   //在w不送货
                //dp[3][1][0]=7   //在w送货,回w
                //dp[3][1][1]=7   //在w送货,停在w
        }
    }
}
bool comp(node x,node y){
    return x.fro<y.fro;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cnt=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>mon[i];
    }
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        shop[cnt].fro=u;
        shop[cnt].to=v;
        cnt++;
        shop[cnt].fro=v;
        shop[cnt].to=u;
        cnt++;
    }
    sort(shop+1,shop+cnt,comp);
    for(int i=1;i<=cnt;i++){
        if(shop[i].fro!=shop[i-1].fro) start[shop[i].fro]=i;
    }
    dfs(1,0);
    cout<<max(dp[1][m][0],dp[1][m][1]);
    return 0;
}