// #include<bits/stdc++.h>//二维01背包
// using namespace std;
// int n,m;
// int item[30][2];//0存价格，1存重要性
// int dp[30][30010];
// int dfs(int num,int mon){
//     if(num>m) return 0;
//     if(dp[num][mon]!=-1) return dp[num][mon];
//     int v1=dfs(num+1,mon);//不选
//     if(mon>=item[num][0]){//有钱才选
//         int v2=dfs(num+1,mon-item[num][0])+item[num][0]*item[num][1];
//         dp[num][mon]=max(v1,v2);//选和不选哪个更优
//         return dp[num][mon];
//     }
//     else{//没钱返回不选的（不然就会返回-1）
//         return v1;
//     }
//     return 0;
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     memset(dp,-1,sizeof(dp));
//     for(int i=1;i<=m;i++) cin>>item[i][0]>>item[i][1];
//     int ans=dfs(1,n);
//     cout<<ans;
//     return 0;
// }
#include<bits/stdc++.h>//一维01背包
using namespace std;
int n,m;
long long dp[100000100];//余额
int item[30005][2];//0放价格，1放重要度
int main(){//01背包 一维递推
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>item[i][0]>>item[i][1];
    for(int i=1;i<=m;i++){
        for(int j=n;j>=item[i][0];j--)//倒序确保每个只能选一次
        dp[j]=max(dp[j],dp[j-item[i][0]]+item[i][0]*item[i][1]);
    }
    cout<<dp[n];
    return 0;
}