#include<bits/stdc++.h>
using namespace std;
int n;
int cake[1010],dp[1010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>cake[i];
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
        dp[j]=max(dp[j],dp[j-i]+cake[i]);
    cout<<dp[n];
    return 0;
}