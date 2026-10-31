#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int n,m;
long long tree[4*MAXN],lazy[4*MAXN];
void pushdown(int u,int l,int r){
    if(lazy[u]==0) return;
    lazy[2*u]^=lazy[u];
    lazy[2*u+1]^=lazy[u];
    int mid=(l+r)/2;
    tree[2*u]=mid-l+1-tree[2*u];
    tree[2*u+1]=r-mid-tree[2*u+1];
    lazy[u]=0;
    return;
}
void update(int u,int l,int r,int x,int y){
    if(x<=l&&r<=y){
        lazy[u]^=1;
        tree[u]=r-l+1-tree[u];
        return;
    }
    pushdown(u,l,r);
    int mid=(l+r)/2;
    if(x<=mid) update(2*u,l,mid,x,y);
    if(y>mid) update(2*u+1,mid+1,r,x,y);
    tree[u]=tree[2*u]+tree[2*u+1];
    return;
}
long long query(int u,int l,int r,int x,int y){
    long long sum=0;
    if(x<=l&&r<=y){
        return tree[u];
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
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int op;
        cin>>op;
        if(op==0){//开关
            int l,r;
            cin>>l>>r;
            update(1,1,n,l,r);
        }
        else{
            int l,r,x;
            cin>>l>>r;
            cout<<query(1,1,n,l,r)<<'\n';
        }
    }
    return 0;
}