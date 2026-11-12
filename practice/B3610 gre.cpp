#include<bits/stdc++.h>
using namespace std;
const int MAXN=50005;
int n,m;
int timer,top,gro;
int dfn[MAXN],low[MAXN],head[MAXN],stk[MAXN];
int mark[MAXN];
struct Node{
    int fro,to,nxt;
}edge[600005];
vector<int> bcc[MAXN];
vector<vector<int>> ans;
void tarjan(int u,int fa){//传父边
    dfn[u]=low[u]=++timer;
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(i==(fa^1)) continue;
        if(dfn[v]==0){
            stk[++top]=i;
            tarjan(v,i);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u]){
                gro++;
                while(true){
                    int x=stk[top--];
                    int uu=edge[x].fro;
                    int vv=edge[x].to;
                    if(mark[uu]!=gro){
                        bcc[gro].push_back(uu);
                        mark[uu]=gro;
                    }
                    if(mark[vv]!=gro){
                        bcc[gro].push_back(vv);
                        mark[vv]=gro;
                    }
                    if(x==i)
                        break;
                }
            }
        }
        else{
            if(dfn[v]<dfn[u])
            low[u]=min(low[u],dfn[v]);
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
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
        if(dfn[i]==0) tarjan(i,0);
    }
    cout<<gro<<'\n';
    for(int i=1;i<=gro;i++){
        sort(bcc[i].begin(),bcc[i].end());
        ans.push_back(bcc[i]);
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++)
        cout<<ans[i][j]<<" ";
        cout<<'\n';
    }
    return 0;
}