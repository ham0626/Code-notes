#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int n,q;
int timer;
int head[MAXN];
int num[MAXN],dep[MAXN],son[MAXN],fa[MAXN],siz[MAXN];
int dfn[MAXN],rnk[MAXN],top[MAXN];
long long tree[4*MAXN],maxx[4*MAXN];
struct Node{
    int fro,to,nxt;
}edge[2*MAXN];
void build(int u,int l,int r){
    if(l==r){
        maxx[u]=rnk[l];
        tree[u]=rnk[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*u,l,mid);
    build(2*u+1,mid+1,r);
    maxx[u]=max(maxx[2*u],maxx[2*u+1]);
    tree[u]=tree[2*u]+tree[2*u+1];
    return;
}
void dfs1(int u,int f){//找重链
    siz[u]=1;
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
void update_po(int u,int l,int r,int x,int k){//单点修改
    if(l==r){
        tree[u]=k;
        maxx[u]=k;
        return;
    }
    int mid=(l+r)/2;
    if(x<=mid) update_po(2*u,l,mid,x,k);
    else update_po(2*u+1,mid+1,r,x,k);
    maxx[u]=max(maxx[2*u],maxx[2*u+1]);
    tree[u]=tree[2*u]+tree[2*u+1];
    return;
}
long long query_sum(int u,int l,int r,int x,int y){//查区间和
    long long  sum=0;
    if(x<=l&&r<=y)
        return tree[u];
    int mid=(l+r)/2;
    if(x<=mid) sum+=query_sum(2*u,l,mid,x,y);
    if(y>mid) sum+=query_sum(2*u+1,mid+1,r,x,y);
    return sum;
}
long long query_ma(int u,int l,int r,int x,int y){//查路径最大值
    long long maxn=-1e18;
    if(x<=l&&r<=y)
        return maxx[u];
    int mid=(l+r)/2;
    if(x<=mid) maxn=max(maxn,query_ma(2*u,l,mid,x,y));
    if(y>mid) maxn=max(maxn,query_ma(2*u+1,mid+1,r,x,y));
    return maxn;
}
long long query_maxx(int x,int y){//查路径最大值
    long long maxn=-1e18;
    while(top[x]!=top[y]){//读链
        if(dep[top[x]]<dep[top[y]]) swap(x,y);//深的往上
        maxn=max(maxn,query_ma(1,1,n,dfn[top[x]],dfn[x]));//只处理当前链的
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    maxn=max(maxn,query_ma(1,1,n,dfn[x],dfn[y]));
    return maxn;
}
long long query_path(int x,int y){//查路径和
    long long sum=0;
    while(top[x]!=top[y]){//读链
        if(dep[top[x]]<dep[top[y]]) swap(x,y);//深的往上
        sum+=query_sum(1,1,n,dfn[top[x]],dfn[x]);//只处理当前链的
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    sum+=query_sum(1,1,n,dfn[x],dfn[y]);
    return sum;
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
    for(int i=1;i<=n;i++) cin>>num[i];
    for(int i=1;i<=n;i++) fa[i]=i;
    dfs1(1,0);
    dfs2(1,1);//顶是自己
    build(1,1,n);
    cin>>q;
    for(int i=1;i<=q;i++){
        string op;
        cin>>op;
        if(op[1]=='H'){//单点修改
            int u,t;
            cin>>u>>t;
            update_po(1,1,n,dfn[u],t);
        }
        else if(op[1]=='M'){//路径上最大值
            int u,v;
            cin>>u>>v;
            cout<<query_maxx(u,v)<<'\n';
        }
        else{//路径上点权和
            int u,v;
            cin>>u>>v;
            cout<<query_path(u,v)<<'\n';
        }
    }
    return 0;
}
