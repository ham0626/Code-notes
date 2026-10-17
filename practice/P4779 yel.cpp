//单源最短路:Dijkstra(无负环，堆优化),SPFA
//多源最短路:Floyd
#include<bits/stdc++.h>
using namespace std;
int n,m,s;//点，边，起点
struct node{
    int fro,to,val,nxt;
}edge[200010];
long long dis[100010];
int head[100010];
bool vis[100010];
priority_queue<pair<long long,int>> q;//必须找最小，不能只在邻居里面搜
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>s;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edge[i].fro=u,edge[i].to=v,edge[i].val=w;
        edge[i].nxt=head[u];
        head[u]=i;
    }
    memset(dis,0x3f3f3f3f,sizeof(dis));
    dis[s]=0;
    q.push({-dis[s],s});
    while(!q.empty()){
        int num=q.top().second;
        q.pop();
        if(vis[num]==true) continue;
        else vis[num]=true;//锁点
        for(int i=head[num];i;i=edge[i].nxt){
            int v=edge[i].to;
            int w=edge[i].val;
            if(vis[v]==false&&dis[v]>dis[num]+w){//有更短路就更新
                dis[v]=dis[num]+w;
                q.push({-(dis[num]+w),v});
            }
        }
    }
    for(int i=1;i<=n;i++)
        cout<<dis[i]<<" ";
    return 0;
}