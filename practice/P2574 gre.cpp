#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int n,m;
char ch[MAXN];
int num[MAXN],lazy[4*MAXN];
struct Node{
    int sum,len;
}tree[4*MAXN];
void build(int u,int l,int r){
    tree[u].len=r-l+1;//*
    if(l==r){
        tree[u].sum=num[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*u,l,mid);
    build(2*u+1,mid+1,r);
    tree[u].sum=tree[2*u].sum+tree[2*u+1].sum;
    return;
}
void pushdown(int u,int l ,int r){
    if(lazy[u]==0) return;
    if(lazy[2*u]==0) lazy[2*u]=1;
    else lazy[2*u]=0;
    tree[2*u].sum=tree[2*u].len-tree[2*u].sum;
    if(lazy[2*u+1]==0) lazy[2*u+1]=1;
    else lazy[2*u+1]=0;
    tree[2*u+1].sum=tree[2*u+1].len-tree[2*u+1].sum;
    lazy[u]=0;//不欠了
    return;
}
void update(int u,int l,int r,int x,int y){
    if(x<=l&&r<=y){
        if(lazy[u]==1) lazy[u]=0;
        else lazy[u]=1;
        tree[u].sum=tree[u].len-tree[u].sum;
        return;
    }
    pushdown(u,l,r);
    int mid=(l+r)/2;
    if(x<=mid) update(2*u,l,mid,x,y);
    if(y>mid) update(2*u+1,mid+1,r,x,y);
    tree[u].sum=tree[2*u].sum+tree[2*u+1].sum;
    return;
}
int query(int u,int l,int r,int x,int y){
    int sum=0;
    if(x<=l&&r<=y)
        return tree[u].sum;
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
    cin>>ch;
    for(int i=0;i<n;i++) num[i+1]=ch[i]-'0';
    build(1,1,n);
    for(int i=1;i<=m;i++){
        int op,l,r;
        cin>>op>>l>>r;
        if(op==0)
            update(1,1,n,l,r);
        else cout<<query(1,1,n,l,r)<<'\n';
    }
    return 0;
}