#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,s;
long long fac[1000005],tree[1000005];//阶乘数组,存比x小的个数
int lowbit(int x){
    return x&-x;
}
void add(int x,int k){
    while(x<=n){
        tree[x]+=k;
        x+=lowbit(x);//加:向尾部走
    }
}
int query(int x){
    int sum=0;
    while(x>0){
        sum+=tree[x];
        x-=lowbit(x);//减:向头部走
    }
    return sum;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) add(i,1);
    long long ans=0;
    fac[0]=1;//预处理
    for(int i=1;i<=n;i++){
        fac[i]=(fac[i-1]*i)%mod;
    }
    for(int i=1;i<=n;i++){
        cin>>s;//挨个读入
        int cnt=query(s-1);//查当前比x-1小的还有多少个没用过
        ans=(ans+cnt*fac[n-i])%mod;//有cnt个可以随便排
        add(s,-1);//删除数字
    }
    cout<<(ans+1)%mod;//自己的排名
    return 0;
}