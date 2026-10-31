#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
long long ori[MAXN],num[MAXN],lazy[4*MAXN],tree[4*MAXN];
int n,m;
void build(int u,int l,int r){
    if(l==r){
        tree[u]=num[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*u,l,mid);
    build(2*u+1,mid+1,r);
    tree[u]=tree[2*u]+tree[2*u+1];
    return;
}
void pushdown(int u,int l,int r){
    if(lazy[u]==0) return;
    int mid=(l+r)/2;
    lazy[2*u]+=lazy[u],lazy[2*u+1]+=lazy[u];
    tree[2*u]+=lazy[u]*(mid-l+1);
    tree[2*u+1]+=lazy[u]*(r-mid);
    lazy[u]=0;
    return;
}
void update(int u,int l,int r,int x,int y,long long v){
    if(x<=l&&r<=y){
        tree[u]+=v*(r-l+1);
        lazy[u]+=v;
        return;
    }
    pushdown(u,l,r);
    int mid=(l+r)/2;
    if(x<=mid) update(2*u,l,mid,x,y,v);
    if(y>mid) update(2*u+1,mid+1,r,x,y,v);
    tree[u]=tree[2*u]+tree[2*u+1];
    return;
}
long long query(int u,int l,int r,int x,int y){
    if(x<=l&&r<=y)
        return tree[u];
    pushdown(u,l,r);
    int mid=(l+r)/2;
    long long sum=0;
    if(x<=mid) sum+=query(2*u,l,mid,x,y);
    if(y>mid) sum+=query(2*u+1,mid+1,r,x,y);
    return sum;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>ori[i];
    for(int i=1;i<=n;i++) num[i]=ori[i]-ori[i-1];
    build(1,1,n);
    for(int i=1;i<=m;i++){
        int opt;
        cin>>opt;
        if(opt==1){
            int l,r,k,d;
            cin>>l>>r>>k>>d;
            update(1,1,n,l,l,k);
            if(l+1<=r) update(1,1,n,l+1,r,d);
            if(r+1<=n) update(1,1,n,r+1,r+1,-(1LL*k+(r-l)*d));
        }
        else{
            int p;
            cin>>p;
            cout<<query(1,1,n,1,p)<<'\n';
        }
    }
    return 0;
}