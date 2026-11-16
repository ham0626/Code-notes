#include<bits/stdc++.h>
using namespace std;
const int MAXN=300005;
const int mod=998244353;
int n,m;
int timer;
struct Node{
    int fro,to,nxt;
}edge[MAXN*2];
int head[2*MAXN];
long long siz[MAXN],son[MAXN],dep[MAXN],fa[MAXN];
long long tree[MAXN][55];//节点 k次方
int dfn[MAXN],top[MAXN];
void dfs1(int u,int f){
    dep[u]=dep[f]+1;
    siz[u]=1;
    fa[u]=f;
    tree[u][0]=dep[u];//从1到u的dep的k次方的和
    long long tmp=1;
    for(int i=1;i<=54;i++){
        tmp=(tmp*dep[u])%mod;
        tree[u][i]=(tree[f][i]+tmp)%mod;
    }
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(v==f) continue;
        dfs1(v,u);
        siz[u]+=siz[v];
        if(siz[v]>siz[son[u]]) son[u]=v;
    }
    return;
}
void dfs2(int u,int t){
    dfn[u]=++timer;
    top[u]=t;
    if(son[u]!=0) dfs2(son[u],t);
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(v==son[u]) continue;
        if(v==fa[u]) continue;
        dfs2(v,v);
    }
    return;
}
long long LCA(int a,int b){
    while(top[a]!=top[b]){
        if(dep[top[a]]<dep[top[b]]) swap(a,b);
        a=fa[top[a]];
    }
    if(dep[a]<dep[b]) return a;
    else return b;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    int cnt=1;
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        edge[cnt].fro=u,edge[cnt].to=v;
        edge[cnt].nxt=head[u];
        head[u]=cnt;
        cnt++;
        edge[cnt].fro=v,edge[cnt].to=u;
        edge[cnt].nxt=head[v];
        head[v]=cnt;
        cnt++;
    }
    dep[0]=-1;//根节点深度=0
    dfs1(1,0);
    dfs2(1,1);
    cin>>m;
    for(int i=1;i<=m;i++){
        int u,v,k;
        cin>>u>>v>>k;
        int l=LCA(u,v);
        long long ans=(tree[u][k]+tree[v][k]-tree[l][k]-tree[fa[l]][k]+mod)%mod;
        cout<<(ans+mod)%mod<<'\n';
    }//父节点算了两次 上面公共的路也算了两次
    return 0;
}