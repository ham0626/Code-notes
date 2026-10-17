#include<bits/stdc++.h>
using namespace std;
int n,ans;
int pri[170]={2,3,5,7,11,13,17,19,23,29,31,37};
long long dp[1010];//和为x时的方法数
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    int cnt=12,flag=0;
    pri[0]=2,pri[1]=3,pri[2]=5,pri[3]=7;
    for(int i=40;i<=1000;i++){
        flag=0;
        for(int j=0;j<12;j++){
        if(i%pri[j]==0){
            flag=1;
            break;
        }
    }
        if(flag==0) pri[cnt]=i,cnt++;
    }
    dp[0]=1;//一定要赋初始值……递推起点
    for(int i=0;i<=167;i++)
        for(int j=pri[i];j<=n;j++)
        dp[j]=dp[j]+dp[j-pri[i]];
    cout<<dp[n];
    return 0;
}