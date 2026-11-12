#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int n,m,r,p;
//树剖 在1~MAXN的范围把点重新排序
int timer;//重新排序
int num[MAXN],head[MAXN];
int fa[MAXN],dep[MAXN],siz[MAXN];
//记录父节点 深度(辈分) 大小->判断哪个是重链(后辈最多)
int son[MAXN],dfn[MAXN],rnk[MAXN],top[MAXN];
//记录重链在哪个儿子那里 遍历顺序 新数组排序 
//线段树的 x y 都是序号而不是内容 因为内容都在tree里面包含了
int tree[4*MAXN],lazy[4*MAXN];
//dfn不是是新的排好序的num
//而是下标存num的序号 内容才是在树里的新序号
struct Node{
    int fro,to,nxt;
}edge[2*MAXN];
void dfs1(int u,int f){//重链剖分
    fa[u]=f;//确保重链在左边
    dep[u]=dep[f]+1;
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(v==f) continue;
        dfs1(v,u);
        siz[u]+=siz[v];
        if(siz[v]>siz[son[u]]) son[u]=v;
        //如果v和子树比原有的值大 v就成为重链
    }
    return;
}
void dfs2(int u,int t){//原数组节点 最顶端(要从链底下跳到顶端)
    dfn[u]=++timer;//时间戳
    rnk[timer]=num[u];//重新分配序号
    //线段树需要的底层数组必须是:下标为顺序序号 内容为值
    //rnk用于建树
    //但是我们其实可以通过num序号直接索引到dfn的下标 进而找到内容
    top[u]=t;
    if(son[u]!=0)
        dfs2(son[u],t);//先走重儿子
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(v==son[u]) continue;
        if(v==fa[u]) continue;
        dfs2(v,v);//轻链要成为新链
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
    tree[u]=(tree[2*u]+tree[2*u+1])%p;
    return;
}
void pushdown(int u,int l,int r){//pushdown改儿子
    int k=lazy[u];
    lazy[2*u]+=k,lazy[2*u+1]+=k;
    int mid=(l+r)/2;
    tree[2*u]+=(mid-l+1)*k;
    tree[2*u+1]+=(r-mid)*k;
    lazy[u]=0;
    return;
}
void update_sum(int u,int l,int r,int x,int y,int k){
    if(x<=l&&r<=y){
        lazy[u]+=k;
        tree[u]+=(r-l+1)*k;
        return;
    }
    pushdown(u,l,r);
    int mid=(l+r)/2;
    if(x<=mid) update_sum(2*u,l,mid,x,y,k);
    if(y>mid) update_sum(2*u+1,mid+1,r,x,y,k);
    tree[u]=(tree[2*u]+tree[2*u+1])%p;
    return;
}
int query_sum(int u,int l,int r,int x,int y){
    int sum=0;
    if(x<=l&&r<=y)
        return tree[u];
    pushdown(u,l,r);
    int mid=(l+r)/2;
    if(x<=mid) sum=(sum+query_sum(2*u,l,mid,x,y))%p;
    if(y>mid) sum=(sum+query_sum(2*u+1,mid+1,r,x,y))%p;
    return sum%p;
}
void update_po(int x,int y,int k){//顺便把值打包了
    while(top[x]!=top[y]){//深的在前
        if(dep[top[x]]<dep[top[y]])//永远保证x跳
            swap(x,y);//top[u]=t 所以要转一次
        update_sum(1,1,n,dfn[top[x]],dfn[x],k);//只在链上修改
        x=fa[top[x]];//放在swap后影响
    }
    if(dep[x]>dep[y]) swap(x,y);//最后肯定在一条链上
    update_sum(1,1,n,dfn[x],dfn[y],k);
    return;
}
int query_path(int x,int y){
    int sum=0;
    while(top[x]!=top[y]){//深的在前
        if(dep[top[x]]<dep[top[y]])//永远保证x跳
            swap(x,y);//top[u]=t 所以要转一次
        sum=(sum+query_sum(1,1,n,dfn[top[x]],dfn[x]))%p;//只在链上修改
        x=fa[top[x]];//放在swap后影响
    }
    if(dep[x]>dep[y]) swap(x,y);//最后肯定在一条链上
    sum=(sum+query_sum(1,1,n,dfn[x],dfn[y]))%p;
    return sum%p;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>r>>p;
    for(int i=1;i<=n;i++) siz[i]=1;
    for(int i=1;i<=n;i++) cin>>num[i];
    int cnt=1;
    for(int i=1;i<=n-1;i++){
        int x,y;
        cin>>x>>y;
        edge[cnt].fro=x,edge[cnt].to=y;
        edge[cnt].nxt=head[x];
        head[x]=cnt;
        cnt++;
        edge[cnt].fro=y,edge[cnt].to=x;
        edge[cnt].nxt=head[y];
        head[y]=cnt;
        cnt++;
    }
    dfs1(r,0);
    dfs2(r,r);
    build(1,1,n);
    for(int i=1;i<=m;i++){
        int op;
        cin>>op;
        if(op==1){//最短路径上节点+z
            int x,y,z;
            cin>>x>>y>>z;
            update_po(x,y,z);//新链的开头结尾
        }
        else if(op==2){//最短路径上节点之和
            int x,y;
            cin>>x>>y;
            cout<<query_path(x,y)%p<<'\n';
        }
        else if(op==3){//以x为根的子树内所有节点+z
            int x,z;//左端是dfn[u]
            cin>>x>>z;//右端是dfn[u]+siz[u]-1
            update_sum(1,1,n,dfn[x],dfn[x]+siz[x]-1,z);
        }
        else{//以x为根的子树内所有节点的和
            int x;
            cin>>x;
            cout<<query_sum(1,1,n,dfn[x],dfn[x]+siz[x]-1)%p<<'\n';
        }
    }
    return 0;
}