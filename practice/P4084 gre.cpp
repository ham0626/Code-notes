#include<bits/stdc++.h>
using namespace std;
int n,k,col[100010];//节点颜色//没涂：0 涂了：1/2/3
long long dp[100010][5];
int mod=1e9+7;
vector<int> tree[100010];
void dfs(int x,int fa){
    if(col[x]!=0){
        dp[x][1]=0,dp[x][2]=0,dp[x][3]=0;
        dp[x][col[x]]=1;//只有这个能成立
    }
    else{
        dp[x][1]=1,dp[x][2]=1,dp[x][3]=1;
    }
    for(int i=0;i<=tree[x].size()-1;i++){//当前是x，父节点fa，子节点tree[x][i]
        if(tree[x][i]==fa) continue;
        dfs(tree[x][i],x);
        for(int j=1;j<=3;j++){
            long long sum=(dp[tree[x][i]][1]+dp[tree[x][i]][2]+dp[tree[x][i]][3]-dp[tree[x][i]][j])%mod;
            dp[x][j]=dp[x][j]*sum%mod;
        }//x涂j的方案数
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    for(int i=1;i<=k;i++){
        int b,c;
        cin>>b>>c;
        col[b]=c;
    }
    dfs(1,0);
    cout<<(dp[1][1]+dp[1][2]+dp[1][3])%mod;//回到最开始选的根上
    return 0;
}