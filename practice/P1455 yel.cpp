#include<bits/stdc++.h>
using namespace std;
int n,m,w;
int dp[1000005],fa[10005];
int wei[10005],val[10005];
struct node{
    int w,v;
}it[10005];
struct Node{
    int w,v;
}item[10005];
int find(int x){
    if(x==fa[x]) return x;
    else return fa[x]=find(fa[x]);//fa[x]要更新
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>w;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=n;i++) cin>>wei[i]>>val[i];
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        fa[find(u)]=find(v);
    }
    for(int i=1;i<=n;i++){
        it[find(i)].v+=val[i];
        it[find(i)].w+=wei[i];
    }
    int cnt=1;
    for(int i=1;i<=n;i++){
        item[cnt].v=it[i].v;
        item[cnt].w=it[i].w;
        cnt++;
    }
    for(int i=1;i<=cnt;i++)
        for(int j=w;j>=item[i].w;j--)
        dp[j]=max(dp[j],dp[j-item[i].w]+item[i].v);
    cout<<dp[w];
    return 0;
}