//混合背包//可以拆成多个01背包，但是时间复杂度爆炸
#include<bits/stdc++.h>
using namespace std;
int w,n;
int val[105],wei[105],num[105];
int dp[40010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>w;
    //二进制拆分
    for(int i=1;i<=n;i++){
        cin>>val[i]>>wei[i]>>num[i];
        int k=1;//理想中块大小
        while(num[i]>0){
            int blo=min(k,num[i]);//拆出来
            int blow=blo*wei[i];
            int blov=blo*val[i];
            for(int j=w;j>=blow;j--){
                dp[j]=max(dp[j],dp[j-blow]+blov);
            }
            num[i]=num[i]-blo;
            k=k*2;
        }
    }
    cout<<dp[w];
    return 0;
}