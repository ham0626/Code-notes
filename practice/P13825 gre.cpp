#include<bits/stdc++.h>
using namespace std;
const long long MAXN=1e9+5;
int n,m;
int num[MAXN];
long long tree[4*MAXN],lazy[4*MAXN];
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
void pushdown(int u,int l,int r){//下传懒标记
    if(lazy[u]==0) return;//发完了
    int mid=(l+r)/2;
    int lc=2*u,rc=2*u+1;
    long long k=lazy[u];
    tree[lc]+=k*(mid-l+1),lazy[lc]+=k;//给左儿子传标记
    tree[rc]+=k*(r-mid),lazy[rc]+=k;//给右儿子传标记
    lazy[u]=0;//不欠了
}
void update(int u,int l,int r,int x,int y,long long k){//单点修改(父节点,左边界,右边界,原下标,改后的值/要加的数)
    if(x<=l&&r<=y){//找到了
        lazy[u]+=k;
        tree[u]+=k*(r-l+1);
        return;
    }
    pushdown(u,l,r);
    int mid=(l+r)/2;
    if(x<=mid) update(2*u,l,mid,x,y,k);
    if(y>mid) update(2*u+1,mid+1,r,x,y,k);
    tree[u]=tree[2*u]+tree[2*u+1];
    return;
}
long long query(int u,int l,int r,int x,int y){
    if(x<=l&&r<=y)
        return tree[u];
    pushdown(u,l,r);
    int mid=(l+r)/2;
    long long tmp=0;
    if(x<=mid) tmp+=query(2*u,l,mid,x,y);
    if(y>mid) tmp+=query(2*u+1,mid+1,r,x,y);
    return tmp;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) num[i]=i;
    build(1,1,n);
    while(m--){
        int op;
        cin>>op;
        if(op==1){
            int l,r,k;
            cin>>l>>r>>k;
            update(1,1,n,l,r,k);
        }
        else{
            int l,r;
            cin>>l>>r;
            cout<<query(1,1,n,l,r)<<'\n';
        }
    }
    return 0;
}