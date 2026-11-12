#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int n,m;
int timer;
int head[MAXN];
int num[MAXN],dep[MAXN],son[MAXN],fa[MAXN],siz[MAXN];
int dfn[MAXN],rnk[MAXN],top[MAXN];
long long tree[4*MAXN],lazy[4*MAXN];
struct Node{
    int fro,to,nxt;
}edge[2*MAXN];
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
void dfs1(int u,int f){//找重链
    dep[u]=dep[f]+1;
    fa[u]=f;
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(v==f) continue;
        dfs1(v,u);//先搜索
        siz[u]+=siz[v];
        if(siz[v]>siz[son[u]]) son[u]=v;//找重链
    }
    return;
}
void dfs2(int u,int t){//重新分配
    dfn[u]=++timer;
    rnk[timer]=num[u];
    top[u]=t;//顶端
    if(son[u]!=0)
        dfs2(son[u],t);//重儿子
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(son[u]==v) continue;//重儿子要跳
        if(v==fa[u]) continue;//父亲也要tiao*
        dfs2(v,v);
    }
    return;
}
void pushdown(int u,int l,int r){
    long long k=lazy[u];
    lazy[2*u]+=k,lazy[2*u+1]+=k;
    int mid=(l+r)/2;
    tree[2*u]+=(mid-l+1)*k;
    tree[2*u+1]+=(r-mid)*k;
    lazy[u]=0;
    return;
}
void update_po(int u,int l,int r,int x,int k){//单点修改
    if(l==r){
        tree[u]+=k;
        return;
    }
    pushdown(u,l,r);
    int mid=(l+r)/2;
    if(x<=mid) update_po(2*u,l,mid,x,k);
    else update_po(2*u+1,mid+1,r,x,k);
    tree[u]=tree[2*u]+tree[2*u+1];
    return;
}
void update_sum(int u,int l,int r,int x,int y,int k){
    if(x<=l&&r<=y){
        lazy[u]+=k;
        tree[u]+=1LL*k*(r-l+1);
        return;
    }
    pushdown(u,l,r);
    int mid=(l+r)/2;
    if(x<=mid) update_sum(2*u,l,mid,x,y,k);
    if(y>mid) update_sum(2*u+1,mid+1,r,x,y,k);
    tree[u]=tree[2*u]+tree[2*u+1];
    return;
}
long long query_sum(int u,int l,int r,int x,int y){
    long long  sum=0;
    if(x<=l&&r<=y)
        return tree[u];
    pushdown(u,l,r);
    int mid=(l+r)/2;
    if(x<=mid) sum+=query_sum(2*u,l,mid,x,y);
    if(y>mid) sum+=query_sum(2*u+1,mid+1,r,x,y);
    return sum;
}
//top和dfn下标和num一样
void update_rt(int x,int y,int k){//子树内修改
    while(top[x]!=top[y]){//读链
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        update_sum(1,1,n,dfn[top[x]],dfn[top[y]],k);//只处理当前链的
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    update_sum(1,1,n,dfn[top[x]],dfn[top[y]],k);
    return;
}
long long  query_path(int x,int y){
    long long  sum=0;
    while(top[x]!=top[y]){//读链
        if(dep[top[x]]<dep[top[y]]) swap(x,y);//深的往上
        sum+=query_sum(1,1,n,dfn[top[x]],dfn[x]);//只处理当前链的
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);//最后x y在同一条链上
    sum+=query_sum(1,1,n,dfn[x],dfn[y]);//这里不能再top了 已经top过
    return sum;//交换后x更浅 符合线段树前浅后深
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>num[i];
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=n;i++) siz[i]=1;
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
    dfs1(1,0);
    dfs2(1,1);//顶是自己
    build(1,1,n);
    for(int i=1;i<=m;i++){
        int op;
        cin>>op;
        if(op==1){//单点+a
            int x,a;
            cin>>x>>a;
            update_po(1,1,n,dfn[x],a);
        }
        else if(op==2){//子树内所有点+a=区间修
            int x,a;
            cin>>x>>a;
            update_sum(1,1,n,dfn[x],dfn[x]+siz[x]-1,a);
        }
        else{//路径上点权和
            int x;
            cin>>x;
            cout<<query_path(1,x)<<'\n';
        }
    }
    return 0;
}