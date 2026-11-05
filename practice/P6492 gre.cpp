#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int n,q;
struct Node{
    int lc,rc;//左边 右边是什么(0是l,1是r)
    int lmax,rmax,maxn;//从左
}tree[4*MAXN];
void pushup(int u,int l,int r){
    int tmp=0;
    tree[u].lc=tree[2*u].lc;
    tree[u].rc=tree[2*u+1].rc;//处理边界
    tree[u].maxn=max(tree[2*u].maxn,tree[2*u+1].maxn);
    if(tree[2*u].rc!=tree[2*u+1].lc){
        tmp=max({tree[2*u].lmax,tree[2*u].rmax+tree[2*u+1].lmax,tree[2*u+1].rmax});
        tree[u].maxn=max(tree[u].maxn,tmp);
    }//更新maxn
    int mid=(l+r)/2;
    if(mid-l+1==tree[2*u].lmax){
        if(tree[2*u].rc!=tree[2*u+1].lc)
        tree[u].lmax=tree[2*u+1].lmax+tree[2*u].lmax;
        else tree[u].lmax=tree[2*u].lmax;
    }
    else tree[u].lmax=tree[2*u].lmax;
    if(r-mid==tree[2*u+1].rmax){
        if(tree[2*u].rc!=tree[2*u+1].lc)
        tree[u].rmax=tree[2*u+1].rmax+tree[2*u].rmax;
        else tree[u].rmax=tree[2*u+1].rmax;
    }
    else tree[u].rmax=tree[2*u+1].rmax;
    return;
}
void build(int u,int l,int r){
    if(l==r){
        tree[u].lc=tree[u].rc=0;
        tree[u].rmax=1,tree[u].lmax=1;
        tree[u].maxn=1;
        return;
    }
    int mid=(l+r)/2;
    build(2*u,l,mid);
    build(2*u+1,mid+1,r);
    pushup(u,l,r);
    return;
}
void update(int u,int l,int r,int x){
    if(l==r){
        tree[u].lc^=1;
        tree[u].rc^=1;
        return;
    }
    int mid=(l+r)/2;
    if(x<=mid) update(2*u,l,mid,x);
    else update(2*u+1,mid+1,r,x);
    pushup(u,l,r);
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    build(1,1,n);
    while(q--){
        int x;
        cin>>x;
        update(1,1,n,x);
        cout<<tree[1].maxn<<'\n';
    }
    return 0;
}