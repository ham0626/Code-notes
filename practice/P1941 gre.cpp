#include<bits/stdc++.h>
using namespace std;
int up[10005],dow[10005];//某个点操作/不操作结果
int low[10005],high[10005];//某个点能走的上下端
int dp[10005][1005];
bool has_pipe[10005];
int n,m,k;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    memset(dp,0x3f3f3f3f,sizeof(dp));
    for(int i=1;i<=n;i++) high[i]=m+5;
    for(int i=1;i<=m;i++) dp[0][i]=0;
    for(int i=1;i<=n;i++) cin>>up[i]>>dow[i];
    for(int i=1;i<=k;i++){
        int p,l,h;
        cin>>p>>l>>h;
        low[p]=l,high[p]=h;
        has_pipe[p]=true;
    }
    for(int i=1;i<=n;i++){//j=j+op[i]
        for(int j=1+up[i];j<=m+up[i];j++){
            int ny=min(j,m);
            dp[i][ny]=min(dp[i][ny],dp[i-1][j-up[i]]+1);
            dp[i][ny]=min(dp[i][ny],dp[i][j-up[i]]+1);
        }//上升
        for(int j=1;j<=m-dow[i];j++){
            dp[i][j]=min(dp[i][j],dp[i-1][j+dow[i]]);
        }
        for(int j=1;j<=m;j++)
            if(j<=low[i]||j>=high[i])
            dp[i][j]=0x3f3f3f3f;
    }
    int minn=0x3f3f3f3f;
    for(int i=1;i<=m;i++)
        minn=min(minn,dp[n][i]);
    if(minn==0x3f3f3f3f){
        cout<<"0"<<'\n';
        int maxn=0;
        for(int i=1;i<=n;i++){
            bool flag=0;
            for(int j=1;j<=m;j++){
                if(dp[i][j]<0x3f3f3f3f){
                    flag=1;
                    break;
                }
            }
            if(flag==1) maxn=i;
            else break;
        }
        int cnt=0;
        for(int i=1;i<=maxn;i++)
        if(has_pipe[i]) cnt++;
        cout<<cnt;
    }
    else{
        cout<<"1"<<'\n';
        cout<<minn;
    }
    return 0;
}