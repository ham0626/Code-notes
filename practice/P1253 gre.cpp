#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000005;
int n,q;
long long num[MAXN],tree[4*MAXN],lazy_add[4*MAXN],lazy_mod[4*MAXN];
void build(int u,int l,int r){
    if(l==r){//找到叶节点了(只有build才是l==r 其他都是包住)
        tree[u]=num[l];//*
        return;
    }
    int mid=(l+r)/2;
    build(2*u,l,mid);//*mid给左边 
    build(2*u+1,mid+1,r);
    tree[u]=max(tree[2*u],tree[2*u+1]);
    return;
}
// void po_update(int u,int l,int r,int x,int k){//单点加特定值
//     if(l==r){//不能比num和tree，因为在tree里会发生修改
//         tree[u]+=k;
//         return;
//     }
//     else{
//         int mid=(l+r)/2;
//         if(x<=mid) po_update(2*u,l,mid,x,k);//这个等号到底放哪边
//         else po_update(2*u+1,mid+1,r,x,k);//不是左就是右
//     }
//     tree[u]=max(tree[2*u],tree[2*u+1]);//更新一遍
// }
void pushdown(int u,int l,int r){
    long long k=lazy_add[u],p=lazy_mod[u];
    if(p!=1e18){//赋值优先级更高
        lazy_mod[u]=1e18;//*
        lazy_mod[2*u]=p,lazy_mod[2*u+1]=p;
        lazy_add[2*u]=0,lazy_add[2*u+1]=0;
        tree[2*u]=p,tree[2*u+1]=p;
    }
    if(k!=0){//要加
        lazy_add[2*u]+=k,lazy_add[2*u+1]+=k;
        tree[2*u]+=k;//*区间大小
        tree[2*u+1]+=k;//刹车在ra_update
        lazy_add[u]=0;
    }
}
void ra_update(int u,int l,int r,int x,int y,int k){//区间内数加特定值
    if(x<=l&&r<=y){//我管的(l~r)都需要
        lazy_add[u]+=k;
        tree[u]+=k;//只管当前的区间
        return;
    }
    pushdown(u,l,r);
    int mid=(l+r)/2;
    if(x<=mid) ra_update(2*u,l,mid,x,y,k);
    if(y>mid) ra_update(2*u+1,mid+1,r,x,y,k);
    tree[u]=max(tree[2*u],tree[2*u+1]);
}
void ra_modify(int u,int l,int r,int x,int y,int k){//区间内数改为特定值
    if(x<=l&&r<=y){//我管的(l~r)都需要
        lazy_add[u]=0;//只要我有一步赋值在加后面,加法就作废
        tree[u]=k;//k是唯一值也是最大值
        lazy_mod[u]=k;
        return;
    }
    pushdown(u,l,r);
    int mid=(l+r)/2;
    if(x<=mid) ra_modify(2*u,l,mid,x,y,k);
    if(y>mid) ra_modify(2*u+1,mid+1,r,x,y,k);
    tree[u]=max(tree[2*u],tree[2*u+1]);
}
long long query(int u,int l,int r,int x,int y){//查询区间和
    if(x<=l&&r<=y){
        return tree[u];
    }
    pushdown(u,l,r);
    int mid=(l+r)/2;
    long long res=-1e18;
    if(x<=mid){
        long long left=query(2*u,l,mid,x,y);
        res=max(left,res);
    }
    if(y>mid){
        long long right=query(2*u+1,mid+1,r,x,y);
        res=max(res,right);
    }
    return res;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>num[i];
    for(int i=1;i<=4*n;i++) lazy_mod[i]=1e18;
    build(1,1,n);
    for(int i=1;i<=q;i++){
        int op;
        cin>>op;
        if(op==1){
            int l,r,x;
            cin>>l>>r>>x;
            ra_modify(1,1,n,l,r,x);
        }
        else if(op==2){
            int l,r,x;
            cin>>l>>r>>x;
            ra_update(1,1,n,l,r,x);
        }
        else{
            int l,r;
            cin>>l>>r;
            cout<<query(1,1,n,l,r)<<'\n';
        }
    }
    return 0;
}