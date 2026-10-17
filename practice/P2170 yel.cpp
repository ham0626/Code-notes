#include<bits/stdc++.h>
using namespace std;
int n,m,k;
bool dp[20010];
int it[20010],bac[20010];//it以i为根的连通块大小
int fa[200010];//存父节点（不需要存根，一直推就行）
int find(int x){
    if(fa[x]==x) return x;//已经是根节点
    else return fa[x]=find(fa[x]);//把所有这条路上的元素全部指向根
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=k;i++){
        int x,y;
        cin>>x>>y;
        fa[find(x)]=find(y);//合并
    }
    for(int i=1;i<=n;i++){
        it[find(i)]++;//一个对应根节点连通块多大
    }
    int cnt=1;
    for(int i=1;i<=n;i++){
        if(it[i]>0){//把每个连通块分别塞入一个物品数组方便背包
            bac[cnt]=it[i];
            cnt++;
        }
    }
    dp[0]=true;//0个人当然能凑出来
    for(int i=1;i<=cnt;i++){
        for(int j=n;j>=bac[i];j--)//要恰好装下，不能最多装下
        if(dp[j-bac[i]]) dp[j]=true;
    }
    int diff=0;
    // for(int i=1;i<=n;i++) cout<<dp[i]<<'\n';
    while(m-diff>=0&&m+diff<=n){
        if(dp[m-diff]!=0){
            cout<<m-diff;
            return 0;
        }
        else if(dp[m-diff]==0&&dp[m+diff]!=0){
            cout<<m+diff;
            return 0;
        }
        diff++;
    }
    return 0;
}