#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int n,m;
int timer,top,ans;
int head[MAXN],low[MAXN],dfn[MAXN];
bool bri[4000005],vis[MAXN];//一个点只能属于一个边双
vector<int> bcc[MAXN];
struct Node{
    int fro,to,nxt;
}edge[4000005];
void tarjan(int u,int fa){//传父边编号
    dfn[u]=low[u]=++timer;
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(i==(fa^1)) continue;//处理回边
        if(dfn[v]==0){
            tarjan(v,i);
            low[u]=min(low[u],low[v]);
            if(low[v]>dfn[u]){
                bri[i]=true;//只标记
                bri[i^1]=true;
            }
        }
        else{
            if(dfn[v]<dfn[u]){//是之前的边 避免重复处理
            low[u]=min(low[u],dfn[v]);
            }
        }
    }
    return;
}
void dfs(int u){
    vis[u]=true;
    bcc[ans].push_back(u);
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(bri[i]==true) continue;
        if(vis[v]==true) continue;//属于其他边双了
        dfs(v);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    int cnt=2;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        if(v==u)
            continue;
        edge[cnt].fro=u,edge[cnt].to=v;
        edge[cnt].nxt=head[u];
        head[u]=cnt;
        cnt++;
        edge[cnt].fro=v,edge[cnt].to=u;
        edge[cnt].nxt=head[v];
        head[v]=cnt;
        cnt++;
    }
    for(int i=1;i<=n;i++){
        if(dfn[i]==0){
            tarjan(i,0);
        }
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            ans++;
            dfs(i);
        }
    }
    cout<<ans<<'\n';
    for(int i=1;i<=ans;i++){
        cout<<bcc[i].size()<<" ";
        for(int j=0;j<bcc[i].size();j++)
        cout<<bcc[i][j]<<" ";
        cout<<'\n';
    }
    return 0;
}