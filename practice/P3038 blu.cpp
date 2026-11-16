#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int n,m;
int timer;
struct Node{
    int fro,to,nxt,idx;
}edge[MAXN*2];
int head[2*MAXN];
int siz[MAXN],son[MAXN],dep[MAXN],fa[MAXN];
int dfn[MAXN],top[MAXN],rnk[MAXN],id[2*MAXN];
int tree[4*MAXN],lazy[4*MAXN];
void dfs1(int u,int f){
    siz[u]=1;
    fa[u]=f;
    dep[u]=dep[f]+1;
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(v==f) continue;
        id[edge[i].idx]=v;
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
void pushdown(int u,int l,int r){
    int k=lazy[u];
    lazy[2*u]+=k,lazy[2*u+1]+=k;
    int mid=(l+r)/2;
    tree[2*u]+=(mid-l+1)*k;
    tree[2*u+1]+=(r-mid)*k;
    lazy[u]=0;
    return;
}
void update_pa(int u,int l,int r,int x,int y){
    if(x<=l&&r<=y){
        lazy[u]++;
        tree[u]+=r-l+1;
        return;
    }
    pushdown(u,l,r);
    int mid=(l+r)/2;
    if(x<=mid) update_pa(2*u,l,mid,x,y);
    if(y>mid) update_pa(2*u+1,mid+1,r,x,y);
    tree[u]=tree[2*u]+tree[2*u+1];//不需要改
    return;
}
void update(int x,int y){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        update_pa(1,1,n,dfn[top[x]],dfn[x]);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    if(x!=y) update_pa(1,1,n,dfn[x]+1,dfn[y]);//把x到x父亲的避开
    return;
}
int query(int u,int l,int r,int x){
    if(l==r)
        return tree[u];
    pushdown(u,l,r);
    int mid=(l+r)/2;
    if(x<=mid) return query(2*u,l,mid,x);
    else return query(2*u+1,mid+1,r,x);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    int cnt=1;
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        edge[cnt].fro=u,edge[cnt].to=v;
        edge[cnt].nxt=head[u];
        head[u]=cnt;
        edge[cnt].idx=i;
        cnt++;
        edge[cnt].fro=v,edge[cnt].to=u;
        edge[cnt].nxt=head[v];
        head[v]=cnt;
        edge[cnt].idx=i;
        cnt++;
    }
    dfs1(1,0);
    dfs2(1,1);
    for(int i=1;i<=m;i++){
        char op;
        cin>>op;
        if(op=='P'){//边权+1
            int u,v;
            cin>>u>>v;
            update(u,v);
        }
        else{//查询两个点之间的那个权值
            int u,v;
            cin>>u>>v;
            if(dep[u]<dep[v]) swap(u,v);//u更深
            cout<<query(1,1,n,dfn[u])<<'\n';
        }
    }
    return 0;
}