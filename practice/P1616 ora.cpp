#include<bits/stdc++.h>
using namespace std;
int t,m;
long long dp[10000100];//时间
int herb[10005][2];//0放时间，1放价格
int main(){//完全背包 一维递推
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>t>>m;
    for(int i=1;i<=m;i++) cin>>herb[i][0]>>herb[i][1];
    for(int i=1;i<=m;i++){
        for(int j=herb[i][0];j<=t;j++)//j太少买不起
        dp[j]=max(dp[j],dp[j-herb[i][0]]+herb[i][1]);
    }
    cout<<dp[t];
    return 0;
}