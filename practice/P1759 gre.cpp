#include<bits/stdc++.h>
using namespace std;
int m,v,n;
int g[105],f[105],tim[105];
int take[205][205];//重量m，阻力v的时候最终选了几号物品
int dp[205][205][205];
// int ans[205];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>m>>v>>n;
    for(int i=1;i<=n;i++) cin>>g[i]>>f[i]>>tim[i];
    for(int i=n;i>=1;i--)
        for(int j=0;j<=m;j++)//重量
            for(int k=0;k<=v;k++){
                dp[i][j][k]=dp[i+1][j][k];//先默认赋值 不然全进if
                if(j>=g[i]&&k>=f[i]){
                    if(dp[i][j][k]<=dp[i+1][j-g[i]][k-f[i]]+tim[i])//选
                    dp[i][j][k]=dp[i+1][j-g[i]][k-f[i]]+tim[i];
                    // take[j][k]=i;
                    else{
                    dp[i][j][k]=dp[i+1][j][k];//保证是小值
                    continue;
                    }
                }
                else continue;
        }
    cout<<dp[1][m][v]<<'\n';
    // int a=m,b=v,cnt=1;
    // while(take[a][b]!=0){//take只能记最后一个 最后一个被覆盖就完了
    //     int num=take[a][b];
    //     ans[cnt]=num;
    //     a=a-g[num];
    //     b=b-f[num];
    //     cnt++;
    // }
    // for(int i=cnt-1;i>0;i--) cout<<ans[i]<<" ";
/*  1:w=3 v=3 t=5
    2:w=5 v=5 t=10
    3:w=3,v=3 t=5
    m=6 v=6
    r1:dp[m][v]=dp[m-3][k-3]+5; take[m][v]=1
    r2:dp[m][v]=dp[m-5][k-5]+10 take[m][v]=2(严格大于)
    r3:不够大 continue;
    take[m][v]=2(实际选1 3字典序更小)
*/
    // int j=m,k=v;
    // for(int i=1;i<=n;i++){
    //     if(j>=g[i]&&k>=f[i]&&dp[j][k]==dp[j-g[i]][k-f[i]]+tim[i]){
    //         cout<<i<<" ";
    //         j=j-g[i];
    //         k=k-f[i];
    //     }
    // }//只看数值有可能重复选
    int j=m,k=v;
    for(int i=1;i<=n;i++){
        if(j>=g[i]&&k>=f[i]&&dp[i][j][k]==dp[i+1][j-g[i]][k-f[i]]+tim[i]){//判断有没有选i
            cout<<i<<" ";
            j=j-g[i];
            k=k-f[i];
        }
    }
    return 0;
}