#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int n,m,top=0,gro=0,timer=0;
int low[MAXN],dfn[MAXN],head[MAXN],head2[MAXN];
int stk[MAXN];
bool instk[MAXN];
int belong[MAXN],siz[MAXN];
int dis[MAXN];
struct Node{
    int fro,to,nxt,val;
}edge[50005];
struct Node2{
    int fro,to,val,nxt;
}edge2[50005];
priority_queue<pair<int,int>> q;
void tarjan(int u){
    low[u]=dfn[u]=++timer;
    instk[u]=true;
    stk[++top]=u;
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(dfn[v]==0){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(instk[v]==true)
            low[u]=min(low[u],dfn[v]);//已经搜过
        else continue;
    }
    if(dfn[u]==low[u]){
        gro++;
        while(true){
            int x=stk[top--];//从最后一个弹出
            instk[x]=false;
            belong[x]=gro;
            siz[gro]++;
            if(x==u) break;
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(dis,0x3f3f3f3f,sizeof(dis));
    cin>>n>>m;
    int cnt=1;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edge[cnt].fro=u,edge[cnt].to=v,edge[cnt].val=w;
        edge[cnt].nxt=head[u];
        head[u]=cnt;
        cnt++;
    }
    for(int i=1;i<=n;i++){
        if(dfn[i]==0) tarjan(i);
    }
    int lin=1;
    for(int i=1;i<cnt;i++){
        int u=edge[i].fro;
        int v=edge[i].to;
        int w=edge[i].val;
        if(belong[u]!=belong[v]){
            u=belong[u],v=belong[v];
            edge2[lin].fro=u,edge2[lin].to=v,edge2[lin].val=w;
            edge2[lin].nxt=head2[u];
            head2[u]=lin;
            lin++;
        }
    }
    dis[belong[1]]=0;
    q.push({-dis[belong[1]],belong[1]});
    while(!q.empty()){
        int cur=q.top().second;
        int d=-q.top().first;
        q.pop();
        if(d>dis[cur]) continue;
        for(int i=head2[cur];i;i=edge2[i].nxt){
            int v=edge2[i].to;
            int w=edge2[i].val;
            if(dis[v]>dis[cur]+w){
                dis[v]=dis[cur]+w;
                q.push({-dis[v],v});
            }
        }
    }
    cout<<dis[belong[n]];
    return 0;
}