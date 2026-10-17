#include<bits/stdc++.h>
using namespace std;
int s;
int dp[1010];
int val[1010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>s;
    for(int i=2;i<=s;i++){
        int ans=1;
        for(int j=2;j*j<=i;j++){
            if(j*j==i) ans=ans+j;
            if(i%j==0&&j*j!=i) ans=ans+j+(i/j);
        }
        val[i]=ans;
    }
    // for(int i=1;i<=s;i++) cout<<val[i]<<"\n";
    dp[1]=0;
    for(int i=2;i<=s;i++)
        for(int j=1;j<=i;j++)
        dp[i]=max(dp[i],dp[i-j]+val[j]);
    cout<<dp[s];
    return 0;
}