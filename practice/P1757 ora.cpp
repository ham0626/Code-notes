//分组背包
#include<bits/stdc++.h>
using namespace std;
int m,n;
struct node{
    int wei,val,gro;
}item[1005];
int start[1005];
int dp[100010];
bool comp(node x,node y){
    return x.gro<y.gro;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>m>>n;
    for(int i=1;i<=n;i++) 
        cin>>item[i].wei>>item[i].val>>item[i].gro;
    sort(item+1,item+n+1,comp);//i从小到大就是gro从小到大
    int cnt=1;
    item[0].gro=item[1].gro;
    start[1]=1;
    for(int i=1;i<=n;i++){
        if(item[i].gro!=item[i-1].gro) cnt++,start[cnt]=i;
        else continue;
    }
    start[cnt+1]=n+1;//最后一组也要走
    for(int i=1;i<=cnt;i++)//每组遍历
        for(int k=m;k>=0;k--)
            for(int j=start[i];j<start[i+1];j++)//物品遍历 只能选一个,小心越界（不能<=）
                if(k>=item[j].wei)
                dp[k]=max(dp[k],dp[k-item[j].wei]+item[j].val);
    cout<<dp[m];
    return 0;
}