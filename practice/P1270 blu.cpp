#include<bits/stdc++.h>
using namespace std;
int T,wei[210],val[210],lt[210],rt[210];
int dp[210][6005],full[210],cap[210];
int cnt=1;
int build(){
    int t,pat;
    if(!(cin>>t>>pat)) return 0;
    int cur=cnt++;
    wei[cur]=t;
    val[cur]=pat;
    if(pat==0){
        lt[cur]=build();
        rt[cur]=build();
    }
    return cur;
}
void dfs(int u){
    int edge=wei[u]*2;
    if(val[u]>0){
        full[u]=edge+5*val[u];
        cap[u]=min(T,full[u]);
        for(int t=edge;t<=cap[u];t++)
            dp[u][t]=min(val[u],(t-edge)/5);
        return;
    }
    int L=lt[u],R=rt[u];
    dfs(L);
    dfs(R);
    full[u]=edge+full[L]+full[R];
    cap[u]=min(T,full[u]);
    for(int t=edge;t<=cap[u];t++){
        int rem=t-edge;
        int lo=max(0,rem-cap[R]);
        int hi=min(rem,cap[L]);
        for(int i=lo;i<=hi;i++)
            dp[u][t]=max(dp[u][t],dp[L][i]+dp[R][rem-i]);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>T;
    build();
    dfs(1);
    int lim=max(0,T-1);
    cout<<dp[1][min(lim,cap[1])];
    return 0;
}