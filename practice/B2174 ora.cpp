#include<bits/stdc++.h>
using namespace std;
int v,n;
long long dp[1100];
int vol[1100],val[1100];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>v;
    for(int i=1;i<=n;i++) cin>>vol[i]>>val[i];
    for(int i=1;i<=n;i++){
        for(int j=vol[i];j<=v;j++)
        dp[j]=max(dp[j],dp[j-vol[i]]+val[i]);
    }
    cout<<dp[v];
    return 0;
}