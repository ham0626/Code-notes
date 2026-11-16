#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int n,q;
int timer;
struct Node{
    int fro,to,nxt;
}edge[2*MAXN];
int head[MAXN];
int num[MAXN],dfn[MAXN],rnk[MAXN],son[MAXN];
int siz[MAXN],top[MAXN],fa[MAXN],dep[MAXN];
long long tree[4*MAXN],tag[4*MAXN];
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
    rnk[timer]=num[u];
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
    long long k=tag[u];//*不能用int
    if(k==-1) return;
    if(k==0){//卸载
        tag[2*u]=0,tag[2*u+1]=0;
        tree[2*u]=0;
        tree[2*u+1]=0;
    }
    else{
        tag[2*u]=1,tag[2*u+1]=1;
        int mid=(l+r)/2;
        tree[2*u]=mid-l+1;
        tree[2*u+1]=r-mid;
    }
    tag[u]=-1;
    return;
}
void update_mod(int u,int l,int r,int x,int y,int k){
    if(x<=l&&r<=y){
        if(k==0) tree[u]=0;
        if(k==1) tree[u]=r-l+1;
        tag[u]=k;
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
    memset(tag,-1,sizeof(tag));
    cin>>n;
    int cnt=1;
    for(int i=1;i<=n-1;i++){
        int d;
        cin>>d;
        d++;
        edge[cnt].fro=i+1,edge[cnt].to=d;
        edge[cnt].nxt=head[i+1];
        head[i+1]=cnt;
        cnt++;
        edge[cnt].fro=d,edge[cnt].to=i+1;
        edge[cnt].nxt=head[d];
        head[d]=cnt;
        cnt++;
    }
    for(int i=1;i<=n;i++) fa[i]=i;
    dfs1(1,0);
    dfs2(1,1);
    build(1,1,n);
    cin>>q;
    for(int i=1;i<=q;i++){
        string op;
        cin>>op;
        if(op[0]=='i'){//安装
            int x;
            cin>>x;
            x++;
            int sum0=tree[1];
            update_path(1,x,1);
            int sum1=tree[1];
            cout<<abs(sum0-sum1)<<'\n';
        }
        else{//卸载
            int x;
            cin>>x;
            x++;
            int sum0=query_sum(1,1,n,dfn[x],dfn[x]+siz[x]-1);
            update_mod(1,1,n,dfn[x],dfn[x]+siz[x]-1,0);
            cout<<sum0<<'\n';//找原来有多少个安装ok
        }
    }
    return 0;
}