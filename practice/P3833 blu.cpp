#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int n,q;
int timer;
struct Node{
    int fro,to,nxt;
}edge[2*MAXN];
int head[MAXN];
int dfn[MAXN],rnk[MAXN],son[MAXN];
int siz[MAXN],top[MAXN],fa[MAXN],dep[MAXN];
long long tree[4*MAXN],lazy[4*MAXN];
void dfs1(int u,int f){
    siz[u]=1;
    fa[u]=f;
    dep[u]=dep[f]+1;
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;//*
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
    if(son[u]!=0)
        dfs2(son[u],t);
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(v==son[u]) continue;
        if(v==fa[u]) continue;
        dfs2(v,v);
    }
    return;
}
void build(int u,int l,int r){
    if(l==r){
        tree[u]=rnk[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*u,l,mid);
    build(2*u+1,mid+1,r);
    tree[u]=tree[2*u]+tree[2*u+1];
    return;
}
void pushdown(int u,int l,int r){
    long long k=lazy[u];//*不能用int
    lazy[2*u]+=k,lazy[2*u+1]+=k;
    int mid=(l+r)/2;
    tree[2*u]+=(mid-l+1)*k;
    tree[2*u+1]+=(r-mid)*k;
    lazy[u]=0;
    return;
}
void update_mod(int u,int l,int r,int x,int y,int k){
    if(x<=l&&r<=y){
        tree[u]+=1LL*(r-l+1)*k;
        lazy[u]+=k;
        return;
    }
    pushdown(u,l,r);
    int mid=(l+r)/2;
    if(x<=mid) update_mod(2*u,l,mid,x,y,k);
    if(y>mid) update_mod(2*u+1,mid+1,r,x,y,k);
    tree[u]=tree[2*u]+tree[2*u+1];
    return;
}
void update_path(int x,int y,int k){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        update_mod(1,1,n,dfn[top[x]],dfn[x],k);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    update_mod(1,1,n,dfn[x],dfn[y],k);//前浅后深
    return;
}
long long query_sum(int u,int l,int r,int x,int y){
    long long sum=0;
    if(x<=l&&r<=y)
        return tree[u];
    pushdown(u,l,r);//*
    int mid=(l+r)/2;
    if(x<=mid) sum+=query_sum(2*u,l,mid,x,y);
    if(y>mid) sum+=query_sum(2*u+1,mid+1,r,x,y);
    return sum;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) fa[i]=i;
    int cnt=1;
    for(int i=1;i<=n-1;i++){
        int a,b;
        cin>>a>>b;//装傻不修改fa 避免混乱
        a++,b++;//集体右移
        edge[cnt].fro=a,edge[cnt].to=b;
        edge[cnt].nxt=head[a];
        head[a]=cnt;
        cnt++;
        edge[cnt].fro=b,edge[cnt].to=a;
        edge[cnt].nxt=head[b];
        head[b]=cnt;
        cnt++;
    }
    dfs1(1,0);
    dfs2(1,1);
    build(1,1,n);
    cin>>q;
    for(int i=1;i<=q;i++){
        char op;
        cin>>op;
        if(op=='A'){//路径上每个点修改
            int u,v,d;
            cin>>u>>v>>d;
            u++,v++;
            update_path(u,v,d);
        }
        else{//询问某点及子树总和
            int u;
            cin>>u;
            u++;
            cout<<query_sum(1,1,n,dfn[u],dfn[u]+siz[u]-1)<<'\n';
        }
    }
    return 0;
}