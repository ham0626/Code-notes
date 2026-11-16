#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int n;
int timer;
int head[MAXN];
int siz[MAXN],son[MAXN],rnk[MAXN],fa[MAXN],dep[MAXN];
int dfn[MAXN],top[MAXN],id[MAXN],val[MAXN];//下标是边 内容是去的那个节点
int tree[MAXN*4];//存u指向父亲的边权
struct Node{
    int fro,to,val,nxt,idx;
}edge[2*MAXN];
void dfs1(int u,int f){
    siz[u]=1;
    fa[u]=f;
    dep[u]=dep[f]+1;
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(v==f) continue;
        id[edge[i].idx]=v;//指向儿子
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
void update_pa(int u,int l,int r,int x,int k){
    if(l==r){
        tree[u]=k;
        return;
    }
    int mid=(l+r)/2;
    if(x<=mid) update_pa(2*u,l,mid,x,k);
    else update_pa(2*u+1,mid+1,r,x,k);
    tree[u]=max(tree[2*u],tree[2*u+1]);
    return;
}
int query(int u,int l,int r,int x,int y){
    int maxx=-1e9;
    if(x<=l&&r<=y)
        return tree[u];
    int mid=(l+r)/2;
    if(x<=mid) maxx=max(maxx,query(2*u,l,mid,x,y));
    if(y>mid) maxx=max(maxx,query(2*u+1,mid+1,r,x,y));
    return maxx;
}
int query_pa(int x,int y){
    int maxx=0;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        maxx=max(maxx,query(1,1,n,dfn[top[x]],dfn[x]));
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    if(x!=y)
    maxx=max(maxx,query(1,1,n,dfn[x]+1,dfn[y]));//把走到x的边算进去
    return maxx;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    int cnt=1;
    for(int i=1;i<=n-1;i++){
        int u,v,w;
        cin>>u>>v>>w;//不知道父子关系不能直接赋值id
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
    string op;
    while(cin>>op){
        if(op[0]=='D') break;
        else if(op[0]=='C'){//修改
            int x,t;
            cin>>x>>t;
            update_pa(1,1,n,dfn[id[x]],t);
        }
        else{//查询
            int a,b;
            cin>>a>>b;
            if(a==b) cout<<"0"<<'\n';
            else cout<<query_pa(a,b)<<'\n';
        }
    }
    return 0;
}