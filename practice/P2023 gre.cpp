#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int n,p,m;
long long num[MAXN],tree[4*MAXN];
long long lazy_add[4*MAXN],lazy_mul[4*MAXN];
void build(int u,int l,int r){
    if(l==r){
        tree[u]=num[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*u,l,mid);
    build(2*u+1,mid+1,r);//*
    tree[u]=(tree[2*u]+tree[2*u+1])%p;
    return;
}
void pushdown(int u,int l,int r){//pushdown改儿子
    long long k=lazy_add[u],j=lazy_mul[u];//pushdown需要改tree
    if(k==0&&j==1) return;//开long long
    int mid=(l+r)/2;
    tree[2*u]=(j*tree[2*u]%p+k*(mid-l+1)%p)%p;
    tree[2*u+1]=(j*tree[2*u+1]%p+k*(r-mid)%p)%p;
    lazy_add[2*u]=(lazy_add[2*u]*j%p+k)%p;//*先乘j后加
    lazy_add[2*u+1]=(lazy_add[2*u+1]*j%p+k)%p;
    lazy_mul[2*u]=lazy_mul[2*u]*j%p;//*取模防爆
    lazy_mul[2*u+1]=lazy_mul[2*u+1]*j%p;
    lazy_add[u]=0,lazy_mul[u]=1;
    return;
}
void add_update(int u,int l,int r,int x,int y,int k){
    if(x<=l&&r<=y){//update改自己
        tree[u]=tree[u]%p+k*(r-l+1)%p;
        lazy_add[u]+=k;//传下去
        return;
    }
    pushdown(u,l,r);
    int mid=(l+r)/2;
    if(x<=mid) add_update(2*u,l,mid,x,y,k);
    if(y>mid) add_update(2*u+1,mid+1,r,x,y,k);
    tree[u]=(tree[2*u]+tree[2*u+1])%p;
    return;
}
void mul_update(int u,int l,int r,int x,int y,int k){
    if(x<=l&&r<=y){//update改自己
        tree[u]=k*tree[u]%p;
        lazy_mul[u]=lazy_mul[u]*k%p;//传下去
        lazy_add[u]=lazy_add[u]*k%p;//*加法也要传 防爆
        return; 
    }
    pushdown(u,l,r);
    int mid=(l+r)/2;
    if(x<=mid) mul_update(2*u,l,mid,x,y,k);
    if(y>mid) mul_update(2*u+1,mid+1,r,x,y,k);
    tree[u]=(tree[2*u]+tree[2*u+1])%p;
    return;
}
long long query(int u,int l,int r,int x,int y){
    // cout<<u<<" "<<l<<" "<<r<<'\n';
    long long sum=0;
    if(x<=l&&r<=y)
        return tree[u];
    pushdown(u,l,r);
    int mid=(l+r)/2;
    if(x<=mid) sum=(sum+query(2*u,l,mid,x,y))%p;
    if(y>mid) sum=(sum+query(2*u+1,mid+1,r,x,y))%p;
    return sum%p;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>p;
    for(int i=1;i<=n;i++) cin>>num[i],num[i]=num[i]%p;
    for(int i=1;i<=4*n;i++) lazy_mul[i]=1;//初始化
    build(1,1,n);
    // for(int i=1;i<=15;i++) cout<<tree[i]<<'\n';
    cin>>m;
    while(m--){
        int op;
        cin>>op;
        if(op==1){//区间内每个数同乘一个值
            int t,g,c;
            cin>>t>>g>>c;
            mul_update(1,1,n,t,g,c);
        }
        else if(op==2){//区间内每个数加上一个值
            int t,g,c;
            cin>>t>>g>>c;
            add_update(1,1,n,t,g,c);
        }
        else{//查询区间和,输出%p
            int t,g;
            cin>>t>>g;
            cout<<query(1,1,n,t,g)%p<<'\n';
        }
    }
    return 0;
}