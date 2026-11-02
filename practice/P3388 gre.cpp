//割点
//在这个连通图里，如果删掉节点u，图就不连通了,那u就是割点
//割边
//删除u->v的边图就不连通了
#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e4+5;
int n,m,top=0,timer=0;
int low[MAXN],dfn[MAXN],head[MAXN];
bool iscut[MAXN];
struct Node{
    int fro,to,nxt;
}edge[300005];
void tarjan(int u,int fa){//割点
    low[u]=dfn[u]=++timer;
    int child=0;
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(v==fa) continue;
        if(dfn[v]==0){
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
            child++;
            if(fa!=0&&low[v]>=dfn[u])//不是根
                iscut[u]=true;
        }
        else if(v!=fa)//访问过但不是父节点
            low[u]=min(low[u],dfn[v]);
    }
    if(fa==0&&child>=2)//根节点
        iscut[u]=true;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    int cnt=1;
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
        if(dfn[i]==0) tarjan(i,0);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(iscut[i]==true) ans++;
    }
    cout<<ans<<'\n';
    for(int i=1;i<=n;i++){
        if(iscut[i]==true) cout<<i<<" ";
    }
    return 0;
}