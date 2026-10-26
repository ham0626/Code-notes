#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int n,m;
long long num[MAXN],tree[4*MAXN];
long long lazy[4*MAXN];
void build(int u,int l,int r){
    if(l==r){
        tree[u]=num[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*u,l,mid);
    build(2*u+1,mid+1,r);
    return;
}
void pushdown(int u,int l,int r){
    if(lazy[u]==0) return;
    tree[2*u]+=lazy[u];
    tree[2*u+1]+=lazy[u];
    lazy[2*u]+=lazy[u];
    lazy[2*u+1]+=lazy[u];
    lazy[u]=0;//擦除
    return;
}
void update(int u,int l,int r,int x,int y,int k){
    if(x<=l&&r<=y){
        tree[u]+=k;
        lazy[u]+=k;
        return;
    }
    pushdown(u,l,r);
    int mid=(l+r)/2;
    if(x<=mid) update(2*u,l,mid,x,y,k);
    if(y>mid) update(2*u+1,mid+1,r,x,y,k);
    return;
}
long long query(int u,int l,int r,int x){
    if(l==r){
        return tree[u];
    }
    pushdown(u,l,r);
    int mid=(l+r)/2;
    if(x<=mid) return query(2*u,l,mid,x);
    else return query(2*u+1,mid+1,r,x);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>num[i];
    build(1,1,n);
    while(m--){
        int op;
        cin>>op;
        if(op==1){//区间内每个数+k
            int x,y,k;
            cin>>x>>y>>k;
            update(1,1,n,x,y,k);
        }
        else{
            int x;
            cin>>x;
            cout<<query(1,1,n,x)<<'\n';
        }
    }
    return 0;
}