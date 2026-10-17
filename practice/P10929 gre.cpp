#include<bits/stdc++.h>
using namespace std;
//重边破坏:for(int i=head[cur];i;i=edge[i].nxt)
//邻接矩阵
int n,m;
long long mod=2147483647;
long long answer=1;
int dis[1005],ans[1005];
bool vis[1005];
int mapp[1005][1005];
priority_queue<pair<int,int>> q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(mapp,0x3f3f3f3f,sizeof(mapp));
    memset(dis,0x3f3f3f3f,sizeof(dis));
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        mapp[u][v]=min(mapp[u][v],w);
        mapp[v][u]=min(mapp[v][u],w);
    }
    dis[1]=0;
    q.push({-dis[1],1});
    while(!q.empty()){
        int cur=q.top().second;
        q.pop();
        if(vis[cur]) continue;
        vis[cur]=true;
        for(int i=0;i<=n;i++){
            int w=mapp[cur][i];
            if(w!=0x3f3f3f3f){//访问过
                if(dis[i]>dis[cur]+w){
                    dis[i]=dis[cur]+w;
                    q.push({-dis[i],i});
                }
                else continue;
                }
            }
        }
    ans[1]=1;
    for(int i=2;i<=n;i++)//找父节点，1节点不需要找//子节点
        for(int j=1;j<=n;j++){//父节点
            int w=mapp[i][j];
            if(dis[j]+w==dis[i]&&w!=0x3f3f3f3f) ans[i]++;
        }
    for(int i=1;i<=n;i++) answer=(answer*ans[i])%mod;
    if(ans!=0) cout<<answer;
    else cout<<"1";
    return 0;
}