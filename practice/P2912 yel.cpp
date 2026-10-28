#include<bits/stdc++.h>
using namespace std;
int n,q;
int head[1005],dep[1005],dis[1005],up[1005][15];
struct Node{
    int fro,to,nxt,val;
}edge[2005];
void dfs(int u,int fa,int val){
    dep[u]=dep[fa]+1;
    dis[u]=dis[fa]+val;//记录边权
    up[u][0]=fa;
    for(int i=1;i<=14;i++)
        up[u][i]=up[up[u][i-1]][i-1];
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        int w=edge[i].val;
        if(v==fa) continue;
        dfs(v,u,w);
    }
    return;
}
int lca(int a,int b){
    int sum=0;
    if(dep[a]<dep[b]) swap(a,b);//a更深
    for(int i=14;i>=0;i--){
        int v=up[a][i];
        if(dep[v]>=dep[b])//可以等于……
            a=v;
    }
    if(a==b) return b;
    for(int i=14;i>=0;i--){
        if(up[a][i]!=up[b][i])
        a=up[a][i],b=up[b][i];
    }
    return up[a][0];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    int cnt=1;
    for(int i=1;i<=n-1;i++){
        int a,b,l;
        cin>>a>>b>>l;
        edge[cnt].fro=a,edge[cnt].to=b,edge[cnt].val=l;
        edge[cnt].nxt=head[a];
        head[a]=cnt;
        cnt++;
        edge[cnt].fro=b,edge[cnt].to=a,edge[cnt].val=l;
        edge[cnt].nxt=head[b];
        head[b]=cnt;
        cnt++;
    }
    dfs(1,0,0);
    for(int i=1;i<=q;i++){
        int a,b;
        cin>>a>>b;
        if(a<b) swap(a,b);
        int c=lca(a,b);
        int dist=dis[a]+dis[b]-2*dis[c];
        cout<<dist<<'\n';
    }
    return 0;
}