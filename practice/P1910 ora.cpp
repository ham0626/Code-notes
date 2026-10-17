//二维背包
#include<bits/stdc++.h>
using namespace std;
int x,n,m;
int cap[105],flaw[105],mon[105];
int dp[1010][1010];//缺点,金额
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>x;
    for(int i=1;i<=n;i++) cin>>cap[i]>>flaw[i]>>mon[i];
    for(int i=1;i<=n;i++)
        for(int j=x;j>=mon[i];j--)//金额
            for(int k=m;k>=flaw[i];k--)//缺点
            dp[k][j]=max(dp[k][j],dp[k-flaw[i]][j-mon[i]]+cap[i]);
    cout<<dp[m][x];
    return 0;
}