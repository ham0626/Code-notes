#include<bits/stdc++.h>
using namespace std;
int n,q;
int dp[105][210];
int start[210],par[210];//从哪里开始是编号为x的边//某个节点的父亲是谁
struct node{
    int fro,to,app;
}tree[210];
void dfs(int x,int fa){
    for(int i=start[x];i<=2*(n-1);i++){//n-1条无向边 2*(n-1)条有向边
        if(fa==tree[i].to) continue;//重复了
        if(tree[i].fro!=x) break;//换下一组了
        // par[tree[i].to]=x;
        dfs(tree[i].to,x);
        for(int j=q;j>=1;j--)
            for(int k=0;k<=j-1;k++)
            dp[x][j]=max(dp[x][j],dp[x][j-1-k]+dp[tree[i].to][k]+tree[i].app);
    }
}
bool comp(node x,node y){
    return x.fro<y.fro;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    int cnt=1;
    for(int i=1;i<=n-1;i++){//n个节点只有n-1条边
        int u,v,w;
        cin>>u>>v>>w;
        tree[cnt].fro=u,tree[cnt].to=v,tree[cnt].app=w;
        cnt++;
        tree[cnt].to=u,tree[cnt].fro=v,tree[cnt].app=w;
        cnt++;
    }
    sort(tree+1,tree+cnt,comp);
    for(int i=1;i<=cnt;i++){
        if(tree[i].fro!=tree[i-1].fro) start[tree[i].fro]=i;
    }
    dfs(1,0);//建树,dp
    cout<<dp[1][q];
    return 0;
}