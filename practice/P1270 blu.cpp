#include<bits/stdc++.h>
using namespace std;
int T,wei[110],val[110],lt[110],rt[110];
int dp[110][6010];
int cnt=1;
int build(){
    int t,pat;
    if(!(cin>>t>>pat)) return 0;
    cin>>t>>pat;
    wei[cnt]=t;
    val[cnt]=pat;
    int cur=cnt;
    cnt++;
    if(pat==0){
        lt[cur]=build();
        rt[cur]=build();
    }
    else lt[cur]=rt[cur]=0;
    return cur;
}
void dfs(int u,int tim){
    if(u==0||tim<0) return;//是空节点
    if(wei[u]!=0){//是画室
        for(int t=0;t<=tim;t++)
        dp[u][t]=min(wei[u],t/val[u]);//局部贪心
        return;
    }
    dfs(lt[u],tim-val[u]*2);
    dfs(rt[u],tim-val[u]*2);
    for(int t=val[u]*2;t<=tim;t++)
        for(int i=0;i<=t-val[u]*2;i++){
            int t2=t-val[u]*2-i;//右子树时间
            dp[u][t]=max(dp[u][t],dp[lt[u]][i]+dp[rt[u]][t2]);
        }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>T;
    build();
    dfs(1,T-1);
    cout<<dp[1][T-1];
    return 0;
}