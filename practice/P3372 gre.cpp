#include<bits/stdc++.h>
int num[500005],tree[2000005];
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
void update(int u,int l,int r,int x,int k){//单点修改(父节点,左边界,右边界,原下标,改后的值/要加的数)
    if(l==r){//找到了
        tree[u]+=k;
        return;
    }
    else{
        int mid=(l+r)/2;
        if(x<=mid) update(2*u,l,mid,x,k);
        else update(2*u+1,mid+1,r,x,k);
    }
    tree[u]=tree[2*u]+tree[2*u+1];
    return;
}
int query(int u,int l,int r,int x,int y){//单点查询(父节点,左边界,右边界,原下标)
    if(x<=l&&r<=y)//找到了(l,r是当前区间,在建树的时候定死了)
        return tree[u];
    int mid=(l+r)/2;
    long long sum=0;
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
        long long sum=0;
        int op,x,y;
        cin>>op>>x>>y;
        if(op==1)
            update(1,1,n,x,y);
        else
            cout<<query(1,1,n,x,y)<<'\n';
    }
    return 0;
}