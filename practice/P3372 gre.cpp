#include<bits/stdc++.h>
long long num[100005],tree[400005],lazy[400005];
using namespace std;
int n,m;
void build(int u,int l,int r){//建树(父节点,左边界,右边界)
    if(l==r){//到叶子节点了
        tree[u]=num[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*u,l,mid);//左子树
    build(2*u+1,mid+1,r);//右子树
    tree[u]=tree[2*u]+tree[2*u+1];
}
// void po_update(int u,int l,int r,int x,int k){//单点修改(父节点,左边界,右边界,原下标,改后的值/要加的数)
//     if(l==r){//找到了
//         tree[u]+=k;
//         return;
//     }
//     else{
//         int mid=(l+r)/2;
//         if(x<=mid) po_update(2*u,l,mid,x,k);
//         else po_update(2*u+1,mid+1,r,x,k);
//     }
//     tree[u]=tree[2*u]+tree[2*u+1];
//     return;
// }
void pushdown(int u,int l,int r){//下传懒标记
    if(lazy[u]==0) return;//发完了
    int mid=(l+r)/2;
    int lc=2*u,rc=2*u+1;
    long long k=lazy[u];
    tree[lc]+=k*(mid-l+1),lazy[lc]+=k;//给左儿子传标记
    tree[rc]+=k*(r-mid),lazy[rc]+=k;//给右儿子传标记
    lazy[u]=0;//不欠了
}
void ra_update(int u,int l,int r,int x,int y,long long k){//单点修改(父节点,左边界,右边界,原下标,改后的值/要加的数)
    if(x<=l&&r<=y){//找到了
        lazy[u]+=k;
        tree[u]+=k*(r-l+1);
        return;
    }
    pushdown(u,l,r);
    int mid=(l+r)/2;
    if(x<=mid) ra_update(2*u,l,mid,x,y,k);
    if(y>mid) ra_update(2*u+1,mid+1,r,x,y,k);
    tree[u]=tree[2*u]+tree[2*u+1];
    return;
}
long long int query(int u,int l,int r,int x,int y){//区间和查询(父节点,左边界,右边界,原下标)
    if(x<=l&&r<=y)//找到了(l,r是当前区间,在建树的时候定死了)
        return tree[u];
    pushdown(u,l,r);//走到这里要确保懒标记传下去了，如果lazy[u]=0会返回
    int mid=(l+r)/2;
    long long int sum=0;
    if(x<=mid) sum+=query(2*u,l,mid,x,y);//左子树需要查,一个二叉树一个二叉树的来
    if(y>mid) sum+=query(2*u+1,mid+1,r,x,y);//右子树需要查,一个二叉树一个二叉树的来
    return sum;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>num[i];
    build(1,1,n);
    for(int i=1;i<=m;i++){
        int op;
        cin>>op;
        if(op==1){
            long long x,y,k;//*
            cin>>x>>y>>k;
            ra_update(1,1,n,x,y,k);
        }
        else{
            int x,y;
            cin>>x>>y;
            cout<<query(1,1,n,x,y)<<'\n';
        }
    }
    return 0;
}