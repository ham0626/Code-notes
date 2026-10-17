#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long dp[400];//和为x时的方法数
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    dp[0]=1;
    if(n==1||n==2){
        cout<<"0";
        return 0;
    }
    ans=n*(n+1)/2;
    if(ans%2!=0){
        cout<<"0";
        return 0;
    }
    else{
        ans=ans/2;
        for(int i=1;i<=n;i++)
            for(int j=ans;j>=i;j--)
            dp[j]=dp[j]+dp[j-i];
            cout<<dp[ans]/2;//{A,B}和{B,A}算一种
            return 0;
    }
    return 0;
}