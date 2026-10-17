#include<bits/stdc++.h>
using namespace std;
int n;
int pri[46]={2,3,5,7,11,13,17};
long long dp[205];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int cnt=7,flag=0;
    for(int i=2;i<=200;i++){
        flag=0;
        for(int j=0;j<=6;j++){
            if(i%pri[j]==0){
                flag=1;
                break;
            }
        }
        if(flag==0){
            pri[cnt]=i;
            cnt++;
        }
    }
    while(cin>>n){
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=0;i<=45;i++)
            for(int j=pri[i];j<=n;j++)
            dp[j]=(dp[j]+dp[j-pri[i]]);
        cout<<dp[n]<<'\n';
    }
    return 0;
}