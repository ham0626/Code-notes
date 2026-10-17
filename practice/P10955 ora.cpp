#include<bits/stdc++.h>
using namespace std;
int n;
long long dp[4010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    dp[0]=1;
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
        dp[j]=(dp[j]+dp[j-i])%2147483648;
    cout<<(dp[n]-1+2147483648)%2147483648;
    return 0;
}