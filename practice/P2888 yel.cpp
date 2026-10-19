#include<bits/stdc++.h>
using namespace std;
int n,m,t;
int dis[305][305];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(dis,0x3f3f3f3f,sizeof(dis));
    cin>>n>>m>>t;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        dis[u][v]=min(dis[u][v],w);
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                int maxn=max(dis[i][k],dis[k][j]);//这个中转站能走通，最高栅栏是多少
                dis[i][j]=min(dis[i][j],maxn);//有没有必要走中转站
            }
    for(int i=1;i<=t;i++){
        int fro,to;
        cin>>fro>>to;
        if(dis[fro][to]==0x3f3f3f3f) cout<<"-1"<<'\n';
        else cout<<dis[fro][to]<<'\n';
    }
    return 0;
}