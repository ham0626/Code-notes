#include<bits/stdc++.h>
using namespace std;
int m,n;
int dp[1010][251];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>m>>n;
    dp[1][1]=1;
    dp[2][1]=1;
    dp[3][1]=2;
    for(int i=2;i<=n-1;i++){
        for(int j=1;j<=250;j++){
            dp[i+2][j]=dp[i][j]+dp[i+1][j]+dp[i+2][j];
            if(dp[i+2][j]>=10){
                dp[i+2][j]=dp[i+2][j]%10;
                dp[i+2][j+1]++;
            }
        }
    }
    int len=0;
    for(int i=250;i>=1;i--){
        if(dp[n-m+1][i]==0) len++;
        else break;
    }
    for(int i=250-len;i>=1;i--) cout<<dp[n-m+1][i];
    return 0;
}