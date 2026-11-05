#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt;
long long num[4000005],ans[4000005],cop[4000005];
long long tree[4000005];
struct Node{//([1,r]里<=的个数)-([1,l-1]里<=的个数)
    int pos;//记边界
    int x;//查询值
    int id;//序号
    int sign;//+([1,r]） -([1,l-1])
}q[4000005];
int rankk(long long x){
    return lower_bound(cop+1,cop+cnt+1,x)-cop;
}
int lowbit(int x){
    return x&-x;
}
void add(int x,int v){
    while(x<=cnt){
        tree[x]+=v;
        x+=lowbit(x);
    }
}
int query(int x){
    int res=0;
    while(x>0){
        res+=tree[x];
        x-=lowbit(x);
    }
    return res;
}
bool comp(Node a,Node b){
    return a.pos<b.pos;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    int t=1;
    for(int i=1;i<=n;i++) cin>>num[i],cop[++cnt]=num[i];
    for(int i=1;i<=m;i++){
        long long l,r,x;
        cin>>l>>r>>x;
        q[t].pos=r,q[t].id=i;
        q[t].sign=1,q[t].x=x;
        t++;
        q[t].pos=l-1,q[t].id=i;
        q[t].sign=-1,q[t].x=x;
        t++;
        cop[++cnt]=x;
    }
    sort(q+1,q+t,comp);
    sort(cop+1,cop+cnt+1);
    cnt=unique(cop+1,cop+cnt+1)-(cop+1);
    int j=1;
    for(int i=1;i<t;i++){
        while(j<=q[i].pos){
            add(rankk(num[j]),1);
            j++;
        }
        int res=query(rankk(q[i].x));
        ans[q[i].id]+=q[i].sign*res;
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<'\n';
    return 0;
}