#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int n,m;
long long num[MAXN],tree[4*MAXN];
bool lazy[4*MAXN];//是否翻转
void pushdown(int u,int l,int r){//pushdown动儿子 update动自己
    if(lazy[u]==true){
        int mid=(l+r)/2;
        if(lazy[2*u]==false) lazy[2*u]=true;
        else lazy[2*u]=false;
        if(lazy[2*u+1]==false) lazy[2*u+1]=true;
        else lazy[2*u+1]=false;
        tree[2*u]=(mid-l+1)-tree[2*u];
        tree[2*u+1]=(r-mid)-tree[2*u+1];
        lazy[u]=false;
        // cout<<tree[u]<<'\n';
        return;
    }
    else return;
}
void update(int u,int l,int r,int x,int y){
    if(x<=l&&r<=y){
        if(lazy[u]==true){
            lazy[u]=false;
            tree[u]=(r-l+1)-tree[u];//自己还是要改的
        }
        else lazy[u]=true,tree[u]=(r-l+1)-tree[u];
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
    // cout<<u<<" "<<l<<" "<<r<<'\n';
    if(x<=l&&r<=y)
        return tree[u];
    pushdown(u,l,r);
    long long sum=0;
    int mid=(l+r)/2;
    if(x<=mid) sum=sum+query(2*u,l,mid,x,y);
    if(y>mid) sum=sum+query(2*u+1,mid+1,r,x,y);
    return sum;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;//0是关 1是开
    for(int i=1;i<=m;i++){
        int op;
        cin>>op;
        if(op==0){//改变状态
            int a,b;
            cin>>a>>b;
            update(1,1,n,a,b);
        }
        else{//输出
            int a,b;
            cin>>a>>b;
            cout<<query(1,1,n,a,b)<<'\n';
        }
    }
    return 0;
}