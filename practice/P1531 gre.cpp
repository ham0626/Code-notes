#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int n,m;
int num[MAXN],tree[4*MAXN];
void build(int u,int l,int r){
    if(l==r){
        tree[u]=num[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*u,l,mid);
    build(2*u+1,mid+1,r);
    tree[u]=max(tree[2*u],tree[2*u+1]);
    return;
}
void update(int u,int l,int r,int x,int y){
    if(l==r){
        if(tree[u]<y) tree[u]=y;
        return;
    }
    int mid=(l+r)/2;
    if(x<=mid) update(2*u,l,mid,x,y);
    else update(2*u+1,mid+1,r,x,y);
    tree[u]=max(tree[2*u],tree[2*u+1]);
    return;
}
int query(int u,int l,int r,int x,int y){
    if(x<=l&&r<=y)
        return tree[u];
    int mid=(l+r)/2;
    int tmp=0;
    if(x<=mid) tmp=max(tmp,query(2*u,l,mid,x,y));
    if(y>mid) tmp=max(tmp,query(2*u+1,mid+1,r,x,y));
    return tmp;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>num[i];
    build(1,1,n);
    while(m--){
        char op;
        cin>>op;
        if(op=='Q'){
            int a,b;
            cin>>a>>b;
            cout<<query(1,1,n,a,b)<<'\n';
        }
        else{
            int a,b;
            cin>>a>>b;
            update(1,1,n,a,b);
        }
    }
    return 0;
}