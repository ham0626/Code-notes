#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int n,m;
long long num[MAXN],tree[4*MAXN][20],lazy[4*MAXN];//异或是对二进制
void build(int u,int l,int r){//子树数位是1的格式
    if(l==r){
        for(int i=0;i<20;i++){
            if((num[l]>>i)&1) tree[u][i]=1;
            else tree[u][i]=0;
        }
        return;
    }
    int mid=(l+r)/2;
    build(2*u,l,mid);
    build(2*u+1,mid+1,r);
    for(int i=0;i<20;i++)
        tree[u][i]=tree[2*u][i]+tree[2*u+1][i];
    return;
}
void pushdown(int u,int l,int r){
    if(lazy[u]==0) return;
    lazy[2*u]^=lazy[u];
    lazy[2*u+1]^=lazy[u];
    int mid=(l+r)/2;
    for(int i=0;i<20;i++){//可以和某一个具体的数异或
        if((lazy[u]>>i)&1){
            tree[2*u][i]=mid-l+1-tree[2*u][i];
            tree[2*u+1][i]=r-mid-tree[2*u+1][i];
        }
    }
    lazy[u]=0;
    return;
}
void update(int u,int l,int r,int x,int y,int k){
    if(x<=l&&r<=y){
        lazy[u]^=k;
        for(int i=0;i<20;i++){
            if((k>>i)&1)
            tree[u][i]=r-l+1-tree[u][i];
        }
        return;
    }
    pushdown(u,l,r);
    int mid=(l+r)/2;
    if(x<=mid) update(2*u,l,mid,x,y,k);
    if(y>mid) update(2*u+1,mid+1,r,x,y,k);
    for(int i=0;i<20;i++)
        tree[u][i]=tree[2*u][i]+tree[2*u+1][i];
    return;
}
long long query(int u,int l,int r,int x,int y){
    long long sum=0;
    if(x<=l&&r<=y){
        for(int i=0;i<20;i++)
            sum+=tree[u][i]*(1<<i);
        return sum;
    }
    pushdown(u,l,r);
    int mid=(l+r)/2;
    if(x<=mid) sum+=query(2*u,l,mid,x,y);
    if(y>mid) sum+=query(2*u+1,mid+1,r,x,y);
    return sum;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>num[i];
    build(1,1,n);
    cin>>m;
    for(int i=1;i<=m;i++){
        int op;
        cin>>op;
        if(op==1){
            int l,r;
            cin>>l>>r;
            cout<<query(1,1,n,l,r)<<'\n';
        }
        else{
            int l,r,x;
            cin>>l>>r>>x;
            update(1,1,n,l,r,x);
        }
    }
    return 0;
}