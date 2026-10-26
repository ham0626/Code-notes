//离散化
//1e9的数组大小开不下 但是只有1e5次操作
//整合子区间没有操作的区间,压缩
//先读取,离线操作
//离散化是左闭右开的
#include<bits/stdc++.h>
using namespace std;
const long long MAXN=2e5+5;
int n,m;
long long cnt=1;
vector<long long> cut;//记l,r+1
unsigned long long tree[4*MAXN],lazy[4*MAXN];//tree只存增量
struct Node{
    int op;
    long long l,r,k;//操作
}mani[MAXN];
void build(int u,int l,int r){
    if(l==r)//第l个区间//存总和很容易算错(拿到真实输入的l,r更好)
        //如果输入是乱的 更算不出来
        //cut里面存的是真实坐标 l,r是映射在当前线段树里面的坐标
        //判断用 l，r，除了直接出答案的计算都用cut
        return;
    int mid=(l+r)/2;
    build(2*u,l,mid);
    build(2*u+1,mid+1,r);
    tree[u]=tree[2*u]+tree[2*u+1];
    return;
}
void pushdown(int u,int l,int r){//下传懒标记
    if(lazy[u]==0) return;//发完了
    int mid=(l+r)/2;
    unsigned long long k=lazy[u];
    tree[2*u]+=k*(cut[mid+1]-cut[l]);
    lazy[2*u]+=k;//给左儿子传标记
    tree[2*u+1]+=k*(cut[r+1]-cut[mid+1]);
    lazy[2*u+1]+=k;//给右儿子传标记
    lazy[u]=0;//不欠了
}
void update(int u,int l,int r,int x,int y,long long k){//单点修改(父节点,左边界,右边界,原下标,改后的值/要加的数)
    if(x<=l&&r<=y){//找到了
        lazy[u]+=k;
        tree[u]+=k*(cut[r+1]-cut[l]);//两个子树都要算,左闭右开
        return;
    }
    pushdown(u,l,r);
    int mid=(l+r)/2;
    if(x<=mid) update(2*u,l,mid,x,y,k);
    if(y>mid) update(2*u+1,mid+1,r,x,y,k);
    tree[u]=tree[2*u]+tree[2*u+1];
    return;
}
unsigned long long query(int u,int l,int r,int x,int y){
    if(x<=l&&r<=y)
        return tree[u];
    pushdown(u,l,r);
    int mid=(l+r)/2;
    unsigned long long tmp=0;
    if(x<=mid) tmp+=query(2*u,l,mid,x,y);
    if(y>mid) tmp+=query(2*u+1,mid+1,r,x,y);
    return tmp;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    cut.push_back(-1);//让正式读入值从下标1开始 和线段树对齐
    for(int i=1;i<=m;i++){
        int op;
        cin>>op;
        if(op==1){
            unsigned long long l,r,k;
            cin>>l>>r>>k;
            cut.push_back(l);
            cut.push_back(r+1);
            mani[cnt].op=1;
            mani[cnt].l=l;
            mani[cnt].r=r;
            mani[cnt].k=k;
            cnt++;
        }
        else{
            unsigned long long l,r;
            cin>>l>>r;
            cut.push_back(l);
            cut.push_back(r+1);
            mani[cnt].op=2;
            mani[cnt].l=l;
            mani[cnt].r=r;
            cnt++;
        }
    }
    sort(cut.begin(),cut.end());
    cut.erase(unique(cut.begin(),cut.end()),cut.end());
    //去重:unique(cut.begin(),cut.end())指向重复的第一个数
    //假设排序后数组是[2, 4, 4, 5, 5, 6]
    //unique处理后,数组会变成[2, 4, 5, 6, ?(unique指向), ?]
    int siz=cut.size()-1;//n个切点,n-1个区间
    build(1,1,siz-1);
    for(int i=1;i<=m;i++){
        unsigned long long op=mani[i].op;
        unsigned long long l=mani[i].l;
        unsigned long long r=mani[i].r;
        unsigned long long k=mani[i].k;
        if(op==1){//区间上每个数加k
            //把真实坐标弄成映射坐标
            unsigned long long posl=lower_bound(cut.begin()+1,cut.end(),l)-cut.begin();
            //减begin,从返回地址变成返回整数
            unsigned long long posr=lower_bound(cut.begin()+1,cut.end(),r+1)-cut.begin();
            //找的开区间,线段树处理闭区
            update(1,1,siz-1,posl,posr-1,k);
        }
        else{
            unsigned long long posl=lower_bound(cut.begin()+1,cut.end(),l)-cut.begin();
            unsigned long long posr=lower_bound(cut.begin()+1,cut.end(),r+1)-cut.begin();
            cout<<query(1,1,siz-1,posl,posr-1)+(r+l)*(r-l+1)/2<<'\n';
        }
    }
    return 0;
}