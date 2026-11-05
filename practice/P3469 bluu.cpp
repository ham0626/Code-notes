#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int n,m;
int timer=0,top=0,gro=0;
int head[MAXN];
long long dfn[MAXN],low[MAXN],siz[MAXN],ans[MAXN];
bool iscut[MAXN];
struct Node{
    int fro,to,nxt;
}edge[MAXN*10];
void tarjan(int u,int fa){
    siz[u]=1;
    ans[u]=2*(n-1);
    dfn[u]=low[u]=++timer;
    int child=0;
    long long sum=0;
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(v==fa) continue;
        if(dfn[v]==0){
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
            child++;
            siz[u]+=siz[v];
            if(low[v]>=dfn[u]){//只能和当前点联通
                ans[u]+=2*siz[v]*(n-siz[v]-1-sum);//每个子树看 整体子树可能被切开了
                sum+=siz[v];
                iscut[u]=true;
            }
        }
        else if(v!=fa){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(child>=2&&fa==0)
        iscut[u]=true;
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    int cnt=1;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        edge[cnt].fro=a,edge[cnt].to=b;
        edge[cnt].nxt=head[a];
        head[a]=cnt;
        cnt++;
        edge[cnt].fro=b,edge[cnt].to=a;
        edge[cnt].nxt=head[b];
        head[b]=cnt;
        cnt++;
    }
    for(int i=1;i<=n;i++){
        if(dfn[i]==0) tarjan(i,0);
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<'\n';
    return 0;
}