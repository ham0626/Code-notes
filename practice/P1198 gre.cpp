#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5;
long long m,d,cnt;
char op;
long long n,tree[4*MAXN];
void update(int u,int l,int r,int c,long long n){
    if(l==r){
        tree[u]=n;
        return;
    }
    int mid=(l+r)/2;
    if(c<=mid) update(2*u,l,mid,c,n);
    else update(2*u+1,mid+1,r,c,n);
    tree[u]=max(tree[2*u],tree[2*u+1]);
    return;
}
long long query(int u,int l,int r,int x,int y){
    if(x<=l&&r<=y)
        return tree[u];
    int mid=(l+r)/2;
    long long maxn=-1e18;
    if(x<=mid) maxn=max(maxn,query(2*u,l,mid,x,y));
    if(y>mid) maxn=max(maxn,query(2*u+1,mid+1,r,x,y));
    return maxn;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>m>>d;
    long long t=0;
    for(int i=1;i<=m;i++){
        cin>>op;
        if(op=='Q'){//查询末尾L个数中最大的数并输出
            int l;
            cin>>l;
            t=query(1,1,m,cnt-l+1,m);
            cout<<t<<'\n';
        }
        else{//插入//把插入变成修改
            cin>>n;
            cnt++;
            update(1,1,m,cnt,(n+t)%d);
        }
    }
    return 0;
}