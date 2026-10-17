#include<bits/stdc++.h>
using namespace std;
int n;
long long bea[16010],dp[16010];
vector<int> flo[16010];//vector<vector<int>> flo;等价
void dfs(int x,int fa){//x是正在访问的节点
    dp[x]=bea[x];
    for(int i=0;i<=flo[x].size()-1;i++){//flo[x]所有邻居
        if(fa==flo[x][i]) continue;
        dfs(flo[x][i],x);
        if(dp[flo[x][i]]>0)
        dp[x]=dp[x]+dp[flo[x][i]];//子树和
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(dp,-0x3f3f3f3f,sizeof(dp));
    cin>>n;
    for(int i=1;i<=n;i++) cin>>bea[i];
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        flo[u].push_back(v);
        flo[v].push_back(u);
    }
    dfs(1,0);
    long long maxm=-0x3f3f3f3f;
    for(int i=1;i<=n;i++)
        maxm=max(maxm,dp[i]);
    cout<<maxm;
    return 0;
}