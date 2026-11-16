#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int n,q;
int timer;
int head[MAXN];
int siz[MAXN],son[MAXN],fa[MAXN],dep[MAXN];
int dfn[MAXN],rnk[MAXN],top[MAXN];
int tree[4*MAXN];//
struct Node{
    int fro,to,nxt;
}edge[2*MAXN];
void dfs1(int u,int f){
    siz[u]=1;
    dep[u]=dep[f]+1;
    fa[u]=f;
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
    rnk[timer]=u;//方便修改后找原点
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
void update(int u,int l,int r,int k){//传进来的就是时间戳
    if(l==r){
        tree[u]=k;
        return;
    }
    int mid=(l+r)/2;
    if(k<=mid) update(2*u,l,mid,k);
    else update(2*u+1,mid+1,r,k);
    tree[u]=max(tree[2*u],tree[2*u+1]);//一条链上看 max必定更深 靠近节点
    return;
}
int query_pa(int u,int l,int r,int x,int y){
    int ans=-1e9;
    if(x<=l&&r<=y) 
        return tree[u];
    int mid=(l+r)/2;
    if(x<=mid) ans=max(ans,query_pa(2*u,l,mid,x,y));
    if(y>mid) ans=max(ans,query_pa(2*u+1,mid+1,r,x,y));
    return ans;
}
int query(int x,int y){
    int ans=-1e9;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        ans=max(ans,query_pa(1,1,n,dfn[top[x]],dfn[x]));
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    ans=max(ans,query_pa(1,1,n,dfn[x],dfn[y]));
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
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
    dfs2(1,1);
    update(1,1,n,dfn[1]);
    for(int i=1;i<=q;i++){
        char op;
        cin>>op;
        if(op=='Q'){//查询
            int x;
            cin>>x;
            int tim=query(1,x);
            cout<<rnk[tim]<<'\n';
        }
        else{
            int x;
            cin>>x;
            update(1,1,n,dfn[x]);
        }
    }
    return 0;
}