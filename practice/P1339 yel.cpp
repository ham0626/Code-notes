#include<bits/stdc++.h>
using namespace std;
int n,m,s,t;
struct node{
    int fro,to,val,nxt;
}edge[12210];
int head[2510],dis[2510];
bool vis[2510];
priority_queue<pair<int,int>> q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(dis,0x3f3f3f3f,sizeof(dis));//*
    cin>>n>>m>>s>>t;
    int cnt=1;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edge[cnt].fro=u,edge[cnt].to=v,edge[cnt].val=w;
        edge[cnt].nxt=head[u];
        head[u]=cnt;
        cnt++;//*
        edge[cnt].fro=v,edge[cnt].to=u,edge[cnt].val=w;
        edge[cnt].nxt=head[v];
        head[v]=cnt;
        cnt++;
    }
    dis[s]=0;
    q.push({-dis[s],s});
    while(!q.empty()){
        int cur=q.top().second;
        q.pop();
        if(vis[cur]==true) continue;
        vis[cur]=true;//标记已经是最短路的
        for(int i=head[cur];i;i=edge[i].nxt){
            int v=edge[i].to;
            int w=edge[i].val;
            if(dis[v]>dis[cur]+w){
                dis[v]=dis[cur]+w;
                q.push({-dis[v],v});
            }
        }
    }
    cout<<dis[t];
    return 0;
}