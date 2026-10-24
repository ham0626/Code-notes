#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int n,q,m;
long long num[MAXN],tree[4*MAXN];
long long lazy_add[4*MAXN],lazy_mul[4*MAXN];
void build(int u,int l,int r){
    if(l==r){
        tree[u]=num[l];//*
        return;
    }
    int mid=(l+r)/2;
    build(2*u,l,mid);
    build(2*u+1,mid+1,r);
    tree[u]=tree[2*u]+tree[2*u+1];
    return;
}
void pushdown(int u,int l,int r){//pushdown动儿子 update动自己
    if(lazy_add[u]==0&&lazy_mul[u]==1) return;
    long long k=lazy_add[u],p=lazy_mul[u];
    int mid=(l+r)/2;
    tree[2*u]=((tree[2*u]*p)%m+k*(mid-l+1)%m)%m;//防爆
    tree[2*u+1]=((tree[2*u+1]*p)%m+k*(r-mid)%m)%m;
    lazy_mul[2*u]=(lazy_mul[2*u]*p)%m;//记得乘
    lazy_mul[2*u+1]=(lazy_mul[2*u+1]*p)%m;
    lazy_add[2*u]=(lazy_add[2*u]*p+k)%m;//已经欠的+新欠的
    lazy_add[2*u+1]=(lazy_add[2*u+1]*p+k)%m;
    lazy_mul[u]=1,lazy_add[u]=0;
    //正在向下传 还没传完不能tree[u]=tree[2*u]+tree[2*u+1];
}
void update_add(int u,int l,int r,int x,int y,int k){
    if(x<=l&&r<=y){
        tree[u]=(tree[u]+k*(r-l+1)%m)%m;//*
        lazy_add[u]+=k;
        return;
    }
    pushdown(u,l,r);
    int mid=(l+r)/2;
    if(x<=mid) update_add(2*u,l,mid,x,y,k);
    if(y>mid) update_add(2*u+1,mid+1,r,x,y,k);
    tree[u]=tree[2*u]+tree[2*u+1];
    return;
}
void update_mul(int u,int l,int r,int x,int y,int k){
    // cout<<u<<" "<<l<<" "<<r<<'\n';
    if(x<=l&&r<=y){
        tree[u]=(tree[u]*k)%m;//不能动儿子
        lazy_mul[u]=(lazy_mul[u]*k)%m;//及时%m
        lazy_add[u]=(lazy_add[u]*k)%m;//*
        return;
    }
    pushdown(u,l,r);
    int mid=(l+r)/2;
    if(x<=mid) update_mul(2*u,l,mid,x,y,k);
    if(y>mid) update_mul(2*u+1,mid+1,r,x,y,k);
    tree[u]=tree[2*u]+tree[2*u+1];
    return;
}
long long query(int u,int l,int r,int x,int y){
    // cout<<u<<" "<<l<<" "<<r<<'\n';
    if(x<=l&&r<=y)
        return tree[u];
    pushdown(u,l,r);
    long long sum=0;
    int mid=(l+r)/2;
    if(x<=mid) sum=(sum+query(2*u,l,mid,x,y))%m;
    if(y>mid) sum=(sum+query(2*u+1,mid+1,r,x,y))%m;
    return sum%m;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>q>>m;
    for(int i=1;i<=n;i++) cin>>num[i],num[i]=num[i]%m;
    for(int i=1;i<=4*n;i++) lazy_mul[i]=1;
    build(1,1,n);
    for(int i=1;i<=q;i++){
        int op;
        cin>>op;
        if(op==1){//乘
            int x,y,k;
            cin>>x>>y>>k;
            update_mul(1,1,n,x,y,k);
        }
        else if(op==2){//加
            int x,y,k;
            cin>>x>>y>>k;
            update_add(1,1,n,x,y,k);
        }
        else{//query取模
            int x,y;
            cin>>x>>y;
            cout<<query(1,1,n,x,y)%m<<'\n';
        }
    }
    return 0;
}