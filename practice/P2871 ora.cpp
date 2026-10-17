
#include<bits/stdc++.h>//一维01背包
using namespace std;
int n,m;
long long dp[12900];//余额
int wei[3500],val[3500];
int main(){//01背包 一维递推
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>wei[i]>>val[i];
    for(int i=1;i<=n;i++){
        for(int j=m;j>=wei[i];j--)//倒序确保每个只能选一次
        dp[j]=max(dp[j],dp[j-wei[i]]+val[i]);
    }
    cout<<dp[m];
    return 0;
}