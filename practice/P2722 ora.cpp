#include<bits/stdc++.h>
using namespace std;
int m,n;
int dp[10010];
int score[10010],tim[10010];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>m>>n;
    for(int i=1;i<=n;i++) cin>>score[i]>>tim[i];
    for(int i=1;i<=n;i++)
        for(int j=tim[i];j<=m;j++){
            dp[j]=max(dp[j],dp[j-tim[i]]+score[i]);
        }
    cout<<dp[m];
    return 0;
}