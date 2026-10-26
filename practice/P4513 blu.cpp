#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int n,m;
int num[MAXN];
struct Node{
    long long sum;//区间和
    long long pre;//最大前缀和
    long long suf;//最大后缀和
    long long mxlin;//最大子段和
}tree[4*MAXN];
void pushup(int u){
    tree[u].sum=tree[2*u].sum+tree[2*u+1].sum;
    tree[u].pre=max(tree[2*u].pre,tree[2*u].sum+tree[2*u+1].pre);
    tree[u].suf=max(tree[2*u+1].suf,tree[2*u].suf+tree[2*u+1].sum);
    tree[u].mxlin=max({tree[2*u].mxlin,tree[2*u+1].mxlin,tree[2*u].suf+tree[2*u+1].pre});
    return;
}
void build(int u,int l,int r){
    if(l==r){
        tree[u].sum=num[l];
        tree[u].pre=num[l];
        tree[u].suf=num[l];
        tree[u].mxlin=num[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*u,l,mid);
    build(2*u+1,mid+1,r);
    pushup(u);
    return;
}
void update_mod(int u,int l,int r,int x,int k){//下标 分数
    if(l==r){
        tree[u].pre=k;
        tree[u].suf=k;
        tree[u].sum=k;
        tree[u].mxlin=k;
        return;
    }
    int mid=(l+r)/2;
    if(x<=mid) update_mod(2*u,l,mid,x,k);//只有x:if-else
    else update_mod(2*u+1,mid+1,r,x,k);
    pushup(u);
    return; 
}
Node merge(Node l,Node r){
    Node re;
    re.sum=l.sum+r.sum;
    re.pre=max(l.pre,l.sum+r.pre);
    re.suf=max(r.suf,r.sum+l.suf);
    re.mxlin=max({l.mxlin,l.suf+r.pre,r.mxlin});
    return re;
}
Node query(int u,int l,int r,int x,int y){
    long long sum=0;
    if(x<=l&&r<=y){
        return tree[u];
    }
    int mid=(l+r)/2;
    if(x>mid) return query(2*u+1,mid+1,r,x,y);//只查右子树
    if(y<=mid) return query(2*u,l,mid,x,y);//只查左子树
    Node ll=query(2*u,l,mid,x,y);
    Node rr=query(2*u+1,mid+1,r,x,y);//都要查
    Node re;
    re.sum=ll.sum+rr.sum;
    re.pre=max(ll.pre,ll.sum+rr.pre);
    re.suf=max(rr.suf,rr.sum+ll.suf);
    re.mxlin=max({ll.mxlin,ll.suf+rr.pre,rr.mxlin});
    return re;
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
        if(op==1){
            int a,b;
            cin>>a>>b;
            if(a<=b){
                Node an=query(1,1,n,a,b);
                cout<<an.mxlin<<'\n';
            }
            else{
                Node an=query(1,1,n,b,a);
                cout<<an.mxlin<<'\n';
            }
        }
        else{
            int p,s;
            cin>>p>>s;
            update_mod(1,1,n,p,s);
        }
    }
    return 0;
}