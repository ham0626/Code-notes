#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
    int gro,wei,val;
}mac[160];
int dp[20][1500];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            cin>>mac[(i-1)*m+j].val;//价值
            mac[(i-1)*m+j].gro=i;//组
            mac[(i-1)*m+j].wei=j;//质量
        }
    for(int i=n;i>=1;i--)
        for(int j=m;j>=0;j--){
            dp[i][j]=dp[i+1][j];//默认值 放在k循环外面
            for(int k=m*i;k>=m*i-m+1;k--){//组要放在最里面，避免重复选
                if(j>=mac[k].wei){//容量够才能选/不选
                    dp[i][j]=max(dp[i][j],dp[i+1][j-mac[k].wei]+mac[k].val);
            }
                else continue;
            }
        }
    cout<<dp[1][m]<<'\n';
    int k=m,flag=0;
    for(int i=1;i<=n;i++){
        flag=0;
        cout<<i<<" ";
        if(dp[i][k]==dp[i+1][k]){//特判分配0台
            cout<<"0"<<'\n';
            flag=1;
        }
            for(int j=m*(i-1)+1;j<=m*i&&j<=n*m;j++){
            if(flag==0&&k>=mac[j].wei&&dp[i][k]==dp[i+1][k-mac[j].wei]+mac[j].val){
                cout<<mac[j].wei<<"\n";
                k=k-mac[j].wei;
                break;
            }
            else continue;
            }
        }
    return 0;
}