#include<bits/stdc++.h>
using namespace std;
int n;
long long dis[105][105],peo[105],ans[105][3];//价格，左子树，右子树
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(dis,0x3f3f3f3f,sizeof(dis));
    cin>>n;
    for(int i=1;i<=n;i++){
        int u,v,w;
        cin>>w>>u>>v;//数值，左子树，右子树
        if(u!=0)
            dis[i][u]=1,dis[u][i]=1;
        if(v!=0)
            dis[i][v]=1,dis[v][i]=1;
        peo[i]=w;
    }
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
    long long minn=1e18;
    for(int i=1;i<=n;i++){
        long long sum=0;
        for(int j=1;j<=n;j++){
            sum+=dis[i][j]*peo[j];
        }
        minn=min(minn,sum);
    }
    cout<<minn;
    return 0;
}