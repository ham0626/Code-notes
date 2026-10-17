#include<bits/stdc++.h>
using namespace std;
int n,e;
int mapp[2005][2005];
int head[2005],ans[2005],dis[2005];
bool vis[2005];
priority_queue<pair<int,int>> q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(mapp,0x3f3f3f3f,sizeof(mapp));
    memset(dis,0x3f3f3f3f,sizeof(dis));
    cin>>n>>e;
    for(int i=1;i<=e;i++){
        int u,v,w;
        cin>>u>>v>>w;//邻接矩阵存，重边取最小
        mapp[u][v]=min(mapp[u][v],w);
    }
    dis[1]=0,ans[1]=1;
    q.push({-dis[1],1});
    while(!q.empty()){
        int cur=q.top().second;
        q.pop();
        if(vis[cur]) continue;
        vis[cur]=true;
        for(int i=1;i<=2000;i++){
            int w=mapp[cur][i];
            if(w!=0x3f3f3f3f){//访问过
                if(dis[i]>dis[cur]+w){
                    dis[i]=dis[cur]+w;
                    ans[i]=ans[cur];
                    q.push({-dis[i],i});
                }
                else if(dis[i]==dis[cur]+w){
                    ans[i]+=ans[cur];
                }
                else continue;
                }
            }
        }
    if(dis[n]==0x3f3f3f3f){
        cout<<"No answer";
        return 0;
    }
    else cout<<dis[n]<<" "<<ans[n];
    return 0;
}