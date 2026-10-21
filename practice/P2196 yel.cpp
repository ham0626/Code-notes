#include<bits/stdc++.h>
using namespace std;
int n;
int pre[25],bomb[25],mapp[25][25],dp[25],ans[25];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(mapp,0x3f3f3f3f,sizeof(mapp));
    cin>>n;
    for(int i=1;i<=n;i++) cin>>bomb[i];
    for(int i=1;i<=n-1;i++)
        for(int j=n-1;j>=i;j--)
        cin>>mapp[i][n-j+i];//起点 终点
    // for(int i=1;i<=n-1;i++){
    //     for(int j=1;j<=n;j++)
    //     cout<<mapp[i][j]<<" ";
    //     cout<<'\n';
    // }
    for(int i=1;i<=n;i++) dp[i]=bomb[i];
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            if(mapp[i][j]==1){//能走通
                // cout<<i<<" "<<j<<'\n';
                if(dp[j]<dp[i]+bomb[j]){
                    dp[j]=dp[i]+bomb[j];
                    pre[j]=i;//对应前驱
                }
            }
        }
    int maxn=0,re;
    for(int i=1;i<=n;i++) maxn=max(maxn,dp[i]);
    for(int i=1;i<=n;i++)
        if(maxn==dp[i]){
            re=i;
            break;
        }
    int cnt=1;
    for(int i=re;i;i=pre[i]){
        // cout<<i<<" ";
        ans[cnt]=i;
        cnt++;
    }
    for(int i=cnt-1;i>=1;i--) cout<<ans[i]<<" ";
    cout<<'\n';
    cout<<maxn;
    // for(int i=1;i<=n;i++) cout<<dp[i]<<" ";
    return 0;
}