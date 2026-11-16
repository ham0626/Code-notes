#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int n,m;
int timer;
struct Node{
    int fro,to,nxt;
}edge[MAXN*2];
struct NODE{
    int lc,rc,sum;
}tree[4*MAXN];
int head[2*MAXN];
int siz[MAXN],son[MAXN],dep[MAXN],fa[MAXN],num[MAXN];
int dfn[MAXN],top[MAXN],rnk[MAXN];
int lazy[4*MAXN];//取相反数
//和 最大 最小
void dfs1(int u,int f){
    siz[u]=1;
    fa[u]=f;
    dep[u]=dep[f]+1;
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
    rnk[timer]=num[u];
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
        tree[u].lc=rnk[l];
        tree[u].rc=rnk[l];
        tree[u].sum=1;
        return;
    }
    int mid=(l+r)/2;
    build(2*u,l,mid);
    build(2*u+1,mid+1,r);
    tree[u].lc=tree[2*u].lc;
    tree[u].rc=tree[2*u+1].rc;
    if(tree[2*u].rc==tree[2*u+1].lc)
        tree[u].sum=tree[2*u].sum+tree[2*u+1].sum-1;
    else tree[u].sum=tree[2*u].sum+tree[2*u+1].sum;
    return;
}
void pushdown(int u,int l,int r){
    int k=lazy[u];
    if(k==0) return;
    lazy[2*u]=k,lazy[2*u+1]=k;
    tree[2*u].lc=k;
    tree[2*u].rc=k;
    tree[2*u].sum=1;
    tree[2*u+1].lc=k;
    tree[2*u+1].rc=k;
    tree[2*u+1].sum=1;
    lazy[u]=0;
    return;
}
NODE query_con(NODE x,NODE y){
    NODE ans;
    ans.lc=x.lc;
    ans.rc=y.rc;
    if(x.rc==y.lc)
        ans.sum=x.sum+y.sum-1;
    else ans.sum=x.sum+y.sum;
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
void update_pa(int u,int l,int r,int x,int y,int k){
    if(x<=l&&r<=y){
        tree[u].lc=k;
        tree[u].rc=k;
        tree[u].sum=1;
        lazy[u]=k;
        return;
    }
    pushdown(u,l,r);
    int mid=(l+r)/2;
    if(x<=mid) update_pa(2*u,l,mid,x,y,k);
    if(y>mid) update_pa(2*u+1,mid+1,r,x,y,k);
    tree[u].lc=tree[2*u].lc;
    tree[u].rc=tree[2*u+1].rc;
    if(tree[2*u].rc==tree[2*u+1].lc)
        tree[u].sum=tree[2*u].sum+tree[2*u+1].sum-1;
    else tree[u].sum=tree[2*u].sum+tree[2*u+1].sum;
    return;
}
void update(int x,int y,int k){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        update_pa(1,1,n,dfn[top[x]],dfn[x],k);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    update_pa(1,1,n,dfn[x],dfn[y],k);
    return;
}
NODE query_sum(int x,int y){
    NODE ansx={0,0,0};//左边的一条长链
    NODE ansy={0,0,0};//右边的一条长链
    //x--ansx--LCA--ansy--y
    //深--------浅--------深
    //       x--top[x]
    //原本是rc--lc  所以需要翻转成lc--rc
    //       top[y]--y
    //原本是lc--rc  不需要翻转
    //lc-----------------rc
    //浅------------------深
    while(top[x]!=top[y]){
        if(dep[top[x]]>dep[top[y]]){//x深
            NODE tmp=query(1,1,n,dfn[top[x]],dfn[x]);
            swap(tmp.lc,tmp.rc);//top数小 是原本的lc
            //但是要继续拼小的 往左拼
            if(ansx.sum==0) ansx=tmp;//放在右边 开始延申
            else ansx=query_con(ansx,tmp);
            x=fa[top[x]];
        }
        else{//y深
            NODE tmp=query(1,1,n,dfn[top[y]],dfn[y]);
            if(ansy.sum==0) ansy=tmp;//放在左边
            else ansy=query_con(tmp,ansy);
            y=fa[top[y]];
        }
    }
    if(dep[x]<dep[y]){//x浅//特判空节点
        NODE tmp=query(1,1,n,dfn[x],dfn[y]);
        if(ansx.sum==0) ansx=tmp;
        else ansx=query_con(ansx,tmp);
        if(ansy.sum==0) return ansx;//不需要合并
        return query_con(ansx,ansy);
    }
    else{
        NODE tmp=query(1,1,n,dfn[y],dfn[x]);
        swap(tmp.lc,tmp.rc);
        if(ansx.sum==0) ansx=tmp;
        else ansx=query_con(ansx,tmp);
        if(ansy.sum==0) return ansx;
        else return query_con(ansx,ansy);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>num[i];
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
    build(1,1,n);
    for(int i=1;i<=m;i++){
        char op;
        cin>>op;
        if(op=='C'){//染色
            int a,b,c;
            cin>>a>>b>>c;
            update(a,b,c);
        }
        else{
            int a,b;
            cin>>a>>b;
            NODE res=query_sum(a,b);
            cout<<res.sum<<'\n';
        }
    }
    return 0;
}