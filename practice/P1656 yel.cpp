#include<bits/stdc++.h>
using namespace std;
int n,m;
int timer,top;
int head[160],dfn[160],low[160];
struct Node{
    int fro,to,nxt;
}edge[10005];
vector<pair<int,int>> ans;
void tarjan(int u,int fa){
    dfn[u]=low[u]=++timer;
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(v==fa) continue;
        if(dfn[v]==0){
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>dfn[u]){
                int a=u,b=v;
                if(a>b) swap(a,b);
                ans.push_back({a,b});
            }
        }
        else if(v!=fa)
            low[u]=min(low[u],dfn[v]);
    }
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
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].first<<" "<<ans[i].second<<'\n';
    }
    return 0;
}