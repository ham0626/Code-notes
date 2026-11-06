#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
//方差要区间中每个数的平方和
int n,m;
double num[MAXN];
double tree[4*MAXN],sqsum[4*MAXN],lazy[4*MAXN];
void build(int u,int l,int r){
    if(l==r){
        tree[u]=num[l];
        sqsum[u]=num[l]*num[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*u,l,mid);
    build(2*u+1,mid+1,r);
    tree[u]=tree[2*u]+tree[2*u+1];
    sqsum[u]=sqsum[2*u]+sqsum[2*u+1];
    return;
}
void pushdown(int u,int l,int r){//懒标记
    if(lazy[u]==0.0) return;
    double k=lazy[u];
    lazy[2*u]+=k,lazy[2*u+1]+=k;
    int mid=(l+r)/2;//完全平方展开
    sqsum[2*u]+=2*k*tree[2*u]+(mid-l+1)*k*k;
    sqsum[2*u+1]+=2*k*tree[2*u+1]+(r-mid)*k*k;
    tree[2*u]+=(mid-l+1)*k;
    tree[2*u+1]+=(r-mid)*k;
    lazy[u]=0;
}
void update(int u,int l,int r,int x,int y,double k){//区间加
    if(x<=l&&r<=y){
        lazy[u]+=k;
        sqsum[u]+=2*k*tree[u]+k*k*(r-l+1);
        tree[u]+=k*(r-l+1);
        return;
    }
    pushdown(u,l,r);
    int mid=(l+r)/2;
    if(x<=mid) update(2*u,l,mid,x,y,k);
    if(y>mid) update(2*u+1,mid+1,r,x,y,k);
    tree[u]=tree[2*u]+tree[2*u+1];
    sqsum[u]=sqsum[2*u]+sqsum[2*u+1];
    return;
}
double query_add(int u,int l,int r,int x,int y){//区间和
    double sum=0;
    if(x<=l&&r<=y)
        return tree[u];
    pushdown(u,l,r);
    int mid=(l+r)/2;
    if(x<=mid) sum+=query_add(2*u,l,mid,x,y);
    if(y>mid) sum+=query_add(2*u+1,mid+1,r,x,y);
    return sum;
}
double query_sq(int u,int l,int r,int x,int y){//区间和
    double sum=0;
    if(x<=l&&r<=y)
        return sqsum[u];
    pushdown(u,l,r);
    int mid=(l+r)/2;
    if(x<=mid) sum+=query_sq(2*u,l,mid,x,y);
    if(y>mid) sum+=query_sq(2*u+1,mid+1,r,x,y);
    return sum;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>num[i];
    build(1,1,n);
    for(int i=1;i<=m;i++){
        int op;
        cin>>op;
        if(op==1){//区间加
            int x,y;
            double k;
            cin>>x>>y>>k;
            update(1,1,n,x,y,k);
        }
        else if(op==2){//平均数
            int x,y;
            cin>>x>>y;
            double ans=(double)query_add(1,1,n,x,y)/(y-x+1);
            cout<<fixed<<setprecision(4)<<ans<<'\n';
        }
        else{//方差
            int x,y;
            cin>>x>>y;
            double ans=(double)query_add(1,1,n,x,y)/(y-x+1);
            double res=(double)query_sq(1,1,n,x,y)/(y-x+1)-ans*ans;
            cout<<fixed<<setprecision(4)<<res<<'\n';
        }
    }
    return 0;
}