#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int n;
int timer;
struct Node{
    int fro,to,nxt,idx,val;
}edge[2*MAXN];
int head[MAXN];
int fa[MAXN],siz[MAXN],son[MAXN],dep[MAXN];
int dfn[MAXN],rnk[MAXN],top[MAXN];
int id[MAXN*2],val[2*MAXN];
int lazy_add[4*MAXN],lazy_cov[4*MAXN];
int tree[4*MAXN];//只记最大值
void dfs1(int u,int f){
    fa[u]=f;
    siz[u]=1;
    dep[u]=dep[f]+1;
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        int w=edge[i].val;
        if(v==f) continue;
        val[v]=w;
        id[edge[i].idx]=v;
        dfs1(v,u);
        siz[u]+=siz[v];
        if(siz[v]>siz[son[u]]) son[u]=v;
    }
    return;
}
void dfs2(int u,int t){
    dfn[u]=++timer;
    rnk[timer]=val[u];
    top[u]=t;
    if(son[u]!=0) dfs2(son[u],t);
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(v==fa[u]) continue;
        if(v==son[u]) continue;
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
    tree[u]=max(tree[2*u],tree[2*u+1]);
    return;
}
void pushdown(int u,int l,int r){
    int k=lazy_add[u],c=lazy_cov[u];
    if(k==0&&c==-1) return;
    if(c!=-1){//要覆盖
        tree[2*u]=c,tree[2*u+1]=c;
        lazy_add[2*u]=0,lazy_add[2*u+1]=0;
        lazy_cov[2*u]=c,lazy_cov[2*u+1]=c;
    }
    if(k!=0){//要加
        lazy_add[2*u]+=k,lazy_add[2*u+1]+=k;
        tree[2*u]+=k,tree[2*u+1]+=k;
    }
    lazy_add[u]=0,lazy_cov[u]=-1;
    return;
}
void update_add0(int u,int l,int r,int x,int y,int k){
    if(x<=l&&r<=y){
        lazy_add[u]+=k;
        tree[u]+=k;
        return;
    }
    pushdown(u,l,r);
    int mid=(l+r)/2;
    if(x<=mid) update_add0(2*u,l,mid,x,y,k);
    if(y>mid) update_add0(2*u+1,mid+1,r,x,y,k);
    tree[u]=max(tree[2*u],tree[2*u+1]);
    return;
}
void update_add(int x,int y,int k){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        update_add0(1,1,n,dfn[top[x]],dfn[x],k);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    if(x!=y) update_add0(1,1,n,dfn[x]+1,dfn[y],k);
    return;
}
void update_cov0(int u,int l,int r,int x,int y,int k){
    if(x<=l&&r<=y){
        lazy_cov[u]=k;
        lazy_add[u]=0;
        tree[u]=k;
        return;
    }
    pushdown(u,l,r);
    int mid=(l+r)/2;
    if(x<=mid) update_cov0(2*u,l,mid,x,y,k);
    if(y>mid) update_cov0(2*u+1,mid+1,r,x,y,k);
    tree[u]=max(tree[2*u],tree[2*u+1]);
    return;
}
void update_cov(int x,int y,int k){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        update_cov0(1,1,n,dfn[top[x]],dfn[x],k);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    if(x!=y) update_cov0(1,1,n,dfn[x]+1,dfn[y],k);
    return;
}
void update_cha(int u,int l,int r,int x,int k){
    if(l==r){
        tree[u]=k;
        return;
    }
    pushdown(u,l,r);
    int mid=(l+r)/2;
    if(x<=mid) update_cha(2*u,l,mid,x,k);
    else update_cha(2*u+1,mid+1,r,x,k);
    tree[u]=max(tree[2*u],tree[2*u+1]);
    return;
}
int query0(int u,int l,int r,int x,int y){
    int maxx=-1e9;
    if(x<=l&&r<=y)
        return tree[u];
    pushdown(u,l,r);
    int mid=(l+r)/2;
    if(x<=mid) maxx=max(maxx,query0(2*u,l,mid,x,y));
    if(y>mid) maxx=max(maxx,query0(2*u+1,mid+1,r,x,y));
    return maxx;
}
int query(int x,int y){
    int maxx=-1e9;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        maxx=max(maxx,query0(1,1,n,dfn[top[x]],dfn[x]));
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    if(x!=y) maxx=max(maxx,query0(1,1,n,dfn[x]+1,dfn[y]));
    return maxx;//*
}
    int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(lazy_cov,-1,sizeof(lazy_cov));
    cin>>n;
    int cnt=1;
    for(int i=1;i<=n-1;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edge[cnt].fro=u,edge[cnt].to=v,edge[cnt].val=w;
        edge[cnt].nxt=head[u];
        head[u]=cnt;
        edge[cnt].idx=i;
        cnt++;
        edge[cnt].fro=v,edge[cnt].to=u,edge[cnt].val=w;
        edge[cnt].nxt=head[v];
        head[v]=cnt;
        edge[cnt].idx=i;
        cnt++;
    }
    dfs1(1,0);
    dfs2(1,1);
    for(int i=1;i<n;i++) id[i]=dfn[id[i]];
    build(1,1,n);
    string op;
    while(cin>>op){
        if(op[0]=='S') return 0;
        if(op[0]=='M'){//查询最多
            int u,v;
            cin>>u>>v;
            cout<<query(u,v)<<'\n';
        }
        else if(op[0]=='A'){//路径上增加
            int u,v,w;
            cin>>u>>v>>w;
            update_add(u,v,w);
        }
        else{
            if(op[1]=='h'){//修改
                int k,w;
                cin>>k>>w;
                update_cha(1,1,n,id[k],w);
            }
            else{//覆盖
                int u,v,w;
                cin>>u>>v>>w;
                update_cov(u,v,w);
            }
        }
    }
    return 0;
}