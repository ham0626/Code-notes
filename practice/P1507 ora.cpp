#include<bits/stdc++.h>
using namespace std;
int h,t,n;//体积，质量
int vol[55],wei[55],cal[55];
int dp[410][410];//体积上限为j,质量上限为k,时能装的最大卡路里
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>h>>t>>n;
    for(int i=1;i<=n;i++) cin>>vol[i]>>wei[i]>>cal[i];
    int temp=t;
    for(int i=1;i<=n;i++)
        for(int j=h;j>=vol[i];j--)
            for(int k=t;k>=wei[i];k--){
                dp[j][k]=max(dp[j][k],dp[j-vol[i]][k-wei[i]]+cal[i]);
            }//dp[j-vol[i]][k-wei[i]]+cal[i] 从大往小推
    cout<<dp[h][t];
    return 0;
}