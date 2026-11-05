#include<bits/stdc++.h>
using namespace std;
const int MAXN =2e5+5;
int n;
int a,b,ans=0x3f3f3f3f;
int timer,top,gro;
int head[MAXN],dfn[MAXN],low[MAXN];
bool vis[MAXN];
struct Node{
    int fro,to,nxt;
}edge[1000005];
void tarjan(int u,int fa){
    dfn[u]=low[u]=++timer;
    if(u==b) vis[u]=true;
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(v==fa) continue;
        if(dfn[v]==0){
            tarjan(v,u);
            low[u]=min(low[v],low[u]);
            if(vis[v]==true) vis[u]=true;//要先搜索才能判断
            if(low[v]>=dfn[u]&&vis[v]==true&&u!=a&&u!=b){//割点
                ans=min(ans,u);
            }
        }
        else if(v!=fa)//防止重边
            low[u]=min(low[u],dfn[v]);
        else continue;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    int cnt=1;
    int u,v;
    while(cin>>u>>v){
        if(u==0&&v==0) break;
        edge[cnt].fro=u,edge[cnt].to=v;
        edge[cnt].nxt=head[u];
        head[u]=cnt;
        cnt++;
        edge[cnt].fro=v,edge[cnt].to=u;
        edge[cnt].nxt=head[v];
        head[v]=cnt;
        cnt++;
    }
    cin>>a>>b;
    tarjan(a,0);//a b必定联通
    if(ans!=0x3f3f3f3f) cout<<ans;
    else cout<<"No solution";
    return 0;
}