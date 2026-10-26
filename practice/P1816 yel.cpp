#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int m,n;
int num[MAXN];
long long tree[4*MAXN];
void build(int u,int l,int r){
    if(l==r){
        tree[u]=num[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*u,l,mid);
    build(2*u+1,mid+1,r);
    tree[u]=min(tree[2*u],tree[2*u+1]);
    return;
}
long long query(int u,int l,int r,int x,int y){
    if(x<=l&&r<=y)
        return tree[u];
    int mid=(l+r)/2;
    long long tmp=0x3f3f3f3f;
    if(x<=mid) tmp=min(tmp,query(2*u,l,mid,x,y));
    if(y>mid) tmp=min(tmp,query(2*u+1,mid+1,r,x,y));
    return tmp;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>m>>n;
    for(int i=1;i<=m;i++) cin>>num[i];
    build(1,1,m);
    while(n--){
        int a,b;
        cin>>a>>b;
        cout<<query(1,1,m,a,b)<<" ";
        }
    return 0;
}