#include<bits/stdc++.h>
using namespace std;
int n,m,s,t;
struct node{
    int fro,to,nxt;
    float val;
}edge[4010];
int head[110],x[110],y[110];
float dis[110];
bool vis[110];
priority_queue<pair<float,int>> q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) dis[i]=1e18;//float初始化
    int cnt=1;
    for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
    cin>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        float w=pow((x[u]-x[v])*(x[u]-x[v])+(y[u]-y[v])*(y[u]-y[v]),0.5);
        edge[cnt].fro=u,edge[cnt].to=v,edge[cnt].val=w;
        edge[cnt].nxt=head[u];
        head[u]=cnt;
        cnt++;//*
        edge[cnt].fro=v,edge[cnt].to=u,edge[cnt].val=w;
        edge[cnt].nxt=head[v];
        head[v]=cnt;
        cnt++;//*
    }
    cin>>s>>t;
    dis[s]=0;
    q.push({-dis[s],s});
    while(!q.empty()){
        int cur=q.top().second;
        q.pop();
        if(vis[cur]==true) continue;
        vis[cur]=true;//标记已经是最短路的
        for(int i=head[cur];i;i=edge[i].nxt){
            int v=edge[i].to;
            float w=edge[i].val;
            if(dis[v]>dis[cur]+w){
                dis[v]=dis[cur]+w;
                q.push({-dis[v],v});
            }
        }
    }
    cout<<fixed<<setprecision(2)<<dis[t];
    return 0;
}