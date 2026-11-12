#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int n,m;
int timer,top,gro,cc;//连通块数
long long ans=1e18;
long long sum,res[MAXN],val[MAXN],qua[MAXN];
int head[MAXN],head2[MAXN];
int dfn[MAXN],low[MAXN],belong[MAXN];
bool vis[MAXN],bri[2*MAXN];
struct Node{
    int fro,to,nxt;
}edge[400005];
struct Node2{
    int fro,to,nxt;
}edge2[400005];
void tarjan(int u,int fa){
    dfn[u]=low[u]=++timer;
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(i==(fa^1)) continue;
        if(dfn[v]==0){
            tarjan(v,i);
            low[u]=min(low[u],low[v]);
            if(low[v]>dfn[u]){
                bri[i]=true;
                bri[i^1]=true;
            }
        }
        else{
            if(dfn[v]<dfn[u])
            low[u]=min(low[u],dfn[v]);
        }
    }
    return;
}
void dfs(int u){
    vis[u]=true;
    belong[u]=gro;
    qua[gro]+=val[u];
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(bri[i]==true) continue;
        if(vis[v]==true) continue;
        dfs(v);
    }
}
void dfs2(int u,int fa){
    res[u]+=qua[u];
    for(int i=head2[u];i;i=edge2[i].nxt){
        int v=edge2[i].to;
        if(v==fa) continue;
        dfs2(v,u);
        res[u]+=res[v];
        ans=min(ans,abs(sum-2*res[v]));
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>val[i],sum+=val[i];
    int cnt=2;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
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
        if(dfn[i]==0) cc++,tarjan(i,0);
    }
    for(int i=1;i<=n;i++){
        if(belong[i]==0){
            gro++;
            dfs(i);
        }
    }
    int lin=1;
    if(cc>=3){
        cout<<"-1";
        return 0;
    }
    else if(cc==2){//本身有两块 不能删
        int flag=0;
        for(int i=2;i<cnt;i+=2){
            if(bri[i]==false){
                flag=1;
                break;
            }
        }
        if(flag==0){
            cout<<"-1";
            return 0;
        }
        long long summ=0;
        queue<int> q;
        q.push(1);
        memset(vis,0,sizeof(vis));
        vis[1]=true;
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            summ+=val[cur];
            for(int i=head[cur];i;i=edge[i].nxt){
                int v=edge[i].to;
                if(vis[v]==false){
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
        cout<<abs(sum-2*summ);
        return 0;
    }
    else{
        for(int i=2;i<cnt;i+=2){
            int u=edge[i].fro;
            int v=edge[i].to;
            if(bri[i]==true){
                u=belong[u];
                v=belong[v];
                edge2[lin].fro=u,edge2[lin].to=v;
                edge2[lin].nxt=head2[u];
                head2[u]=lin;
                lin++;
                edge2[lin].fro=v,edge2[lin].to=u;
                edge2[lin].nxt=head2[v];
                head2[v]=lin;
                lin++;
            }
        }
    }
    dfs2(1,0);//找差值最小
    if(ans==1e18) cout<<"-1";
    else cout<<ans;
    return 0;
}