//分组背包
#include<bits/stdc++.h>
using namespace std;
int n,m,t;
int mon[105],tim[105];
int dp[205][205];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>t;
    for(int i=1;i<=n;i++) cin>>mon[i]>>tim[i];
    for(int i=1;i<=n;i++)
        for(int j=m;j>=mon[i];j--)//金钱
            for(int k=t;k>=tim[i];k--)//时间
            dp[j][k]=max(dp[j][k],dp[j-mon[i]][k-tim[i]]+1);
    cout<<dp[m][t];
    return 0;
}