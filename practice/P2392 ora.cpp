#include<bits/stdc++.h>
using namespace std;
int s1,s2,s3,s4;
int t[25],dp[1500];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>s1>>s2>>s3>>s4;
    int sum=0,ans=0;
    for(int i=1;i<=s1;i++) cin>>t[i],sum=sum+t[i];
    for(int i=1;i<=s1;i++){
        for(int j=sum/2;j>=t[i];j--)
        dp[j]=max(dp[j],dp[j-t[i]]+t[i]);
    }
    ans=ans+(sum-dp[sum/2]);
    memset(t,0,sizeof(t));
    memset(dp,0,sizeof(dp));
    sum=0;
    for(int i=1;i<=s2;i++) cin>>t[i],sum=sum+t[i];
    for(int i=1;i<=s2;i++){
        for(int j=sum/2;j>=t[i];j--)
        dp[j]=max(dp[j],dp[j-t[i]]+t[i]);
    }
    ans=ans+(sum-dp[sum/2]);
    memset(t,0,sizeof(t));
    memset(dp,0,sizeof(dp));
    sum=0;
    for(int i=1;i<=s3;i++) cin>>t[i],sum=sum+t[i];
    for(int i=1;i<=s3;i++){
        for(int j=sum/2;j>=t[i];j--)
        dp[j]=max(dp[j],dp[j-t[i]]+t[i]);
    }
    ans=ans+(sum-dp[sum/2]);
    memset(t,0,sizeof(t));
    memset(dp,0,sizeof(dp));
    sum=0;
    for(int i=1;i<=s4;i++) cin>>t[i],sum=sum+t[i];
    for(int i=1;i<=s4;i++){
        for(int j=sum/2;j>=t[i];j--)
        dp[j]=max(dp[j],dp[j-t[i]]+t[i]);
    }
    ans=ans+(sum-dp[sum/2]);
    cout<<ans;
    return 0;
}