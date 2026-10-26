#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int n,m;
int num[MAXN],rev[MAXN*4],cov[MAXN*4];//翻转,覆盖
struct Node{
    int len;//区间长
    int sum;//有多少个1
    int precon0,precon1;//前缀的连续0/1个数
    int sufcon0,sufcon1;//后缀的连续0/1个数
    int mxlin0,mxlin1;//最长连续0/1l
}tree[4*MAXN];
void pushup(int u){
    int l=2*u,r=2*u+1;
    tree[u].sum=tree[l].sum+tree[r].sum;
    if(tree[l].precon0==tree[l].len)//左子树全为0
        tree[u].precon0=tree[l].len+tree[r].precon0;
    else tree[u].precon0=tree[2*u].precon0;
    if(tree[l].precon1==tree[l].len)//左子树全为1
        tree[u].precon1=tree[l].len+tree[r].precon1;
    else tree[u].precon1=tree[l].precon1;
    if(tree[r].sufcon0==tree[r].len)//右子树全为0
        tree[u].sufcon0=tree[r].len+tree[l].sufcon0;
    else tree[u].sufcon0=tree[r].sufcon0;
    if(tree[r].sufcon1==tree[r].len)//右子树全为1
        tree[u].sufcon1=tree[r].len+tree[l].sufcon1;
    else tree[u].sufcon1=tree[r].sufcon1;
    tree[u].mxlin0=max({tree[l].mxlin0,tree[r].mxlin0,tree[l].sufcon0+tree[r].precon0});
    tree[u].mxlin1=max({tree[l].mxlin1,tree[r].mxlin1,tree[l].sufcon1+tree[r].precon1});
    return;
}
void build(int u,int l,int r){
    tree[u].len=r-l+1;
    if(l==r){
        if(num[l]==0){
            tree[u].precon0=1;
            tree[u].sufcon0=1;
            tree[u].mxlin0=1;
        }
        else{
            tree[u].sum=1;
            tree[u].precon1=1;
            tree[u].sufcon1=1;
            tree[u].mxlin1=1;
        }
        return;
    }
    int mid=(l+r)/2;
    build(2*u,l,mid);
    build(2*u+1,mid+1,r);
    pushup(u);
    return;
}
Node merge(Node l,Node r){//对比返回最大值
    Node re;
    re.len=r.len+l.len;
    if(l.precon0==l.len)//左子树全为0
        re.precon0=l.len+r.precon0;
    else re.precon0=l.precon0;
    if(l.precon1==l.len)//左子树全为1
        re.precon1=l.len+r.precon1;
    else re.precon1=l.precon1;
    if(r.sufcon0==r.len)//右子树全为0
        re.sufcon0=r.len+l.sufcon0;
    else re.sufcon0=r.sufcon0;
    if(r.sufcon1==r.len)//右子树全为1
        re.sufcon1=r.len+l.sufcon1;
    else re.sufcon1=r.sufcon1;
    re.mxlin0=max({l.mxlin0,r.mxlin0,l.sufcon0+r.precon0});
    re.mxlin1=max({l.mxlin1,r.mxlin1,l.sufcon1+r.precon1});
    re.sum=l.sum+r.sum;
    return re;
}
void op_cov(int u,int v){//只覆盖,标记在pushdown里面传
    if(v==1){//全部覆盖为1
        tree[u].sum=tree[u].len;
        tree[u].precon1=tree[u].sufcon1=tree[u].mxlin1=tree[u].len;
        tree[u].mxlin0=tree[u].precon0=tree[u].sufcon0=0;
    }
    else if(v==0){//全部覆盖为0
        tree[u].sum=0;
        tree[u].precon0=tree[u].sufcon0=tree[u].mxlin0=tree[u].len;
        tree[u].mxlin1=tree[u].precon1=tree[u].sufcon1=0;
    }
    else return;//=-1不用操作
    cov[u]=v;//记标记
    rev[u]=0;//覆盖标记
    return;
}
void op_rev(int u){//只翻转,标记在pushdown里面传
    if(cov[u]==-1){//rev操作在后 要保证没有覆盖
        if(rev[u]==1) rev[u]=0;//绝对不能赋值，可能会叠加
        else rev[u]=1;
    }
    else{//有标记
        if(cov[u]==1) cov[u]=0;//直接取反了
        else cov[u]=1;//
    }
    tree[u].sum=tree[u].len-tree[u].sum;
    int tmp;
    tmp=tree[u].mxlin0;
    tree[u].mxlin0=tree[u].mxlin1;
    tree[u].mxlin1=tmp;
    tmp=tree[u].sufcon0;
    tree[u].sufcon0=tree[u].sufcon1;
    tree[u].sufcon1=tmp;
    tmp=tree[u].precon0;
    tree[u].precon0=tree[u].precon1;
    tree[u].precon1=tmp;//不能擦标记
}
void pushdown(int u,int l,int r){//处理rev,cov
    if(cov[u]==-1&&rev[u]==0) return;//没有覆盖也没有翻转
    if(cov[u]!=-1){//有覆盖
        op_cov(2*u,cov[u]);
        op_cov(2*u+1,cov[u]);//函数里面记标记了，这一步相当于在传
        cov[u]=-1;//擦除标记
        return;
    }
    if(rev[u]==1){//要翻转,不能改自己
        op_rev(2*u);
        op_rev(2*u+1);//要调用
        rev[u]=0;//擦标记
    }
    return;
}
void update_rev(int u,int l,int r,int x,int y){//区间取反
    if(x<=l&&r<=y){
        op_rev(u);//肯定要修改
        return;
    }
    pushdown(u,l,r);
    int mid=(l+r)/2;
    if(x<=mid) update_rev(2*u,l,mid,x,y);
    if(y>mid) update_rev(2*u+1,mid+1,r,x,y);
    pushup(u);
    return;
}
void update_cov0(int u,int l,int r,int x,int y){//全部变成0
    if(x<=l&&r<=y){
        op_cov(u,0);//直接在函数里给cov标记赋值
        return;
    }
    pushdown(u,l,r);
    int mid=(l+r)/2;
    if(x<=mid) update_cov0(2*u,l,mid,x,y);
    if(y>mid) update_cov0(2*u+1,mid+1,r,x,y);
    pushup(u);
    return;
}
void update_cov1(int u,int l,int r,int x,int y){//全部变成1
    if(x<=l&&r<=y){
        op_cov(u,1);//直接在函数里给cov标记赋值
        return;
    }
    pushdown(u,l,r);
    int mid=(l+r)/2;
    if(x<=mid) update_cov1(2*u,l,mid,x,y);
    if(y>mid) update_cov1(2*u+1,mid+1,r,x,y);
    pushup(u);
    return;
}
Node query(int u,int l,int r,int x,int y){//查询多少个1/连续的1
    if(x<=l&&r<=y){
        return tree[u];
    }
    pushdown(u,l,r);
    int mid=(l+r)/2;
    if(x>mid) return query(2*u+1,mid+1,r,x,y);//只查右子树
    if(y<=mid) return query(2*u,l,mid,x,y);
    Node ll=query(2*u,l,mid,x,y),rr=query(2*u+1,mid+1,r,x,y);
    return merge(ll,rr);
}
int main(){
    ios::sync_with_stdio( 0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>num[i];
    for(int i=1;i<=4*n;i++) cov[i]=-1;
    build(1,1,n);
    while(m--){
        int op;
        cin>>op;
        if(op==0){//区间内全部变成0
            int l,r;
            cin>>l>>r;
            l++,r++;
            update_cov0(1,1,n,l,r);
        }
        else if(op==1){//区间内全部变成1
            int l,r;
            cin>>l>>r;
            l++,r++;
            update_cov1(1,1,n,l,r);
        }
        else if(op==2){//区间内全部变成0
            int l,r;
            cin>>l>>r;
            l++,r++;
            update_rev(1,1,n,l,r);
        }
        else if(op==3){
            int l,r;
            cin>>l>>r;
            l++,r++;
            Node ans=query(1,1,n,l,r);
            cout<<ans.sum<<'\n';//总共的1
        }
        else{
            int l,r;
            cin>>l>>r;
            l++,r++;
            Node ans=query(1,1,n,l,r);
            cout<<ans.mxlin1<<'\n';//连续的1
        }
    }
    return 0;
}