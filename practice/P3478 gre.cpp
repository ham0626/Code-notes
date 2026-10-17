#include<bits/stdc++.h>
using namespace std;
int n,sz[1000010];//子树有多少个节点
long long dp[1000010];
vector<int> tree[1000010];
void dfs1(int x,int fa,int dep){//以1为根，算每个的深度
    sz[x]=1;
    dp[1]=dp[1]+dep;
    for(int i=0;i<=tree[x].size()-1;i++){
        if(tree[x][i]==fa) continue;
        dfs1(tree[x][i],x,dep+1);
        sz[x]=sz[x]+sz[tree[x][i]];
    }
}
void dfs2(int x,int fa){//换根
    for(int i=0;i<=tree[x].size()-1;i++){
        if(tree[x][i]==fa) continue;
        dp[tree[x][i]]=dp[x]+n-2*sz[tree[x][i]];
        dfs2(tree[x][i],x);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    if(n==1){
        cout<<"1";
        return 0;
    }
    dfs1(1,0,0);
    dfs2(1,0);
    long long maxm=0;
    for(int i=1;i<=n;i++) maxm=max(maxm,dp[i]);
    for(int i=1;i<=n;i++)
        if(dp[i]==maxm){
            cout<<i<<'\n';
            break;
        }
    return 0;
}