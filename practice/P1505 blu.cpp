#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int n,m;
int timer;
struct Node{
    int fro,to,nxt,idx,val;
}edge[MAXN*2];
struct NODE{
    int summ,maxx,minn;
}tree[4*MAXN];
int head[2*MAXN];
int siz[MAXN],son[MAXN],dep[MAXN],fa[MAXN];
int dfn[MAXN],top[MAXN],rnk[MAXN],id[2*MAXN],val[MAXN];
int lazy[4*MAXN];//取相反数
//和 最大 最小
void dfs1(int u,int f){
    siz[u]=1;
    fa[u]=f;
    dep[u]=dep[f]+1;
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(v==f) continue;
        id[edge[i].idx]=v;
        val[v]=edge[i].val;
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
        if(v==son[u]) continue;
        if(v==fa[u]) continue;
        val[v]=edge[i].val;
        dfs2(v,v);
    }
    return;
}
void build(int u,int l,int r){
    if(l==r){
        tree[u].maxx=rnk[l];
        tree[u].minn=rnk[l];
        tree[u].summ=rnk[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*u,l,mid);
    build(2*u+1,mid+1,r);
    tree[u].summ=tree[2*u].summ+tree[2*u+1].summ;
    tree[u].maxx=max(tree[2*u].maxx,tree[2*u+1].maxx);
    tree[u].minn=min(tree[2*u].minn,tree[2*u+1].minn);
    return;
}
void pushdown(int u,int l,int r){
    int k=lazy[u];
    if(k==0) return;
    lazy[2*u]^=1,lazy[2*u+1]^=1;
    int minm=tree[2*u].minn;
    int maxm=tree[2*u].maxx;
    tree[2*u].maxx=-minm;
    tree[2*u].minn=-maxm;
    tree[2*u].summ=-tree[2*u].summ;
    minm=tree[2*u+1].minn;
    maxm=tree[2*u+1].maxx;
    tree[2*u+1].maxx=-minm;
    tree[2*u+1].minn=-maxm;
    tree[2*u+1].summ=-tree[2*u+1].summ;
    lazy[u]=0;
    return;
}
NODE query_con(NODE x,NODE y){
    NODE ans;
    ans.summ=x.summ+y.summ;
    ans.maxx=max(x.maxx,y.maxx);
    ans.minn=min(x.minn,y.minn);
    return ans;
}
NODE query(int u,int l,int r,int x,int y){
    if(x<=l&&r<=y)
        return tree[u];
    pushdown(u,l,r);
    int mid=(l+r)/2;
    if(y<=mid) return query(2*u,l,mid,x,y);
    if(x>mid) return query(2*u+1,mid+1,r,x,y);
    NODE L=query(2*u,l,mid,x,y);
    NODE R=query(2*u+1,mid+1,r,x,y);
    return query_con(L,R);
}
void update_pa(int u,int l,int r,int x,int k){
    if(l==r){
        tree[u].summ=k;
        tree[u].maxx=k;
        tree[u].minn=k;
        return;
    }
    pushdown(u,l,r);
    int mid=(l+r)/2;
    if(x<=mid) update_pa(2*u,l,mid,x,k);
    else update_pa(2*u+1,mid+1,r,x,k);
    tree[u].summ=tree[2*u].summ+tree[2*u+1].summ;
    tree[u].maxx=max(tree[2*u].maxx,tree[2*u+1].maxx);
    tree[u].minn=min(tree[2*u].minn,tree[2*u+1].minn);
    return;
}
void update_op(int u,int l,int r,int x,int y){
    if(x<=l&&r<=y){
        lazy[u]^=1;
        tree[u].summ=-tree[u].summ;
        int minm=tree[u].minn;
        int maxm=tree[u].maxx;
        tree[u].maxx=-minm;
        tree[u].minn=-maxm;
        return;
    }
    pushdown(u,l,r);
    int mid=(l+r)/2;
    if(x<=mid) update_op(2*u,l,mid,x,y);
    if(y>mid) update_op(2*u+1,mid+1,r,x,y);
    tree[u].summ=tree[2*u].summ+tree[2*u+1].summ;
    tree[u].maxx=max(tree[2*u].maxx,tree[2*u+1].maxx);
    tree[u].minn=min(tree[2*u].minn,tree[2*u+1].minn);
    return;
}
void update_op0(int x,int y){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        update_op(1,1,n,dfn[top[x]],dfn[x]);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    if(x!=y) update_op(1,1,n,dfn[x]+1,dfn[y]);//把x到x父亲的避开
    return;
}
long long query_sum(int x,int y){
    long long sum=0;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        NODE tmp=query(1,1,n,dfn[top[x]],dfn[x]);
        sum+=tmp.summ;
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    if(x!=y){
        NODE tmp=query(1,1,n,dfn[x]+1,dfn[y]);
        sum+=tmp.summ;
    }
    return sum;
}
int query_max(int x,int y){
    int maxm=-1e9;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        NODE tmp=query(1,1,n,dfn[top[x]],dfn[x]);
        maxm=max(maxm,tmp.maxx);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    if(x!=y){
        NODE tmp=query(1,1,n,dfn[x]+1,dfn[y]);
        maxm=max(maxm,tmp.maxx);
    }
    return maxm;
}
int query_min(int x,int y){
    int minm=1e9;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        NODE tmp=query(1,1,n,dfn[top[x]],dfn[x]);
        minm=min(minm,tmp.minn);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    if(x!=y){
        NODE tmp=query(1,1,n,dfn[x]+1,dfn[y]);
        minm=min(minm,tmp.minn);
    }
    return minm;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    int cnt=1;
    for(int i=1;i<=n-1;i++){
        int u,v,w;
        cin>>u>>v>>w;
        u++,v++;
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
    build(1,1,n);
    cin>>m;
    for(int i=1;i<=m;i++){
        string op;
        cin>>op;
        int u,v;
        cin>>u>>v;
        if(op[0]=='C'){//改边权
            int to=id[u];
            update_pa(1,1,n,dfn[to],v);
        }
        else if(op[0]=='N'){//路径上边权取相反数
            u++,v++;
            update_op0(u,v);
        }
        else if(op[0]=='S'){//路径上边权和
            u++,v++;
            cout<<query_sum(u,v)<<'\n';
        }
        else{
            if(op[1]=='A'){//路径上最大值
                u++,v++;
                cout<<query_max(u,v)<<'\n';
            }
            else{//路径上最小值
                u++,v++;
                cout<<query_min(u,v)<<'\n';
            }
        }
    }
    return 0;
}