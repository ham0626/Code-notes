//混合背包//可以拆成多个01背包，但是时间复杂度爆炸
#include<bits/stdc++.h>
using namespace std;
int v,n;
int val[505],wei[505],num[505];
int dp[1010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>v;
    //二进制拆分
    //13个=1+2+4+6(6单出来)
    //1=1 2=2 3=1+2 4=4 5=1+4 6=6
    //7=6+1 8=2+6 9=1+2+6 10=4+6  
    //11=6+4+1 12=6+4+2 13=1+2+4+6
    for(int i=1;i<=n;i++){
        cin>>wei[i]>>val[i]>>num[i];
        int k=1;//理想中块大小
        while(num[i]>0){
            int blo=min(k,num[i]);//拆出来
            int blow=blo*wei[i];
            int blov=blo*val[i];
            for(int j=v;j>=blow;j--){
                dp[j]=max(dp[j],dp[j-blow]+blov);
            }
            num[i]=num[i]-blo;
            k=k*2;
        }
    }
    cout<<dp[v];
    return 0;
}