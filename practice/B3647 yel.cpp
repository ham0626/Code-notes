//单源最短路:SPFA,dijkstra
//多源最短路稠密图:Floyd(必须邻接矩阵->转移方程)
//稠密图:邻接矩阵
//稀疏图:链式前向星
#include<bits/stdc++.h>
using namespace std;
int n,m;
int dis[110][110];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(dis,0x3f3f3f3f,sizeof(dis));
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        dis[u][v]=min(dis[u][v],w);
        dis[v][u]=min(dis[v][u],w);
    }
    for(int k=1;k<=n;k++)//途径地
        for(int i=1;i<=n;i++)//起点
            for(int j=1;j<=n;j++){//目的地
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) cout<<"0 ";
            else cout<<dis[i][j]<<" ";
        }
        cout<<'\n';
    }    
    return 0;
}